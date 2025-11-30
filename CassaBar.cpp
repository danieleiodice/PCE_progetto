// COSTRUTTORI

#include "CassaBar.h"

CassaBar::CassaBar() {
	
	lista = new ProdottoBar*[0];
	
}

CassaBar::CassaBar(const CassaBar& cb) {
	
	dim = cb.dim;
	lista = new ProdottoBar*[dim];
		for(int i=0; i<dim; i++) {
	
			lista[i] = new ProdottoBar(*cb.lista[i]);
			
		}
}

// DISTRUTTORE PER DEALLOCARE LISTA FILM

CassaBar::~CassaBar() {
	
	delete [] lista;
	
}

// AGGIUNGI FILM AL TABELLONE (PER MANAGER)

void CassaBar::addProdotto(ProdottoBar* pb) {
	
	ProdottoBar** tmp = new ProdottoBar*[dim+1];
	for(int i=0; i<dim; i++) {
		tmp[i]=lista[i];
	}
	tmp[dim]=pb;
	dim++;
	lista = tmp;
}	

// STAMPA

void CassaBar::printCassa() {

	int count = 0;
	
	for (int i=0; i<dim; i++) {
		cout << i+1 <<  ")";
		
		lista[i]->printProdottoBar();
		
		count = 1;
	}
	
	if(count == 0) {
		
		cout << endl <<  "--- LISTA PRODOTTI VUOTA ---" << endl;
		
	}
}


void CassaBar::removeProdotto(string ricerca) {	
	bool trovato = false;
	int i=0;
	int count = 0;
	
	while(!trovato && i<dim) {
		if(lista[i]->getNomeProdottoBar() == ricerca) {
		
		cout << endl << "--- PRODOTTO RIMOSSO CORRETTAMENTE ---" << endl;
			trovato = true;
			ProdottoBar** tmp = new ProdottoBar*[dim-1];
			for(int j=0; j<dim; j++) {
				if(j<i)
					tmp[j] = lista[j];
				else if(j>=i)	
					tmp[j] = lista[j+1];
			}
			count = 1;
			lista = tmp;
			dim--;
		} else
			i++;
	}
	
	if(count == 0) {
		
		cout << endl <<  "--- PRODOTTO NON TROVATO ---" << endl;
		
	}
}

ProdottoBar* CassaBar::getLista(int n) {	
	
	ProdottoBar** tmp = new ProdottoBar*[dim];
	
	for(int i=0; i<dim; i++) {	
		 tmp[i] = lista[i];
	}
	
	return tmp[n-1];
}



