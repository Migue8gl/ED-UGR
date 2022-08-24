#ifndef IMAGEN_H
#define IMAGEN_H

typedef unsigned char byte;

/**
 * @brief T.D.A Imagen
 * 
 * Una instancia del tipo de Dato @c Imagen es un objeto
 * matriz bidimensional, la cual representa una imagen digital y 
 * esta compuesta por pixeles (casa casilla de la matriz).
 * 
 * @author Miguel Garcia Lopez
 * @date Octubre 2020
 */

class Imagen {
private:
    
    /**
     * @page repConjunto Rep del TDA Imagen
     *
     * @section invConjunto Invariante de la representacion
     * Un objeto valido de @e i del TDA Imagen debe cumplir
     *   @c filas >= 0
     *   @c columnas >= 0
     *   @c img[filas][columnas] >= 0 y img[filas][columnas] <= 255
     *
     * @section faConjunto Funcion de abstraccion
     * Un objeto valido de @e i del TDA Imagen representa una imagen digital
     *
     */
    
    int c; /**< filas */
    int f; /**< columas */
    byte **img; /**< matriz bidimensional que contiene cada píxel */


public:
    
    /**
     * @brief Constructor por defecto de la clase. Crea la imagen f=0, c=0 e img=nullptr
     */
    Imagen();
    
    /**
     * @brief Constructor por copia con un parametro objeto. Crea la imagen f=ob.filas,
     * c=ob.filas e img=ob.img;
     * @param ob Imagen a copiar en el nuevo objeto
     */
    Imagen(const Imagen& ob);
    
    /**
     * @brief Constructor con dos parametros. Crea la imagen f=filas,
     * c=filas e img=nullptr;
     * @param filas Filas de la matriz que representa la imagen
     * @param columnas Columnas de la matriz que representa la imagen
     */
    Imagen(int filas, int columnas);
    
    /**
     * @brief Destructor por defecto de la clase. Libera memoria de la matriz img
     */
    ~Imagen();
    
    /**
     * @brief Reserva dinamica de memoria para la matriz img con tamaño filaxcolumnas
     * @param filas Filas de la matriz que representa la imagen
     * @param columnas Columnas de la matriz que representa la imagen
     */
    void reservarMemoria(int filas, int columnas);
    
    /**
     * @brief Libera la memoria dinamica de la matriz img
     */
    void liberarMemoria();
    
    /**
     * @brief Obtiene la posicion de la matriz img
     * @param filas Filas de la matriz que representa la imagen
     * @param columnas Columnas de la matriz que representa la imagen
     * @pre @c Columnas y @c filas deben ser valores entre 0 y 255
     * @return posicion de la matriz
     */
    byte getPixel(int fila, int columna) const;
    
    /**
     * @brief Obtiene el numero de filas de la matriz
     * @return numero de filas
     */
    int getFilas() const;
    
    /**
     * @brief Obtiene el numero de columnas de la matriz
     * @return numero de columnas
     */
    int getColumnas() const;
    
    /**
     * @brief Modifica el valor que se requiera de la matriz
     * @param fila Fila donde se va a modificar el valor
     * @param columna Columna donde se va a modificar el valor
     * @pre La @c fila y @c columna deben ser menores o iguales a las filas
     * y columnas de la matriz a la que se va a acceder
     * @return numero de filas
     */
    void setPixel(int fila, int columna, byte lum);
    
    /**
     * @brief Sobrecarga del operador =, iguala los atributos del
     * objeto pasado con los del modificado
     * @param ob Objeto del que se toman los atributos
     * @return imagen modificada.
     */
    void operator=(const Imagen& ob);
};

#endif /* IMAGEN_H */


