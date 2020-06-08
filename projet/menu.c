/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	/////// CONTIENT DES SCANF A ACTIVER ///////

	menu.c : 
	- Impression du titre
	- Proposition au joueur de choisir entre les options suivantes :
		- nouvelle_partie()
		- meilleurs_score()
		- quitter

*/

#include <stdio.h>
#include <stdlib.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void menu(void){
	int choix = 0;

	// On affiche le menu tant que que le joueur n'a pas choisit une option valide
	do{
		printf(title_barre);
		printf(title_barre_top);
		printf(title_g"Belote Coinchée"title_d);
		printf(title_barre_top);
		printf(title_barre);

		printf(side_question" Que voulez-vous faire?\n");
		printf(side_only);
		printf(side_question" 1 | Nouvelle Partie\n");
		printf(side_question" 2 | Meilleurs Scores\n");
		printf(side_question" 3 | Quitter\n");
		printf(side_only);
		printf(side_question" Votre choix :");

		//scanf("%d", &choix); 					// A ACTIVER
		choix = 1; 								// A DESACTIVER

		printf(side_only"\n");

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
			printf(side_error" switch(%d) dans menu(void)",choix);
			break;
	}
}