#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED
#include "plateau.h"
#include "cases.h"

S_joueur * initialisation_joueurs();
S_pions * initialisation_pieces(int num_joueur);
S_cases ** initialisation_cases();

#endif // INITIALISATION_H_INCLUDED
