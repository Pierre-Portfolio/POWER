#ifndef PLATEAU_H_INCLUDED
#define PLATEAU_H_INCLUDED
#include "cases.h"
#include "definition.h"


struct plateau{
    S_cases ** cases;
};
typedef struct plateau S_plateau;

void affiche_plateau(S_joueur* joueurs_partie);
void affiche_unites(int x,int y,S_joueur* joueur_partie);

int affiche_mes_unites_numerotees(int x,int y,S_joueur le_joueur);

int affiche_mes_unites_reserve(S_joueur le_joueur,bool numerote);  //S_joueur* <==> S_joueur[]

int somme_powers_a(int position_x, int position_y, S_joueur* joueurs_partie,int num_joueur);
void affiche_plateau2(S_plateau p1, S_joueur* joueurs_partie);
void color (int couleurDuTexte, int couleurDuFond);


void print_case_num(int num_case);
void print_case_dessus();
void print_case_power1(S_joueur* joueurs_partie, int x, int y, int copie_couleur_case);
void print_case_power2(S_joueur* joueurs_partie, int x, int y, int copie_couleur_case);
void print_case_terrain (S_cases c);
void print_color(int num_joueur);
void print_case_dessous ();
void affiche_decompte_unite(int decompte_unite[taille_enum_pion],bool numerote);

#endif // PLATEAU_H_INCLUDED
