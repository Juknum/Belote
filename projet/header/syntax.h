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
#define nboldw reset white bgreen
#define nboldy reset black bgreen

#define side_question	bgreen bold white"║"black nboldy
#define side_only		bgreen bold white"║\n"nboldw
#define side 			bgreen bold white"║"nboldw
#define side_error		bgreen bold white"║"nboldw red" Erreur "white":"
#define side_info		bgreen bold white"║"nboldw green" Info "white":"
#define side_jeu		bgreen bold white"║"nboldw blue" Jeu "white":"

#define carreau 	red"♦"white
#define coeur		red"♥"white
#define trefle		black"♣"white
#define pique		black"♠"white

// Char: ═ ╦ ╠ ╣ ╡ └ ─ ◌
#define title_barre1 	 bgreen bold white"╔══════════════════════════════════════════════════○O○══════════════════════════════════════════════════╗\n"nboldw
#define title_barre2	 bgreen bold white"╠══════════════════════════════════════════════════○O○══════════════════════════════════════════════════╝\n"nboldw
#define title_barre_top1 bgreen bold white"║                                     ╔════════════○O○════════════╗                                     ║\n"nboldw
#define title_barre_top2 bgreen bold white"║                                     ╚════════════○O○════════════╝                                     ║\n"nboldw
#define title_pli_left   bgreen bold white"║                                     ╚════════════"
#define title_pli_right            "/8════════════╝                                     ║\n"nboldw
#define title_only		 bgreen bold white"║                                                                                                       ║\n"nboldw
#define title_info		 bgreen bold white"║ "magenta"INFO "white":"
#define title_ninfo		 bgreen bold white"║       "
#define title_g			 bgreen bold white"║ "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  ║      "cyan
#define title_d			 bgreen bold white"      ║  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau"  "trefle"  "coeur"  "pique"  "carreau" ║\n"nboldw
#define barre_small		 bgreen white"╠══════════════════════════════════════════════════════════════\n"

#define end_perdu1	bgreen bold "║"red"◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌██████╗ ███████╗██████╗ ██████╗ ██╗   ██╗◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌"white"║\n"nboldw
#define end_perdu2	bgreen bold "║"red" ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ██╔══██╗██╔════╝██╔══██╗██╔══██╗██║   ██║ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ "white"║\n"nboldw
#define end_perdu3	bgreen bold "║"red"◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌██████╔╝█████╗  ██████╔╝██║  ██║██║   ██║◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌"white"║\n"nboldw
#define end_perdu4	bgreen bold "║"red" ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ██╔═══╝ ██╔══╝  ██╔══██╗██║  ██║██║   ██║ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ "white"║\n"nboldw
#define end_perdu5	bgreen bold "║"red"◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌██║     ███████╗██║  ██║██████╔╝╚██████╔╝◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌"white"║\n"nboldw
#define end_perdu6	bgreen bold "║"red" ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ╚═╝     ╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ ◌ "white"║\n"nboldw

#define end_gagne1	bgreen bold "║"green"                             ██████╗  █████╗  ██████╗ ███╗   ██╗███████╗██╗                            "white"║\n"nboldw
#define end_gagne2	bgreen bold "║"green"                            ██╔════╝ ██╔══██╗██╔════╝ ████╗  ██║██╔════╝██║                            "white"║\n"nboldw
#define end_gagne3	bgreen bold "║"green"                            ██║  ███╗███████║██║  ███╗██╔██╗ ██║█████╗  ██║                            "white"║\n"nboldw
#define end_gagne4	bgreen bold "║"green"                            ██║   ██║██╔══██║██║   ██║██║╚██╗██║██╔══╝  ╚═╝                            "white"║\n"nboldw
#define end_gagne5	bgreen bold "║"green"                            ╚██████╔╝██║  ██║╚██████╔╝██║ ╚████║███████╗██╗                            "white"║\n"nboldw
#define end_gagne6	bgreen bold "║"green"                             ╚═════╝ ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═╝                            "white"║\n"nboldw

#endif