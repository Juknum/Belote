#include <stdlib.h>
#include <stdio.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

#define TAILLE_MAX 1000

void afficher_carte_east_west(int* cartes, int nb_carte_jouee, int ordre_jeu, int west_a_jouee, int east_a_jouee){
	FILE* carte_west_east     = NULL;
	FILE* not_carte_west_east = NULL;
	FILE* not_carte_west      = NULL;
	FILE* not_carte_east      = NULL;
	char ligne[TAILLE_MAX] = "";

	printf(bold);

	if(east_a_jouee == 0 && west_a_jouee == 0){
		not_carte_west_east = fopen("data/not_carte_west_east.txt", "r");

		if(not_carte_west_east != NULL){

			while( fgets(ligne, TAILLE_MAX, not_carte_west_east) != NULL){
				printf("%s", ligne);
			}
			printf("\n");

			fclose(not_carte_west_east);
		}
		else{
			printf(side_error" Ouverture du fichier not_carte_west_east.txt impossible");
		}
	}
	else{
		if(east_a_jouee == 1 && west_a_jouee == 0){
			not_carte_west = fopen("data/not_carte_west.txt", "r");

			if(not_carte_west != NULL){
				
				int caractere;

				while(( caractere = fgetc(not_carte_west)) != EOF){
					if( caractere == 'z'){
						printf("%s",symbole(cartes[nb_carte_jouee-1]));
					}
					else if( caractere == '1'){
						printf("%s",dictionnaire(cartes[nb_carte_jouee-1]));
					}else{printf("%c",caractere);}
				}

				printf("\n");

				fclose(not_carte_west);
			}
			else{
				printf(side_error" Ouverture du fichier not_carte_west.txt impossible");
			}
		}
		else{
			if(east_a_jouee == 0 && west_a_jouee == 1){
				not_carte_east = fopen("data/not_carte_east.txt", "r");

				if(not_carte_east != NULL){
					
					int caractere;

					while(( caractere = fgetc(not_carte_east)) != EOF){
						if( caractere == 'c'){
							printf("%s",symbole(cartes[nb_carte_jouee-1]));
						}
						else if( caractere == '0'){
							printf("%s",dictionnaire(cartes[nb_carte_jouee-1]));
						}else{printf("%c",caractere);}
					}

					printf("\n");

					fclose(not_carte_east);
				}
				else{
					printf(side_error" Ouverture du fichier not_carte_east.txt impossible");
				}
			}
			else{
				if(east_a_jouee == 1 && west_a_jouee == 1){

					carte_west_east = fopen("data/carte_west_east.txt", "r");

					if(carte_west_east != NULL){
						
						int caractere;

						if(ordre_jeu == 0){
							while(( caractere = fgetc(carte_west_east)) != EOF){
								if( caractere == 'c'){
									printf("%s",symbole(cartes[nb_carte_jouee-1]));
								}
								else if( caractere == '0'){
									printf("%s",dictionnaire(cartes[nb_carte_jouee-1]));
								}
								else if( caractere == 'z'){
									printf("%s",symbole(cartes[nb_carte_jouee-3]));
									
								}
								else if( caractere == '1'){
									printf("%s",dictionnaire(cartes[nb_carte_jouee-3]));
								}
								else{
									printf("%c",caractere);
								}
							}
						}
						else{
							while(( caractere = fgetc(carte_west_east)) != EOF){
								if( caractere == 'c'){
									printf("%s",symbole(cartes[nb_carte_jouee-3]));
								}
								else if( caractere == '0'){
									printf("%s",dictionnaire(cartes[nb_carte_jouee-3]));
								}
								else if( caractere == 'z'){
									printf("%s",symbole(cartes[nb_carte_jouee-1]));
									
								}
								else if( caractere == '1'){
									printf("%s",dictionnaire(cartes[nb_carte_jouee-1]));
								}
								else{
									printf("%c",caractere);
								}
							}
						}

						printf("\n");

						fclose(carte_west_east);
					}
					else{
						printf(side_error" Ouverture du fichier carte_west_east.txt impossible");
					}
				
				}
			}
		}
	}
}