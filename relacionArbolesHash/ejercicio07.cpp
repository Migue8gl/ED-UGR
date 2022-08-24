#include "bintree.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
bool completo(const bintree<T> &arb) {
	typename bintree<T>::node aux = arb.root();
	queue<typename bintree<T>::node> cola;
	bool L = false, R = false, fin = false, completo = false;

	if (arb.empty())
		return true;

	while (!aux.null() && !fin) {

		if (!aux.left().null())
			cola.push(aux.left());
		else {
			L = true;
			fin = true;
		}

		if (!aux.right().null())
			cola.push(aux.right());
		else {
			R = true;
			fin = true;
			if (L)
				completo = true;
		}

		aux = cola.front();
		cola.pop();
	}

	return completo;
}

bintree<int> crear_arbol() {
	bintree<int> A(7);
	bintree<int>::node n;

	A.insert_left(A.root(), 1);
	A.insert_right(A.root(), 9);
	n = A.root().left();
	A.insert_left(n, 6);
	A.insert_right(n, 8);

	n = A.root().right();
	A.insert_left(n, 5);
	A.insert_right(n, 4);

	return A;
}

int main() {
	bintree<int> arbol = crear_arbol();

	if (completo(arbol))
		cout << "El árbol está completo" << endl;
	else
		cout << "El árbol no está completo" << endl;
}