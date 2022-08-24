#include "bintree.h"
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
int altura(const bintree<T> &arb) {
	typename bintree<T>::node aux = arb.root();
	int altura = -1, altura_nodo = 0;;
	stack<pair<typename bintree<T>::node, int>> pila;

	if (arb.empty())
		return altura;

	pila.push(pair<typename bintree<T>::node, int>(aux, altura_nodo));

	while (!pila.empty()) {
		aux = pila.top().first;
		altura_nodo = pila.top().second;

		pila.pop();

		if (!aux.left().null())
			pila.push(pair<typename bintree<T>::node, int>(aux.left(), altura_nodo + 1));

		if (!aux.right().null())
			pila.push(pair<typename bintree<T>::node, int>(aux.right(), altura_nodo + 1));

		if (aux.left().null() && aux.right().null()) {
			if (altura_nodo > altura)
				altura = altura_nodo;
		}
	}

	return altura;
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
	int alt = altura(arbol);

	cout << "Altura del árbol: " << alt << endl;
}