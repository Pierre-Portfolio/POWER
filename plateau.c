#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"

void affiche_plateau(S_cases p1[LIGNES][COLONNES])
{
    //printf("DANS Plateau.c : %d \n",p1[7][7].couleur);

    //printf("\ntest: %d",p1.lignes);

void print_case1 (S_cases c){
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

void print_case5 (S_cases c){
    printf(" %c%c%c%c%c%c%c%c ",200,205,205,205,205,205,205,188);
}
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            print_case1(p1[i][j]);
        }
        printf("\n");
        for(int j=0;j<9;j++){
            print_case2(p1[i][j],i,j);
        }
        printf("\n");
        for(int j=0;j<9;j++){
            print_case3(p1[i][j]);
        }
        printf("\n");
        for(int j=0;j<9;j++){
            print_case4(p1[i][j]);
        }
        printf("\n");
        for(int j=0;j<9;j++){
            print_case5(p1[i][j]);
        }
        printf("\n");
    }
}
