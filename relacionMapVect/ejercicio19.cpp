#include <list>
#include <iostream>
#include <map>
using namespace std;

struct piloto {
	string nombre;
	string apellidos;
	string escuderia;
	int puntos;
};

class pilotos {
private:
	map<string, piloto> map_nomb;
	map<string, piloto> map_apell;
	multimap<int, piloto, greater<int>> map_pos;
	multimap<string, piloto> map_escuderia;

public:

	class iterator {
	private:
		multimap<int, piloto, greater<int>>::iterator p;

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
		piloto & operator*() {
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

		friend class pilotos;
	};

	iterator begin() {
		iterator iter;
		iter.p = map_pos.begin();
		return iter;
	}

	iterator end() {
		iterator iter;
		iter.p = map_pos.end();
		return iter;
	}

	pilotos() {}

	piloto buscar_apellidos(string apellidos) const {
		map<string, piloto>::const_iterator it;

		it = map_apell.find(apellidos);

		if (it == map_apell.cend()) {
			piloto p;
			return p;
		}

		return (*it).second;
	}

	piloto buscar_nombre(string nombre) const {
		map<string, piloto>::const_iterator it;

		it = map_nomb.find(nombre);

		if (it == map_nomb.cend()) {
			piloto p;
			return p;
		}

		return (*it).second;
	}

	list<piloto> buscar_escuderia(string escuderia) const {
		map<string, piloto>::const_iterator it;
		pair<multimap<string, piloto>::const_iterator, multimap<string, piloto>::const_iterator> all_keys;
		list<piloto> grupo_escuderia;

		all_keys = map_escuderia.equal_range(escuderia);

		if (all_keys.first != all_keys.second) {
			for (it = all_keys.first; it != all_keys.second; it++) {
				grupo_escuderia.push_back((*it).second);
			}
		}

		return grupo_escuderia;
	}

	piloto posicion(int num) const {
		map<int, piloto>::const_iterator it = map_pos.cbegin();
		num -= 1;
		int i = 0;

		if (num <= map_pos.size()) {
			while (it != map_pos.cend() && i < num) {
				i++;
				it++;
			}
		}
		else {
			piloto p;
			return p;
		}

		return (*it).second;
	}

	void borrar_piloto(const piloto &p) {
		map<string, piloto>::const_iterator it;
		map<int, piloto>::const_iterator it2;
		pair<multimap<string, piloto>::const_iterator, multimap<string, piloto>::const_iterator> keys;
		pair<multimap<int, piloto>::const_iterator, multimap<int, piloto>::const_iterator> keys2;

		map_nomb.erase(p.nombre);
		map_apell.erase(p.apellidos);
		keys = map_escuderia.equal_range(p.escuderia);
		keys2 = map_pos.equal_range(p.puntos);

		bool borrado = false;

		if (keys.first != keys.second) {
			for (it = keys.first; it != keys.second && !borrado; it++) {
				if ((*it).second.nombre == p.nombre) {
					it = map_escuderia.erase(it);
					borrado = true;
				}
			}
		}

		borrado = false;

		if (keys2.first != keys2.second) {
			for (it2 = keys2.first; it2 != keys2.second && !borrado; it++) {
				if ((*it2).second.nombre == p.nombre) {
					it2 = map_pos.erase(it2);
					borrado = true;
				}
			}
		}
	}

	void insertar_piloto(const piloto &p) {
		map_nomb.insert(pair<string, piloto>(p.nombre, p));
		map_apell.insert(pair<string, piloto>(p.apellidos, p));
		map_escuderia.insert(pair<string, piloto>(p.escuderia, p));
		map_pos.insert(pair<int, piloto>(p.puntos, p));
	}

	void cambiar_puntuacion(string apellidos, string nombre, int puntos) {
		string escuderia = buscar_apellidos(apellidos).escuderia;
		piloto p = {nombre, apellidos, escuderia, puntos};
		piloto p2 = {nombre, apellidos, escuderia, buscar_nombre(nombre).puntos};

		borrar_piloto(p2);
		insertar_piloto(p);
	}
};

int main() {
	piloto p1 = {"Juan", "Garcia", "Ferrari", 120};
	piloto p2 = {"Miguel", "Fernandez", "McLaren", 12};
	piloto p3 = {"Antonio", "Lopez", "RedBull", 320};
	piloto p4 = {"Pedro", "Herrero", "RedBull", 110};

	pilotos P;
	P.insertar_piloto(p1);
	P.insertar_piloto(p2);
	P.insertar_piloto(p3);
	P.insertar_piloto(p4);

	cout << P.buscar_apellidos("Lopez").nombre << endl;
	cout << P.buscar_nombre("Miguel").escuderia << endl;

	list<piloto> miembros_escuderias = P.buscar_escuderia("RedBull");
	list<piloto>::iterator it;

	cout << "\nRedBull: " << endl;
	for (it = miembros_escuderias.begin(); it != miembros_escuderias.end(); it++)
		cout << (*it).nombre << endl;

	cout << "\nPrimera posicion --> " << P.posicion(1).nombre << endl;
	cout << "Segunda posicion --> " << P.posicion(2).nombre << endl;
	cout << "Tercera posicion --> " << P.posicion(3).nombre << endl;

	cout << endl;

	pilotos::iterator iter = P.begin();
	int i = 1;

	while (iter != P.end()) {
		cout << i << "- " << (*iter).nombre << endl;
		i++;
		++iter;
	}

	cout << "\nPuntuacion Antonio -> " << P.buscar_nombre("Antonio").puntos;
	P.cambiar_puntuacion("Lopez", "Antonio", 600);
	cout << "\nPuntuacion modificada Antonio -> " << P.buscar_nombre("Antonio").puntos << endl;
}