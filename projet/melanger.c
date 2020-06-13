/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	melanger.c : 
		- On coupe le tableau en 2
		- On choisi au hasard une position dans chaque partie du tableau
		- On les inverses et on recommence un grand nombre de fois (1000 fois)

*/

#include <stdio.h>
#include <stdlib.h>

#include "./header/syntax.h"

void melanger(int * tableau, int taille){
	int alea_1, alea_2;
	int temp[1];

	printf(side_info" Mélange des cartes... ");

	for(int i = 0; i < 1000; i++){
		alea_1 = rand()%(taille/2);
		alea_2 = taille - (rand()%(taille/2) + 1);
		
		temp[0] = tableau[alea_1];
		tableau[alea_1] = tableau[alea_2];
		tableau[alea_2] = temp[0];
	}

	//DEBUG : affichage du tableau une fois mélangé :
	/*
	for(int i = 0; i < taille ; i++){
		printf("%d ",tableau[i]);
	}
	printf("\n");
	*/	

	printf("Fait!\n");
}