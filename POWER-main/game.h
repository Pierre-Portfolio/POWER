#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

struct game
{
    int etat_partie;
    S_plateau plateau_partie;
    S_joueur* joueurs_partie; //tableau contenant tous les joueurs
};
typedef struct game S_game;


S_game creer_game();
int saisieAction(int nbcoup);
void deplacerPion();
void echangePower();
S_game jouer_game(S_game g1);

#endif // GAME_H_INCLUDED
