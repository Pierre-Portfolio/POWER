#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "definition.h"
#include "Initialisation.h"
#include "game.h"
#include "util.h"

int main()
{
    // on crée une partie
    S_game g1=creer_game();
    g1=jouer_game(g1);
    printf("La partie est terminee, le gagnant est : ");
    return 0;
}



