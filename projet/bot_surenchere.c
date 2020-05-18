#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

#include "./header/fonctions.h"

//bot_enchere(cartes_west, "Ouest", atout, &points, &passe);
void bot_surenchere(int * cartes_bot, char * bot, char * atout_pre, int * points_prev, int *passe){
	printf("\n§ %s examine son jeu...",bot);

	int points_pre = *points_prev;

	char atout[20];
	int points = 0;

	int pique_fort   = 0;							// Nombre de carte fortes par couleur
	int carreau_fort = 0;
	int coeur_fort   = 0;
	int trefle_fort  = 0;

	int choix_couleur = 0;							// Combinaison de couleurs
	int result        = 0;

	// On compte le nombre carte forte par couleur
	for(int i = 0; i < 8; i++){
		
		switch(cartes_bot[i]){

			case 0 ... 8 : // PIQUE
				
				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						pique_fort++;
						break;
				}

				break;

			case 9 ... 16 : // CARREAU

				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						carreau_fort++;
						break;
				}
				
				break;

			case 17 ... 24 : // COEUR

				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						coeur_fort++;
						break;
				}
				
				break;

			case 25 ... 32 : // TREFLE

				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						trefle_fort++;
						break;
				}

				break;
			default:
				printf("\n erreur switch cartes_bot(%d) avec %s",i,bot);
				break;
		}
	}

	// On détermine combien de couleur on le + grand nombre de carte haute
	if(pique_fort   >= carreau_fort && pique_fort   >= coeur_fort   && pique_fort   >= trefle_fort){choix_couleur += 1   ;}
	if(carreau_fort >= pique_fort   && carreau_fort >= coeur_fort   && carreau_fort >= trefle_fort){choix_couleur += 10  ;}
	if(coeur_fort   >= pique_fort   && coeur_fort   >= carreau_fort && coeur_fort   >= trefle_fort){choix_couleur += 100 ;}
	if(trefle_fort  >= pique_fort   && trefle_fort  >= carreau_fort && trefle_fort  >= coeur_fort ){choix_couleur += 1000;}

	/*
		Possibilitées : Permet d'avoir une solution en cas d'égalité de carte forte (en atout)
		   1 :                            PIQUE -------
		  10 :                  CARREAU 		-------
		  11 :                  CARREAU + PIQUE
		 100 :          COEUR 					-------
		 101 :          COEUR           + PIQUE
		 110 :          COEUR + CARREAU
		 111 :          COEUR + CARREAU + PIQUE
		1000 : TREFLE                           -------
		1001 : TREFLE                   + PIQUE
		1010 : TREFLE         + CARREAU
		1011 : TREFLE         + CARREAU + PIQUE
		1100 : TREFLE + COEUR
		1101 : TREFLE + COEUR           + PIQUE
		1110 : TREFLE + COEUR + CARREAU
		1111 : TREFLE + COEUR + CARREAU + PIQUE
	*/
	
	// On analyse result et on choisit la couleur:
	switch(choix_couleur){
		case 1:
			strcpy(atout, "Pique");
			break;
		case 10:
			strcpy(atout, "Carreau");
			break;
		case 11: // entre carreau et pique
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout, "Carreau");}else{strcpy(atout, "Pique");}
			break;
		case 100:
			strcpy(atout, "Coeur");
			break;
		case 101: // entre coeur et pique
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout, "Coeur");}else{strcpy(atout, "Pique");}
			break;
		case 110: // entre coeur et carreau
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout, "Coeur");}else{strcpy(atout, "Carreau");}
			break;
		case 111: // entre coeur, carreau et pique
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout, "Coeur");}else{if(result == 2){strcpy(atout, "Carreau");}else{strcpy(atout, "Pique");}}
			break;
		case 1000:
			strcpy(atout, "Trèfle");
			break;
		case 1001: // entre trefle et pique
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{strcpy(atout, "Pique");}
			break;
		case 1010: // entre trefle et carreau
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{strcpy(atout, "Carreau");}
			break;
		case 1011: // trefle carreau pique
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{if(result == 2){strcpy(atout, "Carreau");}else{strcpy(atout, "Pique");}}
			break;
		case 1100: // trefle coeur
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{strcpy(atout, "Coeur");}
			break;
		case 1101: // trefle coeur pique
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{if(result == 2){strcpy(atout, "Coeur");}else{strcpy(atout, "Pique");}}
			break;
		case 1110: // trefle coeur carreau
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{if(result == 2){strcpy(atout, "Coeur");}else{strcpy(atout, "Carreau");}}
			break;
		case 1111: // trefle coeur carreau pique
			result = rand()%4 + 1;
			if(result == 1){strcpy(atout, "Trèfle");}else{if(result == 2){strcpy(atout, "Coeur");}else{if(result == 3){strcpy(atout, "Carreau");}else{strcpy(atout, "Pique");}}}
		break;
	}

	if(pique_fort == 3 || carreau_fort == 3 || coeur_fort == 3 || trefle_fort == 3){
		points = 80;
	}
	if(pique_fort == 4 || carreau_fort == 4 || coeur_fort == 4 || trefle_fort == 4){
		points = 120;
	}

	// Points supérieur a ceux actuels
	if(points > points_pre){
		printf("\n§ %s annonce %s avec %d pts",bot,atout,points);

		*points_prev = points;
		strcpy(atout_pre, atout);
		
	}else{
		printf(" et a choisit de passer son tours!");
		*passe = *passe +1;
	}

}