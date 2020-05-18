#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

void distribuer(int distrib, int * cartes, char * nom_joueur, int * cartes_west, int * cartes_north, int * cartes_east,  int * cartes_joueur){
	printf("§ INFO : Distribution des cartes... ");

	int distributeur = 0;
	
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
			printf("Erreur switch distribuer(%d)",distrib);
			break;
	}

	printf("Fait!\n");

}