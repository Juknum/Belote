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


// score provisoir, a voir si on peut stocker les scores max dans un fichier txt
int score_max_1 = 0, score_max_2 = 0, score_max_3 = 0;

char* nom_joueur;

char* cartes[] = {
		"7♠", "8♠", "9♠", "10♠", "V♠", "D♠", "R♠", "As♠", 
		"7♦", "8♦", "9♦", "10♦", "V♦", "D♦", "R♦", "As♦", 
		"7♥", "8♥", "9♥", "10♥", "V♥", "D♥", "R♥", "As♥", 
		"7♣", "8♣", "9♣", "10♣", "V♣", "D♣", "R♣", "As♣" };


int nouvelle_partie(char* nom_joueur){

	// melange du jeu de carte : 
	/*
	Fonctionnement : 
	- on coupe le paquet (ici le tableau) en 2
	- on intervertit aléatoirement les cartes de chaque côtés
	*/
	for(int i = 1; i < 1000; i++){
		int alea_1 = rand()%16; // de 0 à 16
		int alea_2 = 32 - (rand()%16 + 1); // de 16 à 32
		
		char* temp[] = {"0"};

		temp[0] = cartes[alea_1];
		cartes[alea_1] = cartes[alea_2];
		cartes[alea_2] = temp[0];

	}

	// DEBUG : affiche les cartes mélangées
	for(int i = 0; i < 32; i++){
		printf("%s",cartes[i]);
	}

	return 0;
}

int menu(void){
	int choix = 0;

	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	printf(u8"            ♣ ♥ BELOTE ♠ ♦\n");
	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	printf(" (1) Nouvelle Partie\n");
	printf(" (2) Voir les meilleurs scores\n");
	printf(" (3) Afficher les caractères spéciaux\n");
	printf(" (4) Quitter\n");

	printf(" Votre choix : "); // scanf("%d",&choix); // A ACTIVER

	// DEBUG :
	choix = 1; //boucle infini si placé sur 2 (normal car il n'est pas redéfini) A DESACTIVER

	switch(choix){
		case 1 :	
			// Ici on demande le nom du joueur avant de lancer une nouvelle partie
			printf("\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
			printf(" Donnez-nous votre nom : ");

			//scanf("%s",nom_joueur); // A ACTIVER
			// DEBUG :
			nom_joueur = "julien"; // A DESACTIVER

			printf("\n");
			nouvelle_partie(nom_joueur);
			break;
		case 2 :
			// On affiche les meilleurs scores précédents
			printf("\n Meilleurs scores précédents :\n");
			printf(" 1er : %d\n 2e  : %d\n 3e  : %d\n",score_max_1,score_max_2,score_max_3);
			menu();
			break;
		case 3 :
			// On explique comment passer en utf-8
			printf("\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-");
			printf("\n| Afin d'afficher les caractères speciaux,");
			printf("\n| il est necessaire d'etre en utf-8, pour cela,");
			printf("\n| rentrez la commande 'chcp 65001' dans l'invite de commande,");
			printf("\n| Puis depuis la meme console, executez le main.exe");
			printf("\n| en vous deplacant dans son repertoire avec 'cd C:/etc...'\n");
			menu();
			break;
		case 4 :
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

	return 0;
}

int main(void){

	srand(time(NULL));

	menu();

return 0;
}