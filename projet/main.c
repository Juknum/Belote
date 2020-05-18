/*

		BELOTE COINCHEE EN C : Groupe F
		- Julien Constant
		- Théo Silva

*/

#include "./fonctions/fonctions.h"

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

/* 
	Permet le changement de la table des caractères de la console 
	> si le programme est utilisé sous Windows
*/
#ifdef _WIN32
#include <windows.h>
#endif

//////////////////// VARIABLES GLOBALBES ////////////////////

// Joueur :
char * nom_joueur = "name_undefined";

// Scores max:
int score_max_1;	// A recuperer dans un fichier .txt
int score_max_2;
int score_max_3;

// Jeux de cartes (non trié) et mains des joueurs:
int cartes[32] = {1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32};
int taille_cartes = (sizeof(cartes)/sizeof(int)); // = 32

int distributeur;						// Celui qui distribue

int cartes_joueur[8] = {0};
int cartes_east[8]   = {0};
int cartes_north[8]  = {0};
int cartes_west[8]   = {0};

// Enchères
char * atout   = "undefined"; 			// Choix de l'atout pour la partie
char * contrat = "undefined"; 			// Personne qui annonce le contrat
int points = 0; 						// Points a atteindre pour remporter le contrat annoncé
int passe  = 0; 						// Nombre de fois qu'un joueur passe

////////////////////     FONCTIONS     ////////////////////

// Fonction pour vider l'écran et ajouter le titre
void espace_vide(int option, char * titre){

	if(option == 1){
		if(titre == "titre"){
			printf("O-------------------------------------------------- - --------------------------------------------------O\n");
			printf("§                                     o------------ - ------------o\n");
			printf("§ ♣  ♦  ♠  ♠  ♣  ♦  ♠  ♠  ♣  ♦  ♠  ♠  !      Belote Coinchée      !  ♣  ♦  ♠  ♠  ♣  ♦  ♠  ♠  ♣  ♦  ♠  ♠ \n");
			printf("§                                     o---------------------------o\n");
			printf("§\n§\n§\n§\n");
			printf("O-------------------------------------------------- - --------------------------------------------------O\n");
		}
		if(titre == "nouvelle"){
			printf("O-------------------------------------------------- - --------------------------------------------------O\n");
			printf("§                                     o------------ - ------------o\n");
			printf("§                                     !      Nouvelle Partie      !\n");
			printf("§                                     o---------------------------o\n");
			printf("§\n§\n§\n§\n");
			printf("O-------------------------------------------------- - --------------------------------------------------O\n");
		}
		if(titre == "enchere"){
			printf("O-------------------------------------------------- - --------------------------------------------------O\n");
			printf("§                                     o------------ - ------------o\n");
			printf("§                                     !      Phase d'Enchère      !\n");
			printf("§                                     o---------------------------o\n");
			printf("§\n§\n§\n§\n");
			printf("O-------------------------------------------------- - --------------------------------------------------O\n");
		}
	}

}

// Mélange des cartes
void melanger(int * tableau, int taille){
	int alea_1, alea_2;
	int temp[1];

	printf("§ INFO : Mélange des cartes... ");

	/*
	Melange d'un tableau:
	- On coupe le tableau en 2
	- On choisi au hasard une position dans chaque partie du tableau
	- On les inverses et on recommence un grand nombre de fois
	*/
	
	for(int i = 0; i < 1000; i++){
		alea_1 = rand()%(taille/2);
		alea_2 = taille - (rand()%(taille/2) + 1);
		
		temp[0] = tableau[alea_1];
		tableau[alea_1] = tableau[alea_2];
		tableau[alea_2] = temp[0];
	}

	//DEBUG : affichage du tableau mélangé :
	/*
	for(int i = 0; i < taille ; i++){
		printf("%d ",tableau[i]);
	}
	printf("\n");
	*/

	printf("Fait!\n");
}

