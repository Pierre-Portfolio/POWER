#include "plateau.h"

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <assert.h>



int somme_powers_a(int position_x, int position_y, S_joueur* joueurs_partie,int num_joueur)
{
    //[INSTRUMENTALISATION DE DEBUG]printf("---numero joueur :%d\n",num_joueur);
    int resultat=0;
    for(int k=0; k<joueurs_partie[num_joueur].nbpions; k++)
    {
        //[INSTRUMENTALISATION DE DEBUG] printf("---numero de pieces k= %d\n",k);
        if(joueurs_partie[num_joueur].tabpion[k].positions.position_x==position_x &&
                joueurs_partie[num_joueur].tabpion[k].positions.position_y==position_y &&
                joueurs_partie[num_joueur].tabpion[k].type_pion!=type_piece_inexistante)
        {
            resultat+=joueurs_partie[num_joueur].tabpion[k].puissance; //resultat+= : rajouter à resultat <==> X=X+Y
        }
    }
    return resultat;
}
int somme_powers_reserve(S_joueur* joueurs_partie,int num_joueur)
{
    //[INSTRUMENTALISATION DE DEBUG]printf("---numero joueur :%d\n",num_joueur);
    int resultat=0;
    for(int k=0; k<joueurs_partie[num_joueur].nbpions_reserve; k++)
    {
        if(joueurs_partie[num_joueur].tabpion_reserve[k].type_pion!=type_piece_inexistante)
        {
            resultat+=joueurs_partie[num_joueur].tabpion_reserve[k].puissance; //resultat+= : rajouter à resultat <==> X=X+Y
        }
    }
    return resultat;
}

