#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

#define TAILLE_MAX 1000

void score_add(int score_gagnant, char * nom_gagnant){

    FILE* score_fichier = NULL;
    char chaine[TAILLE_MAX];

    int score[3] = {0};
    char nom_1[20] = {0};
    char nom_2[20] = {0};
    char nom_3[20] = {0};
    
    // ouverture du fichier en mode lecture
    score_fichier = fopen("./data/score.txt", "r");
    
    if (score_fichier != NULL){
        fscanf(score_fichier, "%d %s %d %s %d %s", &score[0], &nom_1, &score[1], &nom_2, &score[2], &nom_3);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible - lecture");
    }

    // Si le "nouveau" score dépasse le premier
    if(score_gagnant >= score[0]){
        score[2] = score[1];
        score[1] = score[0];
        score[0] = score_gagnant;

        strcpy(nom_3, nom_2);
        strcpy(nom_2, nom_1);
        strcpy(nom_1, nom_gagnant);
    }
    // Si le "nouveau" score dépasse le deuxième
    else if(score_gagnant >= score[1]){
        score[2] = score[1];
        score[1] = score_gagnant;

        strcpy(nom_3, nom_2);
        strcpy(nom_2, nom_gagnant);
    }
    // Si le "nouveau" score dépasse le troisième
    else if(score_gagnant >= score[2]){
        score[2] = score_gagnant;

        strcpy(nom_3, nom_gagnant);
    }

    score_fichier = fopen("./data/score.txt", "w+");

    if (score_fichier != NULL){
        fprintf(score_fichier, "%d %s %d %s %d %s", score[0], nom_1, score[1], nom_2, score[2], nom_3);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible - réécriture");
    }        
}