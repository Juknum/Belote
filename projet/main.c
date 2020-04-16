/*

		BELOTE EN C : Groupe F
		- Julien Constant
		- Théo Silva

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

////////////////// VARIABLES : //////////////////

// score provisoir, a voir si on peut stocker les scores max dans un fichier txt
int score_max_1 = 0, score_max_2 = 0, score_max_3 = 0;
char* nom_joueur;

////////////////// FONCTIONS : //////////////////

void melanger(int* tableau, int taille){
	int alea_1, alea_2;
	int temp[1];

	/*
	Melange d'un tableau:
	- On coupe le tableau en 2
	- On choisi au hasard une position dans chaque partie du tableau
	- On les inverses et on recommence un grand nombre de fois
	*/
	
	for(int i = 0; i < 1000; i++){
		alea_1 = rand()%(taille/2);
		alea_2 = taille - (rand()%(taille/2) + 1);
		
		temp[0] = tableau[alea_1];
		tableau[alea_1] = tableau[alea_2];
		tableau[alea_2] = temp[0];
	}

	//DEBUG : affichage du tableau mélangé :
	/*
	for(int i = 0; i < taille ; i++){
		printf("%d ",tableau[i]);
	}
	printf("\n");
	*/
}

char* dictionnaire(int tableau){
	char* result = "undefined";

	switch(tableau){
		case 1 :
		result = " 7♠";
		break;
		case 2 :
		result = " 8♠";
		break;
		case 3 :
		result = " 9♠";
		break;
		case 4 :
		result = "10♠";
		break;
		case 5 :
		result = " V♠";
		break;
		case 6 :
		result = " D♠";
		break;
		case 7 :
		result = " R♠";
		break;
		case 8 :
		result = "AS♠";
		break;

		case 9 :
		result = " 7♦";
		break;
		case 10 :
		result = " 8♦";
		break;
		case 11 :
		result = " 9♦";
		break;
		case 12 :
		result = "10♦";
		break;
		case 13 :
		result = " V♦";
		break;
		case 14 :
		result = " D♦";
		break;
		case 15 :
		result = " R♦";
		break;
		case 16 :
		result = "AS♦";
		break;

		case 17 :
		result = " 7♥";
		break;
		case 18 :
		result = " 8♥";
		break;
		case 19 :
		result = " 9♥";
		break;
		case 20 :
		result = "10♥";
		break;
		case 21 :
		result = " V♥";
		break;
		case 22 :
		result = " D♥";
		break;
		case 23 :
		result = " R♥";
		break;
		case 24 :
		result = "AS♥";
		break;

		case 25 :
		result = " 7♣";
		break;
		case 26 :
		result = " 8♣";
		break;
		case 27 :
		result = " 9♣";
		break;
		case 28 :
		result = "10♣";
		break;
		case 29 :
		result = " V♣";
		break;
		case 30 :
		result = " D♣";
		break;
		case 31 :
		result = " R♣";
		break;
		case 32 :
		result = "AS♣";
		break;

		default :
		result = "error";
		break;
	}

	// DEBUG :
	//printf("cartes num : %d\n",tableau);
	//printf("traduction : %s\n",result);

	return result;
}

void start_partie(char* nom_joueur){
	int cartes[32] = {1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32};
	// Necessite un dictionnaire (faire une fonction) pour traduire et afficher correctement les cartes
	// de 7 a AS dans cet ordre : pique carreau coeur trèfle
	/*
		" 7♠", " 8♠", " 9♠", "10♠", " V♠", " D♠", " R♠", "As♠", 
		" 7♦", " 8♦", " 9♦", "10♦", " V♦", " D♦", " R♦", "As♦", 
		" 7♥", " 8♥", " 9♥", "10♥", " V♥", " D♥", " R♥", "As♥", 
		" 7♣", " 8♣", " 9♣", "10♣", " V♣", " D♣", " R♣", "As♣"
	*/

	int taille_cartes = (sizeof(cartes)/sizeof(int));

	/* 
		Mélange des cartes : 
	*/
	melanger(cartes, taille_cartes );

	/*
		Distribution des cartes :
	*/
	int cartes_joueur[8] = {0}, cartes_ordi_1[8] = {0}, cartes_ordi_2[8] = {0}, cartes_ordi_3[8] = {0};

	// Distribue 3 cartes par personne
	for(int i = 0; i < 3; i++){
		cartes_joueur[i] = cartes[i];
		cartes_ordi_1[i] = cartes[i+3];
		cartes_ordi_2[i] = cartes[i+6];
		cartes_ordi_3[i] = cartes[i+9];
	}
	// Distribue 2 cartes par personne
	for(int i = 3; i < 5; i++){
		cartes_joueur[i] = cartes[i+9];
		cartes_ordi_1[i] = cartes[i+11];
		cartes_ordi_2[i] = cartes[i+13];
		cartes_ordi_3[i] = cartes[i+15];		
	}
	// Distribue 3 cartes par personne
	for(int i = 5; i < 8; i++){
		cartes_joueur[i] = cartes[i+15];
		cartes_ordi_1[i] = cartes[i+18];
		cartes_ordi_2[i] = cartes[i+21];
		cartes_ordi_3[i] = cartes[i+24];		
	}

	// DEBUG : Affiche les decks de chaque joueurs:
	/*
	for(int i = 0; i < 8; i++){
		printf("cartes_joueur[%d] = %d\n",i,cartes_joueur[i]);
	}
	printf("\n");
	for(int i = 0; i < 8; i++){
		printf("cartes_ordi_1[%d] = %d\n",i,cartes_ordi_1[i]);
	}
	printf("\n");
	for(int i = 0; i < 8; i++){
		printf("cartes_ordi_2[%d] = %d\n",i,cartes_ordi_2[i]);
	}
	printf("\n");
	for(int i = 0; i < 8; i++){
		printf("cartes_ordi_3[%d] = %d\n",i,cartes_ordi_3[i]);
	}
	*/
	
	// test dictionnaire:
	dictionnaire(cartes_joueur[0]);
}

void menu(void){
	int choix = 0;

	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	printf("                BELOTE                \n");
	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	printf(" (1) Nouvelle Partie                  \n");
	printf(" (2) Voir les meilleurs scores        \n");
	printf(" (3) Quitter                          \n");

	printf(" Votre choix : ");

	// scanf("%d",&choix); // A ACTIVER
	// DEBUG :
	choix = 1; //boucle infini si placé sur 2 (normal car il n'est pas redéfini à chaque itération) A DESACTIVER

	switch(choix){
		case 1 :
			// Ici on demande le nom du joueur avant de lancer une nouvelle partie
			printf("\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
			printf(" Donnez-nous votre nom : ");

			//scanf("%s",nom_joueur); // A ACTIVER
			// DEBUG :
			nom_joueur = "julien"; // A DESACTIVER

			printf("\n");
			start_partie(nom_joueur);
			break;
		case 2 :
			// On affiche les meilleurs scores précédents
			printf("\n Meilleurs scores précédents :\n");
			printf(" 1er : %d\n 2e  : %d\n 3e  : %d\n",score_max_1,score_max_2,score_max_3);
			menu();
			break;
		case 3 :
			// On quitte le programme
			printf("\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
			exit(0);
			break;
		default :
			// Si l'utilisateur entre un choix qui n'existe pas, on relance menu()
			printf("\nCe choix n'existe pas");
			menu();
			break;
	}

}

int main(void){

	srand(time(NULL));

	menu();

return 0;
}
