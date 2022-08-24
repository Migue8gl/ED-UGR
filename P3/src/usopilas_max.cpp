#include "Pila_Max.h"
#include <iostream>
using namespace std;

int main() {

  Pila_Max<int> pila;
  int i;

  for (i = 10; i >= 0 ; i--) {
    pila.poner(i);
  }
  while (!pila.vacia()) {
    Elemento<int> x = pila.tope();
    cout << x << endl;
    pila.quitar();
  }
}