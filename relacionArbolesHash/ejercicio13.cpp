#include "bintree.h"
#include <iostream>
#include <queue>
using namespace std;

template <typename T>
double densidad(const bintree<T> &arb) {
	queue<pair<typename bintree<T>::node, int> >nodos;
	pair<typename bintree<T>::node, int> n;
	double sum_prof = 0;
	double altura = 0;
	double densidad = -1;

	if (arb.empty())
		return densidad;

	n = make_pair(arb.root(), 0);

	if (!n.first.null()) {
		nodos.push(n);
		while (!nodos.empty()) {

			n = nodos.front();
			nodos.pop();

			if (n.first.left().null() && n.first.right().null())
				sum_prof += n.second;

			if (!n.first.left().null())
				nodos.push(make_pair(n.first.left(), n.second + 1));

			if (!n.first.right().null())
				nodos.push(make_pair(n.first.right(), n.second + 1));

			if (n.second > altura)
				altura = n.second;
		}

		densidad = sum_prof / altura;

		cout << sum_prof << " " << altura << endl;
	}

	return densidad;
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
	double den = densidad(arbol);

	if (den > 0)
		cout << "La densidad del árbol es: " << den << endl;
}