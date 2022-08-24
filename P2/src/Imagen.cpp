#include "Imagen.h"
#include <cassert>

Imagen::Imagen() {
    img = nullptr;
    c = 0;
    f = 0;
}

Imagen::Imagen(const Imagen& ob) {
    Imagen();
    *this = ob;
}

Imagen::Imagen(int filas, int columnas) {
    assert(filas >= 0 && columnas >= 0);
    c = columnas;
    f = filas;
    img = nullptr;
    
    reservarMemoria(filas, columnas);
}

Imagen::~Imagen() {
    liberarMemoria();
}

void Imagen::reservarMemoria(int filas, int columnas) {
    byte **aux;
    aux = new byte* [filas];

    for (int i = 0; i < filas; i++)
        aux[i] = new byte [columnas];

    for (int i = getFilas(); i < filas; i++)
        for (int j = getColumnas(); j < columnas; j++)
            aux[i][j] = 0;

    if (img != nullptr) {
        for (int i = 0; i < getFilas(); i++)
            for (int j = 0; j < getColumnas(); j++)
                aux[i][j] = getPixel(i, j);

        liberarMemoria();
    }

    img = aux;
    c = columnas;
    f = filas;
    aux = nullptr;
}

void Imagen::liberarMemoria() {
    for (int i = 0; i < f; i++)
        delete [] img[i];
        
    delete [] img;
    img = nullptr;
    c = 0;
    f = 0;
}

byte Imagen::getPixel(int fila, int columna) const{
    assert(fila < getFilas() && columna < getColumnas() && fila >= 0 && columna >= 0);
    return img[fila][columna];
}

int Imagen::getFilas() const{
    return f;
}

int Imagen::getColumnas() const{
    return c;
}

void Imagen::setPixel(int fila, int columna, byte lum) {
    assert(fila < getFilas() && columna < getColumnas() && fila >= 0 && columna >= 0 && lum >= 0 && lum <= 255);
    img[fila][columna] = lum;
}

void Imagen::operator =(const Imagen& ob) {
    if(&ob != this){
        if(img != nullptr)
            liberarMemoria();
        
        reservarMemoria(ob.getFilas(), ob.getColumnas());
        
        for(int i = 0; i < ob.getFilas(); i++)
            for(int j = 0; j < ob.getColumnas(); j++)
                setPixel(i, j, ob.getPixel(i, j));
    }
}
