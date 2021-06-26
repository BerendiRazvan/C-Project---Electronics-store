#pragma once
#include "repoProduseApp.h"
#include "repoMagazinApp.h"
#include "serviceMagazinApp.h"

/*
 * validareAPP.h
 */

 //Verifica daca ID-ul este nr. strict pozitiv
int validareID(int);

//Verifica daca pretul este nr. strict pozitiv
int validarePret(int);

//Verifica daca cantitatea este nr. strict pozitiv
int validareCantitate(int);

//Verifica daca tipul este vid
int validareTip(char*);

//Verifica daca producatorul este vid
int validareProducator(char*);

//Verifica daca modelul este vid
int validareModel(char*);

//Verifica daca ID-ul exista
int existID(Magazin*, int);

//Verifica daca Produsul introdus exista
int validareProdusData(Magazin*, int, char*, char*, char*, int);


