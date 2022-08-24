#include <queue>
#include <iostream>
using namespace std;


template <class T>
class pila {
private:
	queue<T> cola1, cola2;

public:
	pila();
	pila(const pila<T>& orig);
	T top();
	void push(T x);
	void pop();
	int size();
	bool empty() const;
};

template <class T>
pila<T>::pila() {};

template <class T>
pila<T>::pila(const pila<T>& orig) {
	cola1 = orig.cola1;
}

template <class T>
bool pila<T>::empty() const {
	return cola1.empty();
}

template <class T>
T pila<T>::top() {
	return cola1.front();
}

template <class T>
int pila<T>::size() {
	return cola1.size();
}

template<class T>
void pila<T>::push(T x) {
	cola2.push(x);

	while (!empty()) {
		cola2.push(cola1.front());
		cola1.pop();
	}

	while (!cola2.empty()) {
		cola1.push(cola2.front());
		cola2.pop();
	}
}

template <class T>
void pila<T>::pop() {
	cola1.pop();
}

template <class T>
void leerPila(pila<T>&P) {
	pila<T> aux(P);

	while (!aux.empty()) {
		cout << "<" << aux.top() << "> ";
		aux.pop();
	}
}

int main() {
	pila<int> pila;
	int aux;

	for (int i = 0; i < 5; i++) {
		cout << "Introducir --> ";
		cin >> aux;
		pila.push(aux);
	}

	cout << endl;

	cout << "PILA: ";
	leerPila(pila);

	cout << endl;
}


