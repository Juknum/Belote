/*

		BELOTE COINCHEE EN C : Groupe F
		- Julien Constant
		- Théo Silva

*/

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
int score_max_1;
int score_max_2;
int score_max_3;

// Jeux de cartes (non trié) et mains des joueurs:
int cartes[32] = {1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32};
int taille_cartes = (sizeof(cartes)/sizeof(int));

unsigned int distributeur;

int cartes_joueur[8] = {0};
int cartes_east[8]   = {0};
int cartes_north[8]  = {0};
int cartes_west[8]   = {0};

// Enchères
char * atout = "undefined"; // choix de l'atout pour la partie
int points = 0; // Points a atteindre pour remporter le contrat annoncé
int passe = 0; // Nombre de fois qu'un joueur passe

////////////////////     FONCTIONS     ////////////////////

// Fonction pour vider l'écran et ajouter le titre
void espace_vide(int titre){

	for(int i = 0; i < 1; i++){
		printf("\n");
	}

	if(titre == 1){
		printf("**************************\n");
		printf("*                        *\n");
		printf("*     Belote Coinchée    *\n");
		printf("*                        *\n");
		printf("**************************\n");
	}
}

// Dictionnaire pour la traduction d'un int en carte
char * dictionnaire(int tableau){
	char* result = "undefined";

	switch(tableau){
		case 1 :
		result = " 7♠";
		break;
		case 2 :
		result = " 8♠";
		break;
		case 3 :
		result = " 9♠";
		break;
		case 4 :
		result = "10♠";
		break;
		case 5 :
		result = " V♠";
		break;
		case 6 :
		result = " D♠";
		break;
		case 7 :
		result = " R♠";
		break;
		case 8 :
		result = "AS♠";
		break;

		case 9 :
		result = " 7♦";
		break;
		case 10 :
		result = " 8♦";
		break;
		case 11 :
		result = " 9♦";
		break;
		case 12 :
		result = "10♦";
		break;
		case 13 :
		result = " V♦";
		break;
		case 14 :
		result = " D♦";
		break;
		case 15 :
		result = " R♦";
		break;
		case 16 :
		result = "AS♦";
		break;

		case 17 :
		result = " 7♥";
		break;
		case 18 :
		result = " 8♥";
		break;
		case 19 :
		result = " 9♥";
		break;
		case 20 :
		result = "10♥";
		break;
		case 21 :
		result = " V♥";
		break;
		case 22 :
		result = " D♥";
		break;
		case 23 :
		result = " R♥";
		break;
		case 24 :
		result = "AS♥";
		break;

		case 25 :
		result = " 7♣";
		break;
		case 26 :
		result = " 8♣";
		break;
		case 27 :
		result = " 9♣";
		break;
		case 28 :
		result = "10♣";
		break;
		case 29 :
		result = " V♣";
		break;
		case 30 :
		result = " D♣";
		break;
		case 31 :
		result = " R♣";
		break;
		case 32 :
		result = "AS♣";
		break;

		default :
		result = "error carte non définie";
		break;
	}

	// DEBUG :
	//printf("cartes num : %d\n",tableau);
	//printf("traduction : %s\n",result);

	return result;
}

