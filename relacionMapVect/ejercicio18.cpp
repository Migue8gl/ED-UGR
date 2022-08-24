#include <vector>
#include <iostream>
using namespace std;

template <class T>
void intercalar(vector<T> &v, vector<pair<int, T> > pos) {
	typename vector<pair<int, T>>::iterator it;
	typename vector<T>::iterator it2 = v.begin();

	for (it = pos.begin(); it != pos.end(); it++) {
		int pos = (*it).first;
		T item = (*it).second;
		if (pos >= 0 && pos <= v.size()) {
			v.emplace(it2 + pos, item);
			it2 = v.begin();
		}
	}
}

template <class T>
void leerVector(const vector<T> &v) {
	typename vector<T>::const_iterator it;

	for (it = v.cbegin(); it != v.cend(); it++) {
		cout << "<" << (*it) << ">";;
	}
	cout << endl;
}


int main() {
	vector<int> vect1 = {1, 3, 7, 3};
	vector<pair<int, int>> vect2 = {make_pair(1, 5), make_pair(0, 7), make_pair(4, 12) };

	cout << "VECTOR: ";
	leerVector(vect1);
	intercalar(vect1, vect2);
	cout << "VECTOR MODIFICADO: ";
	leerVector(vect1);
}