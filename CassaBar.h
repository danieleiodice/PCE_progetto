#ifndef _CASSABAR_H_
#define _CASSABAR_H_

#include <iostream>
#include <string>

using namespace std;

#include "ProdottoBar.h"

class CassaBar {
	
	private:
		
		ProdottoBar** lista;
		int dim = 0;
		
	public:
		
		
		// COSTRUTTORI
	
		CassaBar();
		CassaBar(const CassaBar&);
		
	// AGGIUNGI FILM AL TABELLONE 
	
		void addProdotto(ProdottoBar*);
		
	//RIMUOVI FILM DAL TABELLONE
	
		ProdottoBar* getLista(int);
		void removeProdotto(string);
		//Film** trovaFilm(string, int&);
		
	// STAMPA TABELLONE
	
		void printCassa();
		
	// DISTRUTTORE PER DEALLOCARE LISTA FILM
	
		~CassaBar();
		
};

#endif
	
