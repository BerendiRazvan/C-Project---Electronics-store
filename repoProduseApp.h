#pragma once

/* -un fel de repository pt. Produse
 *
 * repoProduseAPP.h
 */

 //Struct Produs (ID; TIP; PRODUCATOR; MODEL; PRET; CANTITATE)
typedef struct {
	int idProdus, pretProdus, cantitateProdus;
	char* tipProdus;
	char* producatorProdus;
	char* modelProdus;
}Produs;


//Creaza Produs
Produs creaza_produs(int, char*, char*, char*, int, int);

//Distruge Produs
void destroy_produs(Produs*);

//Copiaza Produs
Produs copyProdus(Produs*);

