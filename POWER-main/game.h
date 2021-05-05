#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

struct game
{
    int etat_partie;
    S_plateau plateau_partie;
    S_joueur* joueurs_partie;
};
typedef struct game S_game;


S_game creer_game();

#endif // GAME_H_INCLUDED
