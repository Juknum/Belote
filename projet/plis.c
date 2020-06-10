#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"


void plis(int points, int distributeur, char * atout, int * cartes_west, int * cartes_north, int * cartes_east, int * cartes_joueur, char * nom_joueur){

	int numero_pli  = 1;
	int depositaire = 0;

	int ordre_jeu[4] = {0};

	int choix_joueur = 0;

	int tableau_pli[4]   = {0};
	int tableau_atout[4] = {0};

	int nb_atout        = 0;
	int nb_cartes_jouee = 0;
	int atout_n         = 0;

	char* symbole = "x\0";

	// Partie concernant l'entête
	printf(title_barre);
	printf(title_barre_top);
	printf(title_g" Phase de Jeu! "title_d);
	printf(title_barre_top);
	printf(title_info" - Plis   : %d/8\n",numero_pli);

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

	printf(title_ninfo" - Atout  : %s %s\n",atout,symbole);
	printf(title_ninfo" - Points : %d\n",points);

	switch(distributeur){
		case 1:
			depositaire = 4;
			ordre_jeu[0] = 4;
			ordre_jeu[1] = 1;
			ordre_jeu[2] = 2;
			ordre_jeu[3] = 3;
			printf(title_ninfo" - Est dépose en 1er\n");
			break;
		case 2:
			depositaire = 1;
			ordre_jeu[0] = 1;
			ordre_jeu[1] = 2;
			ordre_jeu[2] = 3;
			ordre_jeu[3] = 4;
			printf(title_ninfo" - %s dépose en 1er\n",nom_joueur);
			break;
		case 3:
			depositaire = 2;
			ordre_jeu[0] = 2;
			ordre_jeu[1] = 3;
			ordre_jeu[2] = 4;
			ordre_jeu[3] = 1;
			printf(title_ninfo" - Ouest dépose en 1er\n");
			break;
		case 4:
			depositaire = 3;
			ordre_jeu[0] = 3;
			ordre_jeu[1] = 4;
			ordre_jeu[2] = 1;
			ordre_jeu[3] = 2;
			printf(title_ninfo" - Nord dépose en 1er\n");
			break;
		}

	printf(title_barre);
	printf(side_only);

	do{
		// On réinitialise les variables entre chaque plis
		nb_atout = 0;
		nb_cartes_jouee = 0;
		for(int i = 0; i < 4; i++){
			tableau_pli[i] = 0;
			tableau_atout[i] = 0;
		}

		// DEBUG : on affichege l'ordre de jeu
		printf(side" Ordre: ");
		for (int i = 0; i < 4; i++){
			printf("%d ",ordre_jeu[i]);
		}
		printf("\n");

		// Partie correspondant au plis
		while(nb_cartes_jouee != 4){

			if(depositaire==5){depositaire = 1;}

			switch(depositaire){
				case 1:
					printf(side_jeu" %s examine son jeu ...\n",nom_joueur);
					printf(side_only side" Vos cartes :");
						for(int i = 0; i < 8; i++){
							printf(" %s",dictionnaire(cartes_joueur[i]));
						}
					printf("\n"side_only);

					do{
						printf(side_question" Quelle carte voulez-vous jouer ? Entrez son emplacement : ");
						scanf("%d",&choix_joueur);
						do{
							printf("Entrez des cartes que vous possédez :");
							scanf("%d",&choix_joueur);
						}while(cartes_joueur[choix_joueur] == 0);
					}while(choix_joueur < 0 || choix_joueur > 8);

					printf(side_only);

					switch(choix_joueur){
						case 1 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[0];
							cartes_joueur[0] = 0;
							break;
						case 2 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[1];
							cartes_joueur[1] = 0;
							break;
						case 3 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[2];
							cartes_joueur[2] = 0;
							break;
						case 4 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[3];
							cartes_joueur[3] = 0;
							break;
						case 5 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[4];
							cartes_joueur[4] = 0;
							break;
						case 6 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[5];
							cartes_joueur[5] = 0;
							break;
						case 7 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[6];
							cartes_joueur[6] = 0;
							break;
						case 8 :
							tableau_pli[nb_cartes_jouee] = cartes_joueur[7];
							cartes_joueur[7] = 0;
							break;
						default:
							break;
					}

					printf(side" Vos cartes désormais :");
					for(int i = 0; i < 8; i++){
						printf(" %s",dictionnaire(cartes_joueur[i]));
					}
					printf("\n"side_only);

					nb_cartes_jouee++;
					break;

				case 2:
					bot_plis("Ouest", cartes_west, nb_cartes_jouee, tableau_pli);
					nb_cartes_jouee++;
					break;
				case 3:
					bot_plis("Nord", cartes_north, nb_cartes_jouee, tableau_pli);
					nb_cartes_jouee++;
					break;
				case 4:
					bot_plis("Est", cartes_east, nb_cartes_jouee, tableau_pli);
					nb_cartes_jouee++;
					break;
			}

			depositaire++;

			// DEBUG : affiche le nombre de carte jouées
			//printf("nb carte %d\n",nb_cartes_jouee);

			// DEBUG : affiche le tableau des cartes jouées:
			printf(side" Cartes jouées durant la manche:");
			for(int i = 0; i < 4; i++){
				printf(" %s",dictionnaire(tableau_pli[i]));
			}
			printf("\n");
		}

		// Compte du nombre d'atout
		switch(atout_n){
			case 1: // Pique est atout
				// On regarde les cartes jouées et on compte le nbr d'atouts
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 1 ... 8 :
							nb_atout++;
							tableau_atout[i] = tableau_pli[i];
							break;
						default:
							break;
					}
				}
				break;
			case 2: // Carreau est atout
				// On regarde les cartes jouées et on compte le nbr d'atouts
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 9 ... 16 :
							nb_atout++;
							tableau_atout[i] = tableau_pli[i];
							break;
						default:
							break;
					}
				}
				break;
			case 3: // Coeur est atout
				// On regarde les cartes jouées et on compte le nbr d'atouts
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 17 ... 24 :
							nb_atout++;
							tableau_atout[i] = tableau_pli[i];
							break;
						default:
							break;
					}
				}
				break;
			case 4: // Trefle est atout
				// On regarde les cartes jouées et on compte le nbr d'atouts
				for(int i = 0; i < 4; i++){
					switch(tableau_pli[i]){
						case 25 ... 32 :
							nb_atout++;
							tableau_atout[i] = tableau_pli[i];
							break;
						default:
							break;
					}
				}
				break;
			default:
				printf(side_error" switch(%d) atout_n",atout_n);
				break;
		}

		// DEBUG : affiche le tableau des cartes jouées étant des atouts:
		printf(side" Cartes atout durant la manche:");
		for(int i = 0; i < 4; i++){
			printf(" %s",dictionnaire(tableau_atout[i]));
		}
		printf("\n");

		// Si personne n'a joué atout -> la carte la plus haute l'emporte
		// Problème éventuel si 2 carte de meme valeur mais de couleurs différente
			// Ne gene pas le programme, juste un problème d'équité
		if(nb_atout == 0){
			if(tableau_pli[0] > tableau_pli[1] && tableau_pli[0] > tableau_pli[2] && tableau_pli[0] > tableau_pli[3]){
				depositaire = ordre_jeu[0];
			}
			if(tableau_pli[1] > tableau_pli[0] && tableau_pli[1] > tableau_pli[2] && tableau_pli[1] > tableau_pli[3]){
				depositaire = ordre_jeu[1];
			}
			if(tableau_pli[2] > tableau_pli[1] && tableau_pli[2] > tableau_pli[0] && tableau_pli[2] > tableau_pli[3]){
				depositaire = ordre_jeu[2];
			}
			if(tableau_pli[3] > tableau_pli[1] && tableau_pli[3] > tableau_pli[2] && tableau_pli[3] > tableau_pli[0]){
				depositaire = ordre_jeu[3];
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
			if(dictionnaire_atout(tableau_atout[3]) > dictionnaire_atout(tableau_atout[0]) && dictionnaire_atout(tableau_atout[3]) > dictionnaire_atout(tableau_atout[2]) && dictionnaire_atout(tableau_atout[3]) > dictionnaire_atout(tableau_atout[1])){
				depositaire = ordre_jeu[3];
			}
		}
		switch(depositaire){
			case 1:
				printf(side_jeu" %s remporte le plis\n",nom_joueur);
				ordre_jeu[0] = 1;
				ordre_jeu[1] = 2;
				ordre_jeu[2] = 3;
				ordre_jeu[3] = 4;
				break;
			case 2:
				printf(side_jeu" Ouest remporte le plis\n");
				ordre_jeu[0] = 2;
				ordre_jeu[1] = 3;
				ordre_jeu[2] = 4;
				ordre_jeu[3] = 1;
				break;
			case 3:
				printf(side_jeu" Nord remporte le plis\n");
				ordre_jeu[0] = 3;
				ordre_jeu[1] = 4;
				ordre_jeu[2] = 1;
				ordre_jeu[3] = 2;
				break;
			case 4:
				printf(side_jeu" Est remporte le plis\n");
				ordre_jeu[0] = 4;
				ordre_jeu[1] = 1;
				ordre_jeu[2] = 2;
				ordre_jeu[3] = 3;
				break;
		}
		
		numero_pli++;

	}while(numero_pli != 9);
}