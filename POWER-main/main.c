#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

#include "definition.h"
#include "Initialisation.h"
#include "game.h"
#include "util.h"

int main()
{

    printf("\t\t\t********************************Bienvenue dans une partie de POWER********************************\n\nNous vous invitons a etendre la console en plein ecran, afin de profiter d'une experience totale de la partie qui va demarer dans 5sec\n\n");

    #ifdef RELEASE //ATTENTION !!
    sleep(6); //TODO remettre 6
    #endif

    // on crée une partie
    S_game g1=creer_game();

    // on joue avec la partie creee
    g1=jouer_game(g1);

    printf("La partie est terminee, le gagnant est : le joueur %s",joueur_nom[g1.gagnant_partie]);
    return 0;
}



