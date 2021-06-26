#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "repoProduseApp.h"
#include "repoMagazinApp.h"




Magazin creaza_magazin() {

	/*
	Functia care creaza un magazin nou

	-functie de tip Magazin
	-parametrii functie:
		<nu exista parametrii>

	Returneaza noul magazin
	*/

	Magazin inventar;

	inventar.capacitate = 2;
	inventar.listaProduse = malloc(sizeof(Produs) * inventar.capacitate);
	inventar.nrProduse = 0;

	return inventar;
}


void destroy_magazin(Magazin* inventar) {

	/*
	Functia care distruge un magazin

	-functie de tip void
	-parametrii functie:
		<inventar> - Magazin*

	Elibereaza memoria
	*/

	for (int i = 0; i < inventar->nrProduse; i++) {
		ElemType prod = inventar->listaProduse[i];
		destroy_produs(&prod);
	}
	free(inventar->listaProduse);
	//inventar->nrProduse = NULL;

}
