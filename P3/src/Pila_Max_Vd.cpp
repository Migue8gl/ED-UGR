#include <cassert>

template <class T>
Pila_Max<T>::Pila_Max() {};

template <class T>
Pila_Max<T>::Pila_Max(const Pila_Max<T>& orig) {
	vect = orig.vect;
}

template <class T>
bool Pila_Max<T>::vacia() const {
	return vect.empty();
}

template <class T>
Elemento<T> Pila_Max<T>::tope() {
	return vect.back();
}

template <class T>
int Pila_Max<T>::num_elementos() {
	return vect.size();
}

template<class T>
void Pila_Max<T>::poner(T x) {
	Elemento <T> aux;
	aux.ele = x;

	if (!vacia()) {
		if (aux.ele > tope().max)
			aux.max = aux.ele;
		else
			aux.max = tope().max;
	}
	else
		aux.max = x;

	vect.push_back(aux);
}

template <class T>
void Pila_Max<T>::quitar() {
	vect.resize(vect.size() - 1);
}


