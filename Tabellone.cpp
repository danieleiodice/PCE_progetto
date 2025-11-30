#include "Tabellone.h"


// COSTRUTTORI

Tabellone::Tabellone() {
	
	lista = new Biglietto*[0];
	
}

Tabellone::Tabellone(const Tabellone& t) {
	
	dim = t.dim;
	lista = new Biglietto*[dim];
		for(int i=0; i<dim; i++) {
	
			lista[i] = new Biglietto(*t.lista[i]);
			
		}
}

// DISTRUTTORE PER DEALLOCARE LISTA FILM

Tabellone::~Tabellone() {
	
	delete [] lista;
	
}

// AGGIUNGI FILM AL TABELLONE (PER MANAGER)

void Tabellone::addBiglietto(Biglietto* f) {
	
	Biglietto** tmp = new Biglietto*[dim+1];
	for(int i=0; i<dim; i++) {
		tmp[i]=lista[i];
	}
	tmp[dim]=f;
	dim++;
	lista = tmp;
}	

// REMOVE FILM

void Tabellone::removeFilm(string ricerca) {	
	bool trovato = false;
	int i=0;
	int count = 0;
	while(!trovato && i<dim) {
		if(lista[i]->getNome() == ricerca) {
		
		cout << endl << "--- FILM RIMOSSO CORRETTAMENTE ---" << endl;
			trovato = true;
			Biglietto** tmp = new Biglietto*[dim-1];
			for(int j=0; j<dim; j++) {
				if(j<i)
					tmp[j] = lista[j];
				else if(j>=i)	
					tmp[j] = lista[j+1];
			}
			lista = tmp;
			dim--;
			count = 1;
			
		} else
			i++;
	}
	
	if(count == 0) {
		
		cout << endl <<  "--- FILM NON TROVATO ---" << endl;
		
	}
}

// STAMPA

void Tabellone::print() {
	
	int count = 0;
	
	for (int i=0; i<dim; i++) {
		cout << i+1 <<  ")";
		lista[i]->print();
		
		count = 1;
	}
	
	if(count == 0) {
		
		cout <<  "--- LISTA FILM VUOTA ---" << endl;
		
	}
}

// GETTER

Biglietto* Tabellone::getBiglietto(int n) {	
	
	Biglietto** tmp = new Biglietto*[dim];
	
	for(int i=0; i<dim; i++) {	
		 tmp[i] = lista[i];
	}
	
	return tmp[n-1];
}














