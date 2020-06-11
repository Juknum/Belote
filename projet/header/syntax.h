/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	syntax.h : Contient l'ensemble des diverses syntaxe, couleur du programme
	- Couleurs
	- Mise en page (gras...)
	- Sides (§)
	- Couleurs des cartes
	- Titre
	- Titre de fin

*/

#ifndef SYNTAX_H_INCLUDE
#define SYNTAX_H_INCLUDE

#define	black   "\x1B[30m"
#define red     "\x1B[31m"
#define green   "\x1B[32m"
#define yellow  "\x1B[33m"
#define blue    "\x1B[34m"
#define magenta "\x1B[35m"
#define cyan    "\x1B[36m"
#define white   "\x1B[37m"

#define	bblack   "\x1B[40m"
#define bred     "\x1B[41m"
#define bgreen   "\x1B[42m"
#define byellow  "\x1B[43m"
#define bblue    "\x1B[44m"
#define bmagenta "\x1B[45m"
#define bcyan    "\x1B[46m"
#define bwhite   "\x1B[47m"

#define reset   "\x1B[0m"

#define bold  "\x1b[1m"
#define nboldw reset white
#define nboldy reset yellow

#define side_question	white"§"yellow
#define side_only		white"§\n"
#define side 			white"§"
#define side_error		white"§"red" Erreur "white":"
#define side_info		white"§"green" Info "white":"
#define side_jeu		white"§"cyan" Jeu "white":"

#define carreau 	red"♦"white
#define coeur		red"♥"white
#define trefle		white"♣"
#define pique		white"♠"

#define title_barre 	white"O--------------------------------------------------=-=--------------------------------------------------O\n"
#define title_barre_top	white"$                                     o------------=-=------------o                                     $\n"
#define title_only		white"$                                                                                                       $\n"
#define title_info		white"$ "magenta"INFO "white":"
#define title_ninfo		white"$       "
#define title_g			white"$ "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  !      "cyan
#define title_d			white"      !  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau" $\n"
#define barre_small		white"§--------------------------------------------------------------\n"
									  
#define end_perdu1		side bold cyan"                              ██████╗ ███████╗██████╗ ██████╗ ██╗   ██╗                        $\n"nboldw
#define end_perdu2		side bold cyan"                              ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║   ██║                        $\n"nboldw
#define end_perdu3		side bold cyan"                              ██████╔╝█████╗  ██████╔╝██║  ██║██║   ██║                        $\n"nboldw
#define end_perdu4		side bold cyan"                              ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║   ██║                        $\n"nboldw
#define end_perdu5		side bold cyan"                              ██║     ███████╗██║  ██║██████╔╝╚██████╔╝                        $\n"nboldw
#define end_perdu6		side bold cyan"                              ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝                         $\n"nboldw

#define end_gagne1		side bold green"                            ██████╗  █████╗  ██████╗ ███╗   ██╗███████╗██╗                     $\n"nboldw
#define end_gagne2		side bold green"                           ██╔════╝ ██╔══██╗██╔════╝ ████╗  ██║██╔════╝██║                     $\n"nboldw
#define end_gagne3		side bold green"                           ██║  ███╗███████║██║  ███╗██╔██╗ ██║█████╗  ██║                     $\n"nboldw
#define end_gagne4		side bold green"                           ██║   ██║██╔══██║██║   ██║██║╚██╗██║██╔══╝  ╚═╝                     $\n"nboldw
#define end_gagne5		side bold green"                           ╚██████╔╝██║  ██║╚██████╔╝██║ ╚████║███████╗██╗                     $\n"nboldw
#define end_gagne6		side bold green"                            ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝                     $\n"nboldw
 
#endif