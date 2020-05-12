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
char* nom_joueur = "name_undefined";

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
char* atout = "atout_undefined";
int choix_couleur = 0;
int tour_enrichisseur = 0;

int passer = 0; // personne qui passe lors de l'enchère

////////////////////     FONCTIONS     ////////////////////

// Fonction pour vider l'écran
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
char* dictionnaire(int tableau){
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

// Mélange des cartes
void melanger(int* tableau, int taille){
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
	char* distributeur_char;

	int alea = rand()% 4 + 1;
	switch(alea){
		case 1:
			distributeur = 1; // Joueur
			distributeur_char = "Joueur";
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
		cartes_east[i] = cartes[i+3];
		cartes_north[i] = cartes[i+6];
		cartes_west[i] = cartes[i+9];
	}
	// Distribue 2 cartes par personne
	for(int i = 3; i < 5; i++){
		cartes_joueur[i] = cartes[i+9];
		cartes_east[i] = cartes[i+11];
		cartes_north[i] = cartes[i+13];
		cartes_west[i] = cartes[i+15];		
	}
	// Distribue 3 cartes par personne
	for(int i = 5; i < 8; i++){
		cartes_joueur[i] = cartes[i+15];
		cartes_east[i] = cartes[i+18];
		cartes_north[i] = cartes[i+21];
		cartes_west[i] = cartes[i+24];		
	}

	printf("Fait!\n");
}

// Permet de trier nos cartes (tri a bulle)
void tableau_tri(int *tableau){
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

// Plis en cours (phase de jeu)
void plis(int num_plis){
	espace_vide(1);
	printf("Plis : %d/8\n",num_plis);
	printf("Atout: %s\n",atout);
}

// Phase d'Enchère - CONTIENT DES VARIABLES A ACTIVER
void enchere(int encherisseur){
	espace_vide(1);

	printf("Phase d'enchères...\n\n");
	printf("Vos cartes :");

	tableau_tri(cartes_joueur);
	
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_joueur[i]));
	}
	printf("\n\n");

	tableau_tri(cartes_west);
	tableau_tri(cartes_east);
	tableau_tri(cartes_north);

	// DEBUG : Affiches les cartes des autres ordis
	
	printf("Cartes Ouest:\n");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_west[i]));
	}
	printf("\nCartes Est:\n");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_east[i]));
	}
	printf("\nCartes Nord:\n");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_north[i]));
	}
	printf("\n\n");
	

	encherisseur = 2; // A DESACTIVER

	int type_enchere;
	int choix;
	int bot = 1;
	char* couleur;
	
	//passer = 2; // A DESACTIVER
	tour_enrichisseur ++;

	/*
		Lorsque Est distribue, l'enrichisseur est le joueur
		il faut donc remettre à 1 l'enrichisseur
	*/
	if(encherisseur == 5){
		encherisseur = 1;
	}

	switch(encherisseur){
		case 1: //////////////////////// Joueur ////////////////////////
			printf("%s examine son jeu!\n\n",nom_joueur);

			printf("Souhaitez-vous passer ou annoncer?\n1 | Annoncer\n2 | Passer\n");
			//scanf("%d",&choix); // A ACTIVER
			choix = 2; // A DESACTIVER

			if(choix == 1){
				// l'encherisseur choisit la couleur de l'atout
				printf("Choisissez la couleur de l'atout:\n");
				printf("1 | Couleur Unique\n");
				printf("2 | Tout Atout (TA)\n");
				printf("3 | Sans Atout (SA)\n");

				scanf("%d",&type_enchere); // A ACTIVER
				//type_enchere = 3; // A DESACTIVER

				switch(type_enchere){
			    	case 1: //une seule couleur est choisit comme Atout
						do{
							printf("\nVeuillez choisir une des couleurs en marquant le nombre qui lui est attribué\n");
							printf("1 | Trèfle\n2 | Pique\n3 | Carreau\n4 | Coeur\n");
							
							scanf("%d",&choix_couleur); // A ACTIVER
							//choix_couleur = 1; // A DESACTIVER

			            }while(choix_couleur < 1 || choix_couleur > 4);

			            atout = "Couleur";
			           	
			            switch(choix_couleur){
			            	case 1:
			            		couleur = "Trèfle";
			            		break;
			            	case 2:
			            		couleur = "Pique";
			            		break;
			            	case 3:
			            		couleur = "Carreau";
			            		break;
			            	case 4:
			            		couleur = "Coeur";
			            		break;
			            	default:
			            		couleur = "couleur_undefined";
			            		break;
			            }
			            printf("\n%s annonce une couleur de %s!\n",nom_joueur,couleur);
			            break;

			        case 2: //toute les couleurs sont atout
			            atout = "TA";
			            printf("\n%s annonce un Tout Atout!\n",nom_joueur);
			            break;

			        case 3: //toute les couleurs sont sans atout
			            atout = "SA";
			            printf("\n%s annonce un Sans Atout!\n",nom_joueur);
			            break;
			        default :
			            printf("Erreur dans les enchères");
			    }
			}
			else{ // choix == 2;
				printf("\n%s passe!",nom_joueur);
				passer ++;
				if(passer == 3){
					printf("\nLes enchères sont terminées, la partie démarre!\n"); // On lance la partie si 3 personnes consécutives décident de passer
					plis(1);
				} 
				else{
					enchere(encherisseur+1); // On passe au joueur suivant
				}
			}
			break;

		//////////////////////// IA des ordis ////////////////////////

		/*
			Le bot doit prendre en compte l'annonce du joueur/bot précédent et de son coéquipier:
			> Peut-il faire mieux? Oui: annonce mieux; Non: passe
			> Qu'a fait le partenaire? Peut-il aider?
		*/

		/*
			Le bot choisit Tout Atout (TA) si:
			> il possède 3 valet 
			> OU 1 ou 2 suite de cartes d'atout (Valet, 9, As)
				> de la même couleur donc
			> A priviliéger si le bot annonce en premier
		*/

		/*
			Le bot choisit Sans Atout (SA) si:
			> il possède 3 ou 2 As ET possède une suite (As, 10, Roi, Dame, Valet)
			> A priviligier si le bot annonce en premier
		*/
		
		/*
			Par défaut:
			> Le bot choisi une couleur unique: celle qu'il possède le plus
			> Calcul des points : annonce 20pts par plis remportable + 
		*/

		//////////////////////// Ouest ////////////////////////
		case 2: 
			printf("Ouest examine son jeu!\n");

			if(tour_enrichisseur == 1){

				int	ordi_west_as    = 0;
				int ordi_west_valet = 0;

				//////////////////////// Test si TA possible ////////////////////////
				/*
					Les Valets ont pour valeur : 5, 13, 21, 29
				*/
				/*
					Les suites ont pour valeur : 3, 5, 8 // 11, 13, 16 // 19, 21, 24 // 27, 29, 32
				*/

				// On compte les valets
				for(int i = 0; i < 8; i++){
					if(cartes_west[i] == 5 || cartes_west[i] == 13 || cartes_west[i] == 21 || cartes_west[i] == 29){
						ordi_west_valet++;
					}
				}
				// DEBUG : printf("\nOuest Valets : %d",ordi_west_valet);

				// On vérifie que Ouest possède une suite si il a moins de 3 valets
				int suite_ta = 0;
				if( ordi_west_valet < 3){
					int suite_coeur_ta   = 0;
					int suite_carreau_ta = 0;
					int suite_trefle_ta  = 0;
					int suite_pique_ta   = 0;

					for(int i = 0; i < 8; i++){
						// test de la suite dans les coeurs
						if(cartes_west[i] == 3 || cartes_west[i] == 5 || cartes_west[i] == 8){
							suite_coeur_ta++;
						}

						// test de la suite dans les carreau
						if(cartes_west[i] == 11 || cartes_west[i] == 13 || cartes_west[i] == 16){
							suite_carreau_ta++;
						}

						// test de la suite dans les trèfles
						if(cartes_west[i] == 19 || cartes_west[i] == 21 || cartes_west[i] == 24){
							suite_trefle_ta++;
						}

						// test de la suite dans les pique
						if(cartes_west[i] == 27 || cartes_west[i] == 29 || cartes_west[i] == 32){
							suite_pique_ta++;
						}
					}

					// si l'une des trois variables suites == 3 alors Ouest possède une suite;
					if(suite_pique_ta == 3 || suite_trefle_ta == 3 || suite_carreau_ta == 3 || suite_coeur_ta == 3){
						suite_ta = 1;
						// DEBUG : printf("\nsuite : %d",suite);
					}
				}

				if( ordi_west_valet == 3 || suite_ta == 1 ){
					atout = "TA";
					printf("\nOuest annonce Tout Atout");
				}
				else{
					//////////////////////// Test si SA possible ////////////////////////
					/*
						Les As ont pour valeur 8, 16, 24, 32
					*/
					/*
						Les suites 10,V,D,R,As ont pour valeur : 4,5,6,7,8 // 12,13,14,15,16 // 20,21,22,23,24 // 28,29,30,31,32
					*/

					// On compte les As
					for(int i = 0; i < 8; i++){
						if(cartes_west[i] == 8 || cartes_west[i] == 16 || cartes_west[i] == 24 || cartes_west[i] == 32){
							ordi_west_as++;
						}
					}
					// DEBUG : printf("\nOuest As     : %d",ordi_west_as);

					// On vérifie que l'ordi possède la suite (dans tout les cas == elle est nécessaire)
					int suite_sa = 0;
					int suite_coeur_sa   = 0;
					int suite_carreau_sa = 0;
					int suite_trefle_sa  = 0;
					int suite_pique_sa   = 0;

					for(int i = 0; i < 8; i++){
						// test de la suite dans les coeurs
						if(cartes_west[i] == 4 || cartes_west[i] == 5 || cartes_west[i] == 6 || cartes_west[i] == 7 || cartes_west[i] == 8){
							suite_coeur_sa++;
						}

						// test de la suite dans les carreau
						if(cartes_west[i] == 12 || cartes_west[i] == 13 || cartes_west[i] ==  14 || cartes_west[i] == 15 || cartes_west[i] == 16){
							suite_carreau_sa++;
						}

						// test de la suite dans les trèfles
						if(cartes_west[i] == 20 || cartes_west[i] == 21 || cartes_west[i] == 22 || cartes_west[i] == 23 || cartes_west[i] == 24){
							suite_trefle_sa++;
						}

						// test de la suite dans les pique
						if(cartes_west[i] == 28 || cartes_west[i] == 29 || cartes_west[i] == 30 || cartes_west[i] == 31 || cartes_west[i] == 32){
							suite_pique_sa++;
						}
					}

					// si l'une des trois variables suites == 5 alors Ouest possède une suite;
					if(suite_pique_sa == 5 || suite_trefle_sa == 5 || suite_carreau_sa == 5 || suite_coeur_sa == 5){
						suite_sa = 1;
						// DEBUG : printf("\nsuite : %d",suite);
					}

					if( ordi_west_as >= 2 && suite_sa == 1 ){
						atout = "SA";
						printf("\nOuest annonce Sans Atout");
					}
					else atout = "Couleur Unique";
					}
				
				}

				// compte chaque cartes par couleur
				// regarde le nombre de cartes hautes dans la couleur la plus représentée et annonce les pts

			break;

		//////////////////////// Nord ////////////////////////
		case 3:
			printf("Nord examine son jeu!\n");
			bot = 3;
			break;

		//////////////////////// Est ////////////////////////
		case 4:
			printf("Est examine son jeu!\n");
		    bot = 4;
			break;

		default:
			printf("Erreur dans switch(encherisseur)");
			break;
	}
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
	melanger(cartes, taille_cartes);

	printf("Distribution des cartes... ");
	distribuer();

	printf("\n");

	enchere(distributeur+1);
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
	
return 0;
}