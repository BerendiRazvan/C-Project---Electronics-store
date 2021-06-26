#pragma once
#include "repoProduseApp.h"
typedef Produs ElemType;

/* -un fel de repository pt. Magazin
 *
 * repoMagazinAPP.h
 */

 //Struct Magazin (LISTA PRODUSE; NUMAR PRODUSE; CAPACITATE LISTA)
typedef struct {
	Produs* listaProduse;
	int nrProduse;
	int capacitate;
}Magazin;


//Creaza Magazin
Magazin creaza_magazin();

//Distruge Magazin
void destroy_magazin(Magazin*);

