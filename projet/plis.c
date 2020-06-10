#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"


void plis(int distributeur, char * atout, int * cartes_west, int * cartes_north, int * cartes_east, int * cartes_joueur, char * nom_joueur){

	//cartes_north[i];cartes_east[i];cartes_joueur[i];cartes_west[i]
	int numero_pli = 1;
	int depositaire = 0;

	int choix_joueur = 0;

	int tableau_pli[3];
	int tableau_pli_trie[3];
	int tableau_atout[3];
	int tableau_atout_trie[3];

	int nb_atout = 0;
	int atout_n = 0;
	char* symbole = "x\0";

	int nb_cartes_jouee = 0;

	do{
		printf(title_barre);
		printf(title_barre_top);
		printf(title_g" Phase de Jeu! "title_d);
		printf(title_barre_top);
		printf(title_barre);

		printf(side" Début du pli numéro %d/8\n",numero_pli);

		if(strcmp(atout, "Carreau") == 0){
			atout_n = 0;
			symbole = carreau;
		}
		if(strcmp(atout, "Coeur") == 0){
			atout_n = 1;
			symbole = coeur;
		}
		if(strcmp(atout, "Pique") == 0){
			atout_n = 2;
			symbole = pique;
		}
		if(strcmp(atout, "Trèfle") == 0){
			atout_n = 3;
			symbole = trefle;
		}

		printf(side" Atout : %s %s\n",atout,symbole);

		switch(distributeur){
			case 1:
				depositaire = 4;
				printf(side" Le meneur est Est\n");
				break;
			case 2:
				depositaire = 1;
				printf(side" Le meneur est %s\n",nom_joueur);
				break;
			case 3:
				depositaire = 2;
				printf(side" Le meneur est Ouest\n");
				break;
			case 4:
				depositaire = 3;
				printf(side" Le meneur est Nord\n");
				break;
		}

		while(nb_cartes_jouee != 4){
			switch(depositaire){
				case 1:
					printf("\nVotre tour:");
					printf(side_question"\nVos cartes :");
						for(int i = 0; i < 8-numero_pli; i++){
							printf(" %s",dictionnaire(cartes_joueur[i]));
						}
					printf(side_question" Que vous voulez vous jouer ?");
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

					printf(side_question"\nVos cartes désormais :");
					for(int i = 0; i < 8-numero_pli; i++){
						printf(" %s",dictionnaire(cartes_joueur[i]));
					}
					
					depositaire++;

					break;

				case 2:
					bot_plis();
					depositaire++;

					break;
				case 3:
					bot_plis();
					depositaire++;

					break;
				case 4:
					bot_plis();
					depositaire++;

					break;
			}

			nb_cartes_jouee++;
		}
		
		switch(atout_n){
			case 0:
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 0:
							for(int j = 1;j < 9;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 1:
							for(int j = 1;j < 9;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 2:
							for(int j = 1;j < 9;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 3:
							for(int j = 1;j < 9;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;				
					}
				}
				break;
			case 1:
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 0:
							for(int j = 9;j < 17;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 1:
							for(int j = 9;j < 17;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 2:
							for(int j = 9;j < 17;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 3:
							for(int j = 9;j < 17;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;			
					}
				}
				break;	
			case 2:
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 0:
							for(int j = 17;j < 25;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 1:
							for(int j = 17;j < 25;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 2:
							for(int j = 17;j < 25;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 3:
							for(int j = 17;j < 25;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;				
					}
				}
				break;
			case 3:
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 0:
							for(int j = 25;j < 33;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 1:
							for(int j = 25;j < 33;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 2:
							for(int j = 25;j < 33;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;
						case 3:
							for(int j = 25;j < 33;j++){
								if(dictionnaire_atout(tableau_pli[i]) == j){
									tableau_atout[i] = tableau_pli[i];
									nb_atout++;
								}
							}
							break;				
					}
				}
				break;
		}
		

		for(int i = 0; i < 4; i++){
			tableau_pli_trie[i] = tableau_pli[i];
		}
		tableau_tri(tableau_pli_trie);
		for(int i = 0; i < 4; i++){
			tableau_atout_trie[i] = tableau_atout[i];
		}
		tableau_tri(tableau_atout_trie);

		if(nb_atout == 0){
			if(tableau_pli_trie[3] = tableau_pli[0]){
				printf(side_jeu"%s gagnez le pli !\n",nom_joueur);
			}
			if(tableau_pli_trie[3] = tableau_pli[1]){
				printf(side_jeu"Ouest gagne le pli !\n");
			}
			if(tableau_pli_trie[3] = tableau_pli[2]){
				printf(side_jeu"Nord gagne le pli !\n");
			}
			if(tableau_pli_trie[3] = tableau_pli[3]){
				printf(side_jeu"Est gagne le pli !\n");
			}
		}
		else{
			if(tableau_atout_trie[3] = tableau_atout[0]){
				printf(side_jeu"%s gagnez le pli !\n",nom_joueur);
			}
			if(tableau_atout_trie[3] = tableau_atout[1]){
				printf(side_jeu"Ouest gagne le pli !\n");
			}
			if(tableau_atout_trie[3] = tableau_atout[2]){
				printf(side_jeu"Nord gagne le pli !\n");
			}
			if(tableau_atout_trie[3] = tableau_atout[3]){
				printf(side_jeu"Est gagne le pli !\n");
			}					
		}
		
		numero_pli++;

	}while(numero_pli != 8);
}
