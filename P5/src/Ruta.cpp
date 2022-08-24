#include <iostream>
#include "Punto.h"
#include "Ruta.h"
using namespace std;

Ruta::iterator::iterator() {}

Ruta::iterator & Ruta::iterator::operator++() {
	++p;
	return *this;
}

Ruta::iterator & Ruta::iterator::operator--() {
	--p;
	return *this;
}

Ruta::iterator & Ruta::iterator::operator=(const iterator & it) {
	p = it.p;
	return *this;
}

bool Ruta::iterator::operator==(const iterator & it) {
	return it.p == p;
}

bool Ruta::iterator::operator!=(const iterator & it) {
	return it.p != p;
}

const Punto & Ruta::iterator::operator*() const {
	return (*p);
}

Ruta::const_iterator::const_iterator() {}

Ruta::const_iterator & Ruta::const_iterator::operator++() {
	++p;
	return *this;
}

Ruta::const_iterator & Ruta::const_iterator::operator--() {
	--p;
	return *this;
}

Ruta::const_iterator & Ruta::const_iterator::operator=(const const_iterator & it) {
	p = it.p;
	return *this;
}

bool Ruta::const_iterator::operator==(const const_iterator & it) {
	return it.p == p;
}

bool Ruta::const_iterator::operator!=(const const_iterator & it) {
	return it.p != p;
}

const Punto & Ruta::const_iterator::operator*() const {
	return (*p);
}

Ruta::iterator Ruta::begin() {
	iterator it;
	it.p = puntos.begin();
	return it;
}

Ruta::const_iterator Ruta::cbegin()const {
	const_iterator it;
	it.p = puntos.cbegin();
	return it;
}
Ruta::iterator Ruta::end() {
	iterator it;
	it.p = puntos.end();
	return it;
}
Ruta::const_iterator Ruta::cend()const {
	const_iterator it;
	it.p = puntos.cend();
	return it;
}

Ruta::iterator Ruta::find(const Punto & P) {
	iterator it;
	list<Punto>::iterator i;
	for (i = puntos.begin(); i != puntos.end() && !((*i) == P); ++i);
	it.p = i;
	return it;
}

void Ruta::Insertar(const Punto & P) {
	puntos.push_back(P);
}

void Ruta::Borrar(const Punto & P) {
	Ruta::const_iterator it = cbegin();

	while (it != cend()) {
		if ((*it) == P) {
			puntos.erase(it.p);
			break;
		}

		++it;
	}
}

Ruta::Ruta() {
	codigo = "";
}

Ruta::Ruta(string c, list<Punto> p) {
	codigo = c;
	puntos = p;
}

Ruta::Ruta(const Ruta & R) {
	SetRuta(R.GetCodigo(), R.GetPuntos());
}

Ruta & Ruta::operator=(const Ruta & R) {
	SetRuta(R.GetCodigo(), R.GetPuntos());

	return *this;
}

bool Ruta::operator==(const Ruta & R) const {
	bool not_equal = true;
	Ruta::const_iterator it, it2 = R.cbegin();

	if (R.GetCodigo() != GetCodigo())
		return false;

	for (it = cbegin(); it != cend() && not_equal; ++it) {
		if ((*it) == (*it2))
			not_equal = true;
		else
			not_equal = false;

		++it2;
	}

	return not_equal;
}

void Ruta::SetRuta(string c, list<Punto> p) {
	codigo = c;
	puntos = p;
}

string Ruta::GetCodigo() const {
	return codigo;
}

list<Punto> Ruta::GetPuntos() const {
	return puntos;
}

istream & operator>>(istream & is, Ruta & R) {
	Ruta local;
	string cod;
	int x;

	if (is.peek() == '#') {
		string a;
		getline(is, a);
	}

	is >> cod >> x;
	
	Punto p;
	for (int i = 0; i < x; i++) {
		is >> p;
		local.Insertar(p);
	}

	R.SetRuta(cod, local.GetPuntos());

	return is;
}

ostream & operator<<(ostream & os, const Ruta & R) {
	os << R.GetCodigo() << " " << R.GetPuntos().size() << " ";
	Ruta::const_iterator it;

	for (it = R.cbegin(); it != R.cend(); ++it)
		os << "(" << (*it) << ") ";

	return os;
}

