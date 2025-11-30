#ifndef _LISTA_H_
#define _LISTA_H_

#include <iostream>
#include <string>

using namespace std;

struct Nodo{

	float valore;
	Nodo* next;
	
} ;

class Lista{
	
	private:
	
		Nodo* p;
	    	int nelem;
    
 	public:
 
 	// COSTRUTTORI
 	
		Lista ();
		Lista (Lista&);
	
	// DISTRUTTORI
	
	    	~Lista ();
	    	
	// AGGIUNGI ELEMENTO
	
		int inserisci (float); //ritorna 0 se operazione OK -1 se operazione KO
		
	// RIMUOVI ELEMENTO
	
		int cancella  (float); //ritorna 0 se operazione OK -1 se operazione KO
		
	// METODO DI STAMPA
	
		void stampa ();
		
	// METODI DI COPIA
	
		void clone  (Lista&);
		int getsize (void);
		int dumptoarray(float*);
};
 
#endif
