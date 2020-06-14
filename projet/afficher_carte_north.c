#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

#define TAILLE_MAX 1000

void afficher_carte_north(int * cartes, int nb_carte_jouee, int a_jouee){
	FILE* carte_north = NULL;
	char ligne[TAILLE_MAX] = "";

	printf(bold);

	// Le bot nord n'a pas joué, on affiche la carte retournée
	if(a_jouee == 0){
		carte_north = fopen("./data/not_carte_north.txt", "r");

		if(carte_north != NULL){

			while( fgets(ligne, TAILLE_MAX, carte_north) != NULL){
				printf("%s", ligne);
			}
			printf("\n");

			fclose(carte_north);
		}
		else{
			printf(side_error" Ouverture du fichier not_carte_north.txt impossible");
		}
	}
	else{
		carte_north = fopen("./data/carte_north.txt", "r");

		if(carte_north != NULL){
			
			int caractere;

			while(( caractere = fgetc(carte_north)) != EOF){
				if( caractere == 'z'){
					printf("%s",symbole(cartes[nb_carte_jouee-1]));
				}
				else if( caractere == '0'){
					printf("%s",dictionnaire(cartes[nb_carte_jouee-1]));
				}else{printf("%c",caractere);}
			}

			printf("\n");

		    fclose(carte_north);
		}
		else{
			printf(side_error" Ouverture du fichier carte_north.txt impossible");
		}
		
	}

	printf(nboldw);
}