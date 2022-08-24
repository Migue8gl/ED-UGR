#include <iostream>
#include <map>
#include "almacen_rutas.h"
using namespace std;

Almacen_Rutas::iterator::iterator() {}

Almacen_Rutas::iterator & Almacen_Rutas::iterator::operator++() {
	++p;
	return *this;
}

Almacen_Rutas::iterator & Almacen_Rutas::iterator::operator--() {
	--p;
	return *this;
}

Almacen_Rutas::iterator & Almacen_Rutas::iterator::operator=(const iterator & it) {
	p = it.p;
	return *this;
}

bool Almacen_Rutas::iterator::operator==(const iterator & it) {
	return it.p == p;
}

bool Almacen_Rutas::iterator::operator!=(const iterator & it) {
	return it.p != p;
}

const Ruta & Almacen_Rutas::iterator::operator*() const {
	return (*p).second;
}

Almacen_Rutas::const_iterator::const_iterator() {}

Almacen_Rutas::const_iterator & Almacen_Rutas::const_iterator::operator++() {
	++p;
	return *this;
}

Almacen_Rutas::const_iterator & Almacen_Rutas::const_iterator::operator--() {
	--p;
	return *this;
}

Almacen_Rutas::const_iterator & Almacen_Rutas::const_iterator::operator=(const const_iterator & it) {
	p = it.p;
	return *this;
}

bool Almacen_Rutas::const_iterator::operator==(const const_iterator & it) {
	return it.p == p;
}

bool Almacen_Rutas::const_iterator::operator!=(const const_iterator & it) {
	return it.p != p;
}

const Ruta & Almacen_Rutas::const_iterator::operator*() const {
	return (*p).second;
}

Almacen_Rutas::iterator Almacen_Rutas::begin() {
	iterator it;
	it.p = rutas.begin();
	return it;
}

Almacen_Rutas::const_iterator Almacen_Rutas::cbegin()const {
	const_iterator it;
	it.p = rutas.cbegin();
	return it;
}
Almacen_Rutas::iterator Almacen_Rutas::end() {
	iterator it;
	it.p = rutas.end();
	return it;
}
Almacen_Rutas::const_iterator Almacen_Rutas::cend()const {
	const_iterator it;
	it.p = rutas.cend();
	return it;
}

Almacen_Rutas::iterator Almacen_Rutas::find(const Ruta & R) {
	iterator it;
	map<string, Ruta>::iterator i;
	for (i = rutas.begin(); i != rutas.end() && !((*i).second == R); ++i);
	it.p = i;
	return it;
}

void Almacen_Rutas::Insertar(const Ruta & R) {
	rutas.insert(pair<string, Ruta>(R.GetCodigo(), R));
}

void Almacen_Rutas::Borrar(const Ruta & R) {
	rutas.erase(R.GetCodigo());
}

Almacen_Rutas::Almacen_Rutas() {}

Almacen_Rutas::Almacen_Rutas(map<string, Ruta> R) {
	rutas = R;
}

Almacen_Rutas::Almacen_Rutas(const Almacen_Rutas & R) {
	SetRutas(R.GetRutas());
}

Almacen_Rutas & Almacen_Rutas::operator=(const Almacen_Rutas & R) {
	SetRutas(R.GetRutas());

	return *this;
}

void Almacen_Rutas::SetRutas(map<string, Ruta> R) {
	rutas = R;
}

map<string, Ruta> Almacen_Rutas::GetRutas() const {
	return rutas;
}

Ruta Almacen_Rutas::GetRuta(string cod) {
	map<string, Ruta>::const_iterator it;
	it = rutas.find(cod);

	return (*it).second;
}

Almacen_Rutas Almacen_Rutas::GetRutas_Con_Punto(const Punto & P) {
	Almacen_Rutas local;
	Almacen_Rutas::const_iterator it;
	Ruta::const_iterator it2;

	for (it = cbegin(); it != cend(); ++it) {
		for (it2 = (*it).cbegin(); it2 != (*it).cend(); ++it2) {
			if ((*it2) == P)
				local.Insertar((*it));
		}
	}

	return local;
}

istream & operator>>(istream & is, Almacen_Rutas & R) {
	Almacen_Rutas local;

	if (is.peek() == '#') {
		string a;
		getline(is, a);
	}

	Ruta rut;
	while (!is.eof()) {
		is >> rut;
		local.Insertar(rut);
	}
	R = local;
	return is;
}

ostream & operator<<(ostream & os, const Almacen_Rutas & R) {
	Almacen_Rutas::const_iterator it;

	for (it = R.cbegin(); it != R.cend(); ++it)
		os << (*it) << endl;

	return os;
}

