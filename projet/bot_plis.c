#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void bot_plis(char* nom_bot, int* cartes_bot, int nb_cartes_jouee, int* tableau_pli){
	printf(side_jeu" %s Examine son jeu...",nom_bot);

	int carte_choisie = 0; 

	// DEBUG : Affiche les cartes du bot avant son choix
	/*
	printf(side" bot:");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_bot[i]));
	}
	printf("\n");
	*/

	// Evite de au bot de prendre une carte déjà posée au tour précédent
	do{
		carte_choisie = rand()%8 + 1; // A CHANGER
	}while(cartes_bot[carte_choisie-1] == 0);

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

	printf(" et pose %s !\n",dictionnaire(tableau_pli[nb_cartes_jouee]));

	// DEBUG : Affiche les cartes du bot après son choix
	/*
	printf(side" bot:");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_bot[i]));
	}
	printf("\n");
	*/

	// DEBUG : Affiche les cartes face cachée du bot après son choix
	/*
	printf(side" Cartes :");
	for(int i = 0; i < 8; i++){
		if(cartes_bot[i] == 0){
			printf(" %s",dictionnaire(cartes_bot[i]));
		}
		else{
			printf(" %s",dictionnaire(-1));
		}
	}
	*/
	printf(side_only);

	/*
	#include <stdio.h>
	#include <stdlib.h>

	#include <string.h>

	#include "./header/fonctions.h"
	#include "./header/syntax.h"

	void bot_plis(char* nom_bot, int* cartes_bot, int nb_cartes_jouee, int* tableau_pli){
	printf(side_jeu" %s Examine son jeu...\n",nom_bot);



	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva


	// Au tour du bot, le bot check toutes les cartes du tableau et doit ensuite check son tableau de carte. 
	// S'il a une carte plus élevée que celles déjà jouées (faire un tri préliminaire des tableau) :
		// Il joue sa carte la plus faible pouvant lui permettre de l'emporter sauf s'il y a un atout sur la table
		// S'il a un atout (le plus faible possible), il le joue
	// S'il a une carte moins élevée que celles déjà jouées :
		// Il pose sa carte la plus faible (de préférence une carte non atout)
	// S'il est le premier a jouer : 
		// Il joue sa carte la plus faible 
		// Ou alors il joue n'imp

	
	Une pseudo intelligence artificielle sera également réalisée pour jouer avec le joueur :
		• L’IA joue en respectant les règles
		• Si l’IA est en mesure de remporter le pli avec une de ses cartes, elle le fait en posant la carte
		la plus faible possible
		• Si l’IA n’est pas en mesure de remporter le pli, elle joue sa carte la plus faible
		• Vous pouvez enrichir votre IA avec des règles heurisitiques que vous aurez élaborées et
		justifiées dans votre rapport.
	



	int tableau_pli_tbot[3] = {0,0,0,0};
	int tableau_atout_tbot[3] = {0,0,0,0};

	int nbot = 0;


	printf(side_jeu"Tour de %s",bot);

	// Tri des tableaux pour les bots afin qu'ils choisissent quelle carte jouer
	for(int i = 0; i < 4; i++){
		tableau_pli_tbot[i] = tableau_pli[i];
	}
	tableau_tri(tableau_pli_tbot);
	for(int i = 0; i < 4; i++){
		tableau_atout_tbot[i] = tableau_atout[i];
	}
	tableau_tri(tableau_atout_tbot);

	// On traduit le nom des bots numériquement pour ensuite les utiliser dans le switch
	if (bot == 'Ouest'){
		nbot = 1;
	}
	if (bot == 'Nord'){
		nbot = 2;
	}
	if (bot == 'Est'){
		nbot = 3;
	}

	switch(nbot){
		case 1 : // Ouest
			// Analyse des cartes jouées :
			for(int i = 0; i < 8; i++){ // Pour toutes les cartes du bot on va vérifier si :
						
				for(int j = 3; j > -1; j--){ // L'une de ses cartes est supérieure à une des cartes jouées

					if cartes_bot[i] > tableau_pli_tbot[j]{

						tableau_pli[1] = cartes_bot[i];
						cartes_bot[i] = 0;
					}
				}
				for(int j = 3; j > -1; j--){
					if cartes_bot[i] <= tableau_pli_tbot[j]{ 
						// On vérifie que la carte qu'il joue ne soit pas déjà une carte jouée ("X")
						if(cartes_bot[i] = 0){
							tableau_pli[1] = cartes_bot[i+1];
						}

						tableau_pli[1] = cartes_bot[i];
					}
				}			
			}
	}

	*/

}