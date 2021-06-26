#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "serviceMagazinApp.h"
#include "repoProduseApp.h"
#include "repoMagazinApp.h"
#include "validareApp.h"
#include "utilsApp.h"

void testareProdus() {

	/*Testeaza toate functiile din repoProduseAPP.c*/

	Produs produsTest;
	produsTest = creaza_produs(1, "Tip", "Producator", "MODEL1234", 25000, 2300);
	assert(produsTest.idProdus == 1);
	assert(produsTest.cantitateProdus == 2300);
	assert(produsTest.pretProdus == 25000);
	assert(strcmp(produsTest.producatorProdus, "Producator") == 0);
	assert(strcmp(produsTest.tipProdus, "Tip") == 0);
	assert(strcmp(produsTest.modelProdus, "MODEL1234") == 0);

	destroy_produs(&produsTest);

	//copyProdus() - nu e testat direct, dar se testeaza cand testam Swap din Utils.c
}

void testareMagazin() {

	/*Testeaza toate functiile din serviceMagazinAPP.c si repoMagazinAPP.c*/

	Magazin inventar;
	inventar = creaza_magazin();


	Produs p1, p2, p3, p4, p5, p6;
	p1 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	p2 = creaza_produs(2, "TV", "Sony", "FullHD", 1750, 10);
	p3 = creaza_produs(3, "Cablu", "Hama", "Adaptor", 10, 30);
	p4 = creaza_produs(4, "Laptop", "Asus", "ROG0098", 5700, 20);
	p5 = creaza_produs(5, "Laptop", "Lenovo", "LEGION520G", 2500, 20);
	p6 = creaza_produs(6, "Laptop", "Asus", "Strix", 2500, 20);

	assert(inventar.nrProduse == 0);

	adaugare(&inventar, p1, 0);
	assert(inventar.nrProduse == 1);
	assert(inventar.listaProduse[0].idProdus == p1.idProdus);

	adaugare(&inventar, p2, 0);
	assert(inventar.nrProduse == 2);
	assert(inventar.listaProduse[1].idProdus == p2.idProdus);

	adaugare(&inventar, p3, 0);
	assert(inventar.nrProduse == 3);
	assert(inventar.listaProduse[2].idProdus == p3.idProdus);

	adaugare(&inventar, p3, 2);
	assert(inventar.nrProduse == 3);
	assert(inventar.listaProduse[2].idProdus == p3.idProdus);
	assert(inventar.listaProduse[2].cantitateProdus == 60);


	actualizare(&inventar, 1, 2, 3);
	assert(inventar.nrProduse == 3);
	assert(inventar.listaProduse[0].idProdus == p1.idProdus);
	assert(inventar.listaProduse[0].pretProdus == 2);
	assert(inventar.listaProduse[0].cantitateProdus == 3);


	stergere(&inventar, 1);


	assert(inventar.nrProduse == 2);
	assert(inventar.listaProduse[0].idProdus == 2);
	assert(inventar.listaProduse[1].idProdus == 3);

	Produs p7;
	p7 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	adaugare(&inventar, p7, 0);
	adaugare(&inventar, p4, 0);
	adaugare(&inventar, p5, 0);
	adaugare(&inventar, p6, 0);

	stoc(&inventar, "Descrescator");
	assert(inventar.listaProduse[0].idProdus == 4);
	assert(inventar.listaProduse[1].idProdus == 1);
	assert(inventar.listaProduse[2].idProdus == 5);
	assert(inventar.listaProduse[3].idProdus == 6);
	assert(inventar.listaProduse[4].idProdus == 2);
	assert(inventar.listaProduse[5].idProdus == 3);


	stoc(&inventar, "Crescator");

	assert(inventar.listaProduse[0].idProdus == 3);
	assert(inventar.listaProduse[1].idProdus == 2);
	assert(inventar.listaProduse[2].idProdus == 5);
	assert(inventar.listaProduse[3].idProdus == 6);
	assert(inventar.listaProduse[4].idProdus == 1);
	assert(inventar.listaProduse[5].idProdus == 4);

	stoc(&inventar, "Descrescator");
	assert(inventar.listaProduse[0].idProdus == 4);
	assert(inventar.listaProduse[1].idProdus == 1);
	assert(inventar.listaProduse[2].idProdus == 5);
	assert(inventar.listaProduse[3].idProdus == 6);
	assert(inventar.listaProduse[4].idProdus == 2);
	assert(inventar.listaProduse[5].idProdus == 3);

	stoc(&inventar, "aaa");
	assert(inventar.listaProduse[0].idProdus == 3);
	assert(inventar.listaProduse[1].idProdus == 2);
	assert(inventar.listaProduse[2].idProdus == 5);
	assert(inventar.listaProduse[3].idProdus == 6);
	assert(inventar.listaProduse[4].idProdus == 1);
	assert(inventar.listaProduse[5].idProdus == 4);

	Magazin filtrareee;
	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "Cantitate", "20");
	assert(filtrareee.nrProduse == 3);
	assert(filtrareee.listaProduse[0].idProdus == 5);
	assert(filtrareee.listaProduse[1].idProdus == 6);
	assert(filtrareee.listaProduse[2].idProdus == 4);
	destroy_magazin(&filtrareee);

	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "Pret", "2500");
	assert(filtrareee.nrProduse == 3);
	assert(filtrareee.listaProduse[0].idProdus == 5);
	assert(filtrareee.listaProduse[1].idProdus == 6);
	assert(filtrareee.listaProduse[2].idProdus == 1);
	destroy_magazin(&filtrareee);

	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "Producator", "Samsung");
	assert(filtrareee.nrProduse == 1);
	assert(filtrareee.listaProduse[0].idProdus == 1);
	destroy_magazin(&filtrareee);

	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "nimic", "Samsung");
	assert(filtrareee.nrProduse == 0);
	destroy_magazin(&filtrareee);


	destroy_magazin(&inventar);
}

void testareValidare() {

	/*Testeaza toate functiile din validareAPP.c*/

	Magazin inventar;
	inventar = creaza_magazin();

	Produs p1, p2, p3;
	p1 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	p2 = creaza_produs(2, "TV", "Sony", "FullHD", 1750, 10);
	p3 = creaza_produs(3, "Cablu", "Hama", "Adaptor", 10, 30);
	adaugare(&inventar, p1, 0);
	adaugare(&inventar, p2, 0);
	adaugare(&inventar, p3, 0);



	assert(validareID(12) == 0);
	assert(validareID(-12) == 1);
	assert(validareID(0) == 1);

	assert(validarePret(12) == 0);
	assert(validarePret(-12) == 1);
	assert(validarePret(0) == 1);

	assert(validareCantitate(12) == 0);
	assert(validareCantitate(-12) == 1);
	assert(validareCantitate(0) == 0);

	assert(validareTip("tip") == 0);
	assert(validareTip("TIPds09") == 0);
	assert(validareTip(" ") == 1);

	assert(validareProducator("tip") == 0);
	assert(validareProducator("TIPds09") == 0);
	assert(validareProducator(" ") == 1);

	assert(validareModel("tip") == 0);
	assert(validareModel("TIPds09") == 0);
	assert(validareModel(" ") == 1);

	assert(existID(&inventar, 2) == 0);
	assert(existID(&inventar, 0) == 1);
	assert(existID(&inventar, -1) == 1);
	assert(existID(&inventar, 19) == 1);

	assert(validareProdusData(&inventar, 2, "Teleasdfon", "Saasdmsung", "S2sds0", 2500) == 1);
	assert(validareProdusData(&inventar, 33, "Telefon", "Samasdsung", "S20", 2500) == 0);
	assert(validareProdusData(&inventar, 1, "Telefon", "Samsung", "S20", 2500) == 2);
	assert(validareProdusData(&inventar, 3, "Tdsaelefon", "Samassung", "S20", 25000) == 1);
	assert(validareProdusData(&inventar, 45, "Telefonds", "Samsungds", "S20ds", 500) == 0);


	destroy_magazin(&inventar);
}

void testareUtils() {

	/*Testeaza toate functiile din utilsAPP.c*/

	Produs p1, p2;
	p1 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	p2 = creaza_produs(2, "TV", "Sony", "FullHD", 1750, 10);

	swapProd(&p1, &p2);
	assert(p1.idProdus == 2);
	assert(p1.cantitateProdus == 10);
	assert(p1.pretProdus == 1750);
	assert(strcmp(p1.producatorProdus, "Sony") == 0);
	assert(strcmp(p1.tipProdus, "TV") == 0);
	assert(strcmp(p1.modelProdus, "FullHD") == 0);

	assert(p2.idProdus == 1);
	assert(p2.cantitateProdus == 23);
	assert(p2.pretProdus == 2500);
	assert(strcmp(p2.producatorProdus, "Samsung") == 0);
	assert(strcmp(p2.tipProdus, "Telefon") == 0);
	assert(strcmp(p2.modelProdus, "S20") == 0);

	destroy_produs(&p1);
	destroy_produs(&p2);
}

void testareSort() {

	Magazin inventar;
	inventar = creaza_magazin();


	Produs p1, p2, p3, p4, p5, p6;
	p1 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	p2 = creaza_produs(2, "TV", "Sony", "FullHD", 1750, 10);
	p3 = creaza_produs(3, "Cablu", "Hama", "Adaptor", 10, 30);
	p4 = creaza_produs(4, "Laptop", "Asus", "ROG0098", 5700, 20);
	p5 = creaza_produs(5, "Laptop", "Lenovo", "LEGION520G", 2500, 20);
	p6 = creaza_produs(6, "Laptop", "Asus", "Strix", 2500, 20);

	assert(inventar.nrProduse == 0);

	adaugare(&inventar, p1, 0);
	assert(inventar.nrProduse == 1);
	assert(inventar.listaProduse[0].idProdus == p1.idProdus);

	adaugare(&inventar, p2, 0);
	assert(inventar.nrProduse == 2);
	assert(inventar.listaProduse[1].idProdus == p2.idProdus);

	adaugare(&inventar, p3, 0);
	assert(inventar.nrProduse == 3);
	assert(inventar.listaProduse[2].idProdus == p3.idProdus);

	adaugare(&inventar, p3, 2);
	assert(inventar.nrProduse == 3);
	assert(inventar.listaProduse[2].idProdus == p3.idProdus);
	assert(inventar.listaProduse[2].cantitateProdus == 60);


	actualizare(&inventar, 1, 2, 3);
	assert(inventar.nrProduse == 3);
	assert(inventar.listaProduse[0].idProdus == p1.idProdus);
	assert(inventar.listaProduse[0].pretProdus == 2);
	assert(inventar.listaProduse[0].cantitateProdus == 3);


	stergere(&inventar, 1);


	assert(inventar.nrProduse == 2);
	assert(inventar.listaProduse[0].idProdus == 2);
	assert(inventar.listaProduse[1].idProdus == 3);

	Produs p7;
	p7 = creaza_produs(1, "Telefon", "Samsung", "S20", 2500, 23);
	adaugare(&inventar, p7, 0);
	adaugare(&inventar, p4, 0);
	adaugare(&inventar, p5, 0);
	adaugare(&inventar, p6, 0);



	stoc(&inventar, "Crescator");

	assert(inventar.listaProduse[0].idProdus == 3);
	assert(inventar.listaProduse[1].idProdus == 2);
	assert(inventar.listaProduse[2].idProdus == 5);
	assert(inventar.listaProduse[3].idProdus == 6);
	assert(inventar.listaProduse[4].idProdus == 1);
	assert(inventar.listaProduse[5].idProdus == 4);



	stoc(&inventar, "aaa");
	assert(inventar.listaProduse[0].idProdus == 3);
	assert(inventar.listaProduse[1].idProdus == 2);
	assert(inventar.listaProduse[2].idProdus == 5);
	assert(inventar.listaProduse[3].idProdus == 6);
	assert(inventar.listaProduse[4].idProdus == 1);
	assert(inventar.listaProduse[5].idProdus == 4);

	Magazin filtrareee;
	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "Cantitate", "20");
	assert(filtrareee.nrProduse == 3);
	assert(filtrareee.listaProduse[0].idProdus == 5);
	assert(filtrareee.listaProduse[1].idProdus == 6);
	assert(filtrareee.listaProduse[2].idProdus == 4);
	destroy_magazin(&filtrareee);

	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "Pret", "2500");
	assert(filtrareee.nrProduse == 3);
	assert(filtrareee.listaProduse[0].idProdus == 5);
	assert(filtrareee.listaProduse[1].idProdus == 6);
	assert(filtrareee.listaProduse[2].idProdus == 1);
	destroy_magazin(&filtrareee);

	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "Producator", "Samsung");
	assert(filtrareee.nrProduse == 1);
	assert(filtrareee.listaProduse[0].idProdus == 1);
	destroy_magazin(&filtrareee);

	filtrareee = creaza_magazin();
	filtrare(&inventar, &filtrareee, "nimic", "Samsung");
	assert(filtrareee.nrProduse == 0);
	destroy_magazin(&filtrareee);


	destroy_magazin(&inventar);

}

void runAllTests() {

	/*
	Ruleaza toate functiile pt. testare
		-afiseaza: "*ALL TESTS PASSED*\n\n", daca toate testele sunt corecte(TRUE)
	*/

	testareProdus();
	testareMagazin();
	testareValidare();
	testareUtils();
	testareSort();
	printf("*ALL TESTS PASSED*\n\n");
}


