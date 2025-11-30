#include "Biglietto.h"

using namespace std;

Biglietto::Biglietto() {

	prezzoBiglietto = 0.0;
	
}

Biglietto::Biglietto(string nome, string genere, float orario, float prezzoBiglietto) : Film(nome, genere, orario) {

	this -> prezzoBiglietto = prezzoBiglietto;
	
}

void Biglietto::setPrezzoBiglietto(float prezzoBiglietto) {

	this -> prezzoBiglietto = prezzoBiglietto;
	
}

float Biglietto::getPrezzoBiglietto() {

	return prezzoBiglietto;
	
}

void Biglietto::print() {

	Film::print();
	
	cout << endl << "Costo Biglietto = " << prezzoBiglietto << " $" <<endl;
	
}
