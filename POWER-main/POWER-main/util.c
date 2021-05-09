#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "definition.h"
#include "Initialisation.h"
#include "game.h"
#include "util.h"

void rajouter(void** tableau,int taille_element, int* taille_tableau,void* element)
/* taille element prend la valeur du sizeof() : c'est la taille d'un element de 'tableau'
realloc : refaire malloc ==> agrandit le malloc/tableau*/
{
    *tableau=realloc(*tableau,((*taille_tableau)+1)*taille_element); //redimensionnement du tableau, quel qu'il soit
    memcpy((*tableau)+(*taille_tableau)*taille_element,element,taille_element); //dans la memoire, on a rajoute l'element à la fin du tableau// taille_tableau : position de la case que l'on vient de créer
    (*taille_tableau)++;

}

void supprimer(void* tableau, int taille_element, int *taille_tableau,int indice)
{
    memcpy(tableau+indice*taille_element,tableau+((*taille_tableau)-1)*taille_element,taille_element); //case du tableau que l'on veut supprimer //calcul du debut de la derniere case //indice x taille d'une case = adresse de debut de cette case
    (*taille_tableau)--;
}