// Distribution des cartes
void distribuer(int distrib){
	printf("§ INFO : Distribution des cartes... ");
	
	if(distrib == 5){distrib = 1;} // Si le distributeur précédent était Est alors 4 + 1 = 5 sauf que Joueur == 1;

	switch(distrib){
		case 1:
			distributeur = 1; // Joueur
			printf("%s distribue...",nom_joueur);

			// Joueur distribue en 1er a Ouest -> Nord -> Est -> Joueur
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_west[i]   = cartes[i];
				cartes_north[i]  = cartes[i+3];
				cartes_east[i]   = cartes[i+6];
				cartes_joueur[i] = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_west[i]   = cartes[i+9];
				cartes_north[i]  = cartes[i+11];
				cartes_east[i]   = cartes[i+13];
				cartes_joueur[i] = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_west[i]   = cartes[i+15];
				cartes_north[i]  = cartes[i+18];
				cartes_east[i]   = cartes[i+21];
				cartes_joueur[i] = cartes[i+24];		
			}

			break;
		case 2:
			distributeur = 2; // Ouest
			printf("Ouest distribue...");

			// Ouest distribue en 1er a Nord -> Est -> Joueur -> Ouest
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_north[i]  = cartes[i];
				cartes_east[i]   = cartes[i+3];
				cartes_joueur[i] = cartes[i+6];
				cartes_west[i]   = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_north[i]  = cartes[i+9];
				cartes_east[i]   = cartes[i+11];
				cartes_joueur[i] = cartes[i+13];
				cartes_west[i]   = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_north[i]  = cartes[i+15];
				cartes_east[i]   = cartes[i+18];
				cartes_joueur[i] = cartes[i+21];
				cartes_west[i]   = cartes[i+24];		
			}

			break;
		case 3:
			distributeur = 3; // Nord
			printf("Nord distribue...");

			// Nord distribue en 1er a Est -> Joueur -> Ouest -> Nord 
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_east[i]   = cartes[i];
				cartes_joueur[i] = cartes[i+3];
				cartes_west[i]   = cartes[i+6];
				cartes_north[i]  = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_east[i]   = cartes[i+9];
				cartes_joueur[i] = cartes[i+11];
				cartes_west[i]   = cartes[i+13];
				cartes_north[i]  = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_east[i]   = cartes[i+15];
				cartes_joueur[i] = cartes[i+18];
				cartes_west[i]   = cartes[i+21];
				cartes_north[i]  = cartes[i+24];		
			}

			break;
		case 4:
			distributeur = 4; // Est
			printf("Est distribue...");

			// Est distribue en 1er a Joueur -> Ouest -> Nord -> Est 
			// Distribue 3 cartes par personne
			for(int i = 0; i < 3; i++){
				cartes_joueur[i] = cartes[i];
				cartes_west[i]   = cartes[i+3];
				cartes_north[i]  = cartes[i+6];
				cartes_east[i]   = cartes[i+9];
			}
			// Distribue 2 cartes par personne
			for(int i = 3; i < 5; i++){
				cartes_joueur[i] = cartes[i+9];
				cartes_west[i]   = cartes[i+11];
				cartes_north[i]  = cartes[i+13];
				cartes_east[i]   = cartes[i+15];
			}
			// Distribue 3 cartes par personne
			for(int i = 5; i < 8; i++){
				cartes_joueur[i] = cartes[i+15];
				cartes_west[i]   = cartes[i+18];
				cartes_north[i]  = cartes[i+21];
				cartes_east[i]   = cartes[i+24];		
			}

			break;
		default:
			printf("Erreur switch distribuer(%d)",distrib);
			break;
	}

	// On supprime les cartes présentes dans le deck (il est vide)
	for(int i = 0; i < 32; i++){
		cartes[i] = 0;
	}

	printf("Fait!\n");
}

// Permet de recuperer les cartes suite a un plis ou suite a 3 passe après l'enchère
void ramasser(int distributeur){
	printf("Ramassage des cartes... ");

	switch(distributeur){
		case 1: // Joueur a distribué -> on ramasse en premier Ouest -> Nord -> Est -> Joueur
			printf("%s ramasse...",nom_joueur);
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_joueur[i]; }
			break;
		case 2: // Ouest a distribué -> on ramasse en premier Nord -> Est -> Joueur -> Ouest
			printf("Ouest ramasse...");
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_west[i];   }
			break; 
		case 3: // Nord a distribué -> on ramasse en premier Est -> Joueur -> Ouest -> Nord
			printf("Nord ramasse...");
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_east[i];   }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_north[i];  }
			break;
		case 4: // Est a distribué -> on ramasse en premier Joueur -> Ouest -> Nord -> Est
			printf("Est ramasse...");
			for(int i = 0; i < 8; i++){cartes[i]    = cartes_joueur[i]; }
			for(int i = 0; i < 8; i++){cartes[i+8]  = cartes_west[i];   }
			for(int i = 0; i < 8; i++){cartes[i+16] = cartes_north[i];  }
			for(int i = 0; i < 8; i++){cartes[i+24] = cartes_east[i];   }
			break;
		default:
			printf("Erreur switch ramasser(%d)",distributeur);
			break;
	}
	
	// Les mains sont vides donc on vides chaque joueur (on met à 0)
	for(int i = 0; i < 8; i++){
		cartes_joueur[i] = 0;
		cartes_west[i]   = 0;
		cartes_north[i]  = 0;
		cartes_east[i]   = 0;
	}

	printf("Fait!\n");
}

