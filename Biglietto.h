#ifndef _BIGLIETTO_H_
#define _BIGLIETTO_H_

#include <iostream>
#include <string>
#include "Film.h"

class Biglietto : public Film {
	private:
	
		float prezzoBiglietto;
		
	public:
		// COSTRUTTORI
		Biglietto();
		Biglietto(string, string, float, float);	
		
		// SETTER
		void setPrezzoBiglietto(float);	
		
		// GETTER
		float getPrezzoBiglietto();
		virtual void print();
};

#endif
