/*

	BELOTE COINCHEE EN C : Groupe F
	- Julien Constant
	- Ewen Bourdon
	- Théo Silva

	syntax.h : Contient l'ensemble des diverses syntaxe, couleur du programme
	- Couleurs
	- Mise en page (gras...)
	- Sides (║)
	- Couleurs des cartes
	- Cartes
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

#define side_question bold white"║"yellow nboldy
#define side_only	 bold white"║\n"nboldw
#define side 		 bold white"║"nboldw
#define side_error	 bold white"║"nboldw red" Erreur "white":"
#define side_info	 bold white"║"nboldw yellow" Info "white":"
#define side_jeu	 bold white"║"nboldw cyan" Jeu "white":"

#define carreau 	red"♦"white
#define coeur		red"♥"white
#define trefle		white"♣"white
#define pique		white"♠"white

#define carte_top		 bold white"║ ╔══○O○══╦══○O○══╦══○O○══╦══○O○══╦══○O○══╦══○O○══╦══○O○══╦══○O○══╗\n"
#define carte_bottom		  white"║ ╚══○"cyan"1"white"○══╩══○"cyan"2"white"○══╩══○"cyan"3"white"○══╩══○"cyan"4"white"○══╩══○"cyan"5"white"○══╩══○"cyan"6"white"○══╩══○"cyan"7"white"○══╩══○"cyan"8"white"○══╝\n" nboldw
#define carte_top_4		 bold white"║ ╔══○O○══╦══○O○══╦══○O○══╦══○O○══╗\n"
#define carte_bottom_4        white"║ ╚══○O○══╩══○O○══╩══○O○══╩══○O○══╝\n" nboldw
#define carte_top_1		 bold white"║ ╔══○O○══╗\n"
#define carte_bottom_1        white"║ ╚══○O○══╝\n" nboldw


#define title_barre1 	 bold white"╔══════════════════════════════════════════════════○O○══════════════════════════════════════════════════╗\n"nboldw
#define title_barre2	 bold white"╠══════════════════════════════════════════════════○O○══════════════════════════════════════════════════╝\n"nboldw
#define title_barre_top1 bold white"║                                     ╔════════════○O○════════════╗                                     ║\n"nboldw
#define title_barre_top2 bold white"║                                     ╚════════════○O○════════════╝                                     ║\n"nboldw
#define title_pli_left   bold white"║                                     ╚════════════"
#define title_pli_right            "/8════════════╝                                     ║\n"nboldw
#define title_only		 bold white"║                                                                                                       ║\n"nboldw
#define title_info		 bold white"║ "magenta"INFO "white":"
#define title_ninfo		 bold white"║       "
#define title_g			 bold white"║ "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  ║      "cyan
#define title_d			 bold white"      ║  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau" ║\n"nboldw
#define barre_small		 white"╠══════════════════════════════════════════════════════════════\n"

#define end_perdu1	bold "║"red"◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌██████╗ ███████╗██████╗ ██████╗ ██╗   ██╗◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌"white"║\n"nboldw
#define end_perdu2	bold "║"red" ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║   ██║ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ "white"║\n"nboldw
#define end_perdu3	bold "║"red"◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌██████╔╝█████╗  ██████╔╝██║  ██║██║   ██║◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌"white"║\n"nboldw
#define end_perdu4	bold "║"red" ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║   ██║ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ "white"║\n"nboldw
#define end_perdu5	bold "║"red"◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌██║     ███████╗██║  ██║██████╔╝╚██████╔╝◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌"white"║\n"nboldw
#define end_perdu6	bold "║"red" ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ "white"║\n"nboldw

#define end_gagne1	bold "║"blue"                             ██████╗  █████╗  ██████╗ ███╗   ██╗███████╗██╗                            "white"║\n"nboldw
#define end_gagne2	bold "║"blue"                            ██╔════╝ ██╔══██╗██╔════╝ ████╗  ██║██╔════╝██║                            "white"║\n"nboldw
#define end_gagne3	bold "║"blue"                            ██║  ███╗███████║██║  ███╗██╔██╗ ██║█████╗  ██║                            "white"║\n"nboldw
#define end_gagne4	bold "║"blue"                            ██║   ██║██╔══██║██║   ██║██║╚██╗██║██╔══╝  ╚═╝                            "white"║\n"nboldw
#define end_gagne5	bold "║"blue"                            ╚██████╔╝██║  ██║╚██████╔╝██║ ╚████║███████╗██╗                            "white"║\n"nboldw
#define end_gagne6	bold "║"blue"                             ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝                            "white"║\n"nboldw

#endif