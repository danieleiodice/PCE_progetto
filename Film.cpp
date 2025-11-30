#include "Film.h"

// COSTRUTTORI

Film::Film() {
	
	nome = "";
	genere = "";
	orario = 0,00;

}

Film::Film(string Nome, string Genere, float Orario) {
	
	this -> nome = Nome;
	this -> genere = Genere;
	this -> orario = Orario;
	
}

// SETTER

void Film::setNome(string Nome) {
	
	this -> nome = Nome;
	
}

void Film::setGenere(string Genere) {
	
	this -> genere = Genere;
	
}

void Film::setOrario(float Orario) {
	
	this -> orario = Orario;
	
}

// GETTER

string Film::getNome() {

	return nome;
	
}

string Film::getGenere() {
	
	return genere;
	
}

float Film::getOrario() {
	
	return orario;
	
}

// STAMPA

void Film::print() {

	cout << endl << "--- FILM ---" << endl;
	
		cout << "Nome film = " << nome << endl << "Genere film = " << genere << endl << "Orario film = " << orario << endl;

}









