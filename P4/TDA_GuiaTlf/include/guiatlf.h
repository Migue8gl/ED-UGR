

#ifndef _GUIA_TLF_H
#define _GUIA_TLF_H

#include <map>
#include <iostream>
#include <string>
using namespace std;

/**
 * @brief Sobrecarga del operador >> para la lectura de datos de la Guia
 * @param is Flujo de entrada
 * @param d Datos compuestos por un nombre y un telefono
 */
istream & operator>>(istream &is, pair<string, string> &d) {
	getline(is, d.first, '\t');
	getline(is, d.second);
	return is;
}

/**
 * @brief T.D.A Guia Telefonica
 * 
 * Una instancia del tipo de Dato @c GuiaTlf es un objeto
 * con un contenedor de elementos formados por un nombre y un numero de telefono.
 * 
 * @author Miguel Garcia Lopez
 * @date Diciembre 2020
 */
class Guia_Tlf {
private:

	/**
     * @page repConjunto Rep del TDA Guia Telefonica
     *
     * @section invConjunto Invariante de la representacion
     * Un objeto valido de @e i del TDA GuiaTlf debe cumplir
	 * que ningun nombre puede estar repetido, solo existe una clave unica
     *
     * @section faConjunto Funcion de abstraccion
     * Un objeto valido de @e i del TDA GuiaTlf representa una Guia Telefonica
     *
     */

	map<string, string> datos; /**< diccionario de elementos (nombre, telefono) */
	
	/**
 	 * @brief Copia la GuiaTlf que se pase por parametro a la
	 * GuiaTlf del que perteneza este metodo
 	 * @param Guia Guia a copiar
 	 */
	void Copiar(const Guia_Tlf& Guia){
      datos = Guia.datos;
    }
	
	/**
 	 * @brief Borra absolutamente todos los datos de la Guia
 	 */
	void Borrar(){
      this->datos.erase(datos.begin(),datos.end());
    }

public:

	/**
 	 * @brief Constructor por defecto. Crea una Guia vacia
 	 */
	Guia_Tlf():datos(map<string, string>()){}

	/**
 	 * @brief Constructor por copia. Llama al metodo copiar
 	 * @param gt Guia a copiar
 	 */
	Guia_Tlf(const Guia_Tlf & gt){
		Copiar(gt);
	}

	/**
 	 * @brief Destructor por defecto
 	 */
	~Guia_Tlf() {}

	/**
 	 * @brief Sobrecarga del operador = 
 	 * @param gt Guia en la parte derecha de la asignacion
 	 */
	Guia_Tlf & operator=(const Guia_Tlf & gt) {
		if (this != &gt) {
			Borrar();
			Copiar(gt);
		}
		return *this;
	}

	/**
	 * @brief Acceso a un elemento
	 * @param nombre: nombre del elemento  elemento acceder
	 * @return devuelve el valor asociado a un nombre, es decir el telefono
	 */
	string & operator[](const string &nombre) {
		return datos[nombre];
	}

	/**
	 * @brief Devuelve el telefono asocidao a ese nombre
	 * @param nombre: nombre asociado al telefono
	 * @return devuelve el valor asociado a un nombre, es decir el telefono
	 */
	string getTelefono(const string & nombre) {
		map<string, string>::iterator it = datos.find(nombre);
		if (it == datos.end())
			return string("");
		else return it->second;
	}

	/**
	 * @brief Insert un nuevo telefono
	 * @param nombre: nombre clave del nuevo telefono
	 * @param tlf: numero de telefono
	 * @return : un pair donde first apunta al nuevo elemento insertado y 
	 * bool es true si se ha insertado el nuevo tlf o false en caso contrario
	 */
	pair<map<string, string>::iterator, bool>  insert(string nombre, string tlf) {
		pair<string, string> p (nombre, tlf);
		pair< map<string, string> ::iterator, bool> ret;
		ret = datos.insert(p);
		return ret;
	}

