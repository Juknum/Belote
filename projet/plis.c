#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

#include "./header/fonctions.h"


void plis(int distributeur,int * cartes,int * cartes_west, int * cartes_north, int * cartes_east,  int * cartes_joueur, int nom_joueur){

cartes_north[i];cartes_east[i];cartes_joueur[i];cartes_west[i]
int numero_pli = 1;
int premier_joueur = 0;
do{
	printf(" Début du pli numéro %d",numero_pli);
	switch(distributeur){
		case 1:
			premier_joueur = 4;
			printf("Le premier joueur a jouer est Est");
			break;
		case 2:
			premier_joueur = 1;
			printf("Le premier joueur a jouer est %s",nom_joueur);
			break;
		case 3:
			premier_joueur = 2;
			printf("Le premier joueur a jouer est Ouest");
			break;
		case 4:
			premier_joueur = 3;
			printf("Le premier joueur a jouer est Nord");
			break;
	}


	numero_pli++;
}while(cartes_west == 0 || cartes_east == 0 || cartes_north == 0 || cartes_joueur == 0);




}