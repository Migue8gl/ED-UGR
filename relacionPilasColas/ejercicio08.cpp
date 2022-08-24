#include <stack>
#include <queue>
#include <iostream>
using namespace std;

bool palindromo(string cadena) {
	queue<char> Cola;
	stack<char> Pila;
	bool palindromo = true;

	for (int i = 0; i < cadena.size(); i++) {
		if (cadena[i] != ' ') {
			if(cadena[i] >= 65 && cadena[i] <= 90)
				cadena[i] += 32;

			Cola.push(cadena[i]);
			Pila.push(cadena[i]);
		}
	}

	while (!Pila.empty() && palindromo != false) {
		if (Pila.top() != Cola.front())
			palindromo = false;

		Pila.pop();
		Cola.pop();
	}

	return palindromo;
}

int main() {
	string frase;

	cout << "Introduzca frase o palabra (palindromo): ";

	cin.clear();
	getline(cin, frase);

	if (palindromo(frase))
		cout << "La frase/palabra " << frase << " es un palindromo";
	else
		cout << "La frase/palabra " << frase << " no es un palindromo";

	cout << endl;
}