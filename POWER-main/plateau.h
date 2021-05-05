#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "cases.h"


struct plateau{
    S_cases ** plateaux;
};
typedef struct plateau S_plateau;

void affiche_plateau(S_plateau plateau);

#endif // PLATEAU_H_INCLUDED
