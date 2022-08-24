#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string, int> contar(string texto) {
	map<string, int> conteo;
	string palabra = "";

	for (int i = 0; i < texto.size(); i++) {
		if (texto[i] != ' ' && texto[i] != ',' && texto[i] != '.')
			palabra += tolower(texto[i]);
		else {
			if (palabra != "")
				conteo[palabra]++;
			palabra = "";
		}
	}

	return conteo;
}

vector<string> veces(const map<string, int> &palabras, int num) {
	vector<string> veces;
	map<string, int>::const_iterator it;

	for (it = palabras.begin(); it != palabras.end(); it++) {
		if ((*it).second == num)
			veces.push_back((*it).first);
	}

	return veces;
}

int main() {
	map<string, int> contador;
	vector<string> pal_veces;
	vector<string>::iterator it;
	string texto = "En muchas partes del cuerpo como son las manos, las orejas o los pies, están representados todos los órganos y partes del cuerpo. Incidiendo sobre estas zonas se pueden crear arcos reflejos que actúen directamente sobre cualquier órgano del cuerpo y que solucionen cualquier anomalía que exista.";

	contador = contar(texto);
	pal_veces = veces(contador, 3);

	for (it = pal_veces.begin(); it != pal_veces.end(); it++)
		cout << "<" << (*it) << ">";

	cout << endl;

}