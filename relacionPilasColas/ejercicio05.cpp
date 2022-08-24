#include <iostream>
#include <math.h>
#include <stack>
using namespace std;

float evalua(string expresion, pair<char, float>*variables, int num_variables) {
	float resultado = 0;
	stack<float> pila;

	for (int i = 0; i < expresion.size(); i++) {
		if ((expresion[i] <= 122 && expresion[i] >= 96) || (expresion[i] <= 90 && expresion[i] >= 65)) {
			for (int j = 0; j < num_variables; j++) {
				if (variables[j].first == expresion[i]) {
					pila.push(variables[j].second);
				}
			}
		}
		else if (expresion[i] == '*' || expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '/' || expresion[i] == '^') {
			int x2 = pila.top();
			pila.pop();
			int x1 = pila.top();
			pila.pop();

			switch (expresion[i]) {
			case '+':
				resultado =  x1 + x2;
				break;
			case '-':
				resultado = x1 - x2;
				break;
			case '*':
				resultado =  x1 * x2;
				break;
			case '/':
				resultado = x1 / x2;
				break;
			case '^':
				resultado = pow(x1, x2);
				break;
			}

			pila.push(resultado);
		}
	}

	return resultado;
}

int main() {
	pair<char, float> *variables;
	float num;
	int j = 0;
	string expresion;

	cout << "Introduce una expresion postfija --> ";
	cin >> expresion;

	for (int i = 0; i < expresion.size(); i++) {
		if ((expresion[i] <= 122 && expresion[i] >= 96) || (expresion[i] <= 90 && expresion[i] >= 65)) {
			variables = new pair<char, float>[j];
			j++;
		}
	}

	j = 0;

	cout << "Introduce los valores de las variables: " << endl;

	for (int i = 0; i < expresion.size(); i++) {
		if ((expresion[i] <= 122 && expresion[i] >= 96) || (expresion[i] <= 90 && expresion[i] >= 65)) {
			variables[j].first = expresion[i];
			cout << expresion[i] << " = ";
			cin >> num;
			variables[j].second = num;
			j++;
		}
	}

	cout << "RESULTADO DE LA EXPRESION (" << expresion << ") --> ";
	cout << evalua(expresion, variables, j) << endl;

	delete [] variables;
}