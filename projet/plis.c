#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"


void plis(char* contrat, int points, int distributeur, char * atout, int * cartes_west, int * cartes_north, int * cartes_east, int * cartes_joueur, char * nom_joueur){

	int numero_pli  = 1;
	int depositaire = 0;

	int choix_joueur = 0;
	int choix = 0;

	int ordre_jeu[4] = {0};
	int tableau_pli[4]   = {0};
	int tableau_atout[4] = {0};

	int nb_atout        = 0;
	int nb_cartes_jouee = 0;
	int atout_n         = 0;

	int points_north_joueur = 0;
	int points_west_east    = 0;

	char team_north_joueur[30];
	char team_west_east[30];

	char* symbole = "x\0";

	strcpy(team_north_joueur, "Nord/");
	strcat(team_north_joueur, nom_joueur);
	strcpy(team_west_east, "Est/Ouest");

	do{
		// Partie concernant l'entête
		printf(title_barre1);
		printf(title_barre_top1);
		printf(title_g" Phase de Jeu! "title_d);
		printf(title_pli_left"%d",numero_pli);
		printf(title_pli_right);

		if(strcmp(atout, "Pique") == 0){
			atout_n = 1;
			symbole = pique;
		}
		if(strcmp(atout, "Carreau") == 0){
			atout_n = 2;
			symbole = carreau;
		}
		if(strcmp(atout, "Coeur") == 0){
			atout_n = 3;
			symbole = coeur;
		}
		if(strcmp(atout, "Trèfle") == 0){
			atout_n = 4;
			symbole = trefle;
		}

		printf(title_info" - Atout  : %s %s\n",atout,symbole);
		printf(title_ninfo" - Contrat: %s (%d pts)\n",contrat,points);
		printf(title_ninfo" - Nord/%s : %d\n",nom_joueur,points_north_joueur);
		printf(title_ninfo" - Ouest/Est : %d\n",points_west_east);
		printf(title_barre2);
		printf(side_only);

		if(numero_pli == 1){
			switch(distributeur){
				case 1:
					depositaire = 4;
					ordre_jeu[0] = 4;
					ordre_jeu[1] = 1;
					ordre_jeu[2] = 2;
					ordre_jeu[3] = 3;
					printf(side_info" Est joue en 1er\n");
					break;
				case 2:
					depositaire = 1;
					ordre_jeu[0] = 1;
					ordre_jeu[1] = 2;
					ordre_jeu[2] = 3;
					ordre_jeu[3] = 4;
					printf(side_info" %s joue en 1er\n",nom_joueur);
					break;
				case 3:
					depositaire = 2;
					ordre_jeu[0] = 2;
					ordre_jeu[1] = 3;
					ordre_jeu[2] = 4;
					ordre_jeu[3] = 1;
					printf(side_info" Ouest joue en 1er\n");
					break;
				case 4:
					depositaire = 3;
					ordre_jeu[0] = 3;
					ordre_jeu[1] = 4;
					ordre_jeu[2] = 1;
					ordre_jeu[3] = 2;
					printf(side_info" Nord joue en 1er\n");
					break;
			}
		}

		// On réinitialise les variables entre chaque plis
		nb_atout = 0;
		nb_cartes_jouee = 0;
		for(int i = 0; i < 4; i++){
			tableau_pli[i] = 0;
			tableau_atout[i] = 0;
		}

		// DEBUG : on affichege l'ordre de jeu
		/*
		printf(side" Ordre: ");
		for (int i = 0; i < 4; i++){
			printf("%d ",ordre_jeu[i]);
		}
		printf("\n");
		*/

		// Partie correspondant au plis
		while(nb_cartes_jouee != 4){

			if(depositaire==5){depositaire = 1;}

			switch(depositaire){
				case 1:
					printf(side_jeu" %s examine son jeu...\n",nom_joueur);
					afficher_carte(cartes_joueur);

					do{
						printf(side_question" Quelle carte voulez-vous jouer ? Entrez son emplacement : ");
						scanf("%d",&choix_joueur);

						while(cartes_joueur[choix_joueur-1] == -5){					
							printf(side red" Entrez une carte que vous possédez : "yellow);
							scanf("%d",&choix_joueur);
						}

					}while(choix_joueur < 1 || choix_joueur > 8);

					printf(side_only);

					switch(choix_joueur){
						case 1 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[0];
							cartes_joueur[0] = -5;
							break;
						case 2 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[1];
							cartes_joueur[1] = -5;
							break;
						case 3 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[2];
							cartes_joueur[2] = -5;
							break;
						case 4 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[3];
							cartes_joueur[3] = -5;
							break;
						case 5 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[4];
							cartes_joueur[4] = -5;
							break;
						case 6 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[5];
							cartes_joueur[5] = -5;
							break;
						case 7 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[6];
							cartes_joueur[6] = -5;
							break;
						case 8 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[7];
							cartes_joueur[7] = -5;
							break;
						default:
							break;
					}
					// On vérifie si la carte jouée et un atout
					atout_add(nb_cartes_jouee, atout_n, tableau_pli, tableau_atout, &nb_atout);

					printf(side" Vos cartes désormais :");
					for(int i = 0; i < 8; i++){
						printf(" %s",dictionnaire(cartes_joueur[i]));
					}
					printf("\n"side_only);

					nb_cartes_jouee++;
					break;

				case 2:
					bot_plis("Ouest", cartes_west, nb_cartes_jouee, tableau_pli);
					// On vérifie si la carte jouée et un atout à chaque fois que quelqu'un pose (et non pas juste à la fin)
					atout_add(nb_cartes_jouee, atout_n, tableau_pli, tableau_atout, &nb_atout);
					nb_cartes_jouee++;
					break;
				case 3:
					bot_plis("Nord", cartes_north, nb_cartes_jouee, tableau_pli);
					atout_add(nb_cartes_jouee, atout_n, tableau_pli, tableau_atout, &nb_atout);
					nb_cartes_jouee++;
					break;
				case 4:
					bot_plis("Est", cartes_east, nb_cartes_jouee, tableau_pli);
					atout_add(nb_cartes_jouee, atout_n, tableau_pli, tableau_atout, &nb_atout);
					nb_cartes_jouee++;
					break;
			}
			depositaire++;

			// DEBUG : affiche le tableau des cartes jouées étant des atouts:
			/*
			printf(side" Cartes atout durant la manche:");
			for(int i = 0; i < 4; i++){
				printf(" %s",dictionnaire(tableau_atout[i]));
			}
			printf("\n");
			*/
		}
		// DEBUG : affiche le tableau des cartes jouées:
		printf(side" Cartes jouées durant la manche:");
		for(int i = 0; i < 4; i++){
			printf(" %s",dictionnaire(tableau_pli[i]));
		}
		printf("\n");

		// Si personne n'a joué atout -> la 1ere carte la plus haute l'emporte
		if(nb_atout == 0){
			// si la 1ere est plus grande ou identique à celles d'après
			if(dictionnaire_non_atout(tableau_pli[0]) >= dictionnaire_non_atout(tableau_pli[1]) && dictionnaire_non_atout(tableau_pli[0]) >= dictionnaire_non_atout(tableau_pli[2]) && dictionnaire_non_atout(tableau_pli[0]) >= dictionnaire_non_atout(tableau_pli[3])){
				depositaire = ordre_jeu[0];
			}
			else{
				// sinon si la 2e est plus grande ou identique à celles d'après
				if(dictionnaire_non_atout(tableau_pli[1]) >= dictionnaire_non_atout(tableau_pli[2]) && dictionnaire_non_atout(tableau_pli[1]) >= dictionnaire_non_atout(tableau_pli[3])){
					depositaire = ordre_jeu[1];
				}
				else{
					// sinon si la 3e est plus grande ou identique à celle d'après
					if(dictionnaire_non_atout(tableau_pli[2]) >= dictionnaire_non_atout(tableau_pli[3])){
						depositaire = ordre_jeu[2];
					}
					// sinon la 3e est plus grande
					else{
						depositaire = ordre_jeu[3];
					}
				}
			}
		}
		else{
			// Si le premiere carte posée est la plus haute:
			if(dictionnaire_atout(tableau_atout[0]) > dictionnaire_atout(tableau_atout[1]) && dictionnaire_atout(tableau_atout[0]) > dictionnaire_atout(tableau_atout[2]) && dictionnaire_atout(tableau_atout[0]) > dictionnaire_atout(tableau_atout[3])){
				depositaire = ordre_jeu[0];
			}
			if(dictionnaire_atout(tableau_atout[1]) > dictionnaire_atout(tableau_atout[0]) && dictionnaire_atout(tableau_atout[1]) > dictionnaire_atout(tableau_atout[2]) && dictionnaire_atout(tableau_atout[1]) > dictionnaire_atout(tableau_atout[3])){
				depositaire = ordre_jeu[1];
			}
			if(dictionnaire_atout(tableau_atout[2]) > dictionnaire_atout(tableau_atout[0]) && dictionnaire_atout(tableau_atout[2]) > dictionnaire_atout(tableau_atout[1]) && dictionnaire_atout(tableau_atout[2]) > dictionnaire_atout(tableau_atout[3])){
				depositaire = ordre_jeu[2];
			}
			if(dictionnaire_atout(tableau_atout[3]) > dictionnaire_atout(tableau_atout[0]) && dictionnaire_atout(tableau_atout[3]) > dictionnaire_atout(tableau_atout[1]) && dictionnaire_atout(tableau_atout[3]) > dictionnaire_atout(tableau_atout[2])){
				depositaire = ordre_jeu[3];
			}
		}
		switch(depositaire){
			case 1:
				printf(side_jeu" %s remporte le pli\n",nom_joueur);
				ordre_jeu[0] = 1;
				ordre_jeu[1] = 2;
				ordre_jeu[2] = 3;
				ordre_jeu[3] = 4;
				for(int i = 0; i < 4; i++){
					if(tableau_atout[i] == 0){
						points_north_joueur += dictionnaire_non_atout(tableau_pli[i]);
					}
					else{
						points_north_joueur += dictionnaire_atout(tableau_pli[i]); 
					}
				}
				if(numero_pli == 8){ points_north_joueur += 10;}
				break;
			case 2:
				printf(side_jeu" Ouest remporte le pli\n");
				ordre_jeu[0] = 2;
				ordre_jeu[1] = 3;
				ordre_jeu[2] = 4;
				ordre_jeu[3] = 1;
				for(int i = 0; i < 4; i++){
					if(tableau_atout[i] == 0){
						points_west_east += dictionnaire_non_atout(tableau_pli[i]);
					}
					else{
						points_west_east += dictionnaire_atout(tableau_pli[i]); 
					}
				}
				if(numero_pli == 8){ points_west_east += 10;}
				break;
			case 3:
				printf(side_jeu" Nord remporte le pli\n");
				ordre_jeu[0] = 3;
				ordre_jeu[1] = 4;
				ordre_jeu[2] = 1;
				ordre_jeu[3] = 2;
				for(int i = 0; i < 4; i++){
					if(tableau_atout[i] == 0){
						points_north_joueur += dictionnaire_non_atout(tableau_pli[i]);
					}
					else{
						points_north_joueur += dictionnaire_atout(tableau_pli[i]); 
					}
				}
				if(numero_pli == 8){ points_north_joueur += 10;}
				break;
			case 4:
				printf(side_jeu" Est remporte le pli\n");
				ordre_jeu[0] = 4;
				ordre_jeu[1] = 1;
				ordre_jeu[2] = 2;
				ordre_jeu[3] = 3;
				for(int i = 0; i < 4; i++){
					if(tableau_atout[i] == 0){
						points_west_east += dictionnaire_non_atout(tableau_pli[i]);
					}
					else{
						points_west_east += dictionnaire_atout(tableau_pli[i]); 
					}
				}
				if(numero_pli == 8){ points_west_east += 10;}
				break;
		}
		
		numero_pli++;

		// barre de chargement avant l'affichage du prochain pli
		printf("£ Load... £\n");
		for(int i = 0; i < 210; i++){
			if(i%2 == 0){
				printf("=");
			}
			pause_load; // 10ms
		}
		printf("\n");

		//clean;

	}while(numero_pli != 9);

	printf(title_barre1);
	printf(title_barre_top1);
	printf(title_g"Fin de partie !"title_d);
	printf(title_barre_top2);
	printf(title_only);

	// Si le contrat est prit par Nord/Sud(joueur) et qu'il a atteint le nombre de pts annoncée, la partie est gagnée
	// sinon c'est est/ouest qui gagne
	if((strcmp(contrat, team_west_east) == 0 && points_west_east < points) || (strcmp(contrat, team_north_joueur) == 0 && points_north_joueur >= points)){
		printf(end_gagne1);
		printf(end_gagne2);
		printf(end_gagne3);
		printf(end_gagne4);
		printf(end_gagne5);
		printf(end_gagne6);

		// si team west/east non pas rempli leur contrat
		if(strcmp(contrat, team_west_east) == 0){
			points_north_joueur = 162 + points;
		}
		// si on rempli notre contrat
		else{
			points_north_joueur += points;
		}
	}
	else{
		printf(end_perdu1);
		printf(end_perdu2);
		printf(end_perdu3);
		printf(end_perdu4);
		printf(end_perdu5);
		printf(end_perdu6);

		if(strcmp(contrat, team_north_joueur) == 0){
			points_west_east = 162 + points;
		}
		else{
			points_west_east += points;
		}
	}

	printf(title_only);
	printf(title_barre2);

	// Enregistrement des scores dans score.txt
	score_add(points_north_joueur, nom_joueur);

	printf(side_info" Scores Finaux: \n");
	printf(side"        %d - Est/Ouest\n",points_west_east);
	printf(side"        %d - %s\n",points_north_joueur,team_north_joueur);
	printf(side_only);

	printf(side_question" Que voulez-vous faire?\n");
	printf(side_question" 1 | Rejouer\n");
	printf(side_question" 2 | Menu\n");
	printf(side_question" 3 | Quitter\n");
	printf(side_only);

	do{
		printf(side_question" Votre choix : ");
		scanf("%d",&choix);
	}while(choix < 1 || choix > 3);

	switch(choix){
		case 1:
			clean;
			nouvelle_partie();
		case 2:
			clean;
			menu();
		case 3:
			printf(reset);
			clean;
			exit(0);
	}
}