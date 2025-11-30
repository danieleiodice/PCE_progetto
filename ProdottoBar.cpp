#include "ProdottoBar.h"

// COSTRUTTORE

ProdottoBar::ProdottoBar(char* NomeProdottoBar, float PrezzoProdottoBar) {
	
	this -> prezzoProdottoBar = PrezzoProdottoBar;
	this -> nomeProdottoBar = new char [strlen(NomeProdottoBar) + 1];
	strcpy(nomeProdottoBar,NomeProdottoBar);
	
	
}

ProdottoBar::ProdottoBar(const ProdottoBar& pb) {
	
	nomeProdottoBar = pb.nomeProdottoBar;
	prezzoProdottoBar = pb.prezzoProdottoBar;
	
}

// SETTER

void ProdottoBar::setNomeProdottoBar(char* NomeProdottoBar) {
	
	delete [] nomeProdottoBar;
	this -> nomeProdottoBar = new char [strlen(NomeProdottoBar) + 1];
	strcpy(nomeProdottoBar,NomeProdottoBar);
	
}

void ProdottoBar::setPrezzoProdottoBar(float PrezzoProdottoBar) {
	
	this -> prezzoProdottoBar = PrezzoProdottoBar;
	
}

// GETTER

char* ProdottoBar::getNomeProdottoBar() {
	
	return nomeProdottoBar;
	
}

float ProdottoBar::getPrezzoProdottoBar() {
	
	return prezzoProdottoBar;
	
}

// STAMPA

void ProdottoBar::printProdottoBar() {
	
	cout << endl << "--- PRODOTTO BAR ---" << endl;
		cout << "Nome del prodotto bar = " << nomeProdottoBar << endl << "Prezzo del prodotto bar = "<< prezzoProdottoBar << " $";
		cout << endl;
		
}





// DISTRUTTORE

ProdottoBar::~ProdottoBar() {
	
	delete [] nomeProdottoBar;
	
}


// OVERLOAD OPERATORI

/*bool ProdottoBar::operator == (ProdottoBar tmp) {
	
	bool verifica;
		
	if (tmp.nomeProdottoBar == nomeProdottoBar && tmp.prezzoProdottoBar == prezzoProdottoBar) 
	
		verifica = true;
	
	else 
		verifica = false;
		
	return verifica;
}*/




