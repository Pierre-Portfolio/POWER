#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "cases.h"
<<<<<<< HEAD

#define lignes 8
#define colonnes 8

void affiche_plateau(S_cases plateau[lignes][colonnes]);

=======

//variable
#define ligne 8
#define colonne 8

struct plateau
{
    S_cases cases[ligne][colonne];

};
typedef struct plateau S_plateau;

void Affiche_plateau(S_plateau p1);

>>>>>>> 79808c08be2292613da5de23c58470a85a8c9b49
#endif // PLATEAU_H_INCLUDED
