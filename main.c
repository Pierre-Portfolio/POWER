#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void color (int couleurDuTexte, int couleurDuFond);

int main()
{
    printf("\n\t");
    color(15,7);
    printf("\n\t%c        %c",186,186);color(15,0);printf("\n\t%c        %c",186,186);
    //printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187,  218,196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,194,  196,196,196,196,196,196,196,196,191,  201,205,205,205,205,205,205,205,205,187);
   // printf("\n\t  %c";color(15,7)"   1.1  "color(15,0)"%c   %c   1.2  %c   1.3  %c   1.4  %c   %c   1.5  %c   %c   1.6  %c   1.7  %c   1.8  %c   %c   1.9  %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    //printf("\n\t1 %c  VERT  %c   %c   EAU  %c   EAU  %c   EAU  %c   %c  ILE N %c   %c   EAU  %c   EAU  %c   EAU  %c   %c  BLEU  %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    //printf("\n\t  %c   HG   %c   %c        %c        %c        %c   %c        %c   %c        %c        %c        %c   %c   HG   %c",186,186,179,179,179,179,186,186,179,179,179,179,186,186);
    //printf("\n\t  %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c   %c%c%c%c%c%c%c%c%c%c",200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188,  192,196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,193,  196,196,196,196,196,196,196,196,217,  200,205,205,205,205,205,205,205,205,188);


    return 0;
}


void color (int couleurDuTexte, int couleurDuFond)
{
     HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
     SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