// Dictionnaire pour la traduction d'un int en valeur d'atout
int dictionnaire_atout(int tableau){
	int result = -1;

	switch(tableau){
		case 1 :
		result = 0;
		break;
		case 2 :
		result = 0;
		break;
		case 3 :
		result = 14;
		break;
		case 4 :
		result = 10;
		break;
		case 5 :
		result = 20;
		break;
		case 6 :
		result = 3;
		break;
		case 7 :
		result = 4;
		break;
		case 8 :
		result = 11;
		break;

		case 9 :
		result = 0;
		break;
		case 10 :
		result = 0;
		break;
		case 11 :
		result = 14;
		break;
		case 12 :
		result = 10;
		break;
		case 13 :
		result = 20;
		break;
		case 14 :
		result = 3;
		break;
		case 15 :
		result = 4;
		break;
		case 16 :
		result = 11;
		break;

		case 17 :
		result = 0;
		break;
		case 18 :
		result = 0;
		break;
		case 19 :
		result = 14;
		break;
		case 20 :
		result = 10;
		break;
		case 21 :
		result = 20;
		break;
		case 22 :
		result = 3;
		break;
		case 23 :
		result = 4;
		break;
		case 24 :
		result = 11;
		break;

		case 25 :
		result = 0;
		break;
		case 26 :
		result = 0;
		break;
		case 27 :
		result = 14;
		break;
		case 28 :
		result = 10;
		break;
		case 29 :
		result = 20;
		break;
		case 30 :
		result = 3;
		break;
		case 31 :
		result = 4;
		break;
		case 32 :
		result = 11;
		break;

		default :
		result = -2;
		break;
	}

	// DEBUG :
	//printf("cartes num : %d\n",tableau);
	//printf("traduction : %d\n",result);

	return result;
}

