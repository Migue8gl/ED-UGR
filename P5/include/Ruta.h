#ifndef __RUTA_H
#define __RUTA_H
#include <iostream>
#include "Punto.h"
#include <list>
using namespace std;

class Ruta{
  private:
	string codigo;
	list<Punto> puntos;
    
  public:
	class iterator {
		private:
			list<Punto>::iterator p;

		public:
			iterator();

			iterator & operator ++();
		
			iterator & operator --();

			iterator & operator=(const iterator & it);

			bool operator ==(const iterator  & it);

			bool operator !=(const iterator  & it);

			const Punto & operator*() const;

			friend class Ruta;
			friend class const_iterator;
	};

	class const_iterator {
		private:
			list<Punto>::const_iterator p;

		public:
			const_iterator();

			const_iterator & operator ++();
		
			const_iterator & operator --();

			const_iterator & operator=(const const_iterator & it);

			bool operator ==(const const_iterator  & it);

			bool operator !=(const const_iterator  & it);

			const Punto & operator*() const;

			friend class Ruta;
	};

	iterator begin();

	iterator end();

	const_iterator cbegin() const;

	const_iterator cend() const;

	iterator find(const Punto &P);

	void Insertar(const Punto &P);

    void Borrar(const Punto &P);

   	Ruta();
   
   	Ruta(string c, list<Punto> p);
   
   	Ruta(const Ruta & R);
   
   	Ruta & operator=(const Ruta & R);

	bool operator==(const Ruta & R) const;

	void SetRuta(string c, list<Punto> p);

	string GetCodigo() const;

	list<Punto> GetPuntos() const;

	friend istream & operator>>(istream & is, Ruta & R);

	friend ostream & operator<<(ostream & os, const Ruta & R);
};   
   
#endif
