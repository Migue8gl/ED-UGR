#include <list>
#include <iostream>
#include <vector>
using namespace std;

template <class T>
void elimina(list<T> &l, const vector<T> &v) {
	typename list<T>::iterator j = l.begin();
	typename vector<T>::const_iterator i;

	for (i = v.cbegin(); i != v.cend(); i++) {
		do {
			if ((*i) == (*j))
				j = l.erase(j);
			else
				j++;
		} while (j != l.end());
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
	list<int> lista = {2, 1, 1, 1, 1, 5, 3, 6};
	vector<int> vector = {1, 6};

	cout << "LISTA: ";
	leerLista(lista);
	elimina(lista, vector);
	cout << "LISTA MODIFICADA: ";
	leerLista(lista);
}