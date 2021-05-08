#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "cases.h"
#include "definition.h"


struct plateau{
    S_cases ** cases;
};
typedef struct plateau S_plateau;

void affiche_plateau(S_plateau plateau,S_joueur* joueurs_partie);
void affiche_unites(int x,int y,S_joueur* joueur_partie);

#endif // PLATEAU_H_INCLUDED