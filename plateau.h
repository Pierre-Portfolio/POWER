#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "cases.h"

//variable
#define ligne 8
#define colonne 8

struct plateau
{
    S_cases cases[ligne][colonne];

};
typedef struct plateau S_plateau;

void Affiche_plateau(S_plateau p1);

#endif // PLATEAU_H_INCLUDED
