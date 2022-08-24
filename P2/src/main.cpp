// Fichero: main.cpp
// Realiza las funciones de zoom, umbral, aumento de contraste y
// creacion de un icono de una imagen PGM.
// Formato:
//    ejecutable -<Funcion> <Parametros> ... <FichImagenOriginal> <FichImagenDestino>
//    donde:
//   <Funcion> es la transformacion que modificara nuestra imagen PGM.
//   <Paramtros> ... Son los distintos parametros de cada funcion, por
//        ejemplo, en el caso de zoom seran las coordenadas x1,y1 y x2,y2.
//   <FichImagenOriginal> es la imagen PGM a la que se va a calcular
//        distintas funciones. No se modifica.
//   <FichImagenDestino> es la imagen PGM resultado de calcular las
//        distinas funciones a <FichImagenOriginal>.
//
// Miguel García López - Octubre 2020

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "imagenES.h"
#include <math.h>
#include "Imagen.h"
using namespace std;

typedef unsigned char byte;


//Funcion auxiliar para transformar enteros en strings
//La he requerido para nombrar las distintas imagenes de transicion del morphing

string itoa(int n) {
    string rtn;
    for (rtn = ""; n > 0; rtn.insert(rtn.begin(), n % 10 + '0'), n /= 10);
    return rtn;
}

void umbralizar(Imagen & I, int T1, int T2);
void enmarca_imagen(Imagen & I);
void binarizacion_imagen(Imagen & I, int t);
Imagen zoom(Imagen & I, int x1, int y1, int x2, int y2);
Imagen icono(Imagen & I, int nf, int nc);
void aumentar_contraste(Imagen & I, double min, double max);
void pasarVectorToImagen(Imagen &img, byte *vect);
void pasarImagenToVector(Imagen &img, byte *vect);
void morphing(Imagen & I1, Imagen &I2, int num_img, Imagen *imgs);

int main(int argc, char** argv) {

    char *imageE, *imageS;
    byte *datos, *datos2;
    Imagen *imgs;
    int i = 0;
    int nf, nc; // Num. de filas y columnas de las imagenes
    string sarg;
    char *arg[13];
    bool is_umbralizar = false, is_zoom = false, is_aumContraste = false, is_icono = false, is_morphing = false;

    //Lectura de parametros del main
    for (i = 1; i < argc;) {
        sarg = argv[i++];

        if (sarg == "-umbralizar") {
            is_umbralizar = true;
            arg[0] = argv[i++];
            arg[1] = argv[i++];
            break;
        } else if (sarg == "-zoom") {
            is_zoom = true;
            arg[2] = argv[i++];
            arg[3] = argv[i++];
            arg[4] = argv[i++];
            arg[5] = argv[i++];
            break;
        } else if (sarg == "-icono") {
            is_icono = true;
            arg[6] = argv[i++];
            arg[7] = argv[i++];
            break;
        } else if (sarg == "-aumentar_contraste") {
            is_aumContraste = true;
            arg[8] = argv[i++];
            arg[9] = argv[i++];
            break;
        } else if (sarg == "-morphing") {
            is_morphing = true;
            arg[10] = argv[i++];
            break;
        } else {
            cerr << "Uso: -<Funcion> <Parametros> ... <FichImagenOriginal> <FichImagenDestino>\n";
            exit(1);
        }
    }

    arg[11] = argv[i++];
    arg[12] = argv[i++];


    imageE = arg[11];
    imageS = arg[12];

    // Leer la imagen del fichero de entrada
    datos = LeerImagenPGM(imageE, nf, nc);
    if (!datos) {
        cerr << "Error: No pudo leerse la imagen." << endl;
        cerr << "Terminando la ejecucion del programa." << endl;
        exit(1);
    }

    Imagen imagen(nf, nc);
    Imagen imagen2(nf, nc);

    pasarVectorToImagen(imagen, datos);

    if (is_morphing) {
        imgs = new Imagen [atoi(arg[10])];
        datos2 = LeerImagenPGM(imageS, nf, nc);
        if (!datos2) {
            cerr << "Error: No pudo leerse la imagen." << endl;
            cerr << "Terminando la ejecucion del programa." << endl;
            exit(1);
        }

        pasarVectorToImagen(imagen2, datos2);
    }

    // Mostrar los parametros calculados por LeerImagenPGM()
    cout << endl;
    cout << "Dimensiones de " << imageE << ":" << endl;
    cout << "   Imagen   = " << nf << " filas x " << nc << " columnas " << endl;
    cout << endl;
    cout << "Fichero origen: " << imageE << endl;
    cout << "Fichero resultado: " << imageS << endl;

    //Se realiza la funcion especificada
    if (is_umbralizar)
        umbralizar(imagen, atoi(arg[0]), atoi(arg[1]));
    else if (is_zoom)
        imagen = zoom(imagen, atoi(arg[2]), atoi(arg[3]), atoi(arg[4]), atoi(arg[5]));
    else if (is_icono)
        imagen = icono(imagen, atoi(arg[6]), atoi(arg[7]));
    else if (is_aumContraste)
        aumentar_contraste(imagen, stod(arg[8]), stod(arg[9]));
    else if (is_morphing)
        morphing(imagen, imagen2, atoi(arg[10]), imgs);

    if (!is_morphing) {
        datos = new byte [imagen.getColumnas() * imagen.getFilas()];

        pasarImagenToVector(imagen, datos);

        // Guardar la imagen resultado en el fichero
        if (EscribirImagenPGM(imageS, datos, imagen.getFilas(), imagen.getColumnas()))
            cout << "La imagen se guardo en " << imageS << endl;
        else {
            cerr << "Error: No pudo guardarse la imagen." << endl;
            cerr << "Terminando la ejecucion del programa." << endl;
            exit(2);
        }

        delete [] datos;

    } else {
        byte *img = new byte [imagen.getColumnas() * imagen.getFilas()];
        char u;

        for (int i = 0; i < atoi(arg[10]); i++) {
            pasarImagenToVector(imgs[i], img);
            string name = "x";
            name += itoa(i);
            EscribirImagenPGM(name.c_str(), img, imagen.getFilas(), imagen.getColumnas());
        }

        delete [] img;
        delete [] imgs;
        delete [] datos2;
    }

    return (0);
}

