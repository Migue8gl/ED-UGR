#include <iostream>
#include <stack>
using namespace std;

template <typename T>

void modificar(stack<T>&P,const T &x,const T &y) {
	stack<T> newPila;

	while (!P.empty()) {
		if (P.top() == x)
			newPila.push(y);
		else
			newPila.push(P.top());

		P.pop();
	}

	while (!newPila.empty()) {
		P.push(newPila.top());
		newPila.pop();
	}
}

template <typename T>

void leerPila(stack<T>&P) {
	stack<T> aux = P;

	while (!aux.empty()) {
		cout << "<" << aux.top() << "> ";
		aux.pop();
	}
}

int main() {
	stack<int> Pila;
	int x = 2, y = 3, aux;

	for (int i = 0; i < 5; i++) {
		cout << "Introducir --> ";
		cin >> aux;
		Pila.push(aux);
	}

	cout << endl;

	cout << "PILA: ";
	leerPila(Pila);

	cout << endl;

	modificar(Pila, x, y);

	cout << "PILA MODIFICADA: ";
	leerPila(Pila);

	cout << endl;
}