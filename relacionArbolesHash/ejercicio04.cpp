#include "bintree.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
void reflexion(bintree<T> &arb) {
	typename bintree<T>::node aux;
	queue<typename bintree<T>::node> cola;
	bintree<T> aux_tree, aux_tree2;

	if (!arb.empty()) {

		aux = arb.root();

		while (!aux.null()) {

			arb.prune_left(aux, aux_tree);
			arb.prune_right(aux, aux_tree2);
			arb.insert_left(aux, aux_tree2);
			arb.insert_right(aux, aux_tree);

			if (!aux.left().null())
				cola.push(aux.left());

			if (!aux.right().null())
				cola.push(aux.right());

			aux = cola.front();
			cola.pop();

		}
	}
}

template <typename T>
void preorden_binario(const bintree<T>& A, typename bintree<T>::node v) {
	if (!v.null()) {
		cout << *v << " ";
		preorden_binario(A, v.left());
		preorden_binario(A, v.right());
	}
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
	bintree<int> aux_tree, aux_tree2;
	bintree<int>::node aux = arbol.root();

	cout << "ÁRBOL BINARIO: ";
	preorden_binario(arbol, arbol.root());
	reflexion(arbol);
	cout << "\nÁRBOL BINARIO (REFLEXIÓN): ";
	preorden_binario(arbol, arbol.root());

	cout << endl;
}