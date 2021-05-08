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
    //affiche_plateau(p1);
    S_joueur * joueurs=initialisation_joueurs();
    return (S_game){0,p1,joueurs};
}

//environnement de tests
int saisieAction(int nbcoup)
{
    if(nbcoup==0) return 3;

    //demander a l'utilisateur ce qu'il souhaite faire
    int nombreEntre = -1;
    while ((nombreEntre != 0) && (nombreEntre != 1) && (nombreEntre != 2) && (nombreEntre != 3))
    {
        printf("Quelle action souhaitez vous faire ?\n0 : zoom sur les unite d'une case\n1 : deplacer un pion\n2 : echanger des powers\n3 : Fin de tour\n");
        scanf("%d", &nombreEntre);
    }
    return nombreEntre;
}

void * deplacerPion(S_joueur le_joueur)
{
    int x, y;
    enum_type_pion type_pion;
    printf("De quelle case est le pion que vous souhaitez deplacer ?\nEn x (horizontal) : \n");
    scanf("%d",&x);
    printf("En y (vertical) : \n");
    scanf("%d",&y);
    affiche_mes_unites_numerotees(x,y,le_joueur);
    printf("Quel pion voulez-vous deplacer ?\n");
    scanf("%d",&type_pion);
    int indice_pion;
    for(int i=0;i<le_joueur.nbpions;i++)
    {
        if(le_joueur.tabpion[i].positions.position_x==x && le_joueur.tabpion[i].positions.position_y==y && le_joueur.tabpion[i].type_pion==type_pion)
        {
            indice_pion=i;
            break; //n'avoir qu'un seul pion qui repond aux conditions du if
        }
    }
}

bool verifier_case_juste(int x, int y, S_plateau plateau, S_pions pion, int ancienne_couleur, int * nb_chgmt_couleur)
{
    if(pion_type_eau[pion.type_pion]!=(plateau.cases[y][x].terrain==eau))
    {
        return false;
    }
    int nouvelle_couleur=plateau.cases[y][x].joueur;
    if(nouvelle_couleur!=ancienne_couleur)
    {
        *nb_chgmt_couleur ++;
        if(*nb_chgmt_couleur>1)
        {
            return false;
        }
    }
}

bool verifier_chemin(S_plateau plateau, S_pions pion, int x_destination, int y_destination)
{
    int x1 = pion.positions.position_x; //x de départ
    int y1 = pion.positions.position_y; //y de départ
    int x2 = x_destination; //x de fin
    int y2 = y_destination; //y de fin
    int dx = x2-x1; //distance a bouger sur l'axe x
    int dy = y2-y1; //distance a bouger sur l'axe y
    int actuellement_x = x1; //position actuelle en mouvement sur l'axe x
    int actuellement_y = x2; //position actuelle en mouvement sur l'axe y

    int nombre_de_tour = max(dx,dy); //distance sur le plus grand axe -> si on avance de 4 horizontal et 1 vertical, il faut 4 tours

    float add_x = dx/nombre_de_tour; //déplacement à chaque tour sur l'axe X (peut être plus petit de 1)
    float add_y = dy/nombre_de_tour; //déplacement à chaque tour sur l'axe Y (peut être plus petit de 1)
    float actuellement_x_float = actuellement_x; //positon actuelle sur l'axe X SUR LA LIGNE DROITE (donc pas en case entière)
    float actuellement_y_float = actuellement_y; //positon actuelle sur l'axe Y SUR LA LIGNE DROITE (donc pas en case entière)

    bool mouvement_valide = true;

    if(nombre_de_tour > distance_de_déplacement_autorise)
    {
        mouvement_valide = false;
    }

    int nb_chgmt_couleur=0;
    int ancienne_couleur;
    while(actuellement_x != x2 && actuellement_y != y2)   //tant qu'on est pas arrivé
    {
        ancienne_couleur=plateau.cases[y1][x1].joueur;
        actuellement_x_float += add_x;
        actuellement_y_float += add_y;
        actuellement_x = (int)(actuellement_x_float+0.5f); // on arrondi (+0.5 => pas de round en C)
        actuellement_y = (int)(actuellement_y_float+0.5f); // on arrondi (+0.5 => pas de round en C)

        if(!verifier_case_juste(actuellement_x,actuellement_y,plateau,pion,ancienne_couleur,&nb_chgmt_couleur))
        {
            mouvement_valide = false;
        }

    }
}

void echangePower()
{
    //code check
}

S_game jouer_game(S_game g1)
{
    while(g1.etat_partie == 0 )                     //boucle infinie de la partie
    {
        // pour le tour de chaque joueur
        int result;
        for (int i=0; i<NBJOUEURS; i++)
        {
            printf("\n\n\n\n\n");
            affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
            printf("----------------Joueur %d------------------\n",i);
            do
            {
                // on demande au joueur de saisir son action

                printf("-----Nombre actions tour restantes %d------\n",g1.joueurs_partie[i].nbactionTour);

                result = saisieAction(g1.joueurs_partie[i].nbactionTour);
                //printf("action valide detectee car entree = %d\n",result);
                switch(result)
                {
                case 0:
                    zoom(g1.joueurs_partie);
                    break;//joueur_partie sans [] car on veut les pions de tous les joueurs
                case 1: //'1' = code ascii
                    deplacerPion(g1.joueurs_partie[i]);
                    break;
                case 2:
                    echangePower();
                    break;
                case 3:
                    printf("Votre tour est fini\n");
                    break;
                default:
                    printf("Erreur de saisie inconnue\n");
                }
                if(result!=0)
                {
                    g1.joueurs_partie[i].nbactionTour --;
                }
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

void zoom(S_joueur * joueurs_partie) //Zoom de la case demandee
{
    int x,y;
    printf("Quelle case souhaitez-vous agrandir?\nEn x (horizontal) : \n");
    scanf("%d",&x);
    printf("En y (vertical) :\n");
    scanf("%d",&y);
    affiche_unites(x,y,joueurs_partie);
}
