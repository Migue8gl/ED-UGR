#ifndef __PUNTO_H
#define __PUNTO_H
#include <iostream>
using namespace std;

struct Point {
	double latitud;
	double longitud;
};

class Punto{
  private:
	Point p;
    
  public:
   	Punto();
   
	Punto(double lat, double lon);

   	Punto(double lat, double lon, string s);
   
   	Punto(const Punto & P);
   
   	Punto & operator=(const Punto & P);

	void setPunto(double lat, double lon);

	double GetLatitud() const;

	double GetLongitud() const;
	
	bool operator==(const Punto & P) const;

	bool operator<(const Punto & P) const;

	bool operator>(const Punto & P) const;

	friend istream & operator>>(istream & is, Punto & P);

	friend ostream & operator<<(ostream & os, const Punto & P);
};   
   
#endif
