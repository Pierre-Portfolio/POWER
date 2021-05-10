#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "cases.h"
#include "definition.h"


struct plateau{
    S_cases ** cases;
};
typedef struct plateau S_plateau;



int somme_powers_a(int position_x, int position_y, S_joueur* joueurs_partie,int num_joueur);
int somme_powers_reserve(S_joueur* joueurs_partie,int num_joueur);


#endif // PLATEAU_H_INCLUDED
