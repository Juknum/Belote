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

char* atout = "atout_undefined";
int choix_couleur = 0;

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

void ia_enchere(int bot){
	// bot = 2,3,4 : Ouest, Nord, Est
	/*
		Les modes Sans-Atout et Tout-Atout sont eux aussi sources de stratégies qui leur sont propres.
		D’une manière générale, pour le Tout-Atout, veillez à avoir au moins trois Valets ou une ou 
		deux suites de cartes d’atouts (Valet, 9, As) et privilégiez ces enchères lorsque vous êtes 
		placé tout de suite après le donneur, ce qui vous permet d’avoir la main à coup sûr.
		En mode Sans-Atout, veillez à avoir au moins trois As ou deux As et au moins une grande suite 
		(As, 10, Roi, Dame, Valet) si vous êtes placé après le donneur.
	*/
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

	// DEBUG : Affiches les cartes des autres ordis
	/*
	tableau_tri(cartes_west);
	printf("Cartes Ouest:\n");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_west[i]));
	}
	printf("\nCartes Est:\n");
	tableau_tri(cartes_east);
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_east[i]));
	}
	printf("\nCartes Nord:\n");
	tableau_tri(cartes_north);
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_north[i]));
	}
	printf("\n\n");
	*/

	encherisseur = 1; // A DESACTIVER
	int type_enchere;
	char* couleur;
	int choix;

	passer = 2; // A DESACTIVER

	/*
		Lorsque Est distribue, l'enrichisseur est le joueur
		il faut donc remettre à 1 l'enrichisseur
	*/
	if(encherisseur > 4){
		encherisseur = 1;
	}

	switch(encherisseur){
		case 1: // Joueur
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
					printf("\nLes enchères sont terminées, le jeu démarre!"); // On lance la partie si 3 personnes consécutives décident de passer
					plis(1);
				} 
				else{
					enchere(encherisseur+1); // On passe au joueur suivant
				}
			}
			break;

		case 2: // Ouest
			printf("Ouest examine son jeu!\n");
			ia_enchere(2);
			break;

		case 3: // Nord
			printf("Nord examine son jeu!\n");
			ia_enchere(3);
			break;

		case 4: // Est
			printf("Est examine son jeu!\n");
		    ia_enchere(4);
			break;

		default:
			printf("Erreur dans le choix du 1er encherisseur");
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