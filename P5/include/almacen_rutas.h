#ifndef __ALMACEN_RUTAS_H
#define __ALMACEN_RUTAS_H
#include <iostream>
#include "Ruta.h"
#include <map>
using namespace std;

class Almacen_Rutas{
  private:
	map<string, Ruta> rutas;
    
  public:
	class iterator {
		private:
			map<string, Ruta>::iterator p;

		public:
			iterator();

			iterator & operator ++();
		
			iterator & operator --();

			iterator & operator=(const iterator & it);

			bool operator ==(const iterator  & it);

			bool operator !=(const iterator  & it);

			const Ruta & operator*() const;

			friend class Almacen_Rutas;
			friend class const_iterator;
	};

	class const_iterator {
		private:
			map<string, Ruta>::const_iterator p;

		public:
			const_iterator();

			const_iterator & operator ++();
		
			const_iterator & operator --();

			const_iterator & operator=(const const_iterator & it);

			bool operator ==(const const_iterator  & it);

			bool operator !=(const const_iterator  & it);

			const Ruta & operator*() const;

			friend class Almacen_Rutas;
	};

	iterator begin();

	iterator end();

	const_iterator cbegin() const;

	const_iterator cend() const;

	iterator find(const Ruta &R);

	void Insertar(const Ruta &R);

    void Borrar(const Ruta &R);

   	Almacen_Rutas();
   
   	Almacen_Rutas(map<string, Ruta> R);
   
   	Almacen_Rutas(const Almacen_Rutas & R);
   
   	Almacen_Rutas & operator=(const Almacen_Rutas & R);

	void SetRutas(map<string, Ruta> P);

	map<string, Ruta> GetRutas() const;

	Ruta GetRuta(string cod);

	Almacen_Rutas GetRutas_Con_Punto(const Punto & P);

	friend istream & operator>>(istream & is, Almacen_Rutas & R);

	friend ostream & operator<<(ostream & os, const Almacen_Rutas & R);
};   
   
#endif
