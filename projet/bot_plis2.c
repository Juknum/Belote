#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void bot_plis2(char* nom_bot, int* cartes_bot, int nb_cartes_jouee, int atout_n, int* cartes_plis, int* cartes_atout){

	int nb_atout      = 0;		 		// nbr d'atout possédé par le bot
	int nb_atout_plis = 0;				// nbr d'atout posé dans le plis

	int cartes_atout_bot[8]     = {0};	// tableau des atouts possédés
	int cartes_atout_bot_val[8] = {0};	// tableau de la valeurs des atouts possédés

	int cartes_plis_val[4]		= {-1,-1,-1,-1};	// Valeur d'atout des cartes du plis (uniquement les atouts)

	int cartes_bot_val[8]		= {0};  // tableau de la valeurs de toute les cartes en non atout

	int carte_jouee = 0;				// valeur entre 1 et 32 de la carte jouée par le bot

	int aucun_atout_pg  = 1;
	int aucune_carte_pg = 0;

	printf(side_jeu" %s Examine son jeu...",nom_bot);

	pause;

	// DEBUG : Affiche les cartes du bot
	/*
	printf("\nCartes du bot :\n");
	afficher_carte(cartes_bot, 1, 1);
	*/

	// On détermine en fonction de l'atout.. :
	switch(atout_n){
		// Pique
		case 1:
			// les pts des atouts présent dans le plis
			for(int i = 0; i < nb_cartes_jouee; i++){
				if(cartes_plis[i] > 0 && cartes_plis[i] <= 8){
					cartes_plis_val[i] = dictionnaire_atout(cartes_plis[i]);
					nb_atout_plis++;
				}
			}
			for(int i = 0; i < 8; i++){
				// On sépare l'atout dans un tableau a part
				// On sépare la valeur de cet atout dans un tableau aussi a part
				if(cartes_bot[i] > 0 && cartes_bot[i] <= 8){	
					cartes_atout_bot[i]     = cartes_bot[i];
					// On différencie le 7,8 qui valent 0 en atout
					if(cartes_bot[i] == 1){ // 7
						cartes_atout_bot_val[i] = 1;
					}
					else{
						if(cartes_bot[i] == 2){ // 8 
							cartes_atout_bot_val[i] = 2;
						}else{
							cartes_atout_bot_val[i] = dictionnaire_atout(cartes_bot[i]); 
						}
					}
					nb_atout++;
				}
			}
		break;
		// Carreau
		case 2:
			// les pts des atouts présent dans le plis
			for(int i = 0; i < nb_cartes_jouee; i++){
				if(cartes_plis[i] > 8 && cartes_plis[i] <= 16){
					cartes_plis_val[i] = dictionnaire_atout(cartes_plis[i]);
					nb_atout_plis++;
				}
			}
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 8 && cartes_bot[i] <= 16){	
					cartes_atout_bot[i]     = cartes_bot[i];
					// On différencie le 7,8 qui valent 0 en atout
					if(cartes_bot[i] == 9){ // 7
						cartes_atout_bot_val[i] = 1;
					}
					else{
						if(cartes_bot[i] == 10){ // 8 
							cartes_atout_bot_val[i] = 2;
						}else{
							cartes_atout_bot_val[i] = dictionnaire_atout(cartes_bot[i]); 
						}
					}
					nb_atout++;
				}
			}
		break;
		// Coeur
		case 3:
			// les pts des atouts présent dans le plis
			for(int i = 0; i < nb_cartes_jouee; i++){
				if(cartes_plis[i] > 16 && cartes_plis[i] <= 24){
					cartes_plis_val[i] = dictionnaire_atout(cartes_plis[i]);
					nb_atout_plis++;
				}
			}
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 16 && cartes_bot[i] <= 24){
					cartes_atout_bot[i]     = cartes_bot[i];
					// On différencie le 7,8 qui valent 0 en atout
					if(cartes_bot[i] == 17){ // 7
						cartes_atout_bot_val[i] = 1;
					}
					else{
						if(cartes_bot[i] == 18){ // 8 
							cartes_atout_bot_val[i] = 2;
						}else{
							cartes_atout_bot_val[i] = dictionnaire_atout(cartes_bot[i]); 
						}
					}
					nb_atout++;
				}
			}
		break;
		// Trefle
		case 4:
			// les pts des atouts présent dans le plis
			for(int i = 0; i < nb_cartes_jouee; i++){
				if(cartes_plis[i] > 24 && cartes_plis[i] <= 32){
					cartes_plis_val[i] = dictionnaire_atout(cartes_plis[i]);
					nb_atout_plis++;
				}
			}
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] > 24 && cartes_bot[i] <= 32){	
					cartes_atout_bot[i]     = cartes_bot[i];
					// On différencie le 7,8 qui valent 0 en atout
					if(cartes_bot[i] == 25){ // 7
						cartes_atout_bot_val[i] = 1;
					}
					else{
						if(cartes_bot[i] == 26){ // 8 
							cartes_atout_bot_val[i] = 2;
						}else{
							cartes_atout_bot_val[i] = dictionnaire_atout(cartes_bot[i]); 
						}
					}
					nb_atout++;
				}
			}
		break;
	}

	// De façon globale (sert lorsqu'il ne possède aucun atout)
	for(int i = 0; i < 8; i++){
		// On différencie le 7 du 8 du 9
		if(cartes_bot[i] == 1 || cartes_bot[i] == 9 || cartes_bot[i] == 17 || cartes_bot[i] == 25){
			cartes_bot_val[i] = -1;
		}
		else{
			if(cartes_bot[i] == 2 || cartes_bot[i] == 10 || cartes_bot[i] == 18 || cartes_bot[i] == 26){
				cartes_bot_val[i] = 0;
			}
			else{
				if(cartes_bot[i] == 3 || cartes_bot[i] == 11 || cartes_bot[i] == 19 || cartes_bot[i] == 27){
					cartes_bot_val[i] = 1;
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
		}
	}

	// DEBUG :
	/*
	printf("Cartes bot\n");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_bot[i]);
	}
	printf("\nCartes bot val\n");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_bot_val[i]);
	}
	printf("\nCartes atout bot\n");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_atout_bot[i]);
	}
	printf("\nCartes atout bot val\n");
	for(int i = 0; i < 8; i++){
		printf("%d ",cartes_atout_bot_val[i]);
	}
	printf("\nCartes plis val si atout:\n");
	for(int i = 0; i < 4; i++){
		printf("%d ",cartes_plis_val[i]);
	}
	printf("\n");
	*/

	// le bot est le 1er à jouer
	if(nb_cartes_jouee == 0){
		//printf(side" 1er a jouer\n");

		// Pas d'atout : Il joue sa carte la + petite
		if(nb_atout == 0){
			// DEBUG : permet de savoir ou on en est
			//printf(side" %s n'a pas d'atouts!\n",nom_bot);

			// on tri son jeu de non atout et il joue la plus petite carte :
			tableau_tri_slave(cartes_bot_val, cartes_bot);

			// DEBUG :
			/*
			printf("Cartes bot\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot[i]);
			}
			printf("\nCartes bot val\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot_val[i]);
			}
			*/

			for(int i = 0; i < 8; i++){
				if(cartes_bot_val[i] != -5){
					carte_jouee = cartes_bot[i];
					cartes_bot[i] = -5;
					i = 7;
				}

			}

		}
		// Atout : Il joue son atout le + petit
		else{
			// DEBUG : permet de savoir ou on en est
			//printf(side"%s a %d atouts\n",nom_bot,nb_atout);

			// on tri toutes les cartes en fonction de ses valeur atout (pour ne pas perdre la position de la carte)
			tableau_tri_slave(cartes_atout_bot_val, cartes_bot);

			// DEBUG :
			/*
			printf("\nCartes bot\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot[i]);
			}
			printf("\nCartes atout bot\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_atout_bot[i]);
			}
			printf("\nCartes atout bot val\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_atout_bot_val[i]);
			}
			*/

			for(int i = 0; i < 8; i++){
				if(cartes_atout_bot_val[i] != 0){
					carte_jouee   = cartes_bot[i];
					cartes_bot[i] = -5;
					i = 7;
				}
			}

			tableau_tri(cartes_bot);
		}
	}
	// Le bot joue après quelqu'un
	else{
		//printf(side" 2e ou + a jouer\n");
		if(nb_atout == 0){
			// DEBUG : permet de savoir ou on en est
			//printf(side" %s n'a pas d'atouts!\n",nom_bot);

			tableau_tri_slave(cartes_bot_val, cartes_bot);

			for(int i = 0; i < 8; i++){
				// Si la carte d'avant est un atout on joue la carte la + petite possible
				if( cartes_plis_val[nb_cartes_jouee-1] != -1){
					if( cartes_bot[i] != -5 ){
						carte_jouee = cartes_bot[i];
						cartes_bot[i] = -5;
						i = 7;
					}
				}
				// Sinon on joue qqchose de meme hauteur ou +
				else{
					if(dictionnaire_non_atout(cartes_bot[i]) >= dictionnaire_non_atout(cartes_plis[nb_cartes_jouee-1])){
						if( cartes_bot[i] != -5 ){
							carte_jouee = cartes_bot[i];
							cartes_bot[i] = -5;
							i = 7;
						}
					}
					// sinon on joue sa carte la + petite
					else{
						aucune_carte_pg = 1;
					}
				}
				
			}

			// sinon on joue sa carte la + petite
			if(aucune_carte_pg == 1){
				tableau_tri_slave(cartes_bot_val, cartes_bot);
				for(int i = 0; i < 0; i++){
					if(cartes_bot_val[i] != -5){
						carte_jouee   = cartes_bot[i];
						cartes_bot[i] = -5;
						i = 7;
					}
				}
			}

		}
		// Il est obligé de jouer son + petit atout possible
		else{
			// DEBUG : permet de savoir ou on en est
			//printf(side"%s a %d atouts\n",nom_bot,nb_atout);

			// on tri toutes les cartes en fonction de ses valeur atout (pour ne pas perdre la position de la carte)
			tableau_tri_slave(cartes_atout_bot_val, cartes_bot);

			// DEBUG :
			/*
			printf("\nCartes bot\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_bot[i]);
			}
			printf("\nCartes atout bot\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_atout_bot[i]);
			}
			printf("\nCartes atout bot val\n");
			for(int i = 0; i < 8; i++){
				printf("%d ",cartes_atout_bot_val[i]);
			}
			*/

			for(int i = 0; i < 8; i++){
				
				// Si aucun atout n'a été posé on joue le + petit atout
				if( nb_atout_plis == 0 ){
					if( cartes_atout_bot_val[i] > 0){
						carte_jouee = cartes_bot[i];
						cartes_bot[i] = -5;

						aucun_atout_pg = 0;
						i = 7;
					}
				}
				else{
					// Si la carte précédente est un atout et que la carte regardée est + haute :
					if( cartes_atout_bot_val[i] > cartes_plis_val[nb_cartes_jouee-1] && cartes_plis_val[nb_cartes_jouee-1] != -1){
						carte_jouee = cartes_bot[i];
						cartes_bot[i] = -5;

						aucun_atout_pg = 0;
						i = 7;
					}
				}
			}
			
			// Si aucun atout qu'il possède n'est plus grand que ceux posés :
			// il pose la carte la + petite de son deck
			if(aucun_atout_pg == 1){
				tableau_tri_slave(cartes_bot_val, cartes_bot);

				// DEBUG :
				/*
				printf("\nCartes bot\n");
				for(int i = 0; i < 8; i++){
					printf("%d ",cartes_bot[i]);
				}
				printf("\nCartes bot val\n");
				for(int i = 0; i < 8; i++){
					printf("%d ",cartes_bot_val[i]);
				}
				*/
				
				for(int i = 0; i < 8; i++){
					if(cartes_bot_val[i] != -5){
						carte_jouee   = cartes_bot[i];
						cartes_bot[i] = -5;
						i = 7;
					}
				}
			}
			
		}
	}

	// DEBUG : 
	//printf(" carte joue : %d",carte_jouee);

	cartes_plis[nb_cartes_jouee] = carte_jouee;
	afficher_carte(cartes_plis, nb_cartes_jouee, 0);

	pause;
}