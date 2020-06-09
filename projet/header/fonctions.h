#ifndef FUNCTION_H_INCLUDE
#define FUNCTION_H_INCLUDE

// Traduction des cartes:
char *dictionnaire(int);
int dictionnaire_atout(int);
int dictionnaire_non_atout(int);

// Gestion des cartes:
void melanger(int*, int);
void distribuer(int, int*, char*,int*, int*, int*, int*);
void ramasser(int, int, char*, int*, int*, int*, int*);
void tableau_tri(int*);

// Gestion du jeu:
void menu(void);
void nouvelle_partie(void);
void enchere(int, char*, int*, int*, int*, int*);
void bot_enchere(int*, char*, char*, int*, int*);
void bot_surenchere(int*, char*, char*, int*, int*);
void bot_plis(void);
void plis(int ,char*, int*, int*, int*, int*, int*, int);

// Autre :
void meilleurs_score(void);
void scores(int, char*);

#endif