// Mélange des cartes
void melanger(int * tableau, int taille){
	int alea_1, alea_2;
	int temp[1];

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
void distribuer(void){
	char * distributeur_char;

	int alea = rand()% 4 + 1;
	switch(alea){
		case 1:
			distributeur = 1; // Joueur
			distributeur_char = nom_joueur;
			break;
		case 2:
			distributeur = 2; // Ouest
			distributeur_char = "Ouest";
			break;
		case 3:
			distributeur = 3; // Nord
			distributeur_char = "Nord";
			break;
		case 4:
			distributeur = 4; // Est
			distributeur_char = "Est";
			break;
		default:
			printf("Erreur pendant le choix du distributeur");
			break;
	}

	printf("%s distribue... ",distributeur_char);

	// Distribue 3 cartes par personne
	for(int i = 0; i < 3; i++){
		cartes_joueur[i] = cartes[i];
		cartes_east[i]   = cartes[i+3];
		cartes_north[i]  = cartes[i+6];
		cartes_west[i]   = cartes[i+9];
	}
	// Distribue 2 cartes par personne
	for(int i = 3; i < 5; i++){
		cartes_joueur[i] = cartes[i+9];
		cartes_east[i]   = cartes[i+11];
		cartes_north[i]  = cartes[i+13];
		cartes_west[i]   = cartes[i+15];		
	}
	// Distribue 3 cartes par personne
	for(int i = 5; i < 8; i++){
		cartes_joueur[i] = cartes[i+15];
		cartes_east[i]   = cartes[i+18];
		cartes_north[i]  = cartes[i+21];
		cartes_west[i]   = cartes[i+24];		
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

// Phase d'Enchère - BOTs
int enchere_bot(int * cartes_bot, char * bot, int score_estimation){
	////// COULEUR //////
	int total_carreau = 0;
	int total_coeur   = 0;
	int total_pique   = 0;
	int total_trefle  = 0;

	int total = 0; // Permet de différencier quelle couleur est la + forte
	int result = 0; // Sert à choisir entre 2...4 valeurs identiques (si 2/3/4 couleurs ont le même nbr de pts)

	int joue = 0; // 1 si le bot joue la couleur la + forte

	/////// TA ///////

	// Variables TA
	int ordi_bot_valet  = 0; // Valets présent dans la main du bot

	int suite_ta         = 0; // 1 si Le bot possède une suite pour TA
	int suite_coeur_ta   = 0;
	int suite_carreau_ta = 0;
	int suite_trefle_ta  = 0;
	int suite_pique_ta   = 0;

	/////// SA ///////

	// Variables SA
	int	ordi_bot_as     = 0; // As présent dans la main du bot
	
	int suite_sa         = 0; // 1 si le bot possède la suite pour SA
	int suite_coeur_sa   = 0;
	int suite_carreau_sa = 0;
	int suite_trefle_sa  = 0;
	int suite_pique_sa   = 0;

	printf("\n%s examine son jeu...",bot);

	// DEBUG : Affiches les cartes du bot
	printf("\n%s :",bot);
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_bot[i]));
	}
	
	// On regarde la valeur totale des cartes par couleur (en atout) et on garde la meilleure couleur
	for(int i = 0; i < 8; i++){
		switch(cartes_bot[i]){
			case 0 ... 8 :
				total_pique += dictionnaire_atout(cartes_bot[i]);
				break;
			case 9 ... 16 :
				total_carreau += dictionnaire_atout(cartes_bot[i]);
				break;
			case 17 ... 24 :
				total_coeur += dictionnaire_atout(cartes_bot[i]);
				break;
			case 25 ... 32 :
				total_trefle += dictionnaire_atout(cartes_bot[i]);
				break;
			default:
				printf("\n erreur switch cartes_bot() avec %s",bot);
				break;
		}
	}

	// DEBUG : Affiche les valeurs d'atout par couleur
	//printf("\nValeur en Atout : %d♠ / %d♦ / %d♥ / %d♣",total_pique,total_carreau,total_coeur,total_trefle);
			
	if(total_pique   >= total_carreau && total_pique   >= total_coeur   && total_pique   >= total_trefle){total += 1   ;}
	if(total_carreau >= total_pique   && total_carreau >= total_coeur   && total_carreau >= total_trefle){total += 10  ;}
	if(total_coeur   >= total_pique   && total_coeur   >= total_carreau && total_coeur   >= total_trefle){total += 100 ;}
	if(total_trefle  >= total_pique   && total_trefle  >= total_carreau && total_trefle  >= total_coeur ){total += 1000;}

	/*
		Possibilitées : Permet d'avoir une solution en cas d'égalité de pts (en atout)
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
			
	switch(total){
		case 1:
			atout = "Pique";
			break;
		case 10:
			atout = "Carreau";
			break;
		case 11: // entre carreau et pique
			result = rand()%2 + 1;
			if(result == 1){atout = "Carreau";}else{atout = "Pique";}
			break;
		case 100:
			atout = "Coeur";
			break;
		case 101: // entre coeur et pique
			result = rand()%2 + 1;
			if(result == 1){atout = "Coeur";}else{atout = "Pique";}
			break;
		case 110: // entre coeur et carreau
			result = rand()%2 + 1;
			if(result == 1){atout = "Coeur";}else{atout = "Carreau";}
			break;
		case 111: // entre coeur, carreau et pique
			result = rand()%3 + 1;
			if(result == 1){atout = "Coeur";}else{if(result == 2){atout = "Carreau";}else{atout = "Pique";}}
			break;
		case 1000:
			atout = "Trèfle";
			break;
		case 1001: // entre trefle et pique
			result = rand()%2 + 1;
			if(result == 1){atout = "Trèfle";}else{atout = "Pique";}
			break;
		case 1010: // entre trefle et carreau
			result = rand()%2 + 1;
			if(result == 1){atout = "Trèfle";}else{atout = "Carreau";}
			break;
		case 1011: // trefle carreau pique
			result = rand()%3 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Carreau";}else{atout = "Pique";}}
			break;
		case 1100: // trefle coeur
			result = rand()%2 + 1;
			if(result == 1){atout = "Trèfle";}else{atout = "Coeur";}
			break;
		case 1101: // trefle coeur pique
			result = rand()%3 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Coeur";}else{atout = "Pique";}}
			break;
		case 1110: // trefle coeur carreau
			result = rand()%3 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Coeur";}else{atout = "Carreau";}}
			break;
		case 1111: // trefle coeur carreau pique
			result = rand()%4 + 1;
			if(result == 1){atout = "Trèfle";}else{if(result == 2){atout = "Coeur";}else{if(result == 3){atout = "Carreau";}else{atout = "Pique";}}}
		break;
	}

	/*
		On regarde le score de la couleur la plus représentée et on estime si ça vaut le coup de jouer couleur
		ou de prendre TA ou SA.
	*/

	// Si le bot a un score supérireur à score_estimation et bien il annonce ces points et joue couleur;
	if(atout == "Carreau"){
		if(total_carreau > score_estimation){
			joue = 1;
			points = total_carreau * 2.5;
		}
	}
	if(atout == "Coeur"){
		if(total_coeur > score_estimation){
			joue = 1;
			points = total_coeur * 2.5;
		}
	}
	if(atout == "Pique"){
		if(total_pique > score_estimation){
			joue = 1;
			points = total_pique * 2.5;
		}
	}
	if(atout == "Trèfle"){
		if(total_trefle > score_estimation){
			joue = 1;
			points = total_trefle * 2.5;
		}
	}

	/*
		Le bot décide de ne pas jouer la couleur possédant le plus haut score,
		il regarde alors s'il peut faire SA ou TA;
	*/

	if(joue == 0){
		/////// TA ///////
		// On compte les valets possédé par le bot
		for(int i = 0; i < 8; i++){
			if(cartes_bot[i] == 5 || cartes_bot[i] == 13 || cartes_bot[i] == 21 || cartes_bot[i] == 29){
				ordi_bot_valet++;
			}
		}

		// Si le bot n'a pas suffisament de valet, on regarde s'il possède une suite
		if( ordi_bot_valet < 3){
			for(int i = 0; i < 8; i++){
				// test de la suite dans les coeurs
				if(cartes_bot[i] ==  3 || cartes_bot[i] ==  5 || cartes_bot[i] ==  8){suite_coeur_ta++;   }

				// test de la suite dans les carreau
				if(cartes_bot[i] == 11 || cartes_bot[i] == 13 || cartes_bot[i] == 16){suite_carreau_ta++; }

				// test de la suite dans les trèfles
				if(cartes_bot[i] == 19 || cartes_bot[i] == 21 || cartes_bot[i] == 24){suite_trefle_ta++;  }

				// test de la suite dans les pique
				if(cartes_bot[i] == 27 || cartes_bot[i] == 29 || cartes_bot[i] == 32){suite_pique_ta++;   }
			}

			// si l'une des trois variables suites == 3 alors le bot possède une suite;
			if(suite_pique_ta == 3 || suite_trefle_ta == 3 || suite_carreau_ta == 3 || suite_coeur_ta == 3){suite_ta = 1;}
		}
		
		// Décision sur le choix du bot à "prendre" TA:
		if( ordi_bot_valet == 3 || suite_ta == 1 ){
			atout = "TA";
			points = -1;
			printf("\n%s annonce Tout Atout ",bot);
		}
		else{
			/////// SA ///////
			// On compte les As possédé par le bot
			for(int i = 0; i < 8; i++){
				if(cartes_bot[i] == 8 || cartes_bot[i] == 16 || cartes_bot[i] == 24 || cartes_bot[i] == 32){ordi_bot_as++;}
			}

			// On vérifie que l'ordi possède la suite (dans tout les cas == elle est nécessaire)
			for(int i = 0; i < 8; i++){
				// test de la suite dans les coeurs
				if(cartes_bot[i] ==  4 || cartes_bot[i] ==  5 || cartes_bot[i] ==  6 || cartes_bot[i] ==  7 || cartes_bot[i] == 8){suite_coeur_sa++;    }
				// test de la suite dans les carreau
				if(cartes_bot[i] == 12 || cartes_bot[i] == 13 || cartes_bot[i] == 14 || cartes_bot[i] == 15 || cartes_bot[i] == 16){suite_carreau_sa++; }
				// test de la suite dans les trèfles
				if(cartes_bot[i] == 20 || cartes_bot[i] == 21 || cartes_bot[i] == 22 || cartes_bot[i] == 23 || cartes_bot[i] == 24){suite_trefle_sa++;  }
				// test de la suite dans les pique
				if(cartes_bot[i] == 28 || cartes_bot[i] == 29 || cartes_bot[i] == 30 || cartes_bot[i] == 31 || cartes_bot[i] == 32){suite_pique_sa++;   }
			}

			// si l'une des trois variables suites == 5 alors le bot possède une suite;
			if(suite_pique_sa == 5 || suite_trefle_sa == 5 || suite_carreau_sa == 5 || suite_coeur_sa == 5){suite_sa = 1;}
			
			if( ordi_bot_as >= 2 && suite_sa == 1 ){
				atout = "SA";
				points = -1;
				printf("\n%s annonce Sans Atout ",bot);
			}
			else{
				/////// Passe ///////
				printf("\n%s a choisit de passer son tours!",bot);
				atout = "undefined"; // car il ne choisit pas d'atout
				passe++;
			}
		}
	}
	else{ // joue == 1
		points = (points / 10) * 10; // On décide de ne pas garder l'unité
		printf("\n%s annonce une couleur de %s avec %d pts",bot,atout,points);
	}
}

