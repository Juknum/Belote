/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	plis.c : Organise les 8 plis de la partie
		- Tant que le nb de plis != 9 :
			- on demande à celui qui à la main ce qu'il veut faire :
				- SSI c'est une IA : bot_plis()
				- SSI c'est le joueur : 
					- on affiche ses cartes avec afficher_cartes()
					- on demande et on regarde la carte qu'il prend
						- on ajoute cette carte dans cartes_plis (Cartes jouées pendant la manche)
						- on donne la valeur de -5 à l'emplacement de la carte jouée
						- on tri les cartes du joueur
						- on incrémente le nombre de carte jouée de 1
			- on regarde qui a posé la carte la plus forte et on lui donne les points du pli
			- on incrémente le nombre de plis de 1
				- Lorsque c'est le dernier pli, celui qui le remporte gagne 10 points supplémentaires (10 de der)
		- Lorsque les plis sont finis :
			- On calcul les points en fonction de si le contrat a été rempli ou non
			- On affiche l'écran de fin en fonction des résultats (si on perd/gagne)
			- On envoie nom_joueur et points_north_joueur à score_add()
			- On affiche les scores des 2 équipes
*/

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

	int ordre_jeu[4]     = {0};
	int cartes_plis[4]   = {0};
	int cartes_atout[4]  = {0};

	int nb_atout          = 0;
	int nb_atout_joueur   = 0;
	int nb_cartes_jouee   = 0;
	int nb_couleur_joueur = 0;
	int atout_n           = 0;

	int atout_joueur[8]   = {-10,-10,-10,-10,-10,-10,-10,-10};
	int couleur_joueur[8] = {-10,-10,-10,-10,-10,-10,-10,-10};

	int points_north_joueur = 0;
	int points_west_east    = 0;

	char team_north_joueur[30];
	char team_west_east[30];

	char* symbole = "x\0";

	strcpy(team_north_joueur, "Nord/");
	strcat(team_north_joueur, nom_joueur);
	strcpy(team_west_east, "Est/Ouest");

	// Les plis sont dans une boucle do while : Une boucle fait un pli et on incrémente le nombre de plis à la fin de cette boucle
		// On y sort lorsque le nombre de pli est de 8
	do{
		// Partie concernant l'entête
		printf(title_barre1);
		printf(title_barre_top1);
		printf(title_g" Phase de Jeu! "title_d);
		printf(title_pli_left"%d",numero_pli);
		printf(title_pli_right);

		// On traduit numériquement l'atout pour plus tard (1 = Pique, 2 = Carreau, ...)
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

		// Si on se trouve au premier pli on choisit qui commence en premier (celui se trouvant à droite du distributeur)
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

		// On réinitialise les variables entre chaque pli
		nb_atout = 0;
		nb_cartes_jouee = 0;
		nb_atout_joueur = 0;
		nb_couleur_joueur = 0;
		for(int k = 0; k < 4; k++){
			cartes_plis[k] = 0;
			cartes_atout[k] = 0;
		}
		for(int i = 0; i < 8; i++){
			atout_joueur[i] = -10;
			couleur_joueur[i] = -10;
		}

		// DEBUG : on affichege l'ordre de jeu
		/*
		printf(side" Ordre: ");
		for (int i = 0; i < 4; i++){
			printf("%d ",ordre_jeu[i]);
		}
		printf("\n");
		*/

		// Partie correspondant aux plis
		// Cette boucle while fait le tour des 4 cartes joueurs et organise le jeu du joueur
		while(nb_cartes_jouee != 4){

			if(depositaire==5){depositaire = 1;}

			// Switch choisissant le joueur qui doit jouer sachant quà chaque fois que quelqu'un a fini de jouer on incrémente dépositaire afin de passer au prochain
			switch(depositaire){

				case 1: // JOUEUR

					printf(side_jeu" %s examine son jeu...\n",nom_joueur);
					afficher_carte(cartes_joueur, numero_pli, 1);

					// Compte le nombre d'atout du joueur (utile pour faire respecter les règles au joueur)
					for(int i = 0; i < 8; i++){
						if(atout_n == 1 && (cartes_joueur[i] > 0 && cartes_joueur[i] <= 8)){
							nb_atout_joueur++;
							atout_joueur[i] = cartes_joueur[i];
						}
						if(atout_n == 2 && (cartes_joueur[i] > 8 && cartes_joueur[i] <= 16)){
							nb_atout_joueur++;
							atout_joueur[i] = cartes_joueur[i];
						}
						if(atout_n == 3 && (cartes_joueur[i] > 16 && cartes_joueur[i] <= 24)){
							nb_atout_joueur++;
							atout_joueur[i] = cartes_joueur[i];
						}
						if(atout_n == 4 && (cartes_joueur[i] > 24 && cartes_joueur[i] <= 32)){
							nb_atout_joueur++;
							atout_joueur[i] = cartes_joueur[i];
						}
					}

					/*
					printf("\nCarte atout joueur: ");
					for(int i = 0; i < 8; i++){
						printf("%d ",atout_joueur[i]);
					}
					printf("\n");
					*/

					// Ici on régit fait respecter les règles au joueur (tant qu'on est pas au dernier pli ou là il n'a pas le choix entre différentes cartes)
					if(numero_pli != 8){
						// si des atouts on été joués avant durant le pli
						if(nb_atout > 0){
							// Il a des atouts, il doit les jouer
							if(nb_atout_joueur > 0){
								printf(side_question" Quelle atout voulez-vous jouer ? Entrez son emplacement : ");
								scanf("%d",&choix_joueur);

								// Tant que le joueur ne respecte pas ces conditions il ne joue pas
								while(cartes_joueur[choix_joueur-1] == -5 || choix_joueur < 1 || choix_joueur > 8 || atout_joueur[choix_joueur-1] == -10){					
									printf(side red" Vous devez jouer un atout : "yellow);
									scanf("%d",&choix_joueur);
								}
							}
							else{
								// Si le joueur n'a pas d'atouts il joue la carte qu'il veut
								printf(side_question" Quelle carte voulez-vous jouer ? Entrez son emplacement : ");
								scanf("%d",&choix_joueur);
								while(cartes_joueur[choix_joueur-1] == -5 || choix_joueur < 1 || choix_joueur > 8){					
									printf(side red" Entrez une carte que vous possédez : "yellow);
									scanf("%d",&choix_joueur);
								}
							}
						}
						// Il n'y a pas d'atout joué ou il est le premier a jouer
							// soit il doit respecter la couleur ou poser un atout
							// soit il joue ce qu'il veut
						else{
							// Il n'est pas le premier à jouer --> soit respect de la couleur | soit il joue atout
							if(nb_cartes_jouee > 0){

								// DEBUG :
								/*
								for(int k=0; k<4; k++){
									printf("%d ",cartes_plis[k]);
								}
								*/
								
								// On regarde la première carte joué afin de connaître la couleur du pli et de le faire respecter au joueur après
									// On stock donc ses cartes de cette couleur dans un tableau
								switch(cartes_plis[0]){
									case 1 ... 8:
										for(int i = 0; i < 8; i++){
											if(cartes_joueur[i] > 0 && cartes_joueur[i] <= 8){
												couleur_joueur[i] = cartes_joueur[i];
												nb_couleur_joueur++;
											}
										}
										break;
									case 9 ... 16:
										for(int i = 0; i < 8; i++){
											if(cartes_joueur[i] > 8 && cartes_joueur[i] <= 16){
												couleur_joueur[i] = cartes_joueur[i];
												nb_couleur_joueur++;
											}
										}
										break;
									case 17 ... 24:
										for(int i = 0; i < 8; i++){
											if(cartes_joueur[i] > 16 && cartes_joueur[i] <= 24){
												couleur_joueur[i] = cartes_joueur[i];
												nb_couleur_joueur++;
											}
										}
										break;
									case 25 ... 32:
										for(int i = 0; i < 8; i++){
											if(cartes_joueur[i] > 24 && cartes_joueur[i] <= 32){
												couleur_joueur[i] = cartes_joueur[i];
												nb_couleur_joueur++;
											}
										}
										break;
									default :
										printf(side_error" prblm switch");
										break;
								}

								/*
								printf("\nCarte couleur joueur: ");
								for(int i = 0; i < 8; i++){
									printf("%d ",couleur_joueur[i]);
								}
								printf("\n");
								*/

								// Le joueur a une ou plusieurs carte(s) de la couleur du pli et une ou plusieurs carte(s) atout(s)
								if(nb_atout_joueur != 0 || nb_couleur_joueur != 0){
									printf(side_question" Quelle carte voulez-vous jouer ? Entrez son emplacement : ");
									scanf("%d",&choix_joueur);

									while(cartes_joueur[choix_joueur-1] == -5 || choix_joueur < 1 || choix_joueur > 8 || (atout_joueur[choix_joueur-1] == -10 && couleur_joueur[choix_joueur-1] == -10)){					
										printf(side red" Vous devez jouer la couleur ou un atout : "yellow);
										scanf("%d",&choix_joueur);
									}
								}
								// Le joueur ne remplit aucune des deux conditons citées précédemment
									// Il joue ce qu'il veut
								else{
									printf(side_question" Quelle carte voulez-vous jouer ? Entrez son emplacement : ");
									scanf("%d",&choix_joueur);

									while(cartes_joueur[choix_joueur-1] == -5 || choix_joueur < 1 || choix_joueur > 8){					
										printf(side red" Entrez une carte que vous possédez : "yellow);
										scanf("%d",&choix_joueur);
									}
								}
								
							}
							// Le joueur est le premier à jouer, il joue donc ce qu'il veut 
							else{
								printf(side_question" Quelle carte voulez-vous jouer ? Entrez son emplacement : ");
								scanf("%d",&choix_joueur);

								while(cartes_joueur[choix_joueur-1] == -5 || choix_joueur < 1 || choix_joueur > 8){					
									printf(side red" Entrez une carte que vous possédez : "yellow);
									scanf("%d",&choix_joueur);
								}
							}
								
						}
					}
					// Dernier pli, il joue sa dernière carte automatiquement sans possibilité de choisir
					else{
						choix_joueur = 8;
					}
					
					printf(side_only);

					// On fait jouer sa carte
					cartes_plis[nb_cartes_jouee] = cartes_joueur[choix_joueur-1];
					cartes_joueur[choix_joueur-1] = -5;

					// On incrémente le nombre des cartes jouées pour ensuite sortir de la boucle lorsque le pli est terminé
					nb_cartes_jouee++;

					// On vérifie si la carte jouée est un atout pour incrémenter la valeur du nombre d'atout (utile dans la décision des bots)
					atout_add(nb_cartes_jouee, atout_n, cartes_plis, cartes_atout, &nb_atout);

					// On trie les cartes du joueur
					tableau_tri(cartes_joueur);

					
					break;
				
				// Il y a ensuite le tour des bots qui se fait via la fonction bot_pli()
					// On incrémente aussi le nombre d'atout si le bot en joue un et le nombre de cartes jouées
				case 2:
		
					bot_plis("Ouest", cartes_west, nb_cartes_jouee, atout_n, cartes_plis, cartes_atout);
					nb_cartes_jouee++;
					atout_add(nb_cartes_jouee, atout_n, cartes_plis, cartes_atout, &nb_atout);
					break;
				case 3:
					
					bot_plis("Nord", cartes_north, nb_cartes_jouee, atout_n, cartes_plis, cartes_atout);
					nb_cartes_jouee++;
					atout_add(nb_cartes_jouee, atout_n, cartes_plis, cartes_atout, &nb_atout);
					break;
				case 4:

					bot_plis("Est", cartes_east, nb_cartes_jouee, atout_n, cartes_plis, cartes_atout);
					nb_cartes_jouee++;
					atout_add(nb_cartes_jouee, atout_n, cartes_plis, cartes_atout, &nb_atout);
					break;
			}
			// La variable "depositaire" est incrémentée pour faire passer au tour du prochain joueur
			depositaire++;

			// DEBUG : affiche le tableau des cartes jouées étant des atouts:
			/*
			printf(side" Cartes atout durant la manche:");
			for(int i = 0; i < 4; i++){
				printf(" %s",dictionnaire(cartes_atout[i]));
			}
			printf("\n");
			*/
		}
		// Affiche les cartes jouées pendant le pli
		afficher_carte(cartes_plis, 0, 2);

		// On va ensuite regarder qui remporte le pli en comparant la valeur des cartes et en vérifiant si un ou plusieurs atouts ont été joués

		// Si personne n'a joué atout -> la 1ere carte la plus haute l'emporte
		if(nb_atout == 0){
			// si la 1ere est plus grande ou identique à celle d'après
			if(dictionnaire_non_atout(cartes_plis[0]) >= dictionnaire_non_atout(cartes_plis[1]) && dictionnaire_non_atout(cartes_plis[0]) >= dictionnaire_non_atout(cartes_plis[2]) && dictionnaire_non_atout(cartes_plis[0]) >= dictionnaire_non_atout(cartes_plis[3])){
				depositaire = ordre_jeu[0];
			}
			else{
				// sinon si la 2e est plus grande ou identique à celles d'après
				if(dictionnaire_non_atout(cartes_plis[1]) >= dictionnaire_non_atout(cartes_plis[2]) && dictionnaire_non_atout(cartes_plis[1]) >= dictionnaire_non_atout(cartes_plis[3])){
					depositaire = ordre_jeu[1];
				}
				else{
					// sinon si la 3e est plus grande ou identique à celle d'après
					if(dictionnaire_non_atout(cartes_plis[2]) >= dictionnaire_non_atout(cartes_plis[3])){
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
			if(dictionnaire_atout(cartes_atout[0]) > dictionnaire_atout(cartes_atout[1]) && dictionnaire_atout(cartes_atout[0]) > dictionnaire_atout(cartes_atout[2]) && dictionnaire_atout(cartes_atout[0]) > dictionnaire_atout(cartes_atout[3])){
				depositaire = ordre_jeu[0];
			}
			// Si la deuxième carte posée est la plus haute:
			if(dictionnaire_atout(cartes_atout[1]) > dictionnaire_atout(cartes_atout[0]) && dictionnaire_atout(cartes_atout[1]) > dictionnaire_atout(cartes_atout[2]) && dictionnaire_atout(cartes_atout[1]) > dictionnaire_atout(cartes_atout[3])){
				depositaire = ordre_jeu[1];
			}
			// ...
			if(dictionnaire_atout(cartes_atout[2]) > dictionnaire_atout(cartes_atout[0]) && dictionnaire_atout(cartes_atout[2]) > dictionnaire_atout(cartes_atout[1]) && dictionnaire_atout(cartes_atout[2]) > dictionnaire_atout(cartes_atout[3])){
				depositaire = ordre_jeu[2];
			}
			// ...
			if(dictionnaire_atout(cartes_atout[3]) > dictionnaire_atout(cartes_atout[0]) && dictionnaire_atout(cartes_atout[3]) > dictionnaire_atout(cartes_atout[1]) && dictionnaire_atout(cartes_atout[3]) > dictionnaire_atout(cartes_atout[2])){
				depositaire = ordre_jeu[3];
			}
		}

		// A la fin du pli on va compter le score du pli et ensuite attribuer ce score au score de l'équipe qui a remporté le pli
			// On redonne aussi l'ordre du jeu selon le joueur qui a remporté le pli afin de le faire jouer en premier au prochain
		switch(depositaire){
			case 1:
				printf(side_jeu" %s remporte le pli\n",nom_joueur);
				ordre_jeu[0] = 1;
				ordre_jeu[1] = 2;
				ordre_jeu[2] = 3;
				ordre_jeu[3] = 4;
				for(int i = 0; i < 4; i++){
					if(cartes_atout[i] == 0 || cartes_atout[i] == -10){
						points_north_joueur += dictionnaire_non_atout(cartes_plis[i]);
					}
					else{
						points_north_joueur += dictionnaire_atout(cartes_plis[i]); 
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
					if(cartes_atout[i] == 0 || cartes_atout[i] == -10){
						points_west_east += dictionnaire_non_atout(cartes_plis[i]);
					}
					else{
						points_west_east += dictionnaire_atout(cartes_plis[i]); 
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
					if(cartes_atout[i] == 0 || cartes_atout[i] == -10){
						points_north_joueur += dictionnaire_non_atout(cartes_plis[i]);
					}
					else{
						points_north_joueur += dictionnaire_atout(cartes_plis[i]); 
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
					if(cartes_atout[i] == 0 || cartes_atout[i] == -10){
						points_west_east += dictionnaire_non_atout(cartes_plis[i]);
					}
					else{
						points_west_east += dictionnaire_atout(cartes_plis[i]); 
					}
				}
				if(numero_pli == 8){ points_west_east += 10;}
				break;
		}
		
		// On incrémente le nombre de pli
		numero_pli++;

		// Barre de chargement avant l'affichage du prochain pli
		printf("£ Load... £\n");
		for(int i = 0; i < 2; i++){ // a mettre sur 210 pour laisser du temps entre chaque pli
			if(i%2 == 0){
				printf("=");
			}
			pause_load; // 10ms
		}
		printf("\n");

		//clean;

	}while(numero_pli != 9);

	// Affichage de la fin de partie

	printf(title_barre1);
	printf(title_barre_top1);
	printf(title_g"Fin de partie !"title_d);
	printf(title_barre_top2);
	printf(title_only);

	// Si le contrat est prit par Nord/Sud(joueur) et qu'il ont atteint le nombre de points annoncées, la partie est gagnée
	// sinon c'est est/ouest qui gagnent
	if((strcmp(contrat, team_west_east) == 0 && points_west_east < points) || (strcmp(contrat, team_north_joueur) == 0 && points_north_joueur >= points)){
		printf(end_gagne1);
		printf(end_gagne2);
		printf(end_gagne3);
		printf(end_gagne4);
		printf(end_gagne5);
		printf(end_gagne6);

		// si team west/east n'ont pas remplis leur contrat
		if(strcmp(contrat, team_west_east) == 0){
			points_north_joueur = 162 + points;
			// Enregistrement des scores dans score.txt
			score_add(points_north_joueur, nom_joueur);
		}
		// si on rempli notre contrat
		else{
			points_north_joueur += points;
			// Enregistrement des scores dans score.txt
			score_add(points_north_joueur, nom_joueur);
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

	// Affichage des scores finaux et d'un menu permettant au joueur de recommencer, de revenir au menu (consulter les scores) ou de quitter

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