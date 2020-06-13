/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva 
	
	/////// CONTIENT DES SCANF A ACTIVER ///////

	enchere.c : Régit toutes les règles pour l'enchère et fait appel aux fonctions d'enchères des bots
		- Création des variables nécessaire pour la suite
		- Tant que l'atout n'est pas défini :
			- On fait choisir à l'IA (ou au joueur) à droite du distributeur de faire l'annonce d'un contrat ou non
				- Si IA : enchere_bot()
				- Si Joueur : On lui fait choisir les différentes options:
					- n°1 : la couleur 
					- n°2 : le type de contrat (80-160 / Capôt / Général)
				- SSI aucun n'a fait de contrat :
					- Ramasse les cartes (sans mélanger)
					- Redistribution et on recommence les enchères
		- Lorsque l'atout est choisi (un contrat a été fait) :
			- On fait le tour de la table pour savoir si les IA et le joueur veulent sur-encherir
				- Si IA : bot_surenchere()
				- Si Joueur :
					- On lui offre la possibilitée de passer ou d'annoncer mieux
						- On ne cherche pas à savoir s'il ment : ce serait de l'antijeu pour lui et son coéquipier
				- SSI Aucune sur-enchere : plis()
				- Si une surenchère est faite : on refait un tour de table (passe = 0 de nouveau)
					- Si aucune autre sur-enchère (seulement possible par le joueur) : plis()

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void enchere(int encherisseur, char *nom_joueur, int *cartes_joueur, int *cartes_west, int *cartes_north, int *cartes_east){

	char atout[20];							// Choix de l'atout pour la partie
	char contrat[30];				 		// Equipe qui annonce le contrat
	char team_north_south[30];
	int points = 0; 						// Points a atteindre pour remporter le contrat annoncé
	int passe  = 0; 						// Nombre de fois qu'un joueur passe

	int choix_annonce = 0;					// variables concernant les choix du joueur
	int choix_atout   = 0; 
	int choix_couleur = 0; 
	int choix_points  = 0;
	int choix_points_v= 0;

	int choix_surenchere = 0;
	int choix_couleur_surenchere = 0;
	int choix_points_surenchere = 0;

	int valid = 0;							// permet de savoir si la surenchere du joueur respecte les regles

	int distributeur = encherisseur;

	char info_txt_distrib[20];
	char info_txt_enchere[20];


	// Selon le distributeur on choisit qui a la possibilité d'enchérir en premier
	switch(distributeur){
		case 1:
			strcpy(info_txt_distrib, nom_joueur);
			strcpy(info_txt_enchere, "Ouest");
			break;
		case 2:
			strcpy(info_txt_distrib, "Ouest");
			strcpy(info_txt_enchere, "Nord");
			break;
		case 3:
			strcpy(info_txt_distrib, "Nord");
			strcpy(info_txt_enchere, "Est");
			break;
		case 4:
			strcpy(info_txt_distrib, "Est");
			strcpy(info_txt_enchere, nom_joueur);
			break;
	}

	// Affichage de la phase d'enchère
	printf(title_barre1);
	printf(title_barre_top1);
	printf(title_g"Phase d'Enchère"title_d);
	printf(title_barre_top2);
	printf(title_only);
	printf(title_info" %s distribue, %s encherit en premier!\n",info_txt_distrib,info_txt_enchere);
	printf(title_barre2);

	strcpy(atout, "undefined\0");

	// On assemble les deux chaînes pour former le nom d'équipe du contrat
	strcpy(team_north_south, "Nord/");
	strcat(team_north_south, nom_joueur);

	// On recommence tant qu'un contrat n'a pas été défini --> Si un contrat est défini, on passe à la surenchère
	while( strcmp(atout,"undefined\0") == 0){
		encherisseur++;
		
		// On remet a 1 car après Est (=4), c'est joueur (=1)
		if(encherisseur == 5){encherisseur = 1;}

		// DEBUG : Affiche les paramètres suivants : encherisseur & passe
		/*
		printf("\nencherisseur: %d",encherisseur);
		printf("\npasse       : %d",passe);
		printf("\n");
		*/

		// Selon l'encherisseur, soit les bots --> bot_enchere() | soit le joueur --> case 1
		switch(encherisseur){
			// JOUEUR :
			case 1:

				printf(side_jeu" %s examine son jeu...\n",nom_joueur);
				// On afiche les cartes du joueur
				afficher_carte(cartes_joueur, 1, 1);
				
				// Menu pour demander entre annoncer un contrat ou passer
				do{
					printf(side_only);
					printf(side_question" Souhaitez-vous annoncer un contrat ou passer?\n");
					printf(side_question" 1 | Annoncer\n");
					printf(side_question" 2 | Passer\n");
					printf(side_only);
					printf(side_question" Votre choix : "); 

					scanf("%d",&choix_annonce); 								// A ACTIVER
					//choix_annonce = 2; 										// A DESACTIVER 
				}while(choix_annonce < 1 || choix_annonce > 2);
				
				// On regarde ensuite le choix du joueur
				switch(choix_annonce){
					// Selon son annonce on propose un autre menu pour demander la couleur d'atout
					case 1:
						do{
							printf(side_only);
							printf(side_question" Quelle couleur?\n");
							printf(side_question" 1 | "carreau yellow" Carreau\n");
							printf(side_question" 2 | "coeur yellow" Coeur\n");
							printf(side_question" 3 | "pique yellow" Pique\n");
							printf(side_question" 4 | "trefle yellow" Trèfle\n");
							printf(side_only);
							printf(side_question" Votre choix : "); 

							scanf("%d",&choix_couleur); 						// A ACTIVER
						}while(choix_couleur < 1 || choix_couleur > 4);

						// On défini ensuite l'atout dans une chaîne (utile pour le reste des fonctions)
						switch(choix_couleur){
							case 1:
								strcpy(atout,"Carreau\0");
								break;
							case 2:
								strcpy(atout,"Coeur\0");
								break;
							case 3:
								strcpy(atout,"Pique\0");
								break;
							case 4:
								strcpy(atout,"Trèfle\0");
								break;
							default:
								printf(side_error" switch(%d) choix_couleur",choix_couleur);
								break;
							}

						// Menu d'annonce des points:
						printf(side_only);
						printf(side_question" Annoncez vos points:\n");
						printf(side_question" N | Classique - Entre "bold"80"nboldy" et "bold"160"nboldy" pts, par tranche de "bold"10"nboldy"!\n");
						printf(side_question" 1 | Capôt     - "bold"250"nboldy" pts -> remporter tout les plis\n");
						printf(side_question" 2 | Générale  - "bold"500"nboldy" pts -> remporter tout les plis a vous seul\n");
						printf(side_only);
						
						choix_goto:
						printf(side_question" Votre choix : "); 
						scanf("%d",&choix_points); // A ACTIVER
						
						// Le joueur choisi le nombre de points pour son contrat
						switch(choix_points){
							case 1 :
								printf(side_jeu" %s annonce "bold"Capôt"nboldw" avec une couleur de "bold"%s\n"nboldw,nom_joueur,atout);
								points = 250;
								strcpy(contrat, team_north_south);
								break;
							case 2 :
								printf(side_jeu" %s annonce "bold"Générale"nboldw" avec une couleur de "bold"%s\n"nboldw,nom_joueur,atout);
								points = 500;
								strcpy(contrat, team_north_south);
								break;
							case 80 ... 160 : 
								printf(side_jeu" %s annonce une couleur de "bold"%s"nboldw" avec "bold"%d"nboldw" pts\n",nom_joueur,atout,choix_points);
								points = (choix_points/10) * 10;
								strcpy(contrat, team_north_south);
								break;
							default:
								goto choix_goto;
								break;
						}

						break;
					case 2: // Le joueur décide de ne pas passer de contrat, on passe au joueur suivant
						printf(side_jeu" %s a choisit de passer son tours!\n",nom_joueur);
						passe++;
						break;
					default:
						printf(side_error" switch(%d) annonce/passer joueur choix_annonce",choix_annonce);
						break;
				}
				
				break;
			case 2:		// Ouest
				bot_enchere(cartes_west, "Ouest", atout, &points, &passe, contrat, team_north_south);
				break;
			case 3:		// Nord
				bot_enchere(cartes_north, "Nord", atout, &points, &passe, contrat, team_north_south);
				break;
			case 4:		// Est
				bot_enchere(cartes_east, "Est", atout, &points, &passe, contrat, team_north_south);
				break;
			default:
				printf(side_error" switch(%d) dans while(atout=%s)",encherisseur,atout);
		}

		// Si personne n'a décidé de passer de contrat, on ramasse les cartes puis on les redistribue
		if(passe > 3){
			passe = 0;
			printf(side_only);
			printf(barre_small);

			printf(side red" Personne n'a fait de contrat, on redistribue les cartes\n"white);
			
			ramasser(1,distributeur, nom_joueur, cartes_west, cartes_north, cartes_east, cartes_joueur);
			encherisseur = distributeur;

			printf(barre_small);
			printf(side_only);
		}
	}

	// Si un contrat est passé, on passe à la phase de sur-enchère
	if(strcmp(atout,"undefined\0") != 0){passe = 0; printf(side_jeu magenta" Phase de sur-enchère!\n"white);}

	// Tant qu'aucune sur-enchère n'est faite ou alors que personne a décider de sur-enchérir. Sinon on passe à plis()
	while(passe < 3 && strcmp(atout,"undefined\0") != 0){

		// Ici même fonctionnement que l'enchère simplement les joueurs voulant sur-enchérir doivent annoncer un contrat supérieur au précédent

		encherisseur++;

		if(encherisseur == 5){encherisseur = 1;}

		switch(encherisseur){
			case 1:
				printf(side_jeu" %s examine son jeu...\n",nom_joueur);
				afficher_carte(cartes_joueur, 1, 1);

				do{
					printf(side_only);
					printf(side_question" Souhaitez-vous sur-encherir ou passer?\n");
					printf(side_question" 1 | Sur-enchère\n");
					printf(side_question" 2 | Passer\n");
					printf(side_only);
					printf(side_question" Votre choix : ");

					scanf("%d",&choix_surenchere); 									// A ACTIVER
					//choix_surenchere = 2; 										// A DESACTIVER

				}while(choix_surenchere < 1 || choix_surenchere > 2);

				switch(choix_surenchere){
					case 1:

						// Annonce des points: 
						
						printf(side_only);
						printf(side_question" Annoncez vos points:\n");
						printf(side_question" N | Classique - Entre "bold"80"nboldy" et "bold"160"nboldy" pts, par tranche de 10!\n");
						printf(side_question" 1 | Capôt     - "bold"250"nboldy" pts -> gagner tout les plis\n");
						printf(side_question" 2 | Générale  - "bold"500"nboldy" pts -> doit gagner tout les plis a vous seul\n");
						printf(side_only);

						choix_goto_2:
						printf(side_question" Votre choix : ");
						scanf("%d",&choix_points_surenchere); // A ACTIVER
						
						// Vérification entre le contrat annoncé et le contrat précédent
						switch(choix_points_surenchere){
							case 1:
								if(points >= 250){
									// Le joueur ne respecte pas la regle de surenchere
									printf(side red" Vous devez annoncer plus que l'enchère précédente\n");
									valid = 0;
									goto choix_goto_2;
								}else{ valid = 1; points = 250;}

								break;
							case 2:
								if(points >= 500){
									// le joueur ne respecte pas les regles
									printf(side red" Vous devez annoncer plus que l'enchère précédente\n");
									valid = 0;
									goto choix_goto_2;
								}else{ valid = 1; points = 500;}
								
								break;
							case 80 ... 160:
								if(points >= choix_points_surenchere){
									printf(side red" Vous devez annoncer plus que l'enchère précédente\n");
									valid = 0;
									goto choix_goto_2;
								}else{ valid = 1; points = choix_points_surenchere;}

								break;
							default :
								goto choix_goto_2;
								break;
						}

						if(valid == 1){
							do{
								printf(side_question" Quelle couleur?\n");
								printf(side_question" 1 | "carreau yellow" Carreau\n");
								printf(side_question" 2 | "coeur yellow" Coeur\n");
								printf(side_question" 3 | "pique yellow" Pique\n");
								printf(side_question" 4 | "trefle yellow" Trèfle\n");
								printf(side_only);
								printf(side_question" Votre choix : ");

								scanf("%d",&choix_couleur); 							// A ACTIVER

							}while(choix_couleur < 1 || choix_couleur > 4);

							switch(choix_couleur){
								case 1:
									strcpy(atout,"Carreau\0");
									break;
								case 2:
									strcpy(atout,"Coeur\0");
									break;
								case 3:
									strcpy(atout,"Pique\0");
									break;
								case 4:
									strcpy(atout,"Trèfle\0");
									break;
								default:
									printf(side_error" Switch(%d) couleur surenchere",choix_couleur);
									break;
							}

							printf(side_jeu" %s sur-encherit avec une Couleur de "bold"%s"nboldw" avec "bold"%d"nboldw" pts!\n",nom_joueur,atout,points);
							strcpy(contrat, team_north_south);
							passe = 0;
						}

						break;
					case 2: // Le joueur décide de passer son tour pour la sur-enchère
						passe++;
						printf(side_jeu" %s a choisit de passer son tours!\n",nom_joueur);
						break;
					default:
						printf(side_error" while(passe < 3 && atout == undefined) switch(%d)",choix_surenchere);
						break;
				}

				break;
			case 2:
				bot_surenchere(cartes_west, "Ouest", atout, &points, &passe, contrat, team_north_south);
				
				break;
			case 3:
				bot_surenchere(cartes_north, "Nord", atout, &points, &passe, contrat, team_north_south);
				
				break;
			case 4:
				bot_surenchere(cartes_east, "Est", atout, &points, &passe, contrat, team_north_south);
				
				break;
			default:
				printf(side_error" switch(%d) dans while(%d) < 3 && %s",encherisseur,passe,atout);
				passe = 4;
				break;
		}
	}

	// On trie les cartes **après** les enchères et on lance les plis
	tableau_tri(cartes_joueur);
	tableau_tri(cartes_west);
	tableau_tri(cartes_north);
	tableau_tri(cartes_east);

	pause;
	
	clean;
	plis(contrat,points,distributeur,atout,cartes_west,cartes_north,cartes_east,cartes_joueur,nom_joueur);

}