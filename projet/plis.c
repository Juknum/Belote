#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"


void plis(int distributeur,int * cartes,int * cartes_west, int * cartes_north, int * cartes_east,  int * cartes_joueur, int nom_joueur){

//cartes_north[i];cartes_east[i];cartes_joueur[i];cartes_west[i]
int numero_pli = 1;
int joueur = 0;
int choix_joueur = 0;
int tableau_pli[3];
int tableau_pli_trie[3];
int tableau_atout[3];
int tableau_atout_trie[3];
int nb_atout = 0;
int atout_n = 0;





do{
	printf(" Début du pli numéro %d",numero_pli);
	switch(distributeur){
		case 1:
			joueur = 4;
			printf("\nLe premier joueur a jouer est Est");
			break;
		case 2:
			joueur = 1;
			printf("\nLe premier joueur a jouer est %s",nom_joueur);
			break;
		case 3:
			joueur = 2;
			printf("\nLe premier joueur a jouer est Ouest");
			break;
		case 4:
			joueur = 3;
			printf("\nLe premier joueur a jouer est Nord");
			break;
	}


	printf("\nAtout : %s",atout);

	if (atout = 'Carreau'){
			atout_n = 0;
	}
	if (atout = 'Coeur'){
			atout_n = 1;
	}
	if (atout = 'Pique'){
			atout_n = 2;
	}
	if (atout = 'Trèfle'){
			atout_n = 3;
	}

	while(nb_cartes_jouee == 4){

		switch(joueur){
			case 1:
				if(joueur == 1){

					printf("\nVotre tour:");

					printf(side_question"\nVos cartes :");
						for(int i = 0; i < 8-numero_pli; i++){
							printf(" %s",dictionnaire(cartes_joueur[i]));
						}

					printf("\nQue vous voulez vous jouer ?");
					scanf("%d",&choix_joueur);

		
					switch(choix_joueur){
						case 1 :
							tableau_pli[0] = cartes_joueur[0];
							cartes_joueur[0] = 0;
				
							break;
						case 2 :
							tableau_pli[0] = cartes_joueur[1];
							cartes_joueur[1] = 0;
					
							break;
						case 3 :
							tableau_pli[0] = cartes_joueur[2];
							cartes_joueur[2] = 0;
				
							break;
						case 4 :
							tableau_pli[0] = cartes_joueur[3];
							cartes_joueur[3] = 0;
				
							break;
						case 5 :
							tableau_pli[0] = cartes_joueur[4];
							cartes_joueur[4] = 0;
				
							break;
						case 6 :
							tableau_pli[0] = cartes_joueur[5];
							cartes_joueur[5] = 0;
				
							break;
						case 7 :
						tableau_pli[0] = cartes_joueur[6];
							cartes_joueur[6] = 0;
					
							break;
						case 8 :
							tableau_pli[0] = cartes_joueur[7];
							cartes_joueur[7] = 0;
							
							break;
					}
				}

				joueur++;

			case 2:
				bot_pli();
				joueur++;

				break;
			case 3:
				bot_pli();
				joueur++;

				break;
			case 4:
				bot_pli();
				joueur++;

				break;
		}

		nb_cartes_jouee++;
	}
	


	

	switch(atout_n){
		case 0:

			for(int i = 0, i < 4, i++){

				switch(tableau_pli[i]){
					case 0:

						for(int j = 1,j < 9,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 1:

						for(int j = 1,j < 9,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 2:

						for(int j = 1,j < 9,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 3:
						for(int j = 1,j < 9,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}					
				}
			}
		case 1:

			for(int i = 0, i < 4, i++){

				switch(tableau_pli[i]){
					case 0:

						for(int j = 9,j < 17,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 1:

						for(int j = 9,j < 17,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 2:

						for(int j = 9,j < 17,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 3:
						for(int j = 9,j < 17,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}					
				}
			}	
		case 2:

			for(int i = 0, i < 4, i++){

				switch(tableau_pli[i]){
					case 0:

						for(int j = 17,j < 25,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 1:

						for(int j = 17,j < 25,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 2:

						for(int j = 17,j < 25,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 3:
						for(int j = 17,j < 25,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}					
				}
			}
		case 3:

			for(int i = 0, i < 4, i++){

				switch(tableau_pli[i]){
					case 0:

						for(int j = 25,j < 33,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 1:

						for(int j = 25,j < 33,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
						}
					case 2:

						for(int j = 25,j < 33,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}
					case 3:
						for(int j = 25,j < 33,j++){
							if (dictionnaire(tableau_pli[i]) == j){
								tableau_atout[i] = tableau_pli[i];
								nb_atout++;
							}
						}					
				}
			}
	}


	for(int i = 0, i < 4, i++){
		tableau_pli_trie[i] = tableau_pli[i];
	}
	tableau_tri(* tableau_pli_trie);
	for(int i = 0, i < 4, i++){
		tableau_atout_trie[i] = tableau_atout[i];
	}
	tableau_tri(* tableau_atout_trie);

	if (nb_atout == 0){

			if (tableau_pli_trie[3] = tableau_pli[0]){
				printf("Vous gagnez le pli !");
			}
			if (tableau_pli_trie[3] = tableau_pli[1]){
				printf("Ouest gagne le pli !");
			}
			if (tableau_pli_trie[3] = tableau_pli[2]){
				printf("Nord gagnez le pli !");
			}
			if (tableau_pli_trie[3] = tableau_pli[3]){
				printf("Est gagne le pli !");
			}

		else{

			if (tableau_atout_trie[3] = tableau_atout[0]){
				printf("Vous gagnez le pli !");
			}
			if (tableau_atout_trie[3] = tableau_atout[1]){
				printf("Ouest gagne le pli !");
			}
			if (tableau_atout_trie[3] = tableau_atout[2]){
				printf("Nord gagnez le pli !");
			}
			if (tableau_atout_trie[3] = tableau_atout[3]){
				printf("Est gagne le pli !");
			}	
		}				
	}
	


	
	numero_pli++;
}while(numero_pli == 8);
