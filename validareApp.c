#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repoProduseApp.h"
#include "repoMagazinApp.h"
#include "serviceMagazinApp.h"



int validareID(int idP) {

	/*
	Functia care valideaza ID-ul

	-functie de tip int
	-parametrii functie:
		<idP> - int

	Returneaza 1 - ID invalid
	Returneaza 0 - ID valid
	*/

	if (idP <= 0)
		return 1;
	return 0;
}

int validarePret(int pretP) {

	/*
	Functia care valideaza pretul

	-functie de tip int
	-parametrii functie:
		<pretP> - int

	Returneaza 1 - pret invalid
	Returneaza 0 - pret valid
	*/

	if (pretP <= 0)
		return 1;
	return 0;
}
int validareCantitate(int cantitateP) {

	/*
	Functia care valideaza cantiatea

	-functie de tip int
	-parametrii functie:
		<cantitateP> - int

	Returneaza 1 - cantitate invalida
	Returneaza 0 - cantitate valida
	*/

	if (cantitateP < 0)
		return 1;
	return 0;
}
int validareTip(char* tipP) {

	/*
	Functia care valideaza tipul

	-functie de tip int
	-parametrii functie:
		<tipP> - char*

	Returneaza 1 - tip invalid
	Returneaza 0 - tip valid
	*/

	if (strcmp(tipP, " ") == 0)
		return 1;
	return 0;
}
int validareProducator(char* producatorP) {

	/*
	Functia care valideaza producatorul

	-functie de tip int
	-parametrii functie:
		<producatorP> - char*

	Returneaza 1 - producator invalid
	Returneaza 0 - producator valid
	*/

	if (strcmp(producatorP, " ") == 0)
		return 1;
	return 0;
}
int validareModel(char* modelP) {

	/*
	Functia care valideaza modelul

	-functie de tip int
	-parametrii functie:
		<modelP> - char*

	Returneaza 1 - model invalid
	Returneaza 0 - model valid
	*/

	if (strcmp(modelP, " ") == 0)
		return 1;
	return 0;
}

int existID(Magazin* inventar, int idP) {

	/*
	Functia care verifica daca ID-ul exista in magazin

	-functie de tip int
	-parametrii functie:
		<inventar> - Magazin*
		<idP> - int

	Returneaza 1 - ID inexistent
	Returneaza 0 - ID existent
	*/

	for (int i = 0; i < inventar->nrProduse; i++)
		if (idP == inventar->listaProduse[i].idProdus)
			return 0;
	return 1;
}

int validareProdusData(Magazin* inventar, int idP, char* tipP, char* producatorP, char* modelP, int pretP) {

	/*
	Functia care valideaza Produsul

	-functie de tip int
	-parametrii functie:
		<inventar> - Magazin*
		<idP> - int
		<tipP> - char*
		<producatorP> - char*
		<modelP> - char*
		<pretP> - int
		<cantitateP> - int

	Returneaza 2 - Produs existent identic
	Returneaza 1 - Produs existent cu acest ID
	Returneaza 0 - Produs inexistent
	*/

	for (int i = 0; i < inventar->nrProduse; i++)
		if (idP == inventar->listaProduse[i].idProdus) {
			if (inventar->listaProduse[i].pretProdus == pretP && strcmp(inventar->listaProduse[i].tipProdus, tipP) == 0 && strcmp(inventar->listaProduse[i].producatorProdus, producatorP) == 0 && strcmp(inventar->listaProduse[i].modelProdus, modelP) == 0)
				return 2;//produs identic => stoc++
			else
				return 1;
		}

	return 0;
}