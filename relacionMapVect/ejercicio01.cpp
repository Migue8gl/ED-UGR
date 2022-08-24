#include <map>
#include <iostream>
using namespace std;

string encripta(string cad, const map<char, char> &codigo) {
	map<char, char>::const_iterator it;
	for (int i = 0; i < cad.size(); i++) {
		it = codigo.find(cad[i]);

		if (it != codigo.cend())
			cad[i] = (*it).second;
	}

	return cad;
}

int main() {
	map<char, char> codigo;
	string cadena = "supercalifragilisticoespialidoso";

	codigo.insert(pair<char, char>('a', '4'));
	codigo.insert(pair<char, char>('e', '3'));
	codigo.insert(pair<char, char>('i', '1'));
	codigo.insert(pair<char, char>('o', '0'));
	codigo.insert(pair<char, char>('u', '2'));

	cout << "CADENA: ";
	cout << cadena << endl;
	cadena = encripta(cadena, codigo);
	cout << "CADEBA ENCRIPTADA: ";
	cout << cadena << endl;
}