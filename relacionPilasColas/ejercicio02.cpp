#include <iostream>
#include <stack>
using namespace std;

bool parentizada(string expresion) {
	stack<char> Pila;

	for (int i = 0; i < expresion.size(); i++) {
		if (expresion[i] == '(')
			Pila.push(expresion[i]);
		else if (expresion[i] == ')') {
			if (Pila.empty())
				return false;

			if (Pila.top() == ')')
				return false;
			Pila.pop();
		}
	}

	return Pila.empty();
}

int main() {
	string expresion;

	cout << "Introduce una expresion de parentesis: ";
	cin >> expresion;

	if (parentizada(" "))
		cout << "Expresion correcta" << endl;
	else
		cout << "Expresion incorrecta" << endl;
}