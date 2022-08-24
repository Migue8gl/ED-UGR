#include "Ruta.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
	if (argc != 2) {
		cout << "Los parametros son: " << endl;
		cout << "1.-Fichero con la información de una ruta" << endl;
		return 0;
	}

	ifstream f (argv[1]);
	Ruta r1, r2;
	f >> r1;

	cout << r1 << endl;

	r2 = r1;

	Punto p(34.838378732, -2.23232345);
	r2.Insertar(p);

	cout << endl << r2 << endl;

}
