#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "game.h"


//environnement de tests

int saisieAction(int nbcoup){
    //demander a l'utilisateur ce qu'il souhaite faire
    int nombreEntre = -1;
    while ((nombreEntre != 1) && (nombreEntre != 2))
    {
        if(nbcoup == 5){
                printf("Quelle action souhaitez vous faire ?\n1 : deplacer un pion\n2 : echanger des powers\n");
        }else{
                printf("Quelle action souhaitez vous faire ?\n1 : deplacer un pion\n2 : echanger des powers\n3: Fin de tour\n");
        }
        scanf("%d", &nombreEntre);
        if(nbcoup == 5 && nombreEntre==3){ //nbcoup!=5 ???
            nombreEntre = -1;
        }
    }
    return nombreEntre;
}

void deplacerPion(){
    //Demander quel pion est a deplacer
    char* pion_a_bouger;
    int position_entree_x,position_entree_y;

    printf("Quel pion souhaitez-vous deplacer?\n");
    scanf("%s",pion_a_bouger);

    //Verifier que le pion a le droit d'aller dans la case voulue
    int test_comp1=strcmp(pion_a_bouger,destroyer); //attribuer la nature du pion entre
    switch(test_comp1)
    {
        case 1:
        case -1:
        case 0: strcpy(S_pions.type_pion,pion_a_bouger);break;
        default: printf("*****Erreur de traitement*****");
    }



    //demander d'ou il vient et ou il va
    do
    {
        printf("Quelle est sa position actuelle?\nEn x:");
        scanf("%d",&position_entree_x);
        if(position_entree_x== )
        {
            printf("\nEn y:");
            scanf("%d",&position_entree_y);
            if(position_entree_y== )
                printf("\nc'est bien votre position actuelle\n");
        }else
            printf("\nla position entree est incorrecte");
    }while(position_entree_x&&position_entree_y<9 && position_entree_x&&position_entree_y>0);

    //Verifier que le deplacement est autorise : pas de passages par des cases non-autorisees

}


void echangePower(){

}


int main(){
    // on crée une partie
    S_game g1=creer_game();

    // tant que la partie est en cours
    while(g1.etat_partie == 0 ){                    //boucle infinie de la partie
        affiche_plateau(g1.plateau_partie);

        // pour le tour de chaque joueur
        for (int i=0;i<NBJOUEURS;i++){
            // on demande au joueur de saisir son action
            int nbcoup = 5;
            int result = saisieAction(nbcoup);
            printf("action valide detectee car entrée = %d",result);

            switch(result)
               {
               case '1':deplacerPion();
               case '2':echangePower();
               case '3':printf("Votre tour est fini");
               default: printf("Erreur de saisie inconnue");
               }



            /*int nbactionrestante = g1.joueurs_partie.nbactionTour;
            g1.joueurs_partie.nbactionTour -> nbactionrestante - 1;*/
            // on reset le nbr d'action
            //g1.joueurs_partie.nbactionTour = 5;
        }

        // on analyse les coups de chaque joueur
        //...

        // on verifie si c'est la fin de la partie
        g1.etat_partie = 1;                         //fin de la boucle infinie==>fin de la partie
    }
    printf("La partie est terminé, le gagnant est : ");
    return 0;
}



