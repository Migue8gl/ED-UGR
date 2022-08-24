#ifndef _DICCIONARIO_H
#define _DICCIONARIO_H

#include <iostream>
#include <list>
#include <string>
using namespace std;

/**
 * @brief Struct data
 * Compuesto por una clave y una lista de informacion asociada.
 */
template <typename T, typename U>
struct data{
    T clave; /**< dato clave */
    list <U> info_asoci; /**< infomacion asociada a la clave */
};


/**
 * @brief Sobrecarga del operador <, devuelve una relacion de
 * orden sobre las claves
 * @param d1 Clave a comparar
 * @param d2 Clave a comparar con la primera
 * @return true si d1 > d2 y false en caso contrario
 */
template <class T, class U>
bool operator< (const data<T, U> &d1, const data<T, U> &d2){
	if(d1.clave < d2.clave)
		return true;
	return false;
}

/**
 * @brief T.D.A Diccionario
 * 
 * Una instancia del tipo de Dato @c Diccionario es un objeto
 * con una lista de datos, los cuales se descomponen en una clave
 * y una serie de definiciones asociadas a ella.
 * 
 * @author Miguel Garcia Lopez
 * @date Diciembre 2020
 */
template <typename T, typename U>
class Diccionario{
private:

	/**
     * @page repConjunto Rep del TDA Diccionario
     *
     * @section invConjunto Invariante de la representacion
     * Un objeto valido de @e i del TDA Diccionario una clave 
	 * puede tener varias definiciones.
     *
     * @section faConjunto Funcion de abstraccion
     * Un objeto valido de @e i del TDA Diccionario representa un diccionario
     *
     */

	list<data<T, U>> datos; /**< lista de datos */

	/**
 	 * @brief Copia el diccionario que se pase por parametro al
	 * diccionario del que perteneza este metodo
 	 * @param Dicc Diccionario a copiar
 	 */
	void Copiar(const Diccionario<T,U>& Dicc){
      datos.assign(Dicc.datos.begin(),Dicc.datos.end());
    }

	/**
 	 * @brief Borra absolutamente todos los datos del diccionario
 	 */
    void Borrar(){
      this->datos.erase(datos.begin(),datos.end());
    }

public:
	
	/**
 	 * @brief Constructor por defecto. Crea un diccionario vacio
 	 */
    Diccionario():datos(list<data<T,U> >()){}
	
	/**
 	 * @brief Constructor por copia. Llama al metodo copiar
 	 * @param Dicc Diccionario a copiar
 	 */
    Diccionario(const Diccionario &Dicc){
      Copiar(Dicc);
    }
	
	/**
 	 * @brief Destructor por defecto
 	 */
    ~Diccionario(){}

	/**
 	 * @brief Sobrecarga del operador = 
 	 * @param Dicc Diccionario en la parte derecha de la asignacion
 	 */
	Diccionario<T, U> & operator=(const Diccionario<T, U> &Dicc) {
		if (this != &Dicc) {
			Borrar();
			Copiar(Dicc);
		}
		return *this;
	}
	
	/**
 	 * @brief Busca la clave pasada por parametro y devuelve si se
	 * encuentra o no en el diccionario
 	 * @param p Clave a buscar
	 * @param it_out iterador para movernos en el diccionario
	 * @return true si la clave existe, false en caso contrario
 	 */
	bool Esta_Clave(const T &p, typename  list<data<T, U> >::iterator &it_out) {
		bool is_clave = false;
		if (datos.size() > 0) {
			for (it_out = datos.begin(); it_out != datos.end(); it_out++) {
				if ((*it_out).clave == p){
					is_clave = true;
					break;
				}
			}
		}
		else 
			it_out = datos.end();
		
		return is_clave;
	}
	
	/**
 	 * @brief Inserta definiciones (pasadas por parametro) asociadas
	 * a la clave (pasada por parametro), la cual se inserta tambien
 	 * @param clave Clave asociada a la informacion
	 * @param info Informacion a insertar
 	 */
	void Insertar(const T& clave, const list<U> &info) {
		typename list<data<T, U> >::iterator it;
		if (!Esta_Clave(clave, it)) {
			data<T, U> p;
			p.clave = clave;
			p.info_asoci = info;
			datos.insert(it, p);
		}
	}
	
	/**
 	 * @brief Asocia una definicion a una clave, si esta existe
 	 * @param s Definicion a insertar
	 * @param p Clave asociada a la definicion
 	 */
    void AddSignificado_Palabra(const U & s, const T &p){
		typename list<data<T, U> >::iterator it;
		if (Esta_Clave(p , it)) {
			(*it).info_asoci.insert((*it).info_asoci.end(), s);
		}
		else
			cout << "La clave no existe" << endl;
	}

	/**
 	 * @brief Si existe la clave pasada, nos devuelve toda la 
	 * informacion que se asocie a ella
 	 * @param p Clave asociada a una informacion
	 * @return Devuelve la informacion asociada a la clave
 	 */
    list<U> getInfo_Asoc(const T & p) {
		typename list<data<T, U> >::iterator it;
		if (!Esta_Clave(p, it)) {
			return list<U>();
		}
		else {
			return (*it).info_asoci;
		}
	}

	/**
 	 * @brief Borra un numero de definiciones asociadas a una clave
	 * igual numero especificado por parametro
 	 * @param p Clave de la que se borrara informacion
	 * @param num_def Numero de definiciones a borrar
 	 */
	void borrarDefiniciones(const T & p, unsigned num_def) {
		typename list<data<T,U> >::iterator iter;
	    if(Esta_Clave(p,iter)){
			
			if(num_def > (*iter).info_asoci.size())
				num_def = (*iter).info_asoci.size();

			for (unsigned i = 0; i < num_def; i++)
 	   			(*iter).info_asoci.pop_back();
		}
		else
			cout << "La clave no existe" << endl;
	}

	/**
 	 * @brief Muestra por pantallla la clave a la que esta asociada la definicion
	 * dada por parametro
 	 * @param s Definicion asociada a una clave
 	 */
	void getClavePorDefinicion(const U & s) {
		typename list<data<T,U> >::iterator i;
		typename list<U>::iterator j;
		T clav;
		bool is_clave = false;

		for(i = datos.begin(); i != datos.end() && !is_clave; i++){
			for(j = (*i).info_asoci.begin(); j != (*i).info_asoci.end() && !is_clave; j++){
				if((*j) == s){
					clav = (*i).clave;
					is_clave = true;
				}
			}
		}
		
		if(!is_clave)
			cout << "clave no encontrada" << endl;
		else
			cout << clav << endl;
	}
	
	/**
 	 * @brief Muestra por pantalla el diccionario en su totalidad, muestra
	 * cada clave y cada definicion asociada a ella
 	 */
	void getAll() {
		typename list<data<T,U> >::iterator i;
	    typename list<U>::iterator j;
		int cont = 1;

		for(i = datos.begin(); i != datos.end(); i++){
			cout << (*i).clave << endl;

			for(j = (*i).info_asoci.begin(); j != (*i).info_asoci.end(); j++){
				cout << cont << " - "<< (*j) << endl;
				cont++;
			}
			cont = 1;
			cout << "----------------" << endl;
		}
	}

	/**
 	 * @brief Devuelve el tamaño del diccionario (Numero de claves)
 	 */
    inline int size()const{return datos.size();}

	/**
 	 * @brief Iterador de la clase Diccionario
 	 */
	class iterator{
	private:
		typename list<data<T, U>>::iterator it; /**< Iterador de lista */

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
	 	 * @brief Sobrecarga del operador ++
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
		struct data<T, U> &operator *(){
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

		friend class Diccionario;
	};

	/**
 	 * @brief Iterador constante de la clase Diccionario
 	 */
	class const_iterator{
	private:
		typename list<data<T, U>>::const_iterator it; /**< Iterador constante de lista */

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
		const struct data<T, U> &operator *(){
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

		friend class Diccionario;
		friend class iterator;
	};

	/**
 	 * @brief Devuelve un iterador que apunta al primer dato del diccionario
 	 * @return posicion inicial del diccionario
 	 */
 	iterator begin() {
		iterator iter;
		iter.it = datos.begin();
		return iter;
	}

	/**
 	 * @brief Devuelve un iterador que apunta al siguiente del ultimo 
	 * dato del diccionario
 	 * @return posicion final del diccionario
 	 */
	iterator end() {
		iterator iter;
		iter.it = datos.end();
		return iter;
	}
	
	/**
 	 * @brief Devuelve un iterador constante que apunta al primer dato del diccionario 
 	 * @return posicion inicial del diccionario
 	 */
	const_iterator cbegin() const{
		const_iterator iter;
		iter.it = datos.cbegin();
		return iter;
	}

	/**
 	 * @brief Devuelve un iterador constante que apunta al siguiente del ultimo 
	 * dato del diccionario
 	 * @return posicion final del diccionario
 	 */
	const_iterator cend() const{
		const_iterator iter;
		iter.it = datos.cend();
		return iter;
	}

};

#endif /* DICCIONARIO_H */

