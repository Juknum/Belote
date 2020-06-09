#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void meilleurs_score(void){
    FILE* score_fichier = NULL;
    char chaine[1000] = "";

    int score[10] = {0};
    char nom_1[100] = {0};
    char nom_2[100] = {0};
    char nom_3[100] = {0};

    score_fichier = fopen("./data/score.txt", "r");

    if (score_fichier != NULL){
        fscanf(score_fichier, "%d %s %d %s %d %s", &score[0], &nom_1, &score[1], &nom_2, &score[2], &nom_3);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible");
    }

    printf(side"En n°1 : %s - %d pts !\n",nom_1,score[0]);
    printf(side"En n°2 : %s - %d pts !\n",nom_2,score[1]);
    printf(side"En n°3 : %s - %d pts !\n",nom_3,score[2]);

}