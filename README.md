# [SUJET] Jeu de Belote - Projet IFB - TC P20
L'objectif du projet est de créer un programme en mode console permettant à un joueur de jouer à la belote, et plus précisément à la Coinche, dont les règles sont mentionnées ci-après.

## Règles du jeu
Belote classique : https://www.belote.com/regles-et-variantes/les-regles-de-la-belote-classique/  
Coinche : https://www.belote.com/regles-et-variantes/regle-belote-coinche/  

## Objectifs du projet
L’objectif du projet est de réaliser le programme permettant de jouer à ce jeu via une interface console. Le jeu permettra à un seul joueur de jouer, les 3 autres joueurs (y compris le partenaire du joueur) seront contrôlés par l’ordinateur.

#### Vous devrez notamment réaliser :
- [x] Un menu principal permettant de démarrer une nouvelle partie, d’afficher les meilleurs scores ou de quitter. Le joueur sera invité à entrer son nom avant le début de la partie.
- [x] Un affichage permettant d’afficher les cartes que le joueur a en main
- [ ] Un affichage permettant d’afficher les cartes du pli en cours
- [ ] Un menu permettant d'annoncer un contrat ou de passer pendant le tour d’enchère
- [ ] Un menu permettant de jouer une carte parmi les cartes en main, tout en respectant les règles
- [ ] Une sauvegarde du nombre de victoires d’un joueur dans un fichier : chaque joueur identifié par son nom sera enregistré dans un fichier, avec son nombre total de victoire.
- [ ] Un affichage présentant les meilleurs scores (accessible à partir du menu principal) 

#### Les règles de la Coinche devront être appliquées par l’ordinateur :
Distribuer les cartes aux différents joueurs
- [ ] Contrôler que le joueur joue conformément aux règles (règles des enchères et règles pour la pose des cartes)
- [ ] Définir qui remporte le pli lorsque les 4 cartes sont jouées, en tenant compte de la valeur des cartes et de la couleur d’atout
- [ ] Comptage des points et vérification du contrat
- [ ] Dans ce projet, la gestion des annonces est facultative

#### Une pseudo intelligence artificielle sera également réalisée pour jouer avec le joueur :
- [ ] L’IA joue en respectant les règles
- [ ] Au moment des enchères : si une IA possède 3 cartes fortes d’une couleur donnée, elle annoncera un contrat de 80 points pour cette couleur, si elle possède 4 cartes fortes de cette couleur, elle annoncera un contrat de 120 points pour cette couleur
- [ ] Si l’IA est en mesure de remporter le pli avec une de ses cartes, elle le fait en posant la carte la plus faible possible
- [ ] Si l’IA n’est pas en mesure de remporter le pli, elle joue sa carte la plus faible
- [ ] Vous pouvez enrichir votre IA avec des règles heurisitiques que vous aurez élaborées et justifiées dans votre rapport.

## Proposition d'interface de jeu
Les captures d’écran suivantes illustrent ce à quoi pourrait ressembler le jeu. Vous êtes libre de vousen inspirer pour votre projet.

### Menu principal
img
### Ecran d'enchère
img
### Phase de jeu
img

## Conditions de réalisation du projet
Le projet sera intégralement réalisé en C. Il devra être fait en binôme (ou trinôme sur dérogation) de membres d'un même groupe.

#### Le projet donnera lieu à la production :
- [ ] De fichiers sources (fichiers .c et fichiers .h) qui devront être dûment commentés et documentés
- [ ] D'un rapport d'une dizaine de pages présentant le travail réalisé, notamment la structure générale de votre code, les choix réalisés pour le développement du jeu, et le résultat final (en faisant le bilan de ce qui a été réussi et des points d’amélioration éventuels)

Le projet donnera également lieu à une soutenance pendant laquelle le projet sera présenté. Cette soutenance aura lieu pendant les heures de cours.  
L’ensemble des fichiers seront déposés sur Moodle dans l’espace de dépôt “Dépôt projet P20”. Ils devront être contenus dans une archive nommée **NOM-BINOME1_NOM-BINOME2.zip**  
Cette archive contiendra : votre rapport au format PDF et vos sources dans un dossier séparé.  
