#include <iostream>
#include <map>
using namespace std;

struct paciente {
	string nombre;
	string apellidos;
	string dni;
	int gravedad;
};

class urgencias {
private:
	map<string, paciente> map_apell;
	map<string, paciente> map_dni;
	map<pair<string, string>, paciente> map_pacientes;
	multimap<int, paciente, greater<int>> map_graved;

public:
	class iterator {
	private:
		multimap<string, paciente, less<string>>::const_iterator p;

	public:
		iterator(): p(0) {}
		~iterator() {}
		iterator & operator++() {
			p++;
			return *this;
		}
		iterator & operator--() {
			p--;
			return *this;
		}
		iterator operator++(int) {
			p++;
			return *this;
		}
		iterator operator--(int) {
			p--;
			return *this;
		}
		paciente operator*() const {
			return (*p).second;
		}
		bool operator ==(const iterator &i) {
			return i.p == p;
		}
		bool operator !=(const iterator &i) {
			return i.p != p;
		}
		void operator =(const iterator &i) {
			p = i.p;
		}

		friend class urgencias;
	};

	urgencias() {}

	void insertar_paciente(const paciente &p) {
		map_apell.insert(pair<string, paciente>(p.apellidos, p));
		map_graved.insert(pair<int, paciente>(p.gravedad, p));
		map_dni.insert(pair<string, paciente>(p.dni, p));
		map_pacientes.insert(pair<pair<string, string>, paciente>(make_pair(p.nombre, p.apellidos), p));
	}

	void borrar_paciente(const paciente &p) {
		pair<multimap<int, paciente>::const_iterator, multimap<int, paciente>::const_iterator> keys;
		multimap<int, paciente>::const_iterator it;

		map_apell.erase(p.apellidos);
		map_dni.erase(p.dni);
		map_pacientes.erase(make_pair(p.nombre, p.apellidos));
		keys = map_graved.equal_range(p.gravedad);

		bool borrado = false;

		if (keys.first != keys.second) {
			for (it = keys.first; it != keys.second && !borrado; it++) {
				if ((*it).second.nombre == p.nombre) {
					it = map_graved.erase(it);
					borrado = true;
				}
			}
		}
	}

	paciente mas_grave() {
		map<int, paciente>::iterator it = map_graved.begin();

		if (map_graved.empty()) {
			paciente p;
			return p;
		}

		it = map_graved.begin();
		paciente p = (*it).second;
		borrar_paciente(p);

		return (*it).second;
	}

	paciente buscar_paciente(string nombre, string apellidos) const {
		map<pair<string, string>, paciente>::const_iterator it;

		it = map_pacientes.find(make_pair(nombre, apellidos));

		if (it == map_pacientes.cend()) {
			paciente p;
			return p;
		}

		return (*it).second;
	}

	int size() const {
		return map_apell.size();
	}

	iterator begin() const {
		iterator iter;
		iter.p = map_apell.cbegin();
		return iter;
	}

	iterator end() const {
		iterator iter;
		iter.p = map_apell.cend();
		return iter;
	}
};

int main() {
	paciente p1 = {"Miguel", "Garcia", "77149865E", 10};
	paciente p2 = {"Alfonso", "Gonzales", "77649765P", 12};
	paciente p3 = {"Roberto", "Herrero", "76749865Z", 13};
	paciente p4 = {"Lucia", "Bellido", "77009555I", 5};

	urgencias U;
	U.insertar_paciente(p1);
	U.insertar_paciente(p2);
	U.insertar_paciente(p3);
	U.insertar_paciente(p4);

	urgencias::iterator it = U.begin();
	int i = 1;

	while (it != U.end()) {
		cout << i << "- " << (*it).nombre << " " << (*it).apellidos << endl;
		i++;
		it++;
	}

	cout << U.buscar_paciente("Miguel", "Garcia").dni << endl;
	cout << U.size() << endl;
	cout << U.mas_grave().nombre << endl;
	cout << U.size() << endl;

	it = U.begin();
	i = 1;

	while (it != U.end()) {
		cout << i << "- " << (*it).nombre << " " << (*it).apellidos << endl;
		i++;
		it++;
	}
}