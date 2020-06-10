#include <stdio.h>
#include <stdlib.h>

#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include "./header/fonctions.h"
#include "./header/syntax.h"

void meilleurs_score(void){
    FILE* score_fichier = NULL;
    char chaine[1000] = "";

    int score[10] = {0};
    char nom_1[100] = {0};
    char nom_2[100] = {0};
    char nom_3[100] = {0};

    int choix = 0;

    score_fichier = fopen("./data/score.txt", "r");

    if (score_fichier != NULL){
        fscanf(score_fichier, "%d %s %d %s %d %s", &score[0], &nom_1, &score[1], &nom_2, &score[2], &nom_3);
        fclose(score_fichier);
    }
    else{
        printf(side_error" Ouverture du fichier impossible");
    }

    printf(side" Les 3 meilleurs score obtenus à la Belote Coinchée sont :\n");
    printf(side" - En n°1 : %s avec %d pts !\n",nom_1,score[0]);
    printf(side" - En n°2 : %s avec %d pts !\n",nom_2,score[1]);
    printf(side" - En n°3 : %s avec %d pts !\n",nom_3,score[2]);
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
            #ifdef _WIN32
                system("cls");
            #endif
            menu();
            break;
        case 2:
            printf(reset);
            #ifdef _WIN32
                system("cls");
            #endif
            exit(0);
            break;
        default:
            printf(side_error" switch(%d) non défini\n",choix);
            break;
    }

}