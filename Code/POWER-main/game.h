#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#include "plateau.h"

struct game
{
    int gagnant_partie;
    S_plateau plateau_partie;
    S_joueur* joueurs_partie; //tableau contenant tous les joueurs
};
typedef struct game S_game;


typedef enum{
    saisie_zoom = 0,
    saisie_deplacer,
    saisie_achat,
    saisie_sortie,
    saisie_echange,
    saisie_lancement,
    saisie_fintour,
    taille_saisie_joueur,
} saisie_joueur;


S_game creer_game();
int saisieAction(int nbcoup);
void supprimer_pieces_inexistantes(S_game * g1);
bool decompte_egalite_combat(S_game*g1,int x,int y,int power_max,int indice_max);
int decompte_joueur_combat(S_game*g1,int x, int y);
void calcul_gagnant_combat(S_game * g1,int x, int y,int * power_max, int * indice_max);
bool multiple_gagnants_combat(S_game * g1,int x, int y, int * power_max, int * indice_max);
void resolution_des_combats(S_game*g1);
void actions_de_fin_de_tour(S_game * g1);
void verifier_victoire(S_game * g1);
void zoom(S_joueur * joueurs_partie,int num_joueur);
void separer_unites(S_game * g1, int num_joueur, int num_piece, bool en_reserve);
void faire_payer_piece(S_game * g1, int num_joueur);
S_game jouer_game(S_game g1);


#endif // GAME_H_INCLUDED
