#pragma once
#include "repoProduseApp.h"
#include "repoMagazinApp.h"

typedef Produs ElemType;

/* -un fel de service
 *
 * serviceMagazinAPP.h
 */

typedef int(*FctCmp)(Produs* produs1, Produs* produs2);

//Realizeaza adaugarea
void adaugare(Magazin*, Produs, int);

//Realizeaza actualizarea
void actualizare(Magazin*, int, int, int);

//Realizeaza stergerea
void stergere(Magazin*, int);

//Realizeaza sortarea stocului crescator/descrescator
void stoc(Magazin*, char*);

//Realizeaza filtrarea pt. producator/pret/cantitate
void filtrare(Magazin*, Magazin*, char*, char*);
