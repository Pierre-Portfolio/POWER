#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "affichage.h"
#include "plateau.h"
#include "game.h"

//initialisation de la partie
S_game creer_game()
{
    S_plateau p1={initialisation_cases()};
    //affiche_plateau(p1);
    S_joueur * joueurs=initialisation_joueurs();
    return (S_game){0,p1,joueurs};
}
