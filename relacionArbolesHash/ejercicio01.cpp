#include "bintree.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
typename bintree<T>::node mas_profunda(const bintree<T> &arb) {
	typename bintree<T>::node nodo = arb.root();
	typename bintree<T>::node aux = nodo;
	queue<typename bintree<T>::node> cola;

	if (arb.empty())
		return nodo;

	while (!aux.null()) {
		nodo = aux;

		if (!aux.left().null())
			cola.push(aux.left());

		if (!aux.right().null())
			cola.push(aux.right());

		aux = cola.front();
		cola.pop();
	}

	return nodo;
}

bintree<int> crear_arbol() {
	bintree<int> A(7);
	bintree<int>::node n;

	A.insert_left(A.root(), 1);
	A.insert_right(A.root(), 9);
	n = A.root().left();
	A.insert_left(n, 6);
	A.insert_right(n, 8);

	n = n.right();
	A.insert_right(n, 4);

	n = A.root().right();
	A.insert_left(n, 5);

	return A;
}

int main() {
	bintree<int> arbol = crear_arbol();
	bintree<int>::node nodo = mas_profunda(arbol);

	cout << "Hoja más profunda del árbol: " << *nodo << endl;
}