#include <stack>
#include <iostream>
using namespace std;

template <class T>
class cola {
private:
	stack<T> pila1, pila2;

public:
	cola();
	cola(const cola<T>& orig);
	T front();
	T back();
	void push(T x);
	void pop();
	int size();
	bool empty() const;
};

template <class T>
cola<T>::cola() {}

template <class T>
cola<T>::cola(const cola<T>& orig) {
	pila1 = orig.pila1;
	pila2 = orig.pila2;
}

template <class T>
bool cola<T>::empty() const {
	return pila1.empty();
}

template <class T>
T cola<T>::front() {
	return pila1.top();
}

template<class T>
T cola<T>::back() {
	return pila2.top();
}

template <class T>
int cola<T>::size() {
	return pila1.size();
}

template<class T>
void cola<T>::push(T x) {

	if (!pila2.empty())
		pila2.pop();

	while (!empty()) {
		pila2.push(front());
		pop();
	}

	pila2.push(x);

	while (!pila2.empty()) {
		pila1.push(pila2.top());
		pila2.pop();
	}

	pila2.push(x);
}

template <class T>
void cola<T>::pop() {
	pila1.pop();
}

template<class T>
void leerCola(cola<T>&C) {
	cola<T> aux(C);

	while (!aux.empty()) {
		cout << "<" << aux.front() << "> ";
		aux.pop();
	}
}

int main() {
	cola<int> cola;
	int aux;

	for (int i = 0; i < 5; i++) {
		cout << "Introducir --> ";
		cin >> aux;
		cola.push(aux);
	}

	cout << endl;

	cout << "COLA: ";
	leerCola(cola);

	cout << "\nCOLA BACK: ";
	cout << "<" << cola.back() << ">";

	cout << endl;
}


