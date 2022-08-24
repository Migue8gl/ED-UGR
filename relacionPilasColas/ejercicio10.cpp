#include <iostream>
#include <stack>
using namespace std;

template <typename T> class ventana {
private:
	int pos = 0;
	stack<T> izq;
	stack<T> der;

public:
	void insertar(T elemento);
	void mover_derecha();
	void mover_izquierda();
	void borrar_elemento();
	T devolver_elemento() const;
	bool fin() const;
	bool inicio() const;
};

template <typename T>
void ventana<T>::insertar(T elemento) {
	stack<T> aux;

	aux.push(elemento);

	while (!aux.empty()) {
		izq.push(aux.top());
		aux.pop();
	}
}

template <typename T>
void ventana<T>::mover_derecha() {
	if (!fin()) {

		stack<T> aux;

		while (!izq.empty()) {
			aux.push(izq.top());
			izq.pop();
		}

		aux.push(der.top());
		der.pop();

		while (!aux.empty()) {
			izq.push(aux.top());
			aux.pop();
		}

		pos++;
	}
}

template <typename T>
void ventana<T>::mover_izquierda() {
	if (!inicio()) {

		stack<T> aux;

		while (!der.empty()) {
			aux.push(der.top());
			der.pop();
		}

		aux.push(izq.top());
		der.pop();

		while (!aux.empty()) {
			der.push(aux.top());
			aux.pop();
		}

		pos--;
	}
}

template <typename T>
void ventana<T>::borrar_elemento() {
	stack<T> aux;
	int tamPila = izq.size() - 1;

	for (int i = 0; i < tamPila; i++) {
		if (i == pos)
			aux.pop();
		else {
			aux.push(izq.top());
			izq.pop();
		}
	}

	while (!aux.empty()) {
		izq.push(aux.top());
		aux.pop();
	}
}

template <typename T>
T ventana<T>::devolver_elemento() const {
	return izq.top();
}

template <typename T>
bool ventana<T>::fin() const {
	return der.empty();
}

template <typename T>
bool ventana<T>::inicio() const {
	return izq.empty();
}

int main() {
	ventana<char> vent;
	char item;

	for (int i = 0; i < 10; i++) {
		cout << "--> ";
		cin >> item;
		vent.insertar(item);
	}

	for (int i = 0; i < 10; i++) {
		cout << vent.devolver_elemento();
		vent.mover_izquierda();
	}

	cout << endl;
}

