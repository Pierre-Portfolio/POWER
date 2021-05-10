#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>
#include <windows.h>

#include "definition.h"
#include "initialisation.h"
#include "game.h"
#include "util.h"
#include "noms_joueurs.h"

int main()
{

    printf("\t\t\t********************************Bienvenue dans une partie de POWER********************************\n\nNous vous invitons a etendre la console en plein ecran, afin de profiter d'une experience totale de la partie qui va demarer dans 5sec\n\n");

#ifdef RELEASE //ATTENTION !!
    Sleep(6000);
#endif

    // on crée une partie
    S_game g1=creer_game();

    // on joue avec la partie creee
    g1=jouer_game(g1);

    printf("La partie est terminee, le gagnant est : le joueur %s",joueur_nom[g1.gagnant_partie]);
    return 0;
}



