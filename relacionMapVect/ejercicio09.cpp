#include <list>
#include <iostream>
using namespace std;

template <class T>
void inversa(list<T> &l) {
	typename list<T>::iterator it;
	int tam = l.size();
	int i = 0;

	for (it = l.begin(); it != l.end() && i != tam; it++) {
		l.emplace_front(*it);
		i++;
	}

	l.resize(tam);
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
	inversa(lista);
	cout << "LISTA INVERSA: ";
	leerLista(lista);
}