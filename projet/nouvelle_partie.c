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

/////// CONTIENT DES SCANF A ACTIVER ///////

void nouvelle_partie(){

	//// Jeux de cartes (non trié) et mains des joueurs:
	int cartes[32] = {1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32};
	int taille_cartes = (sizeof(cartes)/sizeof(int)); // = 32

	int cartes_joueur[8] = {0};
	int cartes_east[8]   = {0};
	int cartes_north[8]  = {0};
	int cartes_west[8]   = {0};

	char nom_joueur[20];

	int joueur_alea = rand()% 4 + 1; // on prend un joueur au hasard pour distribuer 

	printf("O--------------------------------------------------=-=--------------------------------------------------O\n");
	printf("§                                     o------------=-=------------o\n");
	printf("§ ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  !      "YEL"Nouvelle Partie"WHT"      !  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"\n");
	printf("§                                     o-------------=-------------o\n");
	printf("§\n§\n§\n§\n");
	printf("O--------------------------------------------------=-=--------------------------------------------------O\n");

	//// Demande du nom du joueur
	printf("§ "YEL"Entrez votre nom : ");
	
	//scanf("%s",&nom_joueur); // A ACTIVER
	strcpy(nom_joueur, "Unnamed"); // A DESACTIVER

	printf("\n"WHT"§ "GRN"INFO :"WHT" Nom choisi : %s\n",nom_joueur);
	
	// Mélange & distribution des cartes
	melanger(cartes, taille_cartes);				// melanger(int * tableau, int taille_tableau)

	// distribuer(int distributeur, int * tableau, char * nom_joueur, int * cartes_... ...)
	distribuer(joueur_alea, cartes, nom_joueur, cartes_west, cartes_north, cartes_east, cartes_joueur);	

	// Phase d'enchere
	// enchere(int encherisseur, char nom_joueur, int cartes_joueur, int cartes_west...)
	enchere(joueur_alea, nom_joueur, cartes_joueur, cartes_west, cartes_north, cartes_east);
}
