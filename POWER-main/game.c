#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "affichage.h"
#include "plateau.h"
#include "game.h"

//initialisation de la partie
S_game creer_game()
{
    S_plateau p1={initialisation_cases()};
    printf("1");
    //affiche_plateau(p1);
    S_joueur * joueurs=initialisation_joueurs();
    printf("2");
    return (S_game){0,p1,joueurs};
}

//environnement de tests
int saisieAction(int nbcoup)
{
    if(nbcoup==0) return 3;

    //demander a l'utilisateur ce qu'il souhaite faire
    int nombreEntre = -1;
    while ((nombreEntre != 1) && (nombreEntre != 2))
    {
        printf("%d\n",nbcoup);
        if(nbcoup == 5)
        {
            printf("Quelle action souhaitez vous faire ?\n1 : deplacer un pion\n2 : echanger des powers\n");
        }
        else
        {
            printf("Quelle action souhaitez vous faire ?\n1 : deplacer un pion\n2 : echanger des powers\n3: Fin de tour\n");
        }
        scanf("%d", &nombreEntre);
        if(nbcoup == 5 && nombreEntre==3)
        {
            nombreEntre = -1;
        }
    }
    return nombreEntre;
}

void deplacerPion()
{
    //Demander quel pion est a deplacer
    /* char* pion_a_bouger;
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
    */
}


void echangePower()
{

}

S_game jouer_game(S_game g1)
{
    while(g1.etat_partie == 0 )                     //boucle infinie de la partie
    {
        affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
        printf("avant creer game3\n");
        // pour le tour de chaque joueur
        int result;
        for (int i=0; i<NBJOUEURS; i++)
        {
            do
            {
                // on demande au joueur de saisir son action
                printf("----------------Joueur %d------------------\n",i);
                printf("-----Nombre actions tour restantes %d------\n",g1.joueurs_partie[i].nbactionTour);

                result = saisieAction(g1.joueurs_partie[i].nbactionTour);
                //printf("action valide detectee car entree = %d\n",result);
                switch(result)
                {
                case 1: //'1' = code ascii
                    deplacerPion();break;
                case 2:
                    echangePower();break;
                case 3:
                    printf("Votre tour est fini\n");break;
                default:
                    printf("Erreur de saisie inconnue\n");
                }
                g1.joueurs_partie[i].nbactionTour --;
            }
            while(result!=3);

            // on reset le nbr d'action
            //g1.joueurs_partie.nbactionTour = 5;
        }

        // on analyse les coups de chaque joueur
        //...

        // on verifie si c'est la fin de la partie
        g1.etat_partie = 1;                         //fin de la boucle infinie==>fin de la partie
    }
    return g1;
}
