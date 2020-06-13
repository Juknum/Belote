/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	fonctions.h : Contient l'ensemble des fonctions et des macro de fonctions
		- fonctions Traduction et Affichage des cartes
		- fonctions Gestion des cartes
		- fonctions Gestion du jeu
		- fonctions concernant les scores
		- macros:
			- Lors de l'utilisation de Windows
			- Lors de l'utilisation de Linux

*/

#ifndef FUNCTION_H_INCLUDE
#define FUNCTION_H_INCLUDE

// Traduction des cartes:
char* dictionnaire(int);
char* symbole(int);
void afficher_carte(int*, int, int);
int dictionnaire_atout(int);
int dictionnaire_non_atout(int);

// Gestion des cartes:
void melanger(int*, int);
void distribuer(int, int*, char*,int*, int*, int*, int*);
void ramasser(int, int, char*, int*, int*, int*, int*);
void tableau_tri(int*);
void tableau_tri_slave(int*, int*);
void tableau_tri_slaves(int*, int*, int*);

// Gestion du jeu:
void menu(void);
void nouvelle_partie(void);
void enchere(int, char*, int*, int*, int*, int*);
void bot_enchere(int*, char*, char*, int*, int*, char*, char*);
void bot_surenchere(int*, char*, char*, int*, int*, char*, char*);
//void bot_plis(char*, int*, int, int*, int*, int, int);
void bot_plis(char*, int*, int, int, int*, int*);
void plis(char*,int, int, char*, int*, int*, int*, int*, char*);
void atout_add(int, int, int*, int*, int*);

// Autre :
void meilleurs_score(void);
void score_add(int, char*);

// Compatibilité Windows / Linux :
#ifdef _WIN32
	#include <windows.h>
	#define pause 				Sleep(1000)
	#define pause_load 			Sleep(10)
	#define clean 				system("cls")
	#define table_ascii 		system("chcp 65001")
#endif

#ifdef linux
	#include <unistd.h>
	#define pause 				sleep(1)
	#define pause_load 			sleep(0.1)
	#include <stdio.h>
	#define clean 				printf("\x1b[H\x1b[J")
	#define table_ascii 		printf("")
#endif

#endif