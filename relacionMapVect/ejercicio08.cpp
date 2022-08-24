#include <list>
#include <iostream>
using namespace std;

template <class T>
list<T> inversa(const list<T> &l) {
	list<T> aux;
	typename list<T>::const_iterator it;

	for (it = l.cbegin(); it != l.cend(); ++it)
		aux.emplace_front(*it);

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
	list<int> lista;
	int n, item;

	cout << "Introduzca n: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Introduzca item[" << i + 1 << "] -> ";
		cin >> item;
		lista.push_back(item);
	}

	cout << "LISTA: ";
	leerLista(lista);
	cout << "LISTA INVERSA: ";
	leerLista(inversa(lista));
}