	/**
	 * @brief Insert un nuevo telefono
	 * @param p: pair con el nombre y el telefono asociado
	 * @return : un pair donde first apunta al nuevo elemento insertado y 
	 * bool es true si se ha insertado el nuevo tlf o false en caso contrario
	 */
	pair<map<string, string>::iterator, bool>  insert(pair<string, string> p) {
		pair<map<string, string> ::iterator, bool> ret;
		ret = datos.insert(p);
		return ret;
	}

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar
	 * @note: en caso de que fuese un multimap borraria todos con ese nombre
	 */
	void borrar(const string &nombre) {
		map<string, string>::iterator itlow = datos.lower_bound(nombre);
		map<string, string>::iterator itupper = datos.upper_bound(nombre);
		datos.erase(itlow, itupper);
	}

	/**
	 * @brief Borrar un telefono
	 * @param nombre: nombre que se quiere borrar y telefono asociado
	 * @note: esta funcion nos permite borrar solamente aquel que coincida en nombre y tlf
	 */
	void borrar(const string &nombre, const string &tlf) {
		map<string, string>::iterator itlow = datos.lower_bound(nombre); 
		map<string, string>::iterator itupper = datos.upper_bound(nombre); 
		map<string, string>::iterator it;
		bool salir = false;
		for (it = itlow; it != itupper && !salir; ++it) {
			if (it->second == tlf) {
				datos.erase(it);
				salir = true;
			}
		}
	}

	/**
	 * @brief  Numero de telefonos
	 * @return el numero de telefonos asociados
	 */
	int size()const {
		return datos.size();
	}
	/**
	 * @brief Contabiliza cuantos telefonos tenemos asociados a un nombre
	 * @param nombre: nombre sobre el que queremos consultar
	 * @return numero de telefonos asociados a un nombre
	 */
	unsigned int contabiliza(const string &nombre) {
		return datos.count(nombre);
	}

	/**
	 * @brief Limpia la guia
	 */
	void clear() {
		datos.clear();
	}

