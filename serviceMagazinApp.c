#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "serviceMagazinApp.h"
#include "repoProduseApp.h"
#include "repoMagazinApp.h"
#include "utilsApp.h"


void adaugare(Magazin* inventar, Produs produsNou, int ok) {

	/*
	Functia care adauga un produs nou, in fct. de parametrul ok(0-adauga produs;1-nu adauga;2-produs identic, creste cantitatea)

	-functie de tip void
	-parametrii functie:
		<inventar> - Magazin*
		<produsNou> - Produs
		<ok> - int

	Adauga produs nou in magazin
	*/
	if (inventar->capacitate <= inventar->nrProduse) {
		//realocam spatiu
		ElemType* aux = malloc(sizeof(ElemType) * (inventar->capacitate + 5));
		//copiere produse
		for (int i = 0; i < inventar->nrProduse; i++) {
			aux[i] = inventar->listaProduse[i];
		}

		free(inventar->listaProduse);
		inventar->listaProduse = aux;
		inventar->capacitate += 5;

	}


	if (ok == 2) {
		for (int i = 0; i < inventar->nrProduse; i++)
			if (inventar->listaProduse[i].idProdus == produsNou.idProdus)
				inventar->listaProduse[i].cantitateProdus += produsNou.cantitateProdus;
	}
	if (ok == 0) {
		inventar->listaProduse[inventar->nrProduse] = produsNou;
		inventar->nrProduse++;
	}

}

void actualizare(Magazin* inventar, int idP, int pretP, int cantitateP) {

	/*
	Functia care actualizeaza un produs

	-functie de tip void
	-parametrii functie:
		<inventar> - Magazin*
		<idP> - int
		<ok> - int
		<pretP> - int
		<cantitateP> - int

	Actualizeaza pretul si cantitatea unui produs
	*/

	int gasit = 0;
	for (int i = 0; i < inventar->nrProduse && gasit == 0; i++)
		if (inventar->listaProduse[i].idProdus == idP) {
			inventar->listaProduse[i].pretProdus = pretP;
			inventar->listaProduse[i].cantitateProdus = cantitateP;

			gasit = 1;
		}
}




void stergere(Magazin* inventar, int idP) {

	/*
	Functia care sterge un produs

	-functie de tip void
	-parametrii functie:
		<inventar> - Magazin*
		<idP> - int

	Sterge un produs din magazin
	*/

	for (int i = 0; i < inventar->nrProduse; i++) {
		if (inventar->listaProduse[i].idProdus == idP) {
			for (int j = i; j < inventar->nrProduse - 1; j++) {
				swapProd(&inventar->listaProduse[j], &inventar->listaProduse[j + 1]);
			}
			inventar->nrProduse -= 1;
			destroy_produs(&inventar->listaProduse[inventar->nrProduse]);
		}
	}
}

int compara1(Produs*, Produs*);

int compara1(Produs* produs1, Produs* produs2) {
	if (produs1->pretProdus > produs2->pretProdus)
		return 1;
	if (produs1->pretProdus < produs2->pretProdus)
		return -1;
	if (produs1->pretProdus == produs2->pretProdus && produs1->cantitateProdus > produs2->cantitateProdus)
		return 1;
	if (produs1->pretProdus == produs2->pretProdus && produs1->cantitateProdus < produs2->cantitateProdus)
		return -1;
	return 0;
}


int compara2(Produs*, Produs*);

int compara2(Produs* produs1, Produs* produs2) {
	if (produs1->pretProdus < produs2->pretProdus)
		return 1;
	if (produs1->pretProdus > produs2->pretProdus)
		return -1;
	if (produs1->pretProdus == produs2->pretProdus && produs1->cantitateProdus < produs2->cantitateProdus)
		return 1;
	if (produs1->pretProdus == produs2->pretProdus && produs1->cantitateProdus > produs2->cantitateProdus)
		return -1;
	return 0;
}



void comparaFct(Magazin* inventar, FctCmp cmp) {

	for (int i = 0; i < inventar->nrProduse; i++)
		for (int j = i + 1; j < inventar->nrProduse; j++)
			if (cmp(&inventar->listaProduse[i], &inventar->listaProduse[j]) == -1)
				swapProd(&inventar->listaProduse[i], &inventar->listaProduse[j]);

}

void stoc(Magazin* inventar, char* crescator_descrescator) {

	if (strcmp(crescator_descrescator, "Descrescator") == 0)
		comparaFct(inventar, compara1);
	else
		comparaFct(inventar, compara2);
}



void filtrare(Magazin* inventar, Magazin* magazinFiltrat, char* criteriu, char* dateCrt) {

	/*
	Functia care filtreaza stocul magazinului, dupa criteriu (Producator, Pret, Cantitate) si dateCrt (datele din criteriu)

	-functie de tip void
	-Filtreaza:
		Producator, daca <criteriu> == "Producator";
		Pret, daca <criteriu> == "Pret";
		Cantitate, daca <criteriu> == "Cantitate";
	-parametrii functie:
		<inventar> - Magazin*
		<magazinFiltrat> - Magazin*
		<criteriu> - char*
		<dateCrt> - char*

	Filtreaza Magazinul introdus si pune datele in magazinFiltrat
	*/

	if (strcmp(criteriu, "Pret") == 0) {
		for (int i = 0; i < inventar->nrProduse; i++)
			if (inventar->listaProduse[i].pretProdus == atoi(dateCrt)) {
				Produs produsOk;
				produsOk = copyProdus(&inventar->listaProduse[i]);
				adaugare(magazinFiltrat, produsOk, 0);
			}
	}

	if (strcmp(criteriu, "Cantitate") == 0) {
		for (int i = 0; i < inventar->nrProduse; i++)
			if (inventar->listaProduse[i].cantitateProdus == atoi(dateCrt)) {
				Produs produsOk;
				produsOk = copyProdus(&inventar->listaProduse[i]);
				adaugare(magazinFiltrat, produsOk, 0);
			}
	}

	if (strcmp(criteriu, "Producator") == 0) {
		for (int i = 0; i < inventar->nrProduse; i++)
			if (strcmp(inventar->listaProduse[i].producatorProdus, dateCrt) == 0) {
				Produs produsOk;
				produsOk = copyProdus(&inventar->listaProduse[i]);
				adaugare(magazinFiltrat, produsOk, 0);
			}
	}

}