// Permet de trier nos cartes (tri a bulle)
void tableau_tri(int * tableau){
	int N = 8; // Nombre d'itération du tri (plante au dessus de 32)

	for(int j = 1; j < N; j++){
		for(int i = 0; i < N-1; i++){
			if( tableau[i] > tableau[i+1]){
				int temp = tableau[i];
				tableau[i] = tableau[i+1];
				tableau[i+1] = temp;
			}
		}
	}

}

// Plis
void plis(int num_plis){
	printf("\n plis() undefined");
}

// FACULTATIF : Retourne la somme des points des diverses annonces possibles
int annonce_bot(int * cartes_bot, char * bot){
	/*
		FACULTATIF
	*/

	return 0;
}

// Phase d'Enchère - BOTs
void bot_enchere(int * cartes_bot, char * bot){
	/*
		Au moment des enchères : 
		si une IA possède 3 cartes fortes d’une couleur donnée, 
		> elle annoncera un contrat de 80 points pour cette couleur.

		si elle possède 4 cartes fortes de cette couleur, 
		> elle annoncera un contrat de 120 points pour cette couleur.
	*/

	// On annonce le bot qui examine son jeu:
	printf("\n§ %s examine son jeu...",bot);

	//// Estimation par le bot de la couleur possédant le plus de points :

	int pique_fort   = 0;							// Nombre de carte fortes par couleur
	int carreau_fort = 0;
	int coeur_fort   = 0;
	int trefle_fort  = 0;

	int choix_couleur = 0;							// Combinaison de couleurs
	int result        = 0;							// Resultat si la combinaison prend plusieurs valeurs

	char * atout_bot = "undefined"; 				// choix provisoire d'atout pour le bot

	char * atout_pre = "undefined";					// Memoire de l'ancien atout (pour determiner si le bot a choisi de passer ou non)
	int points_pre = 0;

	// On compte le nombre carte forte par couleur
	for(int i = 0; i < 8; i++){
		
		switch(cartes_bot[i]){

			case 0 ... 8 : // PIQUE
				
				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						pique_fort++;
						break;
				}

				break;

			case 9 ... 16 : // CARREAU

				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						carreau_fort++;
						break;
				}
				
				break;

			case 17 ... 24 : // COEUR

				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						coeur_fort++;
						break;
				}
				
				break;

			case 25 ... 32 : // TREFLE

				switch( dictionnaire_atout(cartes_bot[i]) ){
					case 10 ... 20 :
						trefle_fort++;
						break;
				}

				break;
			default:
				printf("\n erreur switch cartes_bot(%d) avec %s",i,bot);
				break;
		}
	}

	// Affiche le nombre de cartes fortes par couleur
	//printf("\n%d/%d/%d/%d",pique_fort,carreau_fort,coeur_fort,trefle_fort);

	if(pique_fort   >= carreau_fort && pique_fort   >= coeur_fort   && pique_fort   >= trefle_fort){choix_couleur += 1   ;}
	if(carreau_fort >= pique_fort   && carreau_fort >= coeur_fort   && carreau_fort >= trefle_fort){choix_couleur += 10  ;}
	if(coeur_fort   >= pique_fort   && coeur_fort   >= carreau_fort && coeur_fort   >= trefle_fort){choix_couleur += 100 ;}
	if(trefle_fort  >= pique_fort   && trefle_fort  >= carreau_fort && trefle_fort  >= coeur_fort ){choix_couleur += 1000;}

	/*
		Possibilitées : Permet d'avoir une solution en cas d'égalité de carte forte (en atout)
		   1 :                            PIQUE -------
		  10 :                  CARREAU 		-------
		  11 :                  CARREAU + PIQUE
		 100 :          COEUR 					-------
		 101 :          COEUR           + PIQUE
		 110 :          COEUR + CARREAU
		 111 :          COEUR + CARREAU + PIQUE
		1000 : TREFLE                           -------
		1001 : TREFLE                   + PIQUE
		1010 : TREFLE         + CARREAU
		1011 : TREFLE         + CARREAU + PIQUE
		1100 : TREFLE + COEUR
		1101 : TREFLE + COEUR           + PIQUE
		1110 : TREFLE + COEUR + CARREAU
		1111 : TREFLE + COEUR + CARREAU + PIQUE
	*/
			
	switch(choix_couleur){
		case 1:
			atout_bot = "Pique";
			break;
		case 10:
			atout_bot = "Carreau";
			break;
		case 11: // entre carreau et pique
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Carreau";}else{atout_bot = "Pique";}
			break;
		case 100:
			atout_bot = "Coeur";
			break;
		case 101: // entre coeur et pique
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Coeur";}else{atout_bot = "Pique";}
			break;
		case 110: // entre coeur et carreau
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Coeur";}else{atout_bot = "Carreau";}
			break;
		case 111: // entre coeur, carreau et pique
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Coeur";}else{if(result == 2){atout_bot = "Carreau";}else{atout_bot = "Pique";}}
			break;
		case 1000:
			atout_bot = "Trèfle";
			break;
		case 1001: // entre trefle et pique
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{atout_bot = "Pique";}
			break;
		case 1010: // entre trefle et carreau
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{atout_bot = "Carreau";}
			break;
		case 1011: // trefle carreau pique
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Carreau";}else{atout_bot = "Pique";}}
			break;
		case 1100: // trefle coeur
			result = rand()%2 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{atout_bot = "Coeur";}
			break;
		case 1101: // trefle coeur pique
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Coeur";}else{atout_bot = "Pique";}}
			break;
		case 1110: // trefle coeur carreau
			result = rand()%3 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Coeur";}else{atout_bot = "Carreau";}}
			break;
		case 1111: // trefle coeur carreau pique
			result = rand()%4 + 1;
			if(result == 1){atout_bot = "Trèfle";}else{if(result == 2){atout_bot = "Coeur";}else{if(result == 3){atout_bot = "Carreau";}else{atout_bot = "Pique";}}}
		break;
	}

	atout_pre  = atout; 			// On sauvegarde l'ancien atout et les points d'avant
	points_pre = points;

	if(atout_bot == "Pique" && pique_fort == 3){
		atout = atout_bot;
		if(pique_fort == 4){points = 120;}else{points = 80;}
		printf("\n§ %s annonce %s avec %d pts",bot,atout,points);
	}
	if(atout_bot == "Carreau" && carreau_fort == 3){
		atout = atout_bot;
		if(pique_fort == 4){points = 120;}else{points = 80;}
		printf("\n§ %s annonce %s avec %d pts",bot,atout,points);
	}
	if(atout_bot == "Coeur" && coeur_fort == 3){
		atout = atout_bot;
		if(pique_fort == 4){points = 120;}else{points = 80;}
		printf("\n§ %s annonce %s avec %d pts",bot,atout,points);
	}
	if(atout_bot == "Trèfle" && trefle_fort == 3){
		atout = atout_bot;
		if(pique_fort == 4){points = 120;}else{points = 80;}
		printf("\n§ %s annonce %s avec %d pts",bot,atout,points);
	}

	if(atout == atout_pre && points == points_pre){ // Si vrai : le bot n'a pas changer l'atout et les pts -> il passe son tours
		printf("et a choisit de passer son tours!");
		passe++;
	}
}

