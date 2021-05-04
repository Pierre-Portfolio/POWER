#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "game.h"


//environnement de tests


int main(){

    /*S_joueur tabinfos[NBjoueurs];
    S_unitjoueur tabpions[NBjoueurs];

    system("CLS");*/
    S_game g1=creer_game();
    affiche_plateau2(g1.plateau_partie);


    return 0;
}



