#include "Lista.h"

Lista::Lista ()
{ 
  p = NULL; 
  nelem=0;
}

Lista::Lista (Lista& l)
{
  p = NULL; 
  nelem=0;
	 
  float *tmp; 
  int    nelem;
  
  nelem = l.getsize();
  tmp = new float[nelem];
  l.dumptoarray(tmp);
  cout << "nelem = " << nelem << endl;
	
  for (int i=0; i<nelem; i++)
  {
  	this->inserisci(tmp[i]);
  }
    
  delete tmp;

};

int Lista::getsize (void)
{
  return nelem;	
};

void Lista::clone(Lista& l)
{

	l.nelem = nelem;
	float tmp[nelem];
	
	if (p != NULL){ // se non e' vuota
	    Nodo* q = p;
		int i = 1;
		do{ //ce n'e' almeno uno
            tmp[nelem-i] = q->valore;
			q = q->next;
            i++;
		}while (q != NULL);
	} else {
		cout << "Lista da clonare vuota" << endl;
	}	
	
	for (int i=0; i<nelem; i++) {
		l.inserisci(tmp[i]);
	}	

};

int Lista::dumptoarray(float* l)
{	
	int i = 0;
		
	if (p != NULL)
	    { // se non e' vuota
	    Nodo* q = p;
		i = 1;
		do 
		{ //ce n'e' almeno uno
            l[nelem-i] = q->valore;
			q = q->next;
            i++;
		} while (q != NULL);
	} else {
		cout <<  "Lista da copiare vuota" << endl;
		return -1;
	}	
	
	return 0;
  
};

int Lista::cancella (float e)
{
	if( p == NULL) return -1; // impossibile eliminare l'elemento 
	if( p->valore == e ){ // il valore da eliminare coincide con il primo della lista
		Nodo* r = p;
		p=p->next;
		delete r;
        nelem--;
		return 0;
	}
	Nodo* q = p;
	// per gli elementi successivi al primo
	while (q->next != NULL){
		if (q->next->valore == e) {
			Nodo* r= q->next;
			q->next=q->next->next;
                nelem--;
			return 1;
		}
		q=q->next ;
	}

  return 0;
}

void Lista::stampa()
{
	
	if (p != NULL){ // se non e' vuota
		Nodo* q = p;
		int i = 1;
		do{ //ce n'e' almeno uno
			
			cout << endl << i << ")";
			cout << q->valore << "$" << endl;
			q = q->next;
            i++;
		}while (q != NULL);
	} else {
		cout << "Lista vuota" << endl;
	}
} 

Lista::~Lista()
{
    
	if (p != NULL){ // se non e' vuota
		Nodo* q = p;
           Nodo* target = NULL;
		int i = 1;
		do{ //ce n'e' almeno uno
             target = q;  
		  q = q->next;
             //cout << "Libero memoria a indirizzo: ";
             delete target;
             i++;
		} while (q != NULL);
	} else {
		//cout << "Lista vuota" << endl;
	}
	
}

int Lista::inserisci (float e)
{
	if(p == NULL){
		//Nessun nodo in lista, inserimento primo valore
		p = new Nodo;
		p->next=NULL;
		p->valore=e;	
	} else {
	     // Nuovo nodo come primo della lista
	    	Nodo* q = new Nodo;
	    	q->next = p;
		q->valore = e;
		p = q;
     }
	nelem++;		
	return 0;
}

			
			
			
			
			
			
			
			
			
			
			
			
			
			