	/**
	 * @brief Union de guias de telefonos
	 * @param g: guia que se une
	 + @return: una nueva guia resultado de unir el objeto al que apunta this y g
	*/
	Guia_Tlf operator+(const Guia_Tlf & g) {
		Guia_Tlf aux(*this);
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it) {
			aux.insert(it->first, it->second);
		}
		return aux;

	}

	/**
	 * @brief Diferencia de guias de telefonos
	 * @param g: guia que se une
	 * @return: una nueva guia resultado de la diferencia del objeto al que apunta this y g
	*/
	Guia_Tlf operator-(const Guia_Tlf & g) {
		Guia_Tlf aux(*this);
		map<string, string>::const_iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it) {
			aux.borrar(it->first, it->second);
		}
		return aux;

	}

	/**
	 * @brief Escritura de la guia de telefonos
	 * @param os: flujo de salida. Es MODIFICADO
	 * @param g: guia de telefonos que se escribe
	 * @return el flujo de salida
	 */
	friend ostream & operator<<(ostream & os, Guia_Tlf & g) {
		map<string, string>::iterator it;
		for (it = g.datos.begin(); it != g.datos.end(); ++it) {
			os << it->first << "\t" << it->second << endl;
		}
		return os;
	}

	/**
	 * @brief Lectura de  la guia de telefonos
	 * @param is: flujo de entrada. ES MODIFICADO
	 * @param g: guia de telefonos. ES MODIFICADO
	 * @return el flujo de entrada
	*/
	friend istream & operator>>(istream & is, Guia_Tlf & g) {
		pair<string, string> p;
		Guia_Tlf aux;

		while (is >> p) {
			aux.insert(p);
		}
		g = aux;
		return is;
	}

	/**
 	 * @brief Muestra por pantalla la Guia en su totalidad, muestra
	 * cada nombre y cada numero asociado
 	 */
	void getAll() {
		map<string, string>::iterator i;
		for(i = datos.begin(); i != datos.end(); i++){
			cout << i->first << " - " << i->second << endl;
			cout << "--------------------" << endl;
		}
	}

	/**
	 * @brief Devuelve el nombre asocidao a ese telefono
	 * @param telefono: telefono asociado al nombre
	 * @return devuelve el valor asociado a un telefono, es decir el nombre
	 */
	string getNombre(const string & telefono) {
		map<string, string>::iterator it;

		for(it = datos.begin(); it != datos.end(); it++){
			if(it->second == telefono)
				break;
		}

		if (it == datos.end())
			return string("");
		else return it->first;
	}

	/**
	 * @brief Edita el nombre del contacto que se le pase por parametro
	 * @param nombre nombre del contacto
	 * @param new_nomb nuevo nombre para el contacto
	 */
	void editarContacto(const string & nombre, const string & new_nomb) {
		map<string, string>::iterator it = datos.find(nombre);
		datos.insert(it, pair<string, string>(new_nomb, it->second));
		datos.erase(it--);
	}

	/**
 	 * @brief Iterador de la clase Guia
 	 */
	class iterator{
	private:
		map<string,string>::iterator it; /**< Iterador de diccionario */

	public:

		/**
	 	 * @brief Constructor por defecto de la clase iteradora
	 	 */
		iterator():it(0){}
		
		/**
	 	 * @brief Destructor por defecto de la clase iteradora
	 	 */
		~iterator(){}

		/**
	 	 * @brief Sobrecarga del operador ++
		 * @return this
	 	 */
		iterator & operator++(){
			it++;
			return *this;
		}

		/**
	 	 * @brief Sobrecarga del operador --
		 * @return this
	 	 */
		iterator & operator--(){
	  		it--;
			return *this;
		}
		
		/**
	 	 * @brief Sobrecarga del operador *
		 * @return objeto al que apunta this
	 	 */
		pair<const string, string> &operator *(){
			return *it;
		}

		/**
	 	 * @brief Sobrecarga del operador ==
		 * @param i iterador a comparar
		 * @return true si son iguales, false si no
	 	 */
		bool operator ==(const iterator &i){
			return i.it == it;
		}	  
		 
		/**
	 	 * @brief Sobrecarga del operador !=
		 * @param i iterador a comparar
		 * @return true si son distintos, false si no
	 	 */  
      	bool operator !=(const iterator &i){
			return i.it != it;
		}

		friend class Guia_Tlf;
	};

	/**
 	 * @brief Iterador constante de la clase Guia
 	 */
	class const_iterator{
	private:
		map<string,string>::const_iterator it; /**< Iterador constante de diccionario */

	public:
		
		/**
	 	 * @brief Constructor por defecto de la clase iteradora constante
	 	 */
		const_iterator():it(0){}
		
		/**
	 	 * @brief Destructor por defecto de la clase iteradora constante
	 	 */
		~const_iterator(){}

		/**
	 	 * @brief Sobrecarga del operador ++
		 * @return this
	 	 */
		const_iterator & operator++(){
			it++;
			return *this;
		}
	
		/**
	 	 * @brief Sobrecarga del operador --
		 * @return this
	 	 */
		const_iterator & operator--(){
	  		it--;
			return *this;
		}

		/**
	 	 * @brief Sobrecarga del operador *
		 * @return objeto al que apunta this
	 	 */
		const pair<const string, string> &operator *(){
			return *it;
		}

		/**
	 	 * @brief Sobrecarga del operador ==
		 * @param i iterador a comparar
		 * @return true si son iguales, false si no
	 	 */
		bool operator ==(const const_iterator &i){
			return i.it == it;
		}	  
		       
		/**
	 	 * @brief Sobrecarga del operador !=
		 * @param i iterador a comparar
		 * @return true si son distintos, false si no
	 	 */
      	bool operator !=(const const_iterator &i){
			return i.it != it;
		}

		friend class Guia_Tlf;
		friend class iterator;
	};

	/**
 	 * @brief Devuelve un iterador que apunta al primer dato de la Guia
 	 * @return posicion inicial de la Guia
 	 */
 	iterator begin() {
		iterator iter;
		iter.it = datos.begin();
		return iter;
	}

	/**
 	 * @brief Devuelve un iterador que apunta al siguiente del ultimo 
	 * dato de la Guia
 	 * @return posicion final de la Guia
 	 */
	iterator end() {
		iterator iter;
		iter.it = datos.end();
		return iter;
	}
	
	/**
 	 * @brief Devuelve un iterador constante que apunta al primer dato de la Guia 
 	 * @return posicion inicial de la Guia
 	 */
	const_iterator cbegin() const{
		const_iterator iter;
		iter.it = datos.cbegin();
		return iter;
	}

	/**
 	 * @brief Devuelve un iterador constante que apunta al siguiente del ultimo 
	 * dato de la Guia
 	 * @return posicion final de la Guia
 	 */
	const_iterator cend() const{
		const_iterator iter;
		iter.it = datos.cend();
		return iter;
	}
};

#endif

