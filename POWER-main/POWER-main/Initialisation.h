#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED
#include "plateau.h"
#include "cases.h"

S_joueur * initialisation_joueurs();
S_pions * initialisation_pieces(int num_joueur);
S_cases ** initialisation_cases();

S_pions creer_pion_de_type(enum_type_pion type_pion, int x, int y);

#endif // INITIALISATION_H_INCLUDED
