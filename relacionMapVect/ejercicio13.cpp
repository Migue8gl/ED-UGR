#include <list>
#include <iostream>
using namespace std;

template <class T>
list<T> lista_posiciones(const list<T> &l, const list< typename list<T>::iterator> &li) {
	list<T> aux;
	typename list<typename list<T>::iterator>::const_iterator it;

	for (it = li.cbegin(); it != li.cend(); it++) {
		aux.push_back(*(*it));
	}

	return aux;
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
	list<int> lista = {4, 5, 6, 7, 2, 2, 3, 1};
	list<list<int>::iterator> lista_it;
	list<int>::iterator it = lista.begin();
	int pos = 0;

	cout << "LISTA: ";
	leerLista(lista);

	do {
		cout << "Add posicion a lista de iteradores -> ";
		cin >> pos;

		if (pos != -1 && lista_it.size() < lista.size()) {
			for (int i = 0; i < pos; i++)
				it++;

			lista_it.push_back(it);
			it = lista.begin();
		}
	} while (pos != -1 && lista_it.size() < lista.size());

	cout << "LISTA_POSICIONES: ";
	leerLista(lista_posiciones(lista, lista_it));
}