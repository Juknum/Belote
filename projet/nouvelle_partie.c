/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	/////// CONTIENT DES SCANF A ACTIVER /////// ------ Fait

	nouvelle_partie.c : 
	- Impression du titre
	- Création des variables nécessaire pour la suite
	- Demande au joueur de son nom
	- Melange des cartes : melanger()
	- Distribution des cartes : distribuer()
	- Début des enchères avec : enchere()

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

#ifdef _WIN32
#include <windows.h>
#endif

void nouvelle_partie(){

	int cartes[32] = 
	{
		1,2,3,4,5,6,7,8, 
		9,10,11,12,13,14,15,16, 
		17,18,19,20,21,22,23,24, 
		25,26,27,28,29,30,31,32
	};

	int taille_cartes = (sizeof(cartes)/sizeof(int)); 				// = 32

	int cartes_joueur[8] = {0};
	int cartes_east[8]   = {0};
	int cartes_north[8]  = {0};
	int cartes_west[8]   = {0};

	char nom_joueur[20];

	int joueur_alea = rand()% 4 + 1; 								// on prend un joueur au hasard pour distribuer 

	printf(title_barre);
	printf(title_barre_top);
	printf(title_g"Nouvelle Partie"title_d);
	printf(title_barre_top);
	printf(title_barre);
										
	printf(side_question" Entrez votre nom : ");					// Demande du nom du joueur
	
	scanf("%s",&nom_joueur); 										// A ACTIVER
	//strcpy(nom_joueur, "Unnamed"); 								// A DESACTIVER

	printf(side_info" Nom choisi : %s\n",nom_joueur);

	melanger(cartes, taille_cartes);

	pause;

	distribuer(joueur_alea, cartes, nom_joueur, cartes_west, cartes_north, cartes_east, cartes_joueur);	
	
	pause;
	clean;

	enchere(joueur_alea, nom_joueur, cartes_joueur, cartes_west, cartes_north, cartes_east);
}