#include <iostream>
#include <queue>
using namespace std;

struct persona {
	string nombre;
	string apellido;
	int prioridad;
};

class miComp {
public:
	bool operator()(const persona &a, const persona &b) {
		bool comp = true;
		if (a.prioridad > b.prioridad)
			comp = false;

		return comp;
	}
};

int main() {
	priority_queue<persona, vector<persona>, miComp> cp;
	persona p;

	for (int i = 0; i < 5; i++) {
		cout << "Introduzca nombre: ";
		cin >> p.nombre;
		cout << "Introduzca 1er apellido: ";
		cin >> p.apellido;
		cout << "-Introduzca prioridad: ";
		cin >> p.prioridad;
		cout << endl;
		cp.push(p);
	}

	cout << "Personas ordenadas --> ";
	while (!cp.empty()) {
		cout << "<" << cp.top().nombre << " " << cp.top().apellido <<"> ";
		cp.pop();
	}

	cout << endl;
}