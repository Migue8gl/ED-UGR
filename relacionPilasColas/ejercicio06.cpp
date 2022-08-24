#include <iostream>
#include <stack>
using namespace std;

template <typename T>

void insertar(stack<T> &P,int pos,const T &x) {
	stack<T> aux;
	int tamPila = P.size() + 1;

	if (pos < tamPila && pos >= 0) {

		for (int i = 0; i < tamPila; i++) {
			if (i == pos)
				aux.push(x);
			else {
				aux.push(P.top());
				P.pop();
			}
		}

		while (!aux.empty()) {
			P.push(aux.top());
			aux.pop();
		}
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
	int pos = 5, x = 10, aux;

	for (int i = 0; i < 5; i++) {
		cout << "Introducir --> ";
		cin >> aux;
		Pila.push(aux);
	}

	cout << endl;

	cout << "PILA: ";
	leerPila(Pila);

	cout << endl;

	insertar(Pila, pos, x);

	cout << "PILA MODIFICADA: ";
	leerPila(Pila);

	cout << endl;
}