#include <list>
#include <iostream>
using namespace std;

template <class T>
typename list<T>::const_iterator contenida(const list<T> &l1, const list<T> &l2) {
	typename list<T>::const_iterator i;
	typename list<T>::const_iterator aux;
	typename list<T>::const_iterator j = l1.cbegin();
	int cont = 0;
	bool contenida = false;

	if (l1.empty()) {
		aux = l2.cbegin();
		contenida = true;
	}
	for (i = l2.cbegin(); i != l2.cend() && !contenida; i++) {
		if ((*j) == (*i)) {
			j++;
			if (cont == 0) {
				aux = i;
			}

			cont++;
			if (cont == l1.size()) {
				contenida = true;
				break;
			}
		}
		else if (cont != 0) {
			j = l1.cbegin();
			cont = 0;
			i--;
		}
	}

	if (!contenida)
		aux = l2.cend();

	return aux;
}

template <class T>
void leerLista(const list<T> &l) {
	typename list<T>::const_iterator it;

	for (it = l.cbegin(); it != l.cend(); it++) {
		cout << "<" << (*it) << ">";
	}
	cout << endl;
}

int main() {
	list<int> lista1 = {4, 5, 6, 7};
	list<int> lista2 = {4, 5, 6, 4, 1, 5, 6, 8, 4, 5, 6, 7};
	list<int>::const_iterator it, it2;

	cout << "LISTA1: ";
	leerLista(lista1);

	cout << "LISTA2: ";
	leerLista(lista2);

	it = contenida(lista1, lista2);

	int cont = 0;

	for (it2 = lista2.cbegin(); it2 != lista2.cend() && it != it2; it2++)
		cont++;

	if (it == lista2.end())
		cout << "La lista1 no esta contenida en lista2" << endl;
	else {
		cout << "La lista1 esta contenida en lista2" << endl;
		cout << "A partir de posicion -> " << cont << endl;
	}
}