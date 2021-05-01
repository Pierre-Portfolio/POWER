#include "stdio.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

#include "definition.h"
#include "Initialisation.h"
#include "affichage.h"


void ecriture(char texte[]){

    int i=0;
    char fin=';';
    printf("\t");
    while(texte[i]!=fin){

        printf("%c",texte[i]);
        i++;
        Sleep(20);
    }

}
