#include "bintree.h"
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
typename bintree<T>::node ancestro_comun(typename bintree<T>::node n1, typename bintree<T>::node n2) {
	typename bintree<T>::node nodo;
	vector<typename bintree<T>::node> ancestros;
	typename vector<typename bintree<T>::node>::const_iterator it;
	bool encontrado = false;

	if (n1.parent().null() || n2.parent().null() || n1.null() || n2.null())
		return nodo;

	if (n1 == n2)
		return n1.parent();

	while (!n1.parent().null()) {
		ancestros.push_back(n1.parent());
		n1 = n1.parent();
	}

	while (!n2.parent().null() && !encontrado) {
		it = ancestros.cbegin();

		if ((*it) == n2.parent()) {
			encontrado = true;
			nodo = n2.parent();
		}
		else
			n2 = n2.parent();

		it++;
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
	bintree<int>::node n1 = arbol.root();
	bintree<int>::node n2 = arbol.root().left();
	bintree<int>::node n3 = ancestro_comun<int>(n1, n2);

	cout << "Ancestro común de " << *n1 << " y de " << *n2 << " es -> ";
	cout << *n3 << endl;
}