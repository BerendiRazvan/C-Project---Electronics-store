#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "serviceMagazinApp.h"
#include "repoProduseApp.h"
#include "repoMagazinApp.h"
#include "validareApp.h"

void afisare(Magazin*);


void run() {

	/*
	Functia care ruleaza aplicatia, realizeaza toate citirile si afisarile

	-functie de tip void
	-parametrii functie:
		<nu exista parametrii>
	*/

	//creaza Magazinul
	Magazin inventar;
	inventar = creaza_magazin();

	//adaugam cateva produse
	Produs p1, p2, p3, p4, p5, p6;
	p1 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	p2 = creaza_produs(2, "TV", "Sony", "FullHD", 1750, 10);
	p3 = creaza_produs(3, "Cablu", "Hama", "Adaptor", 10, 30);
	p4 = creaza_produs(4, "Laptop", "Asus", "ROG0098", 5700, 20);
	p5 = creaza_produs(5, "Laptop", "Lenovo", "LEGION520G", 2500, 20);
	p6 = creaza_produs(6, "Laptop", "Asus", "Strix", 2500, 20);
	adaugare(&inventar, p1, 0);
	adaugare(&inventar, p2, 0);
	adaugare(&inventar, p3, 0);
	adaugare(&inventar, p4, 0);
	adaugare(&inventar, p5, 0);
	adaugare(&inventar, p6, 0);

	printf("Magazin Electronice -gestiune stoc-\n\n");

	char comanda[100] = { 0 };


	while (!(strcmp(comanda, "x") == 0 || strcmp(comanda, "X") == 0)) {
		printf("\nMENIU\n");
		printf("1 - Adaugare produs\n");
		printf("2 - Actualizare produs\n");
		printf("3 - Stergere produs\n");
		printf("4 - Vizualizare stoc\n");
		printf("5 - Filtrare produse\n");
		printf("\n* - Vizualizare DATE\nX - Inchidere Aplicatie\n\n");

		printf("\nIntroduceti comanda dorita:");
		scanf("%s", &comanda);

		if (strcmp(comanda, "1") == 0) {
			int idP = 0, pretP = 0, cantitateP = 0;
			char tipP[50] = { 0 }, producatorP[50] = { 0 }, modelP[50] = { 0 };
			int ok = 0;

			if (ok == 0) {
				printf("Produs nou\nIntroduceti ID:");
				if (scanf("%d", &idP) != 1) {
					printf("ID-ul trebue sa fie numar!\n");
					ok = 1;
				}
				else
					ok = validareID(idP);
			}

			if (ok == 0) {
				printf("Introduceti tip:");
				scanf("%s", &tipP);
				if (strcmp(tipP, " ") == 0) {
					printf("Tipul nu poate fi null!\n");
					ok = 1;
				}
			}

			if (ok == 0) {
				printf("Introduceti producator:");
				if (scanf("%s", &producatorP) != 1) {
					printf("Producatorul nu poate fi null!\n");
					ok = 1;
				}
			}

			if (ok == 0) {
				printf("Introduceti model:");
				if (scanf("%s", &modelP) != 1) {
					printf("Modelul nu poate fi null!\n");
					ok = 1;
				}
			}

			if (ok == 0) {
				printf("Introduceti pret:");
				if (scanf("%d", &pretP) != 1) {
					printf("Pretul trebue sa fie numar!\n");
					ok = 1;
				}
				else
					ok = validarePret(pretP);
			}

			if (ok == 0) {
				printf("Introduceti cantitate:");
				if (scanf("%d", &cantitateP) != 1) {
					printf("Cantitatea trebue sa fie numar!\n");
					ok = 1;
				}
				else
					ok = validareCantitate(cantitateP);
			}


			if (ok == 1) {
				char mizerie[50] = { 0 };
				scanf("%s", mizerie);
			}
			else
				ok = validareProdusData(&inventar, idP, tipP, producatorP, modelP, pretP);


			if (ok != 1) {
				//creaza produs nou
				Produs produsNou;
				produsNou = creaza_produs(idP, tipP, producatorP, modelP, pretP, cantitateP);

				//adauga Produsul

				adaugare(&inventar, produsNou, ok);


				printf("Adaugare realizata cu succes.\n");
			}
			else {
				printf("Adaugarea  nu s-a putut realizata.\n");
			}
		}

		else if (strcmp(comanda, "2") == 0) {
			int idP = 0, pretP = 0, cantitateP = 0;

			printf("Introduceti ID-ul produsului pe care doriti sa il modificati:");
			int ok = 0;

			if (ok == 0) {
				if (scanf("%d", &idP) != 1) {
					printf("ID-ul trebue sa fie numar!\n");
					ok = 1;
				}
			}

			if (ok == 0) {
				printf("Introduceti noul pret:");
				if (scanf("%d", &pretP) != 1) {
					printf("Pretul trebue sa fie numar!\n");
					ok = 1;
				}
			}

			if (ok == 0) {
				printf("Introduceti noua cantitate:");
				if (scanf("%d", &cantitateP) != 1) {
					printf("Cantitatea trebue sa fie numar!\n");
					ok = 1;
				}
			}
			if (ok == 0)
				ok = existID(&inventar, idP);
			else {
				char mizerie[50] = { 0 };
				scanf("%s", mizerie);
			}

			if (ok == 0)
				actualizare(&inventar, idP, pretP, cantitateP), printf("Actualizarea s-a realizat cu succes.");
			else {
				printf("Actualizarea nu s-a putut realiza.");
			}
		}
		else if (strcmp(comanda, "3") == 0) {
			int idP = 0, ok = 0;
			printf("Introduceti ID-ul produsului pe care doriti sa il stergeti:");
			if (ok == 0) {
				if (scanf("%d", &idP) != 1) {
					printf("ID-ul trebue sa fie numar!\n");
					ok = 1;
				}
			}
			if (ok == 0)
				ok = existID(&inventar, idP);
			else {
				char mizerie[50] = { 0 };
				scanf("%s", mizerie);
			}
			if (ok == 0) {
				stergere(&inventar, idP);
				printf("Stergerea s-a realizat cu succes.");

			}
			else {
				printf("Stergerea nu s-a putut realiza.");
			}

		}
		else if (strcmp(comanda, "4") == 0) {
			char criteriu[51] = { 0 };
			printf("Introduceti un criteriu |-Crescator-|-Descrescator-|:");
			scanf("%s", &criteriu);

			if (strcmp(criteriu, "Descrescator") == 0 || strcmp(criteriu, "Crescator") == 0 || strcmp(criteriu, "D") == 0 || strcmp(criteriu, "C") == 0) {
				stoc(&inventar, criteriu);
				printf("\nLista produse:\n");
				if (inventar.nrProduse == 0)
					printf("-EMPTY-\n");
				else
					afisare(&inventar);
			}
			else
				printf("Criteriu invalid.\n");

		}
		else if (strcmp(comanda, "5") == 0) {
			char criteriu[51] = { 0 }, dateCrt[51] = { 0 };
			printf("Introduceti un criteriu |-Producator-|-Pret-|-Cantitate-|:");
			scanf("%s", &criteriu);
			printf("Introduceti datele pentru criteriul ales:");
			scanf("%s", &dateCrt);

			if (strcmp(criteriu, "Producator") == 0 || strcmp(criteriu, "Pret") == 0 || strcmp(criteriu, "Cantitate") == 0) {
				Magazin magazinFiltrat;
				magazinFiltrat = creaza_magazin();

				filtrare(&inventar, &magazinFiltrat, criteriu, dateCrt);

				printf("\nLista produse:\n");
				if (magazinFiltrat.nrProduse != 0)
					afisare(&magazinFiltrat);
				else
					printf("-EMPTY-\n");

				destroy_magazin(&magazinFiltrat);
			}
			else
				printf("Criteriu invalid.\n");

		}
		else if (strcmp(comanda, "*") == 0) {
			printf("\nLista produse:\n");
			if (inventar.nrProduse == 0)
				printf("-EMPTY-\n");
			else
				afisare(&inventar);
		}
		else if (strcmp(comanda, "x") == 0 || strcmp(comanda, "X") == 0) {
			printf("\nVa multumim! La revedere.\n");
			destroy_magazin(&inventar);
		}
		else
			printf("\nComanda inexistenta!");

		printf("\n");
	}

}


void afisare(Magazin* inventar) {

	/*
	Functia care realizeaza afisarea produselor din magazin

	-functie de tip void
	-parametrii functie:
		<inventar> - Magazin*

	Afiseaza fiecare produs sub forma: "%d. Tip: %s | Producator: %s | Model: %s | Pret: %d lei | Cantitate: %d \n"
	*/

	for (int i = 0; i < inventar->nrProduse; i++)
		printf("%d. Tip: %s | Producator: %s | Model: %s | Pret: %d lei | Cantitate: %d \n", inventar->listaProduse[i].idProdus, inventar->listaProduse[i].tipProdus, inventar->listaProduse[i].producatorProdus, inventar->listaProduse[i].modelProdus, inventar->listaProduse[i].pretProdus, inventar->listaProduse[i].cantitateProdus);

}
