#include <list>
#include <iostream>
using namespace std;

template <class T>
list<T> mezclar(const list<T> &l1, const list<T> &l2) {
	typename list<T>::const_iterator i1 = l1.cbegin();
	typename list<T>::const_iterator i2 = l2.cbegin();
	list<T> mixed_list;

	while (i1 != l1.cend() && i2 != l2.cend()) {
		if ((*i1) <= (*i2)) {
			mixed_list.push_back((*i1));
			i1++;
		}
		else {
			mixed_list.push_back((*i2));
			i2++;
		}
	}

	while (i1 != l1.end()) {
		mixed_list.push_back((*i1));
		i1++;
	}

	while (i2 != l2.end()) {
		mixed_list.push_back((*i2));
		i2++;
	}
	return mixed_list;
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
	list<int> lista2 = {1, 2, 3, 4, 5, 8, 10};
	list<int> lista1 = {5, 6, 7, 8, 12, 12, 20};

	cout << "LISTA1: ";
	leerLista(lista1);
	cout << "LISTA2: ";
	leerLista(lista2);
	list<int> lista3 = mezclar(lista1, lista2);
	cout << "LISTA MEZCLADA: ";
	leerLista(lista3);
}