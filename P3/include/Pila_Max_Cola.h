#ifndef PILA_MAX_H
#define PILA_MAX_H

#include "cola.h"
#include <iostream>
using namespace std;

template <class T>
struct Elemento {
    T ele;
    T max;
};

template <class T>
class Pila_Max {
private:
    Cola<Elemento<T>> cola;

public:
    Pila_Max();
    Pila_Max(const Pila_Max<T>& orig);
    Elemento<T> tope();
    void poner(T x);
    void quitar();
    int num_elementos();
    bool vacia() const;
};

template <class T>
ostream& operator<< (ostream& os, const Elemento<T>& e){
    return os << "ITEM--> " << "<" << e.ele << "> | MAX--> " <<"<" << e.max << ">" << endl;
}

#include "../src/Pila_Max_Cola.cpp"

#endif /* PILA_MAX_H */

