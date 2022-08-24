#include <map>
#include <iostream>
using namespace std;

string desencripta(string cad, const map<char, char> &codigo) {
	map<char, char>::const_iterator it = codigo.cbegin();
	bool encontrado = false;

	for (int i = 0; i < cad.size(); i++) {
		while (it != codigo.cend() && !encontrado) {
			if (cad[i] == (*it).second)
				encontrado = true;
			
			if (!encontrado)
				it++;
		}

		if (encontrado)
			encontrado = false;

		if (it != codigo.cend())
			cad[i] = (*it).first;

		it = codigo.cbegin();
	}

	return cad;
}

int main() {
	map<char, char> codigo;
	string cadena = "s2p3rc4l1fr4g1l1st1c03sp14l1d0s0";

	codigo.insert(pair<char, char>('a', '4'));
	codigo.insert(pair<char, char>('e', '3'));
	codigo.insert(pair<char, char>('i', '1'));
	codigo.insert(pair<char, char>('o', '0'));
	codigo.insert(pair<char, char>('u', '2'));

	cout << "CADENA ENCRIPTADA: ";
	cout << cadena << endl;
	cadena = desencripta(cadena, codigo);
	cout << "CADEBA DESENCRIPTADA: ";
	cout << cadena << endl;
}