// Phase d'Enchère - CONTIENT DES VARIABLES A ACTIVER
int enchere(int encherisseur){

	int choix_annonce = 0;								// variables concernant les choix du joueur
	int choix_atout   = 0; 
	int choix_couleur = 0; 
	int choix_points  = 0;

	espace_vide(1, "enchere");

	while(atout == "undefined"){
		encherisseur++;

		if(encherisseur == 5){encherisseur = 1;}		// On remet a 1 car après Est (=4), c'est joueur et joueur = 1;

		/**/
		// DEBUG : Affiche les paramètres suivants : encherisseur & passe
		printf("\nencherisseur: %d",encherisseur);
		printf("\npasse       : %d",passe);
		printf("\n");
		

		switch(encherisseur){
			case 1:		// Joueur

				//printf("\n§ %s examine son jeu...\n\n",nom_joueur);

				// On affiche les cartes du joueur 
				printf("Vos cartes :");
				for(int i = 0; i < 8; i++){
					printf(" %s",dictionnaire(cartes_joueur[i]));
				}
				
				// Demande entre annoncer un contrat ou passer
				do{
					printf("\n\nSouhaitez-vous annoncer un contrat ou passer?\n1 | Contrat\n2 | Passer\n");
					scanf("%d",&choix_annonce); // A ACTIVER
					//choix_annonce = 2; // A DESACTIVER
				}while(choix_annonce < 1 || choix_annonce > 2);
			
				switch(choix_annonce){
					case 1:
						do{
							printf("\nQuelles couleur?\n1 | Carreau\n2 | Coeur\n3 | Pique\n4 | Trèfle\n");
							scanf("%d",&choix_couleur); // A ACTIVER
						}while(choix_couleur < 1 || choix_couleur > 4);

						switch(choix_couleur){
							case 1:
								atout = "Carreau";
								break;
							case 2:
								atout = "Coeur";
								break;
							case 3:
								atout = "Pique";
								break;
							case 4:
								atout = "Trèfle";
								break;
							default:
								printf("Erreur switch couleur");
								break;
							}

						printf("\nChoix enregistré, annoncez vos points!");

						// Annonce des points: 
								
						printf("\n\nAnnoncez vos points:\nN | Classique - Entre 80 et 160 pts, par tranche de 10!\n1 | Capôt     - 250 pts -> gagner tout les plis\n2 | Générale  - 500 pts -> doit gagner tout les plis a vous seul\n");
						scanf("%d",&choix_points); // A ACTIVER

						switch(choix_points){
							case 1 :
								printf("\n%s annonce Capôt avec une couleur de %s",nom_joueur,atout);
								points = 250;
								break;
							case 2 :
								printf("\n%s annonce Générale avec une couleur de %s",nom_joueur,atout);
								points = 500;
								break;
							case 80 ... 160 : 
								printf("\n%s annonce une couleur de %s avec %d pts",nom_joueur,atout,choix_points);
								points = choix_points;
								contrat = nom_joueur;
							break;
						}

						break;
					case 2:
						printf("\n§ %s a choisit de passer son tours!",nom_joueur);
						passe++;
						break;
					default:
						printf("Erreur switch annonce/passer joueur choix_annonce=%d",choix_annonce);
						break;
				}

				break;
			case 2:		// Ouest
				bot_enchere(cartes_west, "Ouest");
				break;
			case 3:		// Nord
				bot_enchere(cartes_north, "Nord");
				break;
			case 4:		// Est
				bot_enchere(cartes_east, "Est");
				break;
		}

		if(passe > 3){
			passe = 0;
			printf("\n\n");
			printf("--------------------------------------------------------------\n");
			printf("Personne n'a fait de contrat, on redistribue les cartes\n");
			

			ramasser(distributeur);
			distribuer(distributeur+1);

			encherisseur = distributeur;
			printf("--------------------------------------------------------------\n");
		}

	if(atout != "undefined"){passe = 0; printf("\n§---------§");}

	while(passe < 3 && atout != "undefined"){
		encherisseur++;
		switch(encherisseur){
			case 1:
				printf("\n§ %s examine son jeu...",nom_joueur );
				passe++;
				break;
			case 2:
				printf("\n§ Ouest examine son jeu...");
				passe++;
				break;
			case 3:
				printf("\n§ Nord examine son jeu...");
				passe++;
				break;
			case 4:
				printf("\n§ Est examine son jeu...");
				passe++;
				break;
		}
	}

	}

}

