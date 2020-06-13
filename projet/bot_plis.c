#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void bot_plis(char* nom_bot, int* cartes_bot, int nb_cartes_jouee, int atout, int* cartes_plis, int* cartes_atout){

	int nb_atout_bot     = 0;												// Nombre d'atouts possédés par le bot
	int pos_carte_jouee  = 0;												// Position de la carte choisie (entre 0 et 7)
	int carte_jouee      = 0;												// Valeur (entre 1 et 32) de la carte jouee
	int is_atout	     = 0;												// == 1 si un atout a déjà été posé

	int cartes_atout_triee[4]   = {-10,-10,-10,-10};						// Valeur d'atout de l'atout le plus élevé joué pendant le plis
	int cartes_couleur_triee[4] = {-10,-10,-10,-10};						// De meme avec les couleurs

	int couleur	   = 0;														// Prend une valeur entre 1 et 4 si aucun atout n'est joué
	int nb_couleur = 0;

	int cartes_bot_val[8]       = {-10,-10,-10,-10,-10,-10,-10,-10};		// Valeurs non_atout des cartes du bot
	int cartes_bot_atout_val[8] = {-10,-10,-10,-10,-10,-10,-10,-10};		// Valeurs atout des cartes du bot
	int cartes_bot_couleur[8]   = {-10,-10,-10,-10,-10,-10,-10,-10};		// Cartes couleur du bot selon la couleur jouée (seulement si aucun atout n'a été joué)

	printf(side_jeu" %s examine son jeu...",nom_bot);
	
	switch(atout){
		// Pique est atout
		case 1:
			// On compte le nombre d'atouts possédés par le bot
			// On associe les pts atout a cartes_bot_atout_val
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 0 && cartes_bot[i] <= 8){
					nb_atout_bot++;

					cartes_bot_atout_val[i] = dictionnaire_atout(cartes_bot[i]);
				}
				else{
					if(cartes_bot[i] == -5){
						cartes_bot_val[i] = -5;
					}
					else{
						cartes_bot_val[i] = dictionnaire_non_atout(cartes_bot[i]);
					}
				}
			}
			// On regarde les cartes jouées pour savoir si on doit ou non jouer atout
			for(int k = 0; k < 4; k++){
				if(cartes_plis[k] > 0 && cartes_plis[k] <= 8){is_atout = 1;}
			}
			break;
		// Carreau est atout
		case 2:
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 8 && cartes_bot[i] <= 16){
					nb_atout_bot++;

					cartes_bot_atout_val[i] = dictionnaire_atout(cartes_bot[i]);
				}
				else{
					if(cartes_bot[i] == -5){
						cartes_bot_val[i] = -5;
					}
					else{
						cartes_bot_val[i] = dictionnaire_non_atout(cartes_bot[i]);
					}
				}
			}
			for(int k = 0; k < 4; k++){
				if(cartes_plis[k] > 8 && cartes_plis[k] <= 16){is_atout = 1;}
			}
			break;
		// Coeur est atout
		case 3:
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 16 && cartes_bot[i] <= 24){
					nb_atout_bot++;

					cartes_bot_atout_val[i] = dictionnaire_atout(cartes_bot[i]);
				}
				else{
					if(cartes_bot[i] == -5){
						cartes_bot_val[i] = -5;
					}
					else{
						cartes_bot_val[i] = dictionnaire_non_atout(cartes_bot[i]);
					}
				}
			}
			for(int k = 0; k < 4; k++){
				if(cartes_plis[k] > 16 && cartes_plis[k] <= 24){is_atout = 1;}
			}
			break;
		// Trefle est atout
		case 4:
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 24 && cartes_bot[i] <= 32){
					nb_atout_bot++;

					cartes_bot_atout_val[i] = dictionnaire_atout(cartes_bot[i]);
				}
				else{
					if(cartes_bot[i] == -5){
						cartes_bot_val[i] = -5;
					}
					else{
						cartes_bot_val[i] = dictionnaire_non_atout(cartes_bot[i]);
					}
				}
			}			
			for(int k = 0; k < 4; k++){
				if(cartes_plis[k] > 24 && cartes_plis[k] <= 32){is_atout = 1;}
			}
			break;
	}

	if(is_atout == 0){
		switch(cartes_plis[0]){
			case 0 ... 8 :
				couleur = 1;
				break;
			case 9 ... 16:
				couleur = 2;
				break;
			case 17 ... 24:
				couleur = 3;
				break;
			case 25 ... 32:
				couleur = 4;
				break;
			default:
				printf(side_error" la premiere carte n'est pas entre 1 et 32");
				break;
		}
	}

	//printf(side" couleur = %d\n",couleur);


	// Debug : Affiche les tableau
	/*
	afficher_carte(cartes_bot, 1, 1);
	printf("\nCartes bot          : ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_bot[i]);
	}
	printf("\nCartes bot val      : ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_bot_val[i]);
	}
	printf("\nCartes bot atout val: ");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_bot_atout_val[i]);
	}
	printf("\n");
	printf("is_atout = %d\n",is_atout);
	*/

	// Premier a jouer
	if(nb_cartes_jouee == 0){
		// Si le bot possède des atouts, il pose son atout le + faible
		if(nb_atout_bot > 0){

			// dans ce cas on tri son jeu en fonction de ses pts d'atout
			tableau_tri_slaves(cartes_bot_atout_val, cartes_bot_val, cartes_bot);

			// Debug : Affiche les tableau
			/*
			printf("\nCartes bot          : ");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot[i]);
			}
			printf("\nCartes bot val      : ");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot_val[i]);
			}
			printf("\nCartes bot atout val: ");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot_atout_val[i]);
			}
			printf("\n");
			*/

			// On parcourt ses cartes atout triées jusqu'à prendre la première diff de -10
			do{
				pos_carte_jouee++;
			}while(cartes_bot_atout_val[pos_carte_jouee] == -10);

			carte_jouee = cartes_bot[pos_carte_jouee];
			cartes_bot[pos_carte_jouee] = -5;
		}
		// le bot n'a pas d'atout
		else{

			// On tri le jeu du bot en fonction de ses valeurs non atout;
			tableau_tri_slave(cartes_bot_val, cartes_bot);

			// Debug : Affiche les tableau
			/*
			printf("\nCartes bot          : ");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot[i]);
			}
			printf("\nCartes bot val      : ");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot_val[i]);
			}
			printf("\n");
			*/

			do{
				pos_carte_jouee++;
			}while(cartes_bot_val[pos_carte_jouee] == -10 || cartes_bot_val[pos_carte_jouee] == -5);

			carte_jouee = cartes_bot[pos_carte_jouee];
			cartes_bot[pos_carte_jouee] = -5;
		}
	}
	// Le bot n'est pas le 1er a jouer
	else{
		// Si un atout a été posé
		if(is_atout == 1){

			// On sauvegarde les atout du plis pour pouvoir les mélanger sans changer qui les a joués
			for(int k = 0; k < 4; k++){
				cartes_atout_triee[k] = dictionnaire_atout(cartes_atout[k]);
			}
			// L'atout le + fort se trouve en [3]
			tableau_tri(cartes_atout_triee);

			tableau_tri_slave(cartes_bot_atout_val, cartes_bot);

			// DEBUG : affiche les atout du plis triés
			/*
			printf(" atout du plis trié :");
			for(int k = 0; k < 4; k++){
				printf("%d ",cartes_atout_triee[k]);
			}
			printf("\n atout du plis    :");
			for(int k = 0; k < 4; k++){
				printf("%d ",cartes_atout[k]);
			}
			printf("\n atout bot        :");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot_atout_val[i]);
			}
			*/

			// Le bot possède des atouts
			if(nb_atout_bot > 0){
				for(int i = 0; i < 8; i++){
					if(cartes_bot_atout_val[i] != -10 && cartes_bot_atout_val[i] > dictionnaire_atout(cartes_atout_triee[3])){
						carte_jouee = cartes_bot[i];
						cartes_bot[i] = -5;
						i = 7;
					}
				}

				// si il n'a aucun atout plus fort que celui posé (plus faible atout joué)
				if(carte_jouee == 0){
					tableau_tri_slave(cartes_bot_atout_val, cartes_bot);

					do{
						pos_carte_jouee++;
					}while(cartes_bot_atout_val[pos_carte_jouee] == -10);

					carte_jouee = cartes_bot[pos_carte_jouee];
					cartes_bot[pos_carte_jouee] = -5;
				}
			}
			// Le bot n'a pas d'atout (il joue sa carte la + faible)
			else{
				tableau_tri_slave(cartes_bot_val, cartes_bot);

				do{
					pos_carte_jouee++;
				}while(cartes_bot_val[pos_carte_jouee] == -10 || cartes_bot_val[pos_carte_jouee] == -5);

				carte_jouee = cartes_bot[pos_carte_jouee];
				cartes_bot[pos_carte_jouee] = -5;
			}
		}
		// Si aucun atout n'a été posé
		else{

			// S'il a des atouts il pose le + faible
			if(nb_atout_bot > 0){
				tableau_tri_slave(cartes_bot_atout_val, cartes_bot);

				do{
					pos_carte_jouee++;
				}while(cartes_bot_atout_val[pos_carte_jouee] == -10);

				carte_jouee = cartes_bot[pos_carte_jouee];
				cartes_bot[pos_carte_jouee] = -5;

			}
			// Sinon il pose la couleur adéquate
			else{
				// On remplie le tableau de couleur selon la couleur jouée précédement
				switch(couleur){
					// Pique
					case 1:
						for(int i = 0; i < 8; i++){
							if(cartes_bot[i] > 0 && cartes_bot[i] <= 8){
								cartes_bot_couleur[i] = cartes_bot[i];
							}
						}
						break;
					// Carreau
					case 2:
						for(int i = 0; i < 8; i++){
							if(cartes_bot[i] > 8 && cartes_bot[i] <= 16){
								cartes_bot_couleur[i] = cartes_bot[i];
							}
						}
						break;
					// Coeur
					case 3:
						for(int i = 0; i < 8; i++){
							if(cartes_bot[i] > 16 && cartes_bot[i] <= 24){
								cartes_bot_couleur[i] = cartes_bot[i];
							}
						}
						break;
					// Trefle
					case 4:
						for(int i = 0; i < 8; i++){
							if(cartes_bot[i] > 24 && cartes_bot[i] <= 32){
								cartes_bot_couleur[i] = cartes_bot[i];
							}
						}
						break;
				}

				for(int i = 0; i < 8; i++){
					if(cartes_bot_couleur[i] != -10){
						nb_couleur++;
					}
				}

				// Il a des cartes dans la couleur à jouer
				if(nb_couleur > 0){
					for(int k = 0; k < 4; k++){
						switch(cartes_plis[k]){
							case 1 ... 8:
								if(couleur == 1){
									cartes_couleur_triee[k] = cartes_plis[k];
								}
								break;
							case 9 ... 16:
								if(couleur == 2){
									cartes_couleur_triee[k] = cartes_plis[k];
								}
								break;
							case 17 ... 24:
								if(couleur == 3){
									cartes_couleur_triee[k] = cartes_plis[k];
								}
								break;
							case 25 ... 32:
								if(couleur == 4){
									cartes_couleur_triee[k] = cartes_plis[k];
								}
								break;
						}
					}

					tableau_tri(cartes_couleur_triee);

					tableau_tri_slave(cartes_bot_couleur, cartes_bot);

					// DEBUG : affiche les couleurs triées:
					/*
					printf(" couleur triée: ");
					for(int k = 0; k < 4; k++){
						printf("%d ",cartes_couleur_triee[k]);
					}
					*/

					do{
						pos_carte_jouee++;
					}while(cartes_bot_couleur[pos_carte_jouee] <= cartes_couleur_triee[3]);

					carte_jouee = cartes_bot[pos_carte_jouee];
					cartes_bot[pos_carte_jouee] = -5;

				}
				// Il n'a pas de cartes de la couleur du plis
				else{
					tableau_tri_slave(cartes_bot_val, cartes_bot);

					do{
						pos_carte_jouee++;
					}while(cartes_bot_val[pos_carte_jouee] == -5 || cartes_bot_val[pos_carte_jouee] == -10);

					carte_jouee = cartes_bot[pos_carte_jouee];
					cartes_bot[pos_carte_jouee] = -5;
				}

				// DEBUG :
				/*
				printf("\n carte couleur : ");
				for (int i = 0; i < 8; i++){
					printf("%d ",cartes_bot_couleur[i]);
				}
				*/
			}
		}
	}

	//printf("\ncarte choisie : %d ",carte_jouee);
	cartes_plis[nb_cartes_jouee] = carte_jouee;
	afficher_carte(cartes_plis, nb_cartes_jouee, 0);
}