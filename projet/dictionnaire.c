/*
	Recquiert un entier compris entre 1 et 32 
	Retourne un char* a placer dans un printf
*/

#include <stdio.h>
#include <stdlib.h>

#define RED   "\x1B[31m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

char * dictionnaire(int carte){
	char* result = "undefined";

	switch(carte){
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
		result = " 7"RED"♦"WHT"";
		break;
		case 10 :
		result = " 8"RED"♦"WHT"";
		break;
		case 11 :
		result = " 9"RED"♦"WHT"";
		break;
		case 12 :
		result = "10"RED"♦"WHT"";
		break;
		case 13 :
		result = " V"RED"♦"WHT"";
		break;
		case 14 :
		result = " D"RED"♦"WHT"";
		break;
		case 15 :
		result = " R"RED"♦"WHT"";
		break;
		case 16 :
		result = "AS"RED"♦"WHT"";
		break;

		case 17 :
		result = " 7"RED"♥"WHT"";
		break;
		case 18 :
		result = " 8"RED"♥"WHT"";
		break;
		case 19 :
		result = " 9"RED"♥"WHT"";
		break;
		case 20 :
		result = "10"RED"♥"WHT"";
		break;
		case 21 :
		result = " V"RED"♥"WHT"";
		break;
		case 22 :
		result = " D"RED"♥"WHT"";
		break;
		case 23 :
		result = " R"RED"♥"WHT"";
		break;
		case 24 :
		result = "AS"RED"♥"WHT"";
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

	//DEBUG :
	//printf("cartes num : %d\n",tableau);
	//printf("traduction : %s\n",result);

	return result;
}