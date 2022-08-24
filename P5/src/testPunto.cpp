#include "Punto.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
	if(argc != 2) {
		cout << "Los parametros son: " << endl;
		cout << "1.-Fichero con la información de un punto" << endl;
		return 0;
	}

	ifstream f (argv[1]);
	Punto pto1;
	f >> pto1;
	cout << "El primer punto es: " << pto1 << endl;

	Punto pto2(17.24600332673307, -19.670602940234403);
	cout << "El segundo punto es: " << pto2 << endl;

	if(pto2 < pto1)
		cout << "El punto mayor es " << pto1 << endl;
	else
		cout << "El punto mayor es " << pto2 << endl;
}
