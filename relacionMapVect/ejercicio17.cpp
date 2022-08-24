#include <list>
#include <iostream>
using namespace std;

template <class T>
class vector_dinamico {
private:
	list<T> lista;

public:

	class iterator {
	private:
		typename list<T>::iterator it;

	public:
		iterator(): it(0) {}
		~iterator() {}
		iterator & operator++() {
			it++;
			return *this;
		}
		iterator operator++(int) {
			it++;
			return *this;
		}
		T & operator*() {
			return *it;
		}
		bool operator ==(const iterator &i) {
			return i.it == it;
		}
		bool operator !=(const iterator &i) {
			return i.it != it;
		}
		void operator =(const iterator &i) {
			it = i.it;
		}

		friend class vector_dinamico;
	};

	vector_dinamico() {}

	iterator insert(iterator it, const T &x) {
		iterator iter;
		iter.it = lista.insert(it.it, x);
		return iter;
	}

	iterator erase(iterator it) {
		iterator iter;
		iter.it = lista.erase(it);
		return iter;
	}

	iterator erase(int i) {
		iterator iter;
		iter.it = lista.end();
		int cont = 0;

		if (i >= 0 && i <= lista.size()) {
			do {
				cont++;
				++iter;
			} while (iter.it != lista.end() && cont <= i);
			iter.it = lista.erase(iter.it);
		}
		return iter;
	}

	void push_back(const T &x) {
		lista.push_back(x);
	}

	T& operator[](int i) {
		typename list<T>::iterator it = lista.begin();
		int cont = 0;

		if (i >= 0 && i <= lista.size()) {
			while (it != lista.end() && cont != i) {
				cont++;
				it++;
			}
		}
		return (*it);
	}

	int size() const {
		return lista.size();
	}

	iterator begin() {
		iterator iter;
		iter.it = lista.begin();
		return iter;
	}

	iterator end() {
		iterator iter;
		iter.it = lista.end();
		return iter;
	}
};

template <class T>
void leerVector(vector_dinamico<T> &vd) {
	typename vector_dinamico<T>::iterator it;

	for (it = vd.begin(); it != vd.end(); it++) {
		cout << "<" << (*it) << ">";;
	}
	cout << endl;
}

int main() {
	vector_dinamico<int> vd;
	vector_dinamico<int>::iterator it;

	vd.push_back(12);
	vd.push_back(6);
	vd.push_back(1);
	vd.push_back(2);
	vd.push_back(0);
	it = vd.begin();
	vd.insert(it, 777);

	cout << "VECTOR: ";
	leerVector(vd);
	cout << "TAMAÑO: " << vd.size();

	vd.erase(2);
	vd.erase(0);
	cout << "\nVECTOR: ";
	leerVector(vd);

	cout << "Elemento [2]: " << vd[2] << endl;
	cout << "Elemento [0]: " << vd[0] << endl;
}

