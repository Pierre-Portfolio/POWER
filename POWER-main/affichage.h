#ifndef AFFICHAGE_H_INCLUDED
#define AFFICHAGE_H_INCLUDED

#include "definition.h"
#include "plateau.h"

void color (int couleurDuTexte, int couleurDuFond);
void affiche_barre_status(S_joueur * joueur_partie);
void affiche_plateau2(S_plateau p1, S_joueur* joueurs_partie);
void print_case_num(int num_case);
void print_case_dessus ();
void print_case_dessous ();
void print_case_power1(S_joueur* joueurs_partie, int x, int y, int copie_color_case);
void print_case_power2(S_joueur* joueurs_partie, int x, int y, int copie_color_case);
void print_case_terrain (S_cases c);
void print_color(int num_joueur);
void affiche_unites(int x,int y,S_joueur* joueurs_partie);
int affiche_mes_unites_numerotees(int x,int y,S_joueur le_joueur);
int affiche_mes_unites_reserve(S_joueur le_joueur,bool numerote);
void affiche_decompte_unite(int decompte_unite[taille_enum_pion],bool numerote);

#endif // AFFICHAGE_H_INCLUDED
