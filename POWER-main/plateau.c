#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include <windows.h>
#include <assert.h>


void affiche_plateau(S_plateau p1,S_joueur* joueurs_partie )
{
    printf("\n\t       1            2        3        4            5           6        7        8            9");
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
    printf("\n\t  %c",186);color(15,2);printf("%03d  %03d",somme_powers_a(1,1,joueurs_partie,0),somme_powers_a(1,1,joueurs_partie,1));color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,1);printf("   08   ");color(15,0);printf("%c",186);
    printf("\n\t1 %c",186);color(15,2);printf("  HQ.V  ");color(15,0);printf("%c   %c    E   %c    E   %c    E   %c   %c   IN   %c   %c    E   %c    E   %c    E   %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,1);printf("  HQ.B  ");color(15,0);printf("%c",186);
    printf("\n\t  %c",186);color(15,2);printf("%03d  %03d",somme_powers_a(1,1,joueurs_partie,2),somme_powers_a(1,1,joueurs_partie,3));color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);

    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191);
    printf("\n\t  %c%03d  %03d%c   %c",179,somme_powers_a(1,2,joueurs_partie,0),somme_powers_a(1,2,joueurs_partie,1),179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t2 %c    E   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c%03d  %03d%c   %c",179,somme_powers_a(1,2,joueurs_partie,2),somme_powers_a(1,2,joueurs_partie,3),179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t3 %c    E   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t4 %c    E   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
    printf("\n\t  %c        %c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c        %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    printf("\n\t5 %c   IW   %c   %c    E   %c    E   %c    E   %c   %c   IX   %c   %c    E   %c    E   %c    E   %c   %c   IE   %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    printf("\n\t  %c        %c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c        %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);

    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t6 %c    E   %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t7 %c    E   %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t8 %c    E   %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217);

    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
    printf("\n\t  %c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);
    printf("\n\t9 %c",186);color(15,4);printf("  HQ.R  ");color(15,0);printf("%c   %c    E   %c    E   %c    E   %c   %c   IS   %c   %c    E   %c    E   %c    E   %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,6);printf("  HQ.J  ");color(15,0);printf("%c",186);
    printf("\n\t  %c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c\n",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);
}

void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
// 0.Noir
// 1.Bleu fonc?
// 2.Vert fonc?
// 3.Turquoise
// 4.Rouge fonc?
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc?
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc*/

int somme_powers_a(int position_x, int position_y, S_joueur* joueurs_partie,int num_joueur)
{
    //printf("---numero joueur :%d\n",num_joueur);
    int resultat=0;
    for(int k=0; k<joueurs_partie[num_joueur].nbpions; k++)
    {
        //printf("---numero de pieces k= %d\n",k);
        if(joueurs_partie[num_joueur].tabpion[k].positions.position_x==position_x &&
                joueurs_partie[num_joueur].tabpion[k].positions.position_y==position_y)
        {
            resultat+=joueurs_partie[num_joueur].tabpion[k].puissance; //resultat+= : rajouter à resultat
        }
    }
    return resultat;
}






void affiche_plateau2(S_plateau p1, S_joueur* joueurs_partie)
{
    printf("  ");
    for(int x=1;x<=9;x++){

            print_case_num(x);
        }
        printf("\n");
    for(int y=1;y<=9;y++){
        printf("  ");
        for(int x=1;x<=9;x++){
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_dessus();
            print_color(-1);
        }
        printf("%c\n",255);
        printf("  ");
        for(int x=1;x<=9;x++){
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_power1(joueurs_partie,x,y);
            print_color(-1);
        }
        printf("%c\n",255);
        printf("%d ",y);
        for(int x=1;x<=9;x++){
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_terrain(p1.cases[y-1][x-1]);
            print_color(-1);
        }
        printf("%c\n",255);
        printf("  ");
        for(int x=1;x<=9;x++){
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_power2(joueurs_partie,x,y);
            print_color(-1);
        }
        printf("%c\n",255);
        printf("  ");
        for(int x=1;x<=9;x++){
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_dessous();
            print_color(-1);
        }
        printf("%c\n",255);
    }
}
void print_case_num(int num_case){
    printf("       %d        ",num_case);
}
void print_case_dessus (){
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c ",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
}

void print_case_power1(S_joueur* joueurs_partie, int x, int y){
    printf(" %c%04d    %04d%c ",186,somme_powers_a(x,y,joueurs_partie,0),somme_powers_a(x,y,joueurs_partie,1),186);
}
void print_case_power2(S_joueur* joueurs_partie, int x, int y){
    printf(" %c%04d    %04d%c ",186,somme_powers_a(x,y,joueurs_partie,3),somme_powers_a(x,y,joueurs_partie,2),186);
}

void print_case_terrain (S_cases c){
    switch(c.terrain)
    {
       case 1 : printf(" %c    ILE     %c ",186,186); break;
       case 2 : printf(" %c    EAU     %c ",186,186); break;
       case 3 : printf(" %c    HG      %c ",186,186); break;
       default : printf("ERROR");
    }
}

void print_color(int num_joueur)
{
    if(num_joueur==-1)
    {
        color(15,0);
        return;
    }
    color(15,joueur_vers_couleur[num_joueur]);
}

void print_case_dessous (){
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c ",200,205,205,205,205,205,205,205,205,205,205,205,205,188);
}


void affiche_unites(int x,int y,S_joueur* joueurs_partie)
{
    printf("Voici les unites presentes sur la case %d.%d\n",x,y);

    for(int i=0;i<NBJOUEURS;i++)
    {
        int decompte_unites[taille_enum_pion]={0}; //initialisation du tableau à 0
        for(int j=0;j<joueurs_partie[i].nbpions;j++)
        {
            if(joueurs_partie[i].tabpion[j].positions.position_x==x && joueurs_partie[i].tabpion[j].positions.position_y==y)
            {
                decompte_unites[joueurs_partie[i].tabpion[j].type_pion]++; //pour chaque pion de chaque joueur, on incremente si le pion est present sur la case
            }
        }
        print_color(i);
        affiche_decompte_unite(decompte_unites,false);
        print_color(-1);
    }
}
void affiche_mes_unites_numerotees(int x,int y,S_joueur le_joueur)  //S_joueur* <==> S_joueur[]
{
    printf("Voici les unites presentes sur la case %d.%d\n",x,y);

        int decompte_unites[taille_enum_pion]={0}; //initialisation du tableau à 0
        for(int j=0;j<le_joueur.nbpions;j++)
        {
            if(le_joueur.tabpion[j].positions.position_x==x && le_joueur.tabpion[j].positions.position_y==y)
            {
                decompte_unites[le_joueur.tabpion[j].type_pion]++; //pour chaque pion de chaque joueur, on incremente si le pion est present sur la case
            }
        }
        affiche_decompte_unite(decompte_unites,true);
}

void affiche_decompte_unite(int decompte_unite[taille_enum_pion],bool numerote)
{
    for(int i=0;i<taille_enum_pion;i++)
    {
        if(decompte_unite[i]==0)continue; //on n'affiche rien si le decompte egale a 0; continue ignore la suite jusqu'a la fin de la boucle

        printf("%dx",decompte_unite[i]);
        switch(i)
        {
            case type_bombardier:printf("Bombardier");break;
            case type_char:printf("Char");break;
            case type_chasseur:printf("Chasseur");break;
            case type_destroyer:printf("Destroyeur");break;
            case type_croiseur:printf("Croiseur");break;
            case type_megamissile:printf("Mega-missile");break;
            case type_regiment:printf("Regiment");break;
            case type_soldat:printf("Soldat");break;
            case type_tank:printf("Tank");break;
            case type_piece_inexistante:break; //ne fait rien
            default:assert(0);
        }
        if(numerote)
        {
            printf("   -%d-",i); //afficher la numerotation d'un pion ou pas
        }
        printf("\n");
    }
}

