#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include <math.h>
#include <time.h>

#include "./header/fonctions.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

/////// CONTIENT DES SCANF A ACTIVER ///////

void menu(void){
	int choix = 0;

	// On affiche le menu tant que que le joueur n'a pas choisit une option valide
	do{
		printf("O--------------------------------------------------=-=--------------------------------------------------O\n");
		printf("§                                     o------------=-=------------o\n");
		printf("§ ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  !      "YEL"Belote Coinchée"WHT"      !  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"  ♣  "RED"♦"WHT"  ♠  "RED"♥"WHT"\n");
		printf("§                                     o-------------=-------------o\n");
		printf("§\n§\n§\n§\n");
		printf("O--------------------------------------------------=-=--------------------------------------------------O\n");

		printf("§ Que voulez-vous faire?\n§\n");
		printf("§ 1 | Nouvelle Partie\n");
		printf("§ 2 | Meilleurs Scores\n");
		printf("§ 3 | Quitter\n");

		printf("§ Votre choix : ");
		//scanf("%d", &choix); // A ACTIVER
		choix = 1; // A DESACTIVER
		printf("\n§\n");
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
			printf("ERREUR : switch(%d) dans menu(void)",choix);
			break;
	}
}