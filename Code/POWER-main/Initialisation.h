#ifndef INITIALISATION_H_INCLUDED
#define INITIALISATION_H_INCLUDED
#include "plateau.h"
#include "cases.h"


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "definition.h"
#include "Initialisation.h"
#include "cases.h"
#include "plateau.h"
#include "util.h"


S_pions chasseur(int position_x,int position_y);
S_pions destroyer(int position_x,int position_y);
S_pions tank(int position_x,int position_y);
S_pions regiment(int position_x,int position_y);
S_pions bombardier(int position_x,int position_y);
S_pions croiseur(int position_x,int position_y);
S_pions un_char(int position_x,int position_y);
S_pions soldat(int position_x,int position_y);
S_pions megamissile(int position_x,int position_y);
S_pions creer_pion_de_type(enum_type_pion type_pion, int x, int y);
S_joueur * initialisation_joueurs();
S_pions * initialisation_pieces(int num_joueur);
S_cases ** initialisation_cases();
#endif // INITIALISATION_H_INCLUDED
