#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

#include "./header/fonctions.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define BOLD  "\x1b[1m"
#define NBOLD RESET""WHT

// Phase d'Enchère - BOTs
void bot_enchere(int * cartes_bot, char * bot, char * atout, int *points, int *passe){
	/*
		Au moment des enchères : 
		si une IA possède 3 cartes fortes d’une couleur donnée, 
		> elle annoncera un contrat de 80 points pour cette couleur.

		si elle possède 4 cartes fortes de cette couleur, 
		> elle annoncera un contrat de 120 points pour cette couleur.
	*/

	// On annonce le bot qui examine son jeu:
	printf("\n§ "CYN"JEU :"WHT" %s examine son jeu...",bot);

	//// Estimation par le bot de la couleur possédant le plus de points :

	int pique_fort   = 0;							// Nombre de carte fortes par couleur
	int carreau_fort = 0;
	int coeur_fort   = 0;
	int trefle_fort  = 0;

	int choix_couleur = 0;							// Combinaison de couleurs
	int result        = 0;							// Resultat si la combinaison prend plusieurs valeurs

	char atout_bot[20]; 							// choix provisoire d'atout pour le bot

	char atout_pre[20];								// Memoire de l'ancien atout (pour determiner si le bot a choisi de passer ou non)
	int points_pre = 0;								// De meme avec les pts

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

	// Affiche les cartes du bot:
	/*
	printf("\n%s:",bot);
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_bot[i]));
	}
	*/

	// Affiche le nombre de cartes fortes par couleur
	//printf("\n%d/%d/%d/%d",pique_fort,carreau_fort,coeur_fort,trefle_fort);

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
			
	switch(choix_couleur){
		case 1:
			strcpy(atout_bot, "Pique");
			break;
		case 10:
			strcpy(atout_bot, "Carreau");
			break;
		case 11: // entre carreau et pique
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout_bot, "Carreau");}else{strcpy(atout_bot, "Pique");}
			break;
		case 100:
			strcpy(atout_bot, "Coeur");
			break;
		case 101: // entre coeur et pique
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout_bot, "Coeur");}else{strcpy(atout_bot, "Pique");}
			break;
		case 110: // entre coeur et carreau
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout_bot, "Coeur");}else{strcpy(atout_bot, "Carreau");}
			break;
		case 111: // entre coeur, carreau et pique
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout_bot, "Coeur");}else{if(result == 2){strcpy(atout_bot, "Carreau");}else{strcpy(atout_bot, "Pique");}}
			break;
		case 1000:
			strcpy(atout_bot, "Trèfle");
			break;
		case 1001: // entre trefle et pique
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{strcpy(atout_bot, "Pique");}
			break;
		case 1010: // entre trefle et carreau
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{strcpy(atout_bot, "Carreau");}
			break;
		case 1011: // trefle carreau pique
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{if(result == 2){strcpy(atout_bot, "Carreau");}else{strcpy(atout_bot, "Pique");}}
			break;
		case 1100: // trefle coeur
			result = rand()%2 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{strcpy(atout_bot, "Coeur");}
			break;
		case 1101: // trefle coeur pique
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{if(result == 2){strcpy(atout_bot, "Coeur");}else{strcpy(atout_bot, "Pique");}}
			break;
		case 1110: // trefle coeur carreau
			result = rand()%3 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{if(result == 2){strcpy(atout_bot, "Coeur");}else{strcpy(atout_bot, "Carreau");}}
			break;
		case 1111: // trefle coeur carreau pique
			result = rand()%4 + 1;
			if(result == 1){strcpy(atout_bot, "Trèfle");}else{if(result == 2){strcpy(atout_bot, "Coeur");}else{if(result == 3){strcpy(atout_bot, "Carreau");}else{strcpy(atout_bot, "Pique");}}}
		break;
	}

	strcpy(atout_pre, atout);			// On sauvegarde l'ancien atout et les points d'avant
	points_pre = *points;

	if(strcmp(atout_bot, "Pique") == 0 && pique_fort == 3){
		strcpy(atout, atout_bot);
		if(pique_fort == 4){*points = 120;}else{*points = 80;}
		printf("\n§ "CYN"JEU :"WHT" %s annonce "BOLD"%s"NBOLD" avec "BOLD"%d"NBOLD" pts",bot,atout,*points);
	}

	if(strcmp(atout_bot, "Carreau") == 0 && carreau_fort == 3){
		strcpy(atout, atout_bot);
		if(pique_fort == 4){*points = 120;}else{*points = 80;}
		printf("\n§ "CYN"JEU :"WHT" %s annonce "BOLD"%s"NBOLD" avec "BOLD"%d"NBOLD" pts",bot,atout,*points);
	}

	if(strcmp(atout_bot, "Coeur") == 0 && coeur_fort == 3){
		strcpy(atout, atout_bot);
		if(pique_fort == 4){*points = 120;}else{*points = 80;}
		printf("\n§ "CYN"JEU :"WHT" %s annonce "BOLD"%s"NBOLD" avec "BOLD"%d"NBOLD" pts",bot,atout,*points);
	}

	if(strcmp(atout_bot, "Trèfle") == 0 && trefle_fort == 3){
		strcpy(atout, atout_bot);
		if(pique_fort == 4){*points = 120;}else{*points = 80;}
		printf("\n§ "CYN"JEU :"WHT" %s annonce "BOLD"%s"NBOLD" avec "BOLD"%d"NBOLD" pts",bot,atout,*points);
	}

	if(strcmp(atout, atout_pre) == 0 && *points == points_pre){ // Si vrai : le bot n'a pas changer l'atout et les pts -> il passe son tours
		printf(" et a choisit de passer son tours!");
		*passe = *passe +1;
	}
}