#ifndef ORDRES_H_INCLUDED
#define ORDRES_H_INCLUDED

#include "definition.h"
#include "game.h"

#define CENTRE_ILE_BAS 3
#define CENTRE_ILE_HAUT 7

void afficher_les_types_de_pion();
bool verifier_case_terrain(int x, int y, S_plateau plateau, S_pions pion);
bool verifier_chemin(S_plateau plateau, S_pions pion, int x_destination, int y_destination);
void * deplacerPion(int num_joueur);
void * lancer_missile(int num_joueur);
void* achat(int num_joueur);
void* sortie(int num_joueur);
void* echange(int num_joueur);

bool executer_ordre_deplacement(S_game * g1, S_ordre_deplacement * deplacement);
bool executer_ordre_lancement(S_game * g1, S_ordre_lancement * lancement);
bool executer_ordre_achat(S_game * g1, S_ordre_achat * l_achat);
bool executer_ordre_echange(S_game * g1, S_ordre_echange * echange);
bool executer_ordre_sortie(S_game * g1, S_ordre_sortie * sortie);
void reinitialiser_dernier_ordre_pion(S_game * g1);

void executer_ordre(S_game * g1, S_feuille_ordres feuille_ordre[NBJOUEURS]);




#endif // ORDRES_H_INCLUDED
