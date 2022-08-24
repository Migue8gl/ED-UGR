#include "Punto.h"
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

Punto::Punto() {
	setPunto(0, 0);
}

Punto::Punto(double lat, double lon) {
	setPunto(lat, lon);
}

Punto::Punto(double lat, double lon, string s) {
	setPunto(lat, lon);
}

Punto::Punto(const Punto & P) {
	setPunto(P.GetLatitud(), P.GetLongitud());
}

Punto & Punto::operator=(const Punto & P) {
	setPunto(P.GetLatitud(), P.GetLongitud());

	return  *this;
}

void Punto::setPunto(double lat, double lon) {
	p.latitud = lat;
	p.longitud = lon;
}

double Punto::GetLatitud() const {
	return p.latitud;
}

double Punto::GetLongitud() const {
	return p.longitud;
}

bool Punto::operator==(const Punto & P) const {
	return (GetLongitud() == P.GetLongitud()) && (GetLatitud() == P.GetLatitud());
}

bool Punto::operator<(const Punto & P) const {
	double lon1 = GetLongitud(), lon2 = P.GetLongitud();
	double lat1 = GetLatitud(), lat2 = P.GetLatitud();
	bool menor = false;

	if (lon1 < 0)
		lon1 = -lon1;

	if (lon2 < 0)
		lon2 = -lon2;

	if (lon1 != lon2) {
		if (lon1 > lon2)
			menor = true;
	}
	else {
		if (lat1 < 0)
			lat1 = -lat1;

		if (lat2 < 0)
			lat2 = -lat2;

		if (lat1 > lat2)
			menor = true;
	}

	return menor;
}

bool Punto::operator>(const Punto & P) const {
	double lon1 = GetLongitud(), lon2 = P.GetLongitud();
	double lat1 = GetLatitud(), lat2 = P.GetLatitud();
	bool mayor = false;

	if (lon1 < 0)
		lon1 = -lon1;

	if (lon2 < 0)
		lon2 = -lon2;

	if (lon1 != lon2) {
		if (lon1 < lon2)
			mayor = true;
	}
	else {
		if (lat1 < 0)
			lat1 = -lat1;

		if (lat2 < 0)
			lat2 = -lat2;

		if (lat1 < lat2)
			mayor = true;
	}

	return mayor;
}

istream & operator>>(istream & is, Punto & P) {
	string lat, lon;

	while (is.peek() == ' ' || is.peek() == '(' || is.peek() == '	' || is.peek() == '\n')
		is.get();
	getline(is, lat, ',');
	getline(is, lon, ')');
	while (is.peek() == ' ' || is.peek() == '	' || is.peek() == '\n')
		is.get();

	double lat_d = atof(lat.c_str());
	double lon_d = atof(lon.c_str());

	Punto pto(lat_d, lon_d);
	P = pto;

	return is;
}

ostream & operator<<(ostream & os, const Punto & P) {
	os << P.GetLatitud() << ", " << P.GetLongitud();

	return os;
}