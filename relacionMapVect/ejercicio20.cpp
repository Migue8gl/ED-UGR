#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<pair<pair<float, float>, int> > contar(const vector< pair<float, float> > &v) {
	vector< pair<float, float>>::const_iterator it = v.cbegin();
	vector<pair<pair<float, float>, int>> num_coor;
	map<pair<float, float>, int> coordenadas;
	map<pair<float, float>, int>::iterator it2;

	while (it != v.cend()) {
		coordenadas[(*it)]++;
		it++;
	}

	for (it2 = coordenadas.begin(); it2 != coordenadas.end(); it2++) {
		num_coor.push_back(make_pair((*it2).first, (*it2).second ));
	}

	return num_coor;
}

void leerCoordenadas(const vector< pair<float, float> > &vd) {
	vector< pair<float, float> >::const_iterator it;

	for (it = vd.cbegin(); it != vd.cend(); it++) {
		cout << "<" << (*it).first << "," << (*it).second << ">";
	}
	cout << endl;
}

void leerConteoCoordenadas(const vector< pair <pair<float, float>, int > > &vd) {
	vector< pair <pair<float, float>, int > >::const_iterator it;

	for (it = vd.cbegin(); it != vd.cend(); it++) {
		cout << "<" << (*it).first.first << "," << (*it).first.second << ">";
		cout << " | Veces: " << (*it).second << endl;
	}
	cout << endl;
}

int main() {
	vector< pair<float, float> > coordenadas = {make_pair(1, 2), make_pair(1, 2),
	                                            make_pair(1, 2), make_pair(1, 2),
	                                            make_pair(1, 3), make_pair(1, 3),
	                                            make_pair(2, 4), make_pair(5, 6)
	                                           };
	cout << "COORDENADAS: ";
	leerCoordenadas(coordenadas);
	cout << "CONTEO DE COORDENADAS: \n";
	leerConteoCoordenadas(contar(coordenadas));
}