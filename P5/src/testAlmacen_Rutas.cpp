#include "almacen_rutas.h"
#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char * argv[]) {
	if (argc != 2) {
		cout << "Los parametros son: " << endl;
		cout << "1.-Fichero con la información del almacen de rutas" << endl;
		return 0;
	}

	ifstream f (argv[1]);
	Almacen_Rutas ar1, ar2;
	f >> ar1;

	cout << ar1 << endl;

	ar2 = ar1;

	cout << ar2.GetRuta("R5") << endl << endl;

	Almacen_Rutas ar3 = ar1.GetRutas_Con_Punto(Punto(58.695433501291085, -96));

	cout << ar3 << endl;

}
