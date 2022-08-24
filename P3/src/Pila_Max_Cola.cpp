#include <cassert>

template <class T>
Pila_Max<T>::Pila_Max() {};

template <class T>
Pila_Max<T>::Pila_Max(const Pila_Max<T>& orig) {
	cola = orig.cola;
}

template <class T>
bool Pila_Max<T>::vacia() const {
	return cola.vacia();
}

template <class T>
Elemento<T> Pila_Max<T>::tope() {
	return cola.frente();
}

template <class T>
int Pila_Max<T>::num_elementos() {
	return cola.num_elementos();
}

template<class T>
void Pila_Max<T>::poner(T x) {
	Cola <Elemento <T> > aux_cola;
	Elemento <T> aux;
	aux.ele = x;

	if (!cola.vacia()) {
		if (aux.ele > cola.frente().max)
			aux.max = aux.ele;
		else
			aux.max = cola.frente().max;
	}
	else
		aux.max = x;

	aux_cola.poner(aux);

	while (!cola.vacia()) {
		aux_cola.poner(cola.frente());
		cola.quitar();
	}

	while (!aux_cola.vacia()) {
		cola.poner(aux_cola.frente());
		aux_cola.quitar();
	}
}

template <class T>
void Pila_Max<T>::quitar() {
	cola.quitar();
}


