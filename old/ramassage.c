#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

/* 
	Permet le changement de la table des caractères de la console 
	> si le programme est utilisé sous Windows
*/
#ifdef _WIN32
#include <windows.h>
#endif

// Joueur :
char * nom_joueur = "name_undefined";

// Scores max:
int score_max_1;
int score_max_2;
int score_max_3;

// Jeux de cartes (non trié) et mains des joueurs:
int cartes[32] = {1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32};
int taille_cartes = (sizeof(cartes)/sizeof(int));

int distributeur;

int cartes_joueur[8] = {0};
int cartes_east[8]   = {0};
int cartes_north[8]  = {0};
int cartes_west[8]   = {0};

// Enchères
char * atout = "undefined"; // choix de l'atout pour la partie
int points = 0; // Points a atteindre pour remporter le contrat annoncé
int passe = 0; // Nombre de fois qu'un joueur passe

void melanger(int * tableau, int taille){
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

	printf("Fait!\n");
}

void distribuer(int distrib){
	
	if(distrib == 5){distrib = 1;} // Si le distributeur précédent était Est alors 4 + 1 = 5 sauf que Joueur == 1;

	switch(distrib){
		case 1:
			distributeur = 1; // Joueur
			printf("%s distribue...",nom_joueur);

			// Joueur distribue en 1er a Ouest -> Nord -> Est -> Joueur
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_west[i]   = cartes[i];
				cartes_north[i]  = cartes[i+3];
				cartes_east[i]   = cartes[i+6];
				cartes_joueur[i] = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_west[i]   = cartes[i+9];
				cartes_north[i]  = cartes[i+11];
				cartes_east[i]   = cartes[i+13];
				cartes_joueur[i] = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_west[i]   = cartes[i+15];
				cartes_north[i]  = cartes[i+18];
				cartes_east[i]   = cartes[i+21];
				cartes_joueur[i] = cartes[i+24];		
			}

			break;
		case 2:
			distributeur = 2; // Ouest
			printf("Ouest distribue...");

			// Ouest distribue en 1er a Nord -> Est -> Joueur -> Ouest
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_north[i]  = cartes[i];
				cartes_east[i]   = cartes[i+3];
				cartes_joueur[i] = cartes[i+6];
				cartes_west[i]   = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_north[i]  = cartes[i+9];
				cartes_east[i]   = cartes[i+11];
				cartes_joueur[i] = cartes[i+13];
				cartes_west[i]   = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_north[i]  = cartes[i+15];
				cartes_east[i]   = cartes[i+18];
				cartes_joueur[i] = cartes[i+21];
				cartes_west[i]   = cartes[i+24];		
			}

			break;
		case 3:
			distributeur = 3; // Nord
			printf("Nord distribue...");

			// Nord distribue en 1er a Est -> Joueur -> Ouest -> Nord 
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_east[i]   = cartes[i];
				cartes_joueur[i] = cartes[i+3];
				cartes_west[i]   = cartes[i+6];
				cartes_north[i]  = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_east[i]   = cartes[i+9];
				cartes_joueur[i] = cartes[i+11];
				cartes_west[i]   = cartes[i+13];
				cartes_north[i]  = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_east[i]   = cartes[i+15];
				cartes_joueur[i] = cartes[i+18];
				cartes_west[i]   = cartes[i+21];
				cartes_north[i]  = cartes[i+24];		
			}

			break;
		case 4:
			distributeur = 4; // Est
			printf("Est distribue...");

			// Est distribue en 1er a Joueur -> Ouest -> Nord -> Est 
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_joueur[i] = cartes[i];
				cartes_west[i]   = cartes[i+3];
				cartes_north[i]  = cartes[i+6];
				cartes_east[i]   = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_joueur[i] = cartes[i+9];
				cartes_west[i]   = cartes[i+11];
				cartes_north[i]  = cartes[i+13];
				cartes_east[i]   = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_joueur[i] = cartes[i+15];
				cartes_west[i]   = cartes[i+18];
				cartes_north[i]  = cartes[i+21];
				cartes_east[i]   = cartes[i+24];		
			}

			break;
		default:
			printf("Erreur pendant le choix du distributeur");
			break;
	}

	// On supprime les cartes présentes dans le deck (il est vide)
	for(int i = 0; i < 32; i++){
		cartes[i] = 0;
	}

	printf("Fait!\n");
}

void ramasser(int distributeur){

	switch(distributeur){
		case 1: // Joueur a distribué -> on ramasse en premier Ouest -> Nord -> Est -> Joueur
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_joueur[i]; }
			break;
		case 2: // Ouest a distribué -> on ramasse en premier Nord -> Est -> Joueur -> Ouest
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_west[i];   }
			break; 
		case 3: // Nord a distribué -> on ramasse en premier Est -> Joueur -> Ouest -> Nord
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_north[i];  }
			break;
		case 4: // Est a distribué -> on ramasse en premier Joueur -> Ouest -> Nord -> Est
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_east[i];   }
			break;
		default:
			printf("Erreur switch ramasser(%d)",distributeur);
			break;
	}
	
	// Les mains sont vides donc on vides chaque joueur (on met à 0)
	for(int i = 0; i < 8; i++){
		cartes_joueur[i] = 0;
		cartes_west[i]   = 0;
		cartes_north[i]  = 0;
		cartes_east[i]   = 0;
	}
}

int main(void){

	srand(time(NULL));

	printf("Mélange des cartes... ");
	melanger(cartes, taille_cartes);

	printf("  Cartes: ");
	for(int i = 0; i < 32; i++){
		printf("%d ",cartes[i]);
	}

	printf("\nDistribution des cartes... ");
	int distrib_alea = rand()% 4 + 1; // on prend un joueur pour distribuer au hasard
	distribuer(distrib_alea);

	printf("  Cartes: ");
	for(int i = 0; i < 32; i++){
		printf("%d ",cartes[i]);
	}
	printf("\n J: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_joueur[i]);
	}
	printf("\n O: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_west[i]);
	}
	printf("\n N: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_north[i]);
	}
	printf("\n E: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_east[i]);
	}

	printf("\nRamassage des cartes...\n");
	ramasser(distributeur);

	printf("  Cartes: ");
	for(int i = 0; i < 32; i++){
		printf("%d ",cartes[i]);
	}

	distribuer(distributeur+1);

	printf("  Cartes: ");
	for(int i = 0; i < 32; i++){
		printf("%d ",cartes[i]);
	}
	printf("\n J: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_joueur[i]);
	}
	printf("\n O: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_west[i]);
	}
	printf("\n N: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_north[i]);
	}
	printf("\n E: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_east[i]);
	}

	return 0;
}