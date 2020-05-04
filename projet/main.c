/*

		BELOTE EN C : Groupe F
		- Julien Constant
		- Théo Silva

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

//////////////////// VARIABLES GLOBALBES ////////////////////

// Joueur :
char* nom_joueur = "undefined";

// Scores max:
int score_max_1;
int score_max_2;
int score_max_3;

// Jeux de cartes (non trié) et mains des joueurs:
int cartes[32] = {1,2,3,4,5,6,7,8, 9,10,11,12,13,14,15,16, 17,18,19,20,21,22,23,24, 25,26,27,28,29,30,31,32};
int taille_cartes = (sizeof(cartes)/sizeof(int));

int cartes_joueur[8] = {0}; 
int cartes_east[8]   = {0}; 
int cartes_north[8]  = {0}; 
int cartes_west[8]   = {0};


////////////////////     FONCTIONS     ////////////////////

// Fonction pour vider l'écran
void espace_vide(int titre){

	for(int i = 0; i < 5; i++){
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
		result = "error";
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

// Phase d'Enchère
/*
Stratégies d’enchères pour débuter
	Pour les débutants, il est généralement recommandé de suivre dans un premier temps une stratégie d’enchères classique, 
    telle qu’exposée ci-dessous :

    - Passer : 
    	Le joueur n’a pas un jeu suffisant pour remporter 80 points ou surenchérir.

    - Attendre : 
	    Le joueur n’a pas un jeu suffisant pour remporter 80 points ou surenchérir, 
	    toutefois il dispose dans son jeu de plusieurs cartes maîtresses potentielles 
	    telles que des As et des valets.

    - Enchère à 80 : 
    	Il manque à l’annonceur un des deux atouts maîtres, 
    	à savoir le valet ou le neuf. Mais il est très bien servi en atout (deux ou trois autres) 
    	et sur les autres couleurs (As, 10 … Son partenaire pourra augmenter l’enchère s’il possède l’atout maître complémentaire 
    	à celui de l’annonceur (ce que recherche à la base l’annonceur), si cet atout n’est pas trop seul.

    - Enchère à 90 : 
    	L’annonceur a les deux atouts maîtres (le valet et le neuf) avec quelques intéressantes en plus. 
    	Par exemple un ou deux atouts supplémentaires et quelques cartes maîtresses.  
    	Aussi, le partenaire pourra-t-il surenchérir s’il possède au moins un atout et quelques cartes maîtresses ou 
    	bien simplement 3 atouts ou plus.
    	
    - Enchère à 100 : 
	    L’annonceur est maître à l’atout (valet, neuf, As) et possède au moins un as ou une coupe franche.
	    Le rôle du partenaire sera alors de compléter les As. 
	    Ainsi, il lui est conseillé d’augmenter l’enchère de 10 points par As (sauf l’As d’atout), et ce, 
	    même s’il ne possède pas beaucoup d’atouts.

Monter systématiquement de 10 points avec As dans la main est une règle suivie par beaucoup de débutants. 
Or, il faut également considérer le reste de la main et la complémentarité avec son partenaire : 
si le joueur possède un dix seul (“tout nu”) ou bien s’il possède une longe avec son As (qui risque alors d’être coupé), 
la prudence est de mise.
*/
void enchere(void){
	espace_vide(1);

	printf("Phase d'enchères...\n\n");

	printf("Vos cartes :");
	for(int i = 0; i < 8; i++){
		printf(" %s",dictionnaire(cartes_joueur[i]));
	}
	printf("\n\n");

	
}

// Lancement de la partie:
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

	enchere();
}

// Fonction pour afficher les meilleurs scores enregistrés
void meilleurs_score(){
	printf("meilleurs_score() undefined\n");
}

// Menu
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

	int choix = 1;
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

	srand(time(NULL));

	menu();
	
return 0;
}