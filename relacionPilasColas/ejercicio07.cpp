#include <iostream>
#include <queue>
using namespace std;

template <typename T>

void insertar(queue<T> &P,int pos,const T &x) {
	queue<T> aux;
	int tamCola = P.size() + 1;

	if (pos < tamCola && pos >= 0) {

		for (int i = 0; i < tamCola; i++) {
			if (i == pos)
				aux.push(x);
			else {
				aux.push(P.front());
				P.pop();
			}
		}

		while (!aux.empty()) {
			P.push(aux.front());
			aux.pop();
		}
	}
}

template <typename T>

void leerCola(queue<T>&Q) {
	queue<T> aux = Q;

	while (!aux.empty()) {
		cout << "<" << aux.front() << "> ";
		aux.pop();
	}
}

int main() {
	queue<int> Cola;
	int pos = 4, x = 10, aux;

	for (int i = 0; i < 5; i++) {
		cout << "Introducir --> ";
		cin >> aux;
		Cola.push(aux);
	}

	cout << endl;

	cout << "COLA: ";
	leerCola(Cola);

	cout << endl;

	insertar(Cola, pos, x);

	cout << "COLA MODIFICADA: ";
	leerCola(Cola);

	cout << endl;
}