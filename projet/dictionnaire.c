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
		result = " 7 "; // Pique
		break;
		case 2 :
		result = " 8 ";
		break;
		case 3 :
		result = " 9 ";
		break;
		case 4 :
		result = "1 0";
		break;
		case 5 :
		result = " V ";
		break;
		case 6 :
		result = " D ";
		break;
		case 7 :
		result = " R ";
		break;
		case 8 :
		result = " A ";
		break;

		case 9 :
		result = " 7 "; // Carreau
		break;
		case 10 :
		result = " 8 ";
		break;
		case 11 :
		result = " 9 ";
		break;
		case 12 :
		result = "1 0";
		break;
		case 13 :
		result = " V ";
		break;
		case 14 :
		result = " D ";
		break;
		case 15 :
		result = " R ";
		break;
		case 16 :
		result = " A ";
		break;

		case 17 :
		result = " 7 "; // Coeur
		break;
		case 18 :
		result = " 8 ";
		break;
		case 19 :
		result = " 9 ";
		break;
		case 20 :
		result = "1 0";
		break;
		case 21 :
		result = " V ";
		break;
		case 22 :
		result = " D ";
		break;
		case 23 :
		result = " R ";
		break;
		case 24 :
		result = " A ";
		break;

		case 25 :
		result = " 7 "; // Trèfle
		break;
		case 26 :
		result = " 8 ";
		break;
		case 27 :
		result = " 9 ";
		break;
		case 28 :
		result = "1 0";
		break;
		case 29 :
		result = " V ";
		break;
		case 30 :
		result = " D ";
		break;
		case 31 :
		result = " R ";
		break;
		case 32 :
		result = " A ";
		break;

		default :
		result = "N/A";
		break;
	}

	//DEBUG :
	//printf("cartes num : %d\n",tableau);
	//printf("traduction : %s\n",result);

	return result;
}