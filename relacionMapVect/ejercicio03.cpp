#include <map>
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

int main() {
	map<string, int> contador;
	string texto = "En muchas partes del cuerpo como son las manos, las orejas o los pies, están representados todos los órganos y partes del cuerpo. Incidiendo sobre estas zonas se pueden crear arcos reflejos que actúen directamente sobre cualquier órgano del cuerpo y que solucionen cualquier anomalía que exista.";

	contador = contar(texto);
	map<string, int>::iterator it;

	for (it = contador.begin(); it != contador.end(); it++)
		cout << "La palabra <" << (*it).first << "> aparece " << (*it).second << " veces\n";
}