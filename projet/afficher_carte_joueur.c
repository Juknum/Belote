#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

#define TAILLE_MAX 1000

void afficher_carte_joueur(int * cartes, int nb_carte_jouee, int a_jouee, char* nom_joueur){
	FILE* carte_joueur = NULL;
	char ligne[TAILLE_MAX] = "";

	printf(bold);

	// Le bot nord n'a pas joué, on affiche la carte retournée
	if(a_jouee == 0){
		carte_joueur = fopen("./data/not_carte_joueur.txt", "r");

		if(carte_joueur != NULL){
			
			int caractere;

			while(( caractere = fgetc(carte_joueur)) != EOF){
				if( caractere == '%'){
					printf("%s",nom_joueur);
				}else{printf("%c",caractere);}
			}

			printf("\n");

		    fclose(carte_joueur);
		}
		else{
			printf(side_error" Ouverture du fichier not_carte_joueur.txt impossible");
		}
	}
	else{
		carte_joueur = fopen("./data/carte_joueur.txt", "r");

		if(carte_joueur != NULL){
			
			int caractere;

			while(( caractere = fgetc(carte_joueur)) != EOF){
				if( caractere == 'z'){
					printf("%s",symbole(cartes[nb_carte_jouee-1]));
				}
				else if( caractere == '0'){
					printf("%s",dictionnaire(cartes[nb_carte_jouee-1]));
				}else if( caractere == '%'){
					printf("%s",nom_joueur);
				}else{printf("%c",caractere);}
			}

			printf("\n");

		    fclose(carte_joueur);
		}
		else{
			printf(side_error" Ouverture du fichier carte_joueur.txt impossible");
		}
		
	}

	printf(nboldw);
}