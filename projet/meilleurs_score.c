/*

    BELOTE COINCHEE EN C : Groupe F
    - Julien Constant
    - Ewen Bourdon
    - Théo Silva

    meilleurs_score.c :

*/

#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#include "./header/fonctions.h"
#include "./header/syntax.h"

void meilleurs_score(void){
    FILE* score_fichier = NULL;
    char chaine[1000] = "";

    int score[3] = {0};
    int nbr[3] = {0};
    char nom_0[20] = {0};
    char nom_1[20] = {0};
    char nom_2[20] = {0};
    char nom_vide[20] = {0};

    int choix = 0;

    score_fichier = fopen("./data/score.txt", "r");

    if (score_fichier != NULL){
        fscanf(score_fichier, "%d %s %d %d %s %d %d %s %d", &score[0], &nom_0, &nbr[0], &score[1], &nom_1, &nbr[1], &score[2], &nom_2, &nbr[2]);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible");
    }

    if(strcmp(nom_0, nom_vide) == 0){
        printf(side" Aucun meilleurs score n'a encore été enregistré !\n");
    }
    else{
        printf(side" Les 3 meilleurs score obtenus à la Belote Coinchée sont :\n");
        printf(side" - En n°1 : %s avec %d victoire et %d pts !\n",nom_0,nbr[0],score[0]);
        printf(side" - En n°2 : %s avec %d victoire et %d pts !\n",nom_1,nbr[1],score[1]);
        printf(side" - En n°3 : %s avec %d victoire et %d pts !\n",nom_2,nbr[2],score[2]);
    }

    printf(side_only);
    printf(side_question" Que voulez-vous faire?\n");
    printf(side_only);
    printf(side_question" 1 | Retour\n");
    printf(side_question" 2 | Quitter\n");
    printf(side_only);

    do{
        printf(side_question" Votre choix : ");
        scanf("%d",&choix);
    }while(choix < 1 || choix > 2);
    
    switch(choix){
        case 1:
            clean;
            menu();
            break;
        case 2:
            printf(reset);
            clean;
            exit(0);
            break;
        default:
            printf(side_error" switch(%d) non défini\n",choix);
            break;
    }

}