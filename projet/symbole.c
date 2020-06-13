/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	symbole.c : Permet la traduction numérique d'une couleur


*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

char * symbole(int carte){
	char * symb = "N";

	switch(carte){
		case  1 ...  8 :
			symb = pique;
			break;
		case  9 ... 16 :
			symb = carreau;
			break;
		case 17 ... 24 :
			symb = coeur;
			break;
		case 25 ... 32 :
			symb = trefle;
			break;
		default :
			symb = red"E"white;
			break;
	}

	return symb;
}