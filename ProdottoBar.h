#ifndef _PRODOTTOBAR_H_
#define _PRODOTTOBAR_H_

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

#include "Lista.h"

class ProdottoBar {
	
	private:
		
		char* nomeProdottoBar;
		float prezzoProdottoBar;
		
	public:
		
		// COSTRUTTORE
		
		ProdottoBar(char*,float);
		ProdottoBar(const ProdottoBar&);
		
		// SETTER
		
		void setNomeProdottoBar(char*);
		void setPrezzoProdottoBar(float);
		
		// GETTER
			
		char* getNomeProdottoBar();
		float getPrezzoProdottoBar();
		
		// STAMPA
		
		void printProdottoBar();
		
		// OVERLOAD OPERATORI
		
		//bool operator == (ProdottoBar);
		
		// DISTRUTTORE
		
		~ProdottoBar();
		
};

#endif
		
