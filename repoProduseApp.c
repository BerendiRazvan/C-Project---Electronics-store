#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "repoProduseApp.h"


Produs creaza_produs(int idP, char* tipP, char* producatorP, char* modelP, int pretP, int cantitateP) {

	/*
	Functia care creaza un produs nou

	-functie de tip Produs
	-parametrii functie:
		<idP> - int
		<tipP> - char*
		<producatorP> - char*
		<modelP> - char*
		<pretP> - int
		<cantitateP> - int

	Returneaza noul produs
	*/

	Produs produsNou;

	produsNou.idProdus = idP;

	int tipP_dim = strlen(tipP) + 1;
	produsNou.tipProdus = malloc(tipP_dim * sizeof(char));
	strcpy_s(produsNou.tipProdus, tipP_dim, tipP);

	int producatorP_dim = strlen(producatorP) + 1;
	produsNou.producatorProdus = malloc(producatorP_dim * sizeof(char));
	strcpy_s(produsNou.producatorProdus, producatorP_dim, producatorP);

	int modelP_dim = strlen(modelP) + 1;
	produsNou.modelProdus = malloc(modelP_dim * sizeof(char));
	strcpy_s(produsNou.modelProdus, modelP_dim, modelP);

	produsNou.pretProdus = pretP;
	produsNou.cantitateProdus = cantitateP;

	return produsNou;
}



//distruge produs
void destroy_produs(Produs* produsDistr) {

	/*
	Functia care distruge un produs

	-functie de tip void
	-parametrii functie:
		<produsDistr> - Produs*

	Elibereaza memoria
	*/

	free(produsDistr->modelProdus);
	free(produsDistr->producatorProdus);
	free(produsDistr->tipProdus);

	//produsDistr->cantitateProdus = NULL;
	//produsDistr->pretProdus = NULL;
	//produsDistr->idProdus = NULL;
}



Produs copyProdus(Produs* p) {
	/*
	Functia care copiaza un Produs

	-functie de tip Produs
	-parametrii functie:
		<p> - Produs*

	Returneaza copia produsului introdus
	*/

	return creaza_produs(p->idProdus, p->tipProdus, p->producatorProdus, p->modelProdus, p->pretProdus, p->cantitateProdus);
}


