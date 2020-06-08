# [Windows] Comment compiler le projet:

- Compilateur utilisé : [gcc](https://osdn.net/projects/mingw/releases/)
- Il faut notamment installer la dépendance make de MingW
- Il est nécessaire d'intégrer **gcc** au PATH de Windows

Commande à effectuer dans le `cmd` après avoir télécharger `gcc` :
```cmd
cd C:\Users\..\GitHub\Belote_IFB\projet
mingw32-make
belote.exe
```

# [Windows] Ajouter des dépendances au projet:

Pour ajouter une fonction, il faut l'intégrer au `fonctions.h` présent dans `/header`, mais il faut aussi l'ajouter au makefile qui se consititue ainsi:

- **Il n'est pas nécessaire de modifier l'entièreté du fichier, il suffit simplement d'ajouter à `SRC` le nom de votre fichier `.c`**

- **Il est notamment possible de changer de compilateur si l'on s'intéresse à `CC=gcc` voir doc : [ici](https://gl.developpez.com/tutoriel/outil/makefile/)**

```make
CC=gcc
CFLAGS= -W -Wall -ansi -pedantic
LDFLAGS=
EXEC=belote

# Ajouter vos fonctions dans cette ligne :
SRC= bot_surenchere.c meilleurs_score.c bot_enchere.c enchere.c nouvelle_partie.c menu.c tableau_tri.c ramasser.c distribuer.c melanger.c dictionnaire_atout.c dictionnaire.c main.c

OBJ= $(SRC: .c=.o)

all: $(EXEC)

belote: $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS)

main.o : header/fonctions.h

%.o: %.c
    $(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
    @rm -rf *.o

mrproper: clean
    @rm -rf $(EXEC)
```