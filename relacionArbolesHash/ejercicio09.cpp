#include "bintree.h"
#include <iostream>
using namespace std;

template <typename T>
bool similares(const bintree<T> &arb1, const bintree<T> &arb2) {
	bintree<T> a1_left, a1_right, a2_left, a2_right;

	if (arb1.empty() && arb2.empty())
		return true;

	if (arb1.empty() || arb2.empty())
		return false;

	a1_left.assign_subtree(arb1, arb1.root().left());
	a2_left.assign_subtree(arb2, arb2.root().left());
	
	a1_right.assign_subtree(arb1, arb1.root().right());
	a2_right.assign_subtree(arb2, arb2.root().right());

	if (!arb1.empty() && !arb2.empty())
		return (similares(a1_left, a2_left) && similares(a1_right, a2_right));
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

bintree<int> crear_arbol2() {
	bintree<int> A(1);
	bintree<int>::node n;

	A.insert_left(A.root(), 2);
	A.insert_right(A.root(), 9);
	n = A.root().left();
	A.insert_left(n, 5);
	A.insert_right(n, 6);

	n = A.root().right();
	A.insert_left(n, 3);
	

	return A;
}

int main() {
	bintree<int> arbol = crear_arbol();
	bintree<int> arbol2 = crear_arbol2();

	if (similares(arbol, arbol2))
		cout << "Los árboles son similares" << endl;
	else
		cout << "Los árboles no son similares" << endl;
}