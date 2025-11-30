#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

#include "Film.h"
#include "Tabellone.h"
#include "ProdottoBar.h"
#include "Lista.h"
#include "CassaBar.h"
#include "Biglietto.h"

struct Progetto {
    string titoloProgetto;
    string corsoDiStudi;
    int annoProgetto;
};

int main() {

// DATI PER LETTURA E SCRITTURA FILE

    ofstream fo;
    ifstream fi;
    int n = sizeof(Progetto);
    string decorazione;

    const int numProgetto = 1;

    Progetto P[numProgetto];
    P[0].titoloProgetto = "PROGETTO PCE";
    P[0].corsoDiStudi = "IBeT";
    P[0].annoProgetto = 2023;
    
// SCRITTURA FILE
 
    fo.open("myFile.txt", ios::out);
    fo.write(reinterpret_cast <const char*> (&P), n); 
    for(int i = 0; i < numProgetto; i++) {
        fo << setw(40) << setfill(' ') << right << P[i].titoloProgetto << setw(20) << setfill(' ') << right << "CdS: " << P[i].corsoDiStudi << setw(10) << setfill(' ') << right << "A.A.: " << P[i].annoProgetto << endl;
    }
    fo.close();
    
// LETTURA FILE
   
    fi.open("myFile.txt", ios::in);
    fi.read(reinterpret_cast <char*> (&P), n);
    cout.width(80); cout.fill('*'); cout << decorazione << endl;
    for(int i = 0; i < numProgetto; i++) {
        cout << setw(40) << setfill(' ') << right << P[i].titoloProgetto << setw(20) << setfill(' ') << right << "CdS: " << P[i].corsoDiStudi << setw(10) << setfill(' ') << right << "A.A.: " << P[i].annoProgetto << endl;
    }
    cout.width(80); cout.fill('-'); cout << decorazione << endl;
   
   
// DATI PER FILM

Tabellone tabellone;

string nomeFilm, genereFilm;
float Orario;
float prezzoFilm;
string ricercaFilm;

Biglietto* biglietto;

// DATI PER SCELTA RUOLO

char sceltaRuolo;
char sceltaBiglietti;
int ciclo1 = 0;
int ciclo2,ciclo3,ciclo4;
char sceltaBar;
char sceltaCassa;
int numero;

// DATI PER BAR

CassaBar cb;
ProdottoBar* prodottoBar;

char nomeProdottoBar[100];
float prezzoProdottoBar;
char ricercaProdottoBar[100];
string ricercaCast;
float prezzoTmp;

// LISTA DINAMICA

Lista lista;



// MAIN 
	
	do {
	
	cout << endl << " --- SCEGLI IL RUOLO --- " << endl;
	cout << "[1] FORNITORE BIGLIETTI " << endl;
	cout << "[2] FORNITORE BAR " << endl;
	cout << "[3] ADDETTO ALLA CASSA " << endl;
	cout << "[0] ESCI " << endl;
	
	cout << endl << "SCELTA = ";
		cin >> sceltaRuolo;
		
	switch(sceltaRuolo) {
		
		case '1' : 
		
			ciclo2 = 0;
			
			do {
			
			cout << endl << "			-----------------------		" <<endl;
			cout << "			| FORNITORE BIGLIETTI |			" <<endl;
			cout << "			-----------------------			" <<endl;
			cout << endl << "--- SCEGLIERE UNA DELLE SEGUENTI OPZIONI ---" << endl;
				
			cout << endl << "[1]	creare biglietto per un film" << endl;	
			cout << "[2]	vedere biglietti dei film" << endl;	
			cout << "[3]	rimuovere biglietto per un film" << endl;
			cout << "[4]	cambiare ruolo" << endl;
			cout << "[0]	esci" << endl;	
			cout << endl << "SCELTA: ";
				cin >> sceltaBiglietti;
				
				switch(sceltaBiglietti) {
						
						case '3' :
							
							
							cout << "Inserisci il nome del film da rimuovere: ";
							cin.ignore();
							getline(cin,ricercaFilm);	
							tabellone.removeFilm(ricercaFilm);	
							
						break;
							
						case '1' :
								
							cout << endl << "Inserire nome film: ";
								cin.ignore();
								getline(cin,nomeFilm);
							cout << "Inserire genere film: ";
								getline(cin,genereFilm);
							cout << "Inserire orario film: ";
								cin >> Orario;
							cout << "inserire prezzo biglietto: ";
								cin >> prezzoFilm;	
								
								// CREAZIONE FILM CON DATI RACCOLTI DA TERMINALE
									
								biglietto = new Biglietto(nomeFilm,genereFilm,Orario,prezzoFilm);
									
								// USO DEL METODO DI TABELLONE PER AGGIUNGERE FILM
									
								tabellone.addBiglietto(biglietto);
								
									
						break;
								
						case '2' : 
								
							cout << endl;
								
							// USO DEL METODO DI TABELLONE PER VEDERE LISTA FILM
								
							tabellone.print();
									
						break;
								
								
								
						case '0' : 
								
							// CAMBIO IL VALORE DI CICLE PER INTERROMPERE IL DO/WHILE
								
							ciclo1 = 1;
							ciclo2 = 1;
							
							cout << endl << "ARRIVEDERCI E BUONA GIORNATA" << endl;
								
						break;
								
						default:
								
							cout << endl << "OPZIONE NON VALIDA, REINSERIRE LA SCELTA." << endl;
								
						break;
						
						case '4' :
							
							cout <<  endl << "--- CAMBIO RUOLO ---" << endl;
							ciclo2 = 1; 
						
						break;
						
				}
							
			} while(ciclo2 == 0);
			
		break;
		
		case '2' : 
		
			ciclo3 = 0;
				
				do {
					
					cout << endl << "			-----------------		" <<endl;
					cout << "			| FORNITORE BAR |			" <<endl;
					cout << "			-----------------			" <<endl;
					cout << endl << "--- SCEGLIERE UNA DELLE SEGUENTI OPZIONI ---" << endl;
								
					cout << endl << "[1]	aggiungere un prodotto bar" << endl;
					cout << "[2]	Vedere prodotti bar disponibili" << endl;
					cout << "[3]	rimuovere prodotto bar" << endl;
					cout << "[4]	cambiare ruolo" << endl;
					cout << "[0]	esci" << endl;
								
					cout << endl << "SCELTA: ";
						cin >> sceltaBar;
									
						switch(sceltaBar) {
										
							case '3' :
											
								cout << "inserisci il nome del prodotto bar da eliminare: ";
								cin.ignore();
								cin.getline(ricercaProdottoBar,100);
								ricercaCast = (string) ricercaProdottoBar;
											
								cb.removeProdotto(ricercaCast);
											
							break;
										
							case '4' :
											
								ciclo3 = 1;
								cout <<  endl << "--- CAMBIO RUOLO ---" << endl;
									
							break;
										
							case '1' :
											
								cout << endl << "Inserire il nome del prodotto bar: ";
								cin.ignore(100,'\n');
								cin.getline(nomeProdottoBar,100);
								cout << "Inserire il prezzo del prodotto bar: ";
								cin >> prezzoProdottoBar;
											
								prodottoBar = new ProdottoBar(nomeProdottoBar,prezzoProdottoBar);	
								cb.addProdotto(prodottoBar);
											
											
							break;
										
							case '2' :
											
								cout << endl;
								cb.printCassa();
											
							break;
											
							case '0' : 
								
								// CAMBIO IL VALORE DI CICLE PER INTERROMPERE IL DO/WHILE
											
								ciclo1 = 1;
								ciclo3 = 1;
								cout << endl << "ARRIVEDERCI E BUONA GIORNATA"<< endl;
											
							break;
										
							default:
											
								cout << endl << "OPZIONE NON VALIDA, REINSERIRE LA SCELTA." << endl;
												
							break;
										
										
					}
				
				}while(ciclo3 == 0);
			
		
		break;
		
		case '3' :
			
			ciclo4 = 0;
			
			do{
				
				cout<< endl << "----------------------" << endl;
				cout << "| ADDETTO ALLA CASSA |" << endl;
				cout << "----------------------" << endl;
				
				cout << endl << "[1] vedere biglietti dei film" << endl;
				cout << "[2] vedere prodotti bar" << endl;
				cout << "[3] cambio ruolo" << endl;
				cout << "[4] vendere prodotto bar" << endl;
				cout << "[5] vendere biglietto film" << endl;
				cout << "[6] vedere incassi" << endl;
				cout << "[0] esci" << endl;
				cout << endl << "SCELTA:";
					cin >> sceltaCassa;
				
				switch(sceltaCassa) {
					
					case '1':
						
						cout << endl;
						tabellone.print();
						
					break;
					
					case '2':
						
						cout << endl;
						cb.printCassa();
					
					break;
					
					case '0':
						
						ciclo1 = 1;
						ciclo4 = 1;
						cout << endl << "ARRIVEDERCI E BUONA GIORNATA"<< endl;
						
					break;
					
					case '3':
						
						ciclo4 = 1;
						cout <<  endl << "--- CAMBIO RUOLO ---" << endl;
									
					break;
					
					case '4':
						
						cout << endl << "Inserire indice del prodotto da vendere" << endl;
						cout << endl << "INDICE:";
							cin >> numero;
							
						prodottoBar = cb.getLista(numero);
						prodottoBar->printProdottoBar();
						prezzoTmp = prodottoBar->getPrezzoProdottoBar();
						
						lista.inserisci(prezzoTmp);
						
						cout << endl << "--- PRODOTTO DEL BAR VENDUTO CORRETTAMENTE, OTTENUTI: " << prezzoTmp << "$ ---" << endl;
					
					break;
					
					case '5':
						
						cout << endl << "Inserire indice del biglietto del film da vendere" << endl;
						cout << endl << "INDICE:";
							cin >> numero;
							
						biglietto = tabellone.getBiglietto(numero);
						biglietto->print();
						prezzoTmp = biglietto->getPrezzoBiglietto();
						
						lista.inserisci(prezzoTmp);
							
						cout << endl << "--- BIGLIETTO DEL FILM VENDUTO CORRETTAMENTE, OTTENUTI: " << prezzoTmp << "$ ---" << endl;
						
					break;
					
					case '6':
						
						cout << endl << "--- TRANSAZIONI ---" << endl;
						
						lista.stampa();
						
					break;
						
					default:
											
						cout << endl << "OPZIONE NON VALIDA, REINSERIRE LA SCELTA." << endl;
												
					break;
				}
				
			}while(ciclo4 == 0);
			
		break;
		
		case '0' :
		
			cout << endl << "ARRIVEDERCI E BUONA GIORNATA" << endl;
			ciclo1 = 1;
			
		break;
		
		default :
			
			cout << endl << "CARATTERE NON VALIDO, REINSERIRE LA SCELTA" << endl;
			
		break;
		 
	}
		
    	}while(ciclo1 == 0);
    
    
}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