// Lancement de la partie: - CONTIENT DES VARIABLES A ACTIVER
void nouvelle_partie(){
	espace_vide(1, "nouvelle");

	// Demande du nom du joueur
	printf("§ Entrez votre nom : ");
	scanf("%s",&nom_joueur); // A ACTIVER
	printf("\n§\n");
	

	// Mélange des cartes
	melanger(cartes, taille_cartes); // melanger(tableau, taille tableau)
	

	int distrib_alea = rand()% 4 + 1; // on prend un joueur au hasard pour distribuer 
	distribuer(distrib_alea);

	enchere(distributeur); // enchere(encherisseur) (encherisseur -> clockwise)

}

// Fonction pour afficher les meilleurs scores enregistrés
void meilleurs_score(){
	printf("meilleurs_score() undefined\n");
}

// Menu - CONTIENT DES VARIABLES A ACTIVER
void menu(void){
	espace_vide(1, "titre");

	int choix = 0;

	do{
		printf("§ Que voulez-vous faire?\n§\n");

		printf("§ 1 | Nouvelle Partie\n");
		printf("§ 2 | Meilleurs Scores\n");
		printf("§ 3 | Quitter\n\n");

		//scanf("%d",&choix); // A ACTIVER
		choix = 1;
	}while(choix < 1 || choix > 3);

	switch(choix){
		case 1:
			nouvelle_partie();
			break;
		case 2:
			meilleurs_score();
			break;
		case 3:
			exit(0);
			break;
		default:
			printf("Erreur dans switch(choix = %d)",choix);
			espace_vide(0, "N/A");
			menu();
			break;
	}
}


// Main
int main(void){

	/* 
		Change la table des caractères de la console 
		> si le programme est utilisé sous Windows
	*/
	#ifdef _WIN32
	    SetConsoleOutputCP(65001);
	#endif

	srand(time(NULL));

	menu();

	printf("\n\nFin de main()\n contrat: %s\n atout  : %s\n points : %d\n\n",contrat,atout,points);
	
return 0;
}