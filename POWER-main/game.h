#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

struct game
{
    int gagnant_partie;
    S_plateau plateau_partie;
    S_joueur* joueurs_partie; //tableau contenant tous les joueurs
};
typedef struct game S_game;


S_game creer_game();
int saisieAction(int nbcoup);
void * deplacerPion(S_plateau plateau, S_joueur le_joueur, int num_joueur);
void echangePower();
S_game jouer_game(S_game g1);

#endif // GAME_H_INCLUDED