// Phase d'Enchère - CONTIENT DES VARIABLES A ACTIVER
int enchere(int encherisseur){
	// Espace textuel :
	espace_vide(1);

	printf("Phase d'enchères...\n\n");
	printf("Vos cartes :");

	// On affiche les cartes du joueur 
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_joueur[i]));
	}
	printf("\n");

	////// enrichisseur Joueur //////
	// tout mettre sur 0
	int choix_annonce = 0; 
	int choix_atout   = 0; 
	int choix_couleur = 0; 
	int choix_points  = 0;

	////// Score bot minimum //////
	// mini 80 pts : 80 / 2.5 = 32 // Score minimum de la couleur pour que le bot décide de jouer
	// 2.5 -> il pense remporter 2,5 plis
	int score_estimation = 32; 

	// Lorsqu'il faut annonce un contrat + points
	while(atout == "undefined"){
		encherisseur++; // celui a gauche du distributeur encherit en 1er

		// Si Est distribue alors encherisseur == 5 == 1
		if(encherisseur == 5){encherisseur = 1;}

		printf("\npasse = %d",passe);
		switch(encherisseur){
			/////// Joueur ///////
			case 1:
				printf("\n%s examine son jeu...\n\n",nom_joueur);
				do{
					printf("Souhaitez-vous annoncer un contrat ou passer?\n1 | Contrat\n2 | Passer\n");
					scanf("%d",&choix_annonce); // A ACTIVER*
				}while(choix_annonce < 1 || choix_annonce > 2);
			
				switch(choix_annonce){
					case 1:
						do{
							printf("\n\nQuel contrat souhaitez-vous?\n1 | Couleur\n2 | Tout Atout (TA)\n3 | Sans Atout (SA)\n");
							scanf("%d",&choix_atout); // A ACTIVER
						}while(choix_atout < 1 || choix_atout > 3);

						switch(choix_atout){
							case 1:
								do{
									printf("\nQuelles couleur?\n1 | Carreau\n2 | Coeur\n3 | Pique\n4 | Trèfle\n");
									scanf("%d",choix_couleur); // A ACTIVER
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
									default:
										printf("Erreur switch couleur");
										break;
								}

								printf("\nChoix enregistré, annoncez vos points!");

								// Annonce des points: 
								
								printf("\n\nAnnoncez vos points:\nN | Classique - Entre 80 et 160 pts, par tranche de 10!\n1 | Capôt     - 250 pts -> gagner tout les plis\n2 | Générale  - 500 pts -> doit gagner tout les plis a vous seul\n");
								scanf("%d",choix_points); // A ACTIVER

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
										break;
								}
								break;
							case 2:
								atout = "TA";
								points = -1;
								printf("\n%s annonce un Tout Atout!",nom_joueur);
								break;
							case 3:
								atout = "SA";
								points = -1;
								printf("\n%s annonce un Sans Atout!",nom_joueur);
								break;
							default: 
								printf("Erreur switch couleur/ta/sa");
								break;
						}

						break;
					case 2:
						printf("\n%s a choisit de passer son tours!",nom_joueur);
						passe++;
						break;
					default:
						printf("Erreur switch annonce/passer");
						break;
				}

				break;
			///////  Ouest ///////
			case 2:
				if(passe > 3){ // L'estimation minimal du bot diminu si personne ne choisit d'atout au 1er tour
					passe = 0;
					score_estimation = score_estimation - 12;
					printf("\nestim = %d",score_estimation);

					enchere_bot(cartes_west, "Ouest",score_estimation);
				}else{
					printf("\nestim = %d",score_estimation);
					enchere_bot(cartes_west, "Ouest", score_estimation);
				}

				break;
			///////  Nord  ///////
			case 3:
				if(passe > 3){
					passe = 0;
					score_estimation = score_estimation - 12;
					printf("\nestim = %d",score_estimation);

					enchere_bot(cartes_north, "Nord",score_estimation);
				}else{
					printf("\nestim = %d",score_estimation);
					enchere_bot(cartes_north, "Nord", score_estimation);
				}

				break;
			///////   Est  ///////
			case 4:
				if(passe > 3){
					passe = 0;
					score_estimation = score_estimation - 12;
					printf("\nestim = %d",score_estimation);

					enchere_bot(cartes_east, "Est",score_estimation);
				}else{
					printf("\nestim = %d",score_estimation);
					enchere_bot(cartes_east, "Est", score_estimation);
				}

				break;
			default:
				printf("Erreur dans le switch encherisseur");
				break;
		}

	}

	// Lorsqu'il y a juste besoin de faire les pts/annonce
	if(atout != "undefined"){
		while(passe != 3){
			encherisseur++; // Le joueur précédent à choisit l'atout, celui-ci décide de sur-enchérir ou non

			// Si Est donne le contrat alors l'encherisseur d'après == 5 == 1
			if(encherisseur == 5){encherisseur = 1;}
			
			switch(encherisseur){
				case 1:
					passe++;
					break;
				case 2:
					passe++;
					break;
				case 3:
					passe++;
					break;
				case 4:
					passe++;
					break;
				default:
					printf("Erreur switch sur-enchère");
					break;
			}
		}
	}
		

	/*
		Ici on décide de la continuité ou non des enchères
		> Combien de joueur on passé
		> Qui est le prochain a enchérir?
	*/

	if(passe > 2){
		printf("\n\n---------------------------------");
		printf("\nFin des enchères... début du jeu!");
		printf("\n---------------------------------");

		plis(0);

		return 0; // On quitte la fonction
	}

	return 0;
}

