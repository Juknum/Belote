#include <stdio.h>
#include <stdlib.h>

#include <string.h>

//#include "./header/fonctions.h"
//#include "./header/syntax.h"

#define red     "\x1B[31m"
#define white   "\x1B[37m"
#define side_error		white"§"red" Erreur "white":"

#define TAILLE_MAX 3

void score(int score_gagnant, char * nom_gagnant){

	FILE* score_fichier = NULL;
    char chaine[TAILLE_MAX];

    int score[10] = {0};
    char nom_1[100] = {0};
    char nom_2[100] = {0};
    char nom_3[100] = {0};
    
    // ouverture du fichier en mode lecture
    score_fichier = fopen("C:\\Users\\julie\\OneDrive\\Documents\\GitHub\\Belote_IFB\\projet\\data\\score.txt", "r");
    
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

    score_fichier = fopen("C:\\Users\\julie\\OneDrive\\Documents\\GitHub\\Belote_IFB\\projet\\data\\score.txt", "w+");

    if (score_fichier != NULL){
        fprintf(score_fichier, "%d %s %d %s %d %s", score[0], nom_1, score[1], nom_2, score[2], nom_3);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible - réécriture");
    }
}

void meilleurs_score(void){
    FILE* score_fichier = NULL;
    char chaine[1000] = "";

    int score[10] = {0};
    char nom_1[100] = {0};
    char nom_2[100] = {0};
    char nom_3[100] = {0};

    score_fichier = fopen("C:\\Users\\julie\\OneDrive\\Documents\\GitHub\\Belote_IFB\\projet\\data\\score.txt", "r");

    if (score_fichier != NULL){
        fscanf(score_fichier, "%d %s %d %s %d %s", &score[0], &nom_1, &score[1], &nom_2, &score[2], &nom_3);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible");
    }

    printf("En n°1 : %s - %d pts !\n",nom_1,score[0]);
    printf("En n°2 : %s - %d pts !\n",nom_2,score[1]);
    printf("En n°3 : %s - %d pts !\n",nom_3,score[2]);

}

int main(void){
    int score_gagnant = 150;
    char * gagnant = "www";

    score(score_gagnant, gagnant);

    printf("====\n");
    meilleurs_score();

    return 0;
}