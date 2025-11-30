#ifndef _FILM_H_
#define _FILM_H_

#include <iostream>
#include <string>

using namespace std;

class Film {
	
	private:
		
		string nome;
		string genere;
		float orario;
		
	public:
	
	// COSTRUTTORI
	
		Film();
		Film(string,string,float);
		
	// SETTER
	
		void setNome(string);
		void setGenere(string);
		void setOrario(float);
		
	// GETTER
	
		string getGenere();
		string getNome();
		float getOrario();
		
	// STAMPA
	
		virtual void print() = 0;
		
};

#endif
		