// Lancement de la partie: - CONTIENT DES VARIABLES A ACTIVER
void nouvelle_partie(){
	espace_vide(1);

	// Demande du nom du joueur
	printf("Entrez votre nom : ");
	//scanf("%s",&nom_joueur); // A ACTIVER
	printf("\n\n");

	// Mélange des cartes
	printf("Mélange des cartes... ");
	melanger(cartes, taille_cartes); // melanger(tableau, taille tableau)

	printf("Distribution des cartes... ");
	distribuer();

	printf("\n");

	// On trie les cartes de tout le monde
	tableau_tri(cartes_joueur);
	tableau_tri(cartes_west);
	tableau_tri(cartes_east);
	tableau_tri(cartes_north);

	enchere(distributeur); // enchere(encherisseur) (encherisseur -> clockwise)

}

// Fonction pour afficher les meilleurs scores enregistrés
void meilleurs_score(){
	printf("meilleurs_score() undefined\n");
}

// Menu - CONTIENT DES VARIABLES A ACTIVER
void menu(void){
	printf("**************************\n");
	printf("*                        *\n");
	printf("*     Belote Coinchée    *\n");
	printf("*                        *\n");
	printf("**************************\n");

	printf("Que voulez-vous faire?\n\n");

	printf("1 | Nouvelle Partie\n");
	printf("2 | Meilleurs Scores\n");
	printf("3 | Quitter\n\n");

	int choix;
	choix = 1; // A DESACTIVER
	//scanf("%d",&choix); // A ACTIVER

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
			printf("Erreur dans les choix");
			espace_vide(0);
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

	printf("\n\nFin de main()\n atout  : %s\n points : %d\n\n",atout,points);
	
return 0;
}