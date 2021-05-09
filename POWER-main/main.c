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
    // on crée une partie
    S_game g1=creer_game();

    // on joue avec la partie creee
    g1=jouer_game(g1);

    printf("La partie est terminee, le gagnant est : le joueur %d",g1.gagnant_partie+1);
    return 0;
}



