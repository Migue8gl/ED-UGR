#include <map>
#include <vector>
#include <iostream>
using namespace std;

map<string, string> params(string cad) {
	map<string, string> params;
	pair<string, string> opc_param("", "");
	int i = 0;

	while (i < cad.size()) {
		if (cad[i] == '-')
			opc_param.first = cad[i + 1];
		else if (cad[i + 1] != '-') {
			i++;
			string palabra;
			while (cad[i] != '-' && i <= cad.size()) {
				palabra += cad[i];
				i++;
			}
			i--;
			opc_param.second = palabra;
		}
		else
			opc_param.second = " ";
		i++;

		if (opc_param.first != "" && opc_param.second != "") {
			params.insert(opc_param);
			opc_param = make_pair("", "");
		}
	}

	return params;
}

int main(int argc, char** argv) {
	string sarg;
	map<string, string> parametros;

	for (int i = 1; i < argc;)
		sarg += argv[i++];

	parametros = params(sarg);

	map<string, string>::iterator it;

	for (it = parametros.begin(); it != parametros.end(); it++) {
		cout << "Opcion: -" << (*it).first;
		cout << " | Parámetro: " << (*it).second << endl;
	}
}