#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "repoProduseApp.h"


void swapProd(Produs* A, Produs* B) {

	/*
	Functia care realizeaza Swap intre doua Produse A si B

	-functie de tip void
	-parametrii functie:
		<A> - Produs*
		<B> - Produs*

	Produsul A ia valoarea lui B, iar B valoarea lui A
	*/
	Produs C;

	C = copyProdus(A);
	destroy_produs(A);

	*A = copyProdus(B);
	destroy_produs(B);

	*B = copyProdus(&C);
	destroy_produs(&C);
}