void enmarca_imagen(Imagen & I) {
    int f, c, nf = I.getFilas(), nc = I.getColumnas();

    for (f = 0; f < nf; f++)
        I.setPixel(f, 0, 0);

    for (f = 0; f < nf; f++)
        I.setPixel(f, nc - 1, 0);

    for (c = 0; c < nc; c++)
        I.setPixel(0, c, 0);

    for (c = 0; c < nc; c++)
        I.setPixel(nf - 1, c, 0);
}

void binarizacion_imagen(Imagen & I, int t) {
    int f, c, nf = I.getFilas(), nc = I.getColumnas();

    for (f = 0; f < nf; f++)
        for (c = 0; c < nc; c++)
            if (I.getPixel(f, c) <= t)
                I.setPixel(f, c, 0);
            else
                I.setPixel(f, c, 255);
}

void umbralizar(Imagen & I, int T1, int T2) {

    for (int i = 0; i < I.getFilas(); i++)
        for (int j = 0; j < I.getColumnas(); j++) {
            if (I.getPixel(i, j) <= T1 || I.getPixel(i, j) >= T2)
                I.setPixel(i, j, 255);
        }
}

Imagen zoom(Imagen & I, int x1, int y1, int x2, int y2) {

    Imagen imagen_zoom(2 * (x2 - x1) - 1, 2 * (y2 - y1) - 1);

    //Cogemos la sección a aumentar
    for (int i = 0; i < x2 - x1; i++)
        for (int j = 0; j < y2 - y1; j++) {
            imagen_zoom.setPixel(2 * i, 2 * j, I.getPixel(i + x1, j + y1));
        }

    byte pixel;

    //Interpolación de las columnas
    for (int r = 0; r < imagen_zoom.getFilas(); r += 2) {
        for (int c = 1; c < imagen_zoom.getColumnas(); c += 2) {

            pixel = round((imagen_zoom.getPixel(r, c - 1) + imagen_zoom.getPixel(r, c + 1)) / 2);
            imagen_zoom.setPixel(r, c, pixel);
        }
    }

    //Interpolación de las filas
    for (int r = 1; r < imagen_zoom.getFilas(); r += 2) {
        for (int c = 0; c < imagen_zoom.getColumnas(); c++) {

            pixel = round((imagen_zoom.getPixel(r - 1, c) + imagen_zoom.getPixel(r + 1, c)) / 2);
            imagen_zoom.setPixel(r, c, pixel);
        }
    }

    return imagen_zoom;
}


/**
*NOTA:
* Pese a haberlo intentado, no he conseguido que icono funcione para todos
* los tamaños, solo funciona para tamaños divisores del tamaño original
*/
Imagen icono(Imagen & I, int nf, int nc) {

    Imagen imagen_icono(nf, nc);

    float x = I.getFilas() / nf;
    float y = I.getColumnas() / nc;
    float bloque_pixel = 0;
    int x_begin = 0, x_end = 0;
    int y_begin = 0, y_end = 0;

    for (int i = 0; i < nf; i++) {
        x_begin = x * i;
        x_end = x + x_begin;

        for (int j = 0; j < nc; j++) {
            y_begin = y * j;
            y_end = y + y_begin;

            for (int k = x_begin; k < x_end; k++) {
                for (int h = y_begin; h < y_end; h++) {
                    bloque_pixel += round(I.getPixel(k, h));
                }
            }
            bloque_pixel /= (x * y);
            imagen_icono.setPixel(i, j, bloque_pixel);
            bloque_pixel = 0;
        }
    }

    return imagen_icono;
}

void morphing(Imagen & I1, Imagen &I2, int imagenes, Imagen *imgs) {

    float g = 0.0;

    for (int h = 0; h < imagenes; h++) {
        Imagen img(I1.getFilas(), I2.getColumnas());

        for (int i = 0; i < I1.getFilas(); i++) {
            for (int j = 0; j < I1.getColumnas(); j++) {
                img.setPixel(i, j, (1 - g) * I1.getPixel(i, j) + g * I2.getPixel(i, j));
            }
        }
        g += 1 / (float) imagenes;
        imgs[h] = img;
    }
}

void aumentar_contraste(Imagen & I, double min, double max) {
    double cociente = (max - min) / (255 - 0);
    double valor = 0;

    for (int i = 0; i < I.getFilas(); i++)
        for (int j = 0; j < I.getColumnas(); j++) {
            valor = min + (cociente * (I.getPixel(i, j) - 0));
            I.setPixel(i, j, round(valor));
        }
}

void pasarVectorToImagen(Imagen &img, byte *vect) {
    int k = 0;

    for (int i = 0; i < img.getFilas(); i++)
        for (int j = 0; j < img.getColumnas(); j++) {
            img.setPixel(i, j, vect[k]);
            k++;
        }
}

void pasarImagenToVector(Imagen &img, byte *vect) {
    int k = 0;

    for (int i = 0; i < img.getFilas(); i++) {
        for (int j = 0; j < img.getColumnas(); j++) {
            vect [k] = img.getPixel(i, j);
            k++;
        }
    }
}


