#include <list>
#include <iostream>
using namespace std;

template <class T>
list<pair<T, int>> comprimir(const list<T> &l) {
	list<pair<T, int>> l_comprimida;
	typename list<T>::const_iterator it = l.cbegin();
	int cont = 1;
	T item;

	while (it != l.cend()) {
		item = (*it);
		it++;

		if ((*it) == item)
			cont++;
		else {
			l_comprimida.push_back(make_pair(item, cont));
			cont = 1;
		}
	}

	return l_comprimida;
}

template <class T>
list<T> descomprimir(const list<pair<T, int> > &lc) {
	list<T> l_descomprimida;
	typename list<pair<T, int>>::const_iterator it = lc.cbegin();

	while (it != lc.cend()) {
		for (int i = 0; i < (*it).second; i++)
			l_descomprimida.push_back((*it).first);
		it++;
	}

	return l_descomprimida;
}

template <class T>
void leerLista(const list<T> &l) {
	typename list<T>::const_iterator it;

	for (it = l.cbegin(); it != l.cend(); it++) {
		cout << "<" << (*it) << ">";
	}
	cout << endl;
}

template <class T>
void leerListaComprimida(const list<pair<T, int>> &l) {
	typename list<pair<T, int>>::const_iterator it;

	for (it = l.cbegin(); it != l.cend(); it++) {
		cout << "<" << (*it).first << "," << (*it).second << ">";
	}
	cout << endl;
}

int main() {
	list<int> l1 = {1, 1, 1, 2, 2, 2, 2, 2, 2, 7, 7, 7, 7, 7, 12, 1, 1, 5, 5};
	list<pair<int, int>> l2;

	cout << "LISTA: ";
	leerLista(l1);

	l2 = comprimir(l1);
	cout << "LISTA COMPRIMIDA: ";
	leerListaComprimida(l2);

	l1 = descomprimir(l2);
	cout << "LISTA DESCOMPRIMIDA: ";
	leerLista(l1);
}