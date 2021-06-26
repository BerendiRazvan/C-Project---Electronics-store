#define _CRTDBG_MAP_ALLOC
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <crtdbg.h>

#include "testingApp.h"
#include "consoleApp.h"


int main() {

	//Testare app
	runAllTests();


	//Rulare app
	run();

	printf("\nAplicatie inchisa.\n");
	_CrtDumpMemoryLeaks();

	return 0;
}


/*
--------------------------------------------------------------------------------------------------------------------------------------------------------------


Cerinte generale



Creati o aplicatie modulara in C.

Se cere interfata utilizator de tip consola.

Datele introduse de utilizator trebuie validate.

Folositi athitectura stratificata.

Folositi dezvoltare dirijata de teste (Test Driven Development)

Fiecare metoda din aplicatie trebuie specificat si testat.

Implementati vector dinamic pentru lucru cu liste:

	- in prima saptamana puteti folosi reprezentarea cu un struct ( un vector static si lungime in el)

	- pana in saptamana 2 trebuie folosit alocare dinamica (sa acomodeze oricate elemente)

Timp de lucru 2 saptamani.


--------------------------------------------------------------------------------------------------------------------------------------------------------------


P8. Magazin electronice


Creati o aplicatie care permite gestiunea stocului de produse intr-un magazin de electronice.

Fiecare produs are un identificator unic, tip (laptop, frigider, televizor,etc), producator, model,

pret, cantitate.

Aplicatia permite:

 a) Adaugarea de noi produse. Daca produsul este deja in stoc trebuie actualizat cantitatea

 b) Actualizare produse (modificare pret sau cantitate)

 c) Stergere produs

 d) Vizualizare produse din stoc, ordonat dupa pret, cantitate (crescator/descrescator)

 e) Vizualizare lista de produse filtrate dupa un criteriu (producator, pret, cantitate)


 --------------------------------------------------------------------------------------------------------------------------------------------------------------
*/


