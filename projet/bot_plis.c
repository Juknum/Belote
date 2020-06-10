#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void bot_plis(char* nom_bot, int* cartes_bot, int nb_cartes_jouee, int* tableau_pli){
	printf(side_jeu" %s Examine son jeu...\n",nom_bot);

	int carte_choisie = rand()%8 + 1; // A CHANGER

	switch(carte_choisie){
		case 1 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[0];
			cartes_bot[0] = 0;
		break;
		case 2 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[1];
			cartes_bot[1] = 0;
		break;
		case 3 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[2];
			cartes_bot[2] = 0;
		break;
		case 4 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[3];
			cartes_bot[3] = 0;
		break;
		case 5 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[4];
			cartes_bot[4] = 0;
		break;
		case 6 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[5];
			cartes_bot[5] = 0;
		break;
		case 7 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[6];
			cartes_bot[6] = 0;
		break;
		case 8 :
			tableau_pli[nb_cartes_jouee] = cartes_bot[7];
			cartes_bot[7] = 0;
		break;
		default:
			printf(side_error" switch(%d)",carte_choisie);
		break;
	}

	printf(side" Cartes :");
	for(int i = 0; i < 8; i++){
		if(cartes_bot[i] == 0){
			printf(" %s",dictionnaire(cartes_bot[i]));
		}
		else{
			printf(" %s",dictionnaire(-1));
		}
	}
	printf("\n"side_only);
}