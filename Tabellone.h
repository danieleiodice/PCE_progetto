#ifndef _TABELLONE_H_
#define _TABELLONE_H_

#include <iostream>
#include <cstring>

using namespace std;

#include "Film.h"
#include "Biglietto.h"

class Tabellone {
	
	private:
	
		int dim = 0;
		Biglietto** lista;
		
	public:
		
	// COSTRUTTORI
	
		Tabellone();
		Tabellone(const Tabellone&);
		
	// AGGIUNGI FILM AL TABELLONE 
	
		//void addFilm(Film*);
		void addBiglietto(Biglietto*);
		
	//RIMUOVI FILM DAL TABELLONE 
	
		void removeFilm(string);
		
	// STAMPA TABELLONE
	
		virtual void print();
		
	// DISTRUTTORE PER DEALLOCARE LISTA FILM
	
		~Tabellone();
		
	// GETTER
	
		Biglietto* getBiglietto(int);
		
};

#endif
