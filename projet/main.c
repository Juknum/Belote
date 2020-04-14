#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

// Tableau contenant toute les cartes jouées
char *TabValCol[] = {"7 Pique", "8 Pique", "9 Pique", "10 Pique", "Valet Pique", "Dame Pique", "Roi Pique", "As Pique", "7 Carreau", "8 Carreau", "9 Carreau", "10 Carreau", "Valet Carreau", "Dame Carreau", "Roi Carreau", "As Carreau", "7 Coeur", "8 Coeur", "9 Coeur", "10 Coeur", "Valet Coeur", "Dame Coeur", "Roi Coeur", "As Coeur", "7 Trefle", "8 Trefle", "9 Trefle", "10 Trefle", "Valet Trefle", "Dame Trefle", "Roi Trefle", "As Trefle"};

// score provisoir, a voir si on peut stocker les scores max dans un fichier txt
int score_max_1 = 0, score_max_2 = 0, score_max_3 = 0;

int nouvelle_partie(char* nom_joueur){

	printf(" \nNom choisi: %s",nom_joueur);

	return 0;
}

int menu(void){
	int choix = 0;
	char* nom_joueur;

	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	printf("            ♣ ♥ BELOTE ♠ ♦\n");
	printf("-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
	printf(" (1) Nouvelle Partie\n");
	printf(" (2) Voir les meilleurs scores\n");
	printf(" (3) Quitter\n");

	printf(" Votre choix : "); // scanf("%d",&choix);

	// DEBUG :
	choix = 1; //boucle infini si placé sur 2 (normal car il n'est pas redéfini)

	switch(choix){
		case 1 :	
			// Ici on demande le nom du joueur avant de lancer une nouvelle partie
			printf("\n-=-=-=-=-=-=-=-=-=--=-=-=-=-=-=-=-=-=-\n");
			printf(" Donnez-nous votre nom : ");

			//scanf("%s",nom_joueur);
			//DEBUG
			nom_joueur = "julien";

			nouvelle_partie(nom_joueur);
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

	return 0;
}

int main(void){
	

	// DEBUG : Affiche l'ensemble des cartes
	/*
	for(int i = 0; i < 32; i++){
			printf("%s\n",TabValCol[i]);
		}
	*/

	menu();

return EXIT_SUCCESS;
}