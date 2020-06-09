/*
*  Code écrit par Briglim
*
*  Tested on:
*  Konsole
*  Mate terminal
*  Unity terminal
* 
* ANSI Colors used:
*     Reset terminal color: \x1B[0m
*     black: \x1B[30m
*     red: \x1B[31m
*     green: \x1B[32m
*     yellow: \x1B[33m
*     blue: \x1B[34m
*     magenta: \x1B[35m
*     cyan: \x1B[36m
*     white: \x1B[37m
*/

#include <windows.h>
 
#define INFO               "\x1B[34mℹ"
#define CORRECTBOX         "\x1B[32m☑"
#define WRONGBOX           "\x1B[31m❎"
#define WRONG_ANSWER       "\x1B[31m✔"
#define CORRECT_ANSWER     "\x1B[32m✖"
#define WARNING_ALERT      "\x1B[33m⚠"
#define LOADING_SIGN       "\x1B[33m⌛"
#define RECYCLE_SIGN       "\x1B[32m♻"
 
#define RESET              "\x1B[0m"
#define BLACK              "\x1B[30m"
#define RED                "\x1B[31m"
#define GREEN              "\x1B[32m"
#define YELLOW             "\x1B[33m"
#define BLUE               "\x1B[34m"
#define MAGENTA            "\x1B[35m"
#define CYAN               "\x1B[36m"
#define WHITE              "\x1B[37m"
 
#include <stdio.h>
#include <string.h>
 
int main() {
    system("chcp 65001");
    
    printf(INFO "Information topic \n");
    printf("Correct box " CORRECTBOX "\n");
    printf("Wrong box " WRONGBOX "\n");
    printf("Correct answer " CORRECT_ANSWER "\n");
    printf("Wrong answer " WRONG_ANSWER "\n");
    printf("Warning alert " WARNING_ALERT "\n");
    printf("Loading " LOADING_SIGN "\n");
    printf("Recycle " RECYCLE_SIGN "\n");
    // Example of a color line
    printf(RED "Voici une ligne en rouge" RESET);
    // Reset the color of the terminal
    printf("\n La ligne a reppris la couleur du terminal\n");
    return 0;
}