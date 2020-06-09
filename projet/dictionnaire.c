/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	dictionnaire.c : Sert de traducteur pour passer du numérique à la chaîne de caractère
		- On donne un int entre 1 et 32 et on retourne un char* (nécessite d'appeler la fonction dans un printf)

*/

#include <stdio.h>
#include <stdlib.h>

#include "./header/syntax.h"

char * dictionnaire(int carte){
	char* result = "undefined";

	switch(carte){
		case 1 :
		result = " 7"pique;
		break;
		case 2 :
		result = " 8"pique;
		break;
		case 3 :
		result = " 9"pique;
		break;
		case 4 :
		result = "10"pique;
		break;
		case 5 :
		result = " V"pique;
		break;
		case 6 :
		result = " D"pique;
		break;
		case 7 :
		result = " R"pique;
		break;
		case 8 :
		result = "AS"pique;
		break;

		case 9 :
		result = " 7"carreau;
		break;
		case 10 :
		result = " 8"carreau;
		break;
		case 11 :
		result = " 9"carreau;
		break;
		case 12 :
		result = "10"carreau;
		break;
		case 13 :
		result = " V"carreau;
		break;
		case 14 :
		result = " D"carreau;
		break;
		case 15 :
		result = " R"carreau;
		break;
		case 16 :
		result = "AS"carreau;
		break;

		case 17 :
		result = " 7"coeur;
		break;
		case 18 :
		result = " 8"coeur;
		break;
		case 19 :
		result = " 9"coeur;
		break;
		case 20 :
		result = "10"coeur;
		break;
		case 21 :
		result = " V"coeur;
		break;
		case 22 :
		result = " D"coeur;
		break;
		case 23 :
		result = " R"coeur;
		break;
		case 24 :
		result = "AS"coeur;
		break;

		case 25 :
		result = " 7"trefle;
		break;
		case 26 :
		result = " 8"trefle;
		break;
		case 27 :
		result = " 9"trefle;
		break;
		case 28 :
		result = "10"trefle;
		break;
		case 29 :
		result = " V"trefle;
		break;
		case 30 :
		result = " D"trefle;
		break;
		case 31 :
		result = " R"trefle;
		break;
		case 32 :
		result = "AS"trefle;
		break;

		default :
		result = bold red"N/A"nboldw;
		break;
	}

	//DEBUG :
	//printf("cartes num : %d\n",tableau);
	//printf("traduction : %s\n",result);

	return result;
}