#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "game.h"


//environnement de tests

int saisieAction(int nbcoup){
    //demander à l'utilisateur ce qu'il souhaite faire
    int nombreEntre = -1;
    while ((nombreEntre != 1) || (nombreEntre != 2))
    {
        if(nbcoup == 5){
                printf("Quel actions souhaitez vous faire ?\n1 : deplacer un pion\n2 : echanger des powers\n");
        }else{
                printf("Quel actions souhaitez vous faire ?\n1 : deplacer un pion\n2 : echanger des powers\n3: Fin de tour\n");
        }
        scanf("%d", &nombreEntre);
        if(nbcoup == 5 && nombreEntre==3){
            nombreEntre = -1;
        }
    }
    return nombreEntre;
}

void deplacerPion(){

}

void echangePower(){

}

int main(){
    // on crée une partie
    S_game g1=creer_game();

    // temps que la partie est en cour
    while(g1.etat_partie == 0 ){
        affiche_plateau2(g1.plateau_partie);

        // pour le tour de chaque joueurs
        for (int i = 0; i < NBJOUEURS ; i++ ){
            // on demander au joueur de saisir son action
            int nbcoup = 5;
            int result = saisieAction(nbcoup);
            printf("action valide detecter car entré = %d",result);

            switch(result)
               {
               case '1':deplacerPion();
               case '2':echangePower();
               case '3':printf("Votre tour est fini");
               default: printf("Erreur de saisie inconnu");
               }



            /*int nbactionrestante = g1.joueurs_partie.nbactionTour;
            g1.joueurs_partie.nbactionTour = nbactionrestante - 1;*/
            // on reset le nbr d'action
            //g1.joueurs_partie.nbactionTour = 5;
        }

        // on analyse les coups de chaque joueurs
        //...

        // on verifie si c'est la fin de la partie
        g1.etat_partie = 1;
    }
    printf("La partie est terminé, le gagnant est : ");
    return 0;
}



