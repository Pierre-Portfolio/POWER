#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include <windows.h>


void affiche_plateau(S_cases p1[LIGNES][COLONNES])
{
    printf("\n\t       0            1        2        3            4           5        6        7            8");
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
    printf("\n\t  %c",186);color(15,2);printf("   00   ");color(15,0);printf("%c   %c   01   %c   02   %c   03   %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,1);printf("   08   ");color(15,0);printf("%c",186);
    printf("\n\t0 %c",186);color(15,2);printf("  HQ.V  ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,1);printf("  HQ.B  ");color(15,0);printf("%c",186);
    printf("\n\t  %c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);

    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191);
    printf("\n\t  %c   10   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t1 %c    E   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c   12   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t2 %c    E   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c   13   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t3 %c    E   %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c",186);color(15,2);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c",186);color(15,1);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
    printf("\n\t  %c        %c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c        %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    printf("\n\t4 %c   IW   %c   %c    E   %c    E   %c    E   %c   %c   IX   %c   %c    E   %c    E   %c    E   %c   %c   IE   %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    printf("\n\t  %c        %c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c        %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);

    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,203,  205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,191);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t5 %c    E   %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t6 %c    E   %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,            195,196,196,196,196,196,196,196,196,180,  204,205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,206,  205,205,205,205,205,205,205,205,185,  195,196,196,196,196,196,196,196,196,180);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t7 %c    E   %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c    E   %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c    E   %c",186,  179,179);
    printf("\n\t  %c        %c   %c",179,179,186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c   %c",186,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c",186);color(15,6);printf("        ");color(15,0);printf("%c   %c        %c",186,  179,179);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,202,  205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,217);

    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
    printf("\n\t  %c",186);color(15,4);printf("   08   ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,6);printf("   88   ");color(15,0);printf("%c",186);
    printf("\n\t8 %c",186);color(15,4);printf("  HQ.R  ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,6);printf("  HQ.J  ");color(15,0);printf("%c",186);
    printf("\n\t  %c",186);color(15,4);printf("        ");color(15,0);printf("%c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c",186,179,179,179,179,186,186,179,179,179,179,186);color(15,6);printf("        ");color(15,0);printf("%c",186);
    printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);
}

void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
// 0.Noir
// 1.Bleu fonc�
// 2.Vert fonc�
// 3.Turquoise
// 4.Rouge fonc�
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc�
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc*/

void affiche_plateau2(S_cases p1[LIGNES][COLONNES])
{
    printf("DANS Plateau.c : %d \n",p1[8][0].terrain);

    //printf("\ntest: %d",p1.lignes);

void print_case1 (){
    printf(" %c%c%c%c%c%c%c%c ",201,205,205,205,205,205,205,187);
}

void print_case2 (S_cases c,int i, int j){
    printf(" %c %d.%d  %c ",186,i,j,186);
}

void print_case3 (S_cases c){
    switch(c.couleur)
    {
       case 1 : printf(" %cROUGE %c ",186,186); break;
       case 2 : printf(" %c VERT %c ",186,186); break;
       case 3 : printf(" %cJAUNE %c ",186,186); break;
       case 4 : printf(" %c BLEU %c ",186,186); break;
       case 5 : printf(" %cNEUTRE%c ",186,186); break;
       default : printf("ERROR");
    }
}

void print_case4 (S_cases c){
    switch(c.terrain)
    {
       case 1 : printf(" %c ILE  %c ",186,186); break;
       case 2 : printf(" %c EAU  %c ",186,186); break;
       case 3 : printf(" %c HG   %c ",186,186); break;
       default : printf("ERROR");
    }
}

void print_case5 (){
    printf(" %c%c%c%c%c%c%c%c ",200,205,205,205,205,205,205,188);
}
    printf("DANS MAIN : %d \n",p1[8][0].terrain);
    int redondance = 1;
    int start = 0;
    for(int i=0;i<9;i++){
        int j = 0;
        for(j=0;j<9;j++){
            print_case1();
        }
        printf("\n");
        for(j=start;j<9;j++){
            print_case2(p1[i][j],i,j);
        }
        printf("\n");
        for(j=start;j<9;j++){
            print_case3(p1[i][j]);
        }
        printf("\n");
        for(j=start;j<9;j++){
            print_case4(p1[i][j]);
        }
        printf("\n");
        for(j=0;j<9;j++){
            print_case5();
        }
        printf("\n");
    }
}


