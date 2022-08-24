#include <list>
#include <iostream>
using namespace std;

template <class T>
void elimina_duplicados(list<T> &l) {
	typename list<T>::iterator it = l.begin();

	for (it = l.begin(); it != l.end(); it++) {
		typename list<T>::iterator it2 = it;
		it2++;

		while (it2 != l.end()) {
			if ((*it2) == (*it))
				it2 = l.erase(it2);
			else
				it2++;
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
	list<int> lista = {2, 1, 1, 1, 5, 5, 6, 4, 2};

	cout << "LISTA: ";
	leerLista(lista);
	elimina_duplicados(lista);
	cout << "LISTA MODIFICADA: ";
	leerLista(lista);
}