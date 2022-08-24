#include <list>
#include <iostream>
using namespace std;

template <class T>
void inserta_despues(list<T> &l, int x) {
	typename list<T>::iterator it;

	for (it = l.begin(); it != l.end(); it++) {
		if ((*it) == x) {
			it++;
			it = l.insert(it, x - 1);
		}
	}
}

template <class T>
void leerLista(const list<T> &l) {
	typename list<T>::const_iterator it;

	for (it = l.cbegin(); it != l.cend(); it++) {
		cout << "<" << (*it) << ">";;
	}
	cout << endl;
}

int main() {
	list<int> lista = {2, 1, 2, 2, 4, 5, 2, 3, 5, 2, 2, 8};
	int x = 2;

	cout << "LISTA: ";
	leerLista(lista);
	inserta_despues(lista, x);
	cout << "LISTA MODIFICADA: ";
	leerLista(lista);
}