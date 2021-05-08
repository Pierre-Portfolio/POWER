#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"



//******************************************************************INITIALISATIONS******************************************************************//


//******************************************INITIALISATIONS_joueurs***********************************************//

void initialisation_joueurs(S_joueur tabinfos[])
{

    int i;

    system("CLS");

    for(i=0; i<NBjoueurs; i++)
    {
        tabinfos[i].etat=1;
        tabinfos[i].numero_joueur=i+1;
        tabinfos[i].power=10;

        printf("\n\njoueur %d initialise**********************************",i+1);
        if (tabinfos[i].etat==1)
        {
            printf("\n\tle joueur est toujours en jeu");
        }
        else
        {
            printf("\n\tle joueur n'est plus en jeu");
        }

        printf("\n\tle numero du joueur est :%d",tabinfos[i].numero_joueur);
        printf("\n\tSon nombre de power est :%d",tabinfos[i].power);
    }

}


//******************************************INITIALISATIONS_pieces***********************************************//


void initialisation_pieces(S_unitjoueur tabpions[])
{

    system("CLS");
    int j,k;

    for(j=0;j<NBjoueurs;j++){

        for(k=0; k<CDT;k++){
            tabpions[j].chasseurs[k].num_piece=k+1;
            strcpy(tabpions[j].chasseurs[k].type_pion,"C");
            tabpions[j].chasseurs[k].positions.position_x=100;
            tabpions[j].chasseurs[k].positions.position_y=100;
            tabpions[j].chasseurs[k].positions.positionfutur_x=0;
            tabpions[j].chasseurs[k].positions.positionfutur_y=0;
            tabpions[j].chasseurs[k].num_joueur=j+1;
            tabpions[j].chasseurs[k].puissance=5;
            tabpions[j].chasseurs[k].deja_deplace=0;
            tabpions[j].chasseurs[k].dans_reserve=1;
            tabpions[j].chasseurs[k].rcbc_pion=0; //pas sur encore si la variable servira

            printf("\nchasseur %d INITIALISE************:",tabpions[j].chasseurs[k].num_piece);

            printf("\npositions chasseurs :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].chasseurs[k].positions.position_x,tabpions[j].chasseurs[k].positions.position_y,tabpions[j].chasseurs[k].positions.positionfutur_x,tabpions[j].chasseurs[k].positions.positionfutur_y);
            printf("\n\n\t\tle chasseur %d appartient au joueur %d\n\n",tabpions[j].chasseurs[k].num_piece,tabpions[j].chasseurs[k].num_joueur);

            tabpions[j].destroyers[k].num_piece=k+1;
            strcpy(tabpions[j].destroyers[k].type_pion,"D");
            tabpions[j].destroyers[k].positions.position_x=100;
            tabpions[j].destroyers[k].positions.position_y=100;
            tabpions[j].destroyers[k].positions.positionfutur_x=0;
            tabpions[j].destroyers[k].positions.positionfutur_y=0;
            tabpions[j].destroyers[k].num_joueur=j+1;
            tabpions[j].destroyers[k].puissance=10;
            tabpions[j].destroyers[k].deja_deplace=0;
            tabpions[j].destroyers[k].dans_reserve=1;
            tabpions[j].destroyers[k].rcbc_pion=0;

            printf("\ndestroyer %d INITIALISE************:",tabpions[j].destroyers[k].num_piece);

            printf("\npositions destroyers :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].destroyers[k].positions.position_x,tabpions[j].destroyers[k].positions.position_y,tabpions[j].destroyers[k].positions.positionfutur_x,tabpions[j].destroyers[k].positions.positionfutur_y);
            printf("\n\n\t\tle destroyer %d appartient au joueur %d\n\n",tabpions[j].destroyers[k].num_piece,tabpions[j].destroyers[k].num_joueur);

            tabpions[j].tanks[k].num_piece=k+1;
            strcpy(tabpions[j].tanks[k].type_pion,"T");
            tabpions[j].tanks[k].positions.position_x=100;
            tabpions[j].tanks[k].positions.position_y=100;
            tabpions[j].tanks[k].positions.positionfutur_x=0;
            tabpions[j].tanks[k].positions.positionfutur_y=0;
            tabpions[j].tanks[k].num_joueur=j+1;
            tabpions[j].tanks[k].puissance=3;
            tabpions[j].tanks[k].deja_deplace=0;
            tabpions[j].tanks[k].dans_reserve=1;
            tabpions[j].tanks[k].rcbc_pion=0;
            printf("\ntank %d INITIALISE************:",tabpions[j].tanks[k].num_piece);

            printf("\npositions tanks :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].tanks[k].positions.position_x,tabpions[j].tanks[k].positions.position_y,tabpions[j].tanks[k].positions.positionfutur_x,tabpions[j].tanks[k].positions.positionfutur_y);
            printf("\n\n\t\tle tank %d appartient au joueur %d\n\n",tabpions[j].tanks[k].num_piece,tabpions[j].tanks[k].num_joueur);

        }


        for(k=0; k<RCBC;k++){
            tabpions[j].regiments[k].num_piece=k+1;
            strcpy(tabpions[j].regiments[k].type_pion,"R");
            tabpions[j].regiments[k].positions.position_x=101;
            tabpions[j].regiments[k].positions.position_y=101;
            tabpions[j].regiments[k].positions.positionfutur_x=0;
            tabpions[j].regiments[k].positions.positionfutur_y=0;
            tabpions[j].regiments[k].num_joueur=j+1;
            tabpions[j].regiments[k].puissance=20;
            tabpions[j].regiments[k].deja_deplace=0;
            tabpions[j].regiments[k].dans_reserve=1;
            tabpions[j].regiments[k].rcbc_pion=0;
            printf("\nregiment %d INITIALISE************:",tabpions[j].regiments[k].num_piece);

            printf("\npositions regiments :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].regiments[k].positions.position_x,tabpions[j].regiments[k].positions.position_y,tabpions[j].regiments[k].positions.positionfutur_x,tabpions[j].regiments[k].positions.positionfutur_y);
            printf("\n\n\t\tle regiment %d appartient au joueur %d\n\n",tabpions[j].regiments[k].num_piece,tabpions[j].regiments[k].num_joueur);

            tabpions[j].bombardiers[k].num_piece=k+1;
            strcpy(tabpions[j].bombardiers[k].type_pion,"B");
            tabpions[j].bombardiers[k].positions.position_x=101;
            tabpions[j].bombardiers[k].positions.position_y=101;
            tabpions[j].bombardiers[k].positions.positionfutur_x=0;
            tabpions[j].bombardiers[k].positions.positionfutur_y=0;
            tabpions[j].bombardiers[k].num_joueur=j+1;
            tabpions[j].bombardiers[k].puissance=25;
            tabpions[j].bombardiers[k].deja_deplace=0;
            tabpions[j].bombardiers[k].dans_reserve=1;
            tabpions[j].bombardiers[k].rcbc_pion=0;
            printf("\nbombardier %d INITIALISE************:",tabpions[j].bombardiers[k].num_piece);

            printf("\npositions bombardiers :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].bombardiers[k].positions.position_x,tabpions[j].bombardiers[k].positions.position_y,tabpions[j].bombardiers[k].positions.positionfutur_x,tabpions[j].bombardiers[k].positions.positionfutur_y);
            printf("\n\n\t\tle bombardier %d appartient au joueur %d\n\n",tabpions[j].bombardiers[k].num_piece,tabpions[j].bombardiers[k].num_joueur);

            tabpions[j].croiseurs[k].num_piece=k+1;
            strcpy(tabpions[j].croiseurs[k].type_pion,"CR");
            tabpions[j].croiseurs[k].positions.position_x=101;
            tabpions[j].croiseurs[k].positions.position_y=101;
            tabpions[j].croiseurs[k].positions.positionfutur_x=0;
            tabpions[j].croiseurs[k].positions.positionfutur_y=0;
            tabpions[j].croiseurs[k].num_joueur=j+1;
            tabpions[j].croiseurs[k].puissance=50;
            tabpions[j].croiseurs[k].deja_deplace=0;
            tabpions[j].croiseurs[k].dans_reserve=1;
            tabpions[j].croiseurs[k].rcbc_pion=0;
            printf("\ncroiseur %d INITIALISE************:",tabpions[j].croiseurs[k].num_piece);

            printf("\npositions croiseurs :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].croiseurs[k].positions.position_x,tabpions[j].croiseurs[k].positions.position_y,tabpions[j].croiseurs[k].positions.positionfutur_x,tabpions[j].croiseurs[k].positions.positionfutur_y);
            printf("\n\n\t\tle croiseur %d appartient au joueur %d\n\n",tabpions[j].croiseurs[k].num_piece,tabpions[j].croiseurs[k].num_joueur);

            tabpions[j].chars[k].num_piece=k+1;
            strcpy(tabpions[j].chars[k].type_pion,"A");
            tabpions[j].chars[k].positions.position_x=101;
            tabpions[j].chars[k].positions.position_y=101;
            tabpions[j].chars[k].positions.positionfutur_x=0;
            tabpions[j].chars[k].positions.positionfutur_y=0;
            tabpions[j].chars[k].num_joueur=j+1;
            tabpions[j].chars[k].puissance=30;
            tabpions[j].chars[k].deja_deplace=0;
            tabpions[j].chars[k].dans_reserve=1;
            tabpions[j].chars[k].rcbc_pion=0;
            printf("\nchar %d INITIALISE************:",tabpions[j].chars[k].num_piece);

            printf("\npositions chars :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].chars[k].positions.position_x,tabpions[j].chars[k].positions.position_y,tabpions[j].chars[k].positions.positionfutur_x,tabpions[j].chars[k].positions.positionfutur_y);
            printf("\n\n\t\tle char %d appartient au joueur %d\n\n",tabpions[j].chars[k].num_piece,tabpions[j].chars[k].num_joueur);


        }
        for(k=0; k<NBsoldats;k++){
            tabpions[j].soldats[k].num_piece=k+1;
            strcpy(tabpions[j].soldats[k].type_pion,"S");
            tabpions[j].soldats[k].positions.position_x=100;
            tabpions[j].soldats[k].positions.position_y=100;
            tabpions[j].soldats[k].positions.positionfutur_x=0;
            tabpions[j].soldats[k].positions.positionfutur_y=0;
            tabpions[j].soldats[k].num_joueur=j+1;
            tabpions[j].soldats[k].puissance=2;
            tabpions[j].soldats[k].deja_deplace=0;
            tabpions[j].soldats[k].dans_reserve=1;
            tabpions[j].soldats[k].rcbc_pion=0; //pas sur encore si la variable servira

            printf("\nsoldat %d INITIALISE************:",tabpions[j].soldats[k].num_piece);

            printf("\npositions soldats :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].soldats[k].positions.position_x,tabpions[j].soldats[k].positions.position_y,tabpions[j].soldats[k].positions.positionfutur_x,tabpions[j].soldats[k].positions.positionfutur_y);
            printf("\n\n\t\tle soldat %d appartient au joueur %d\n\n",tabpions[j].soldats[k].num_piece,tabpions[j].soldats[k].num_joueur);


        }

            tabpions[j].missile.num_piece=666;
            strcpy(tabpions[j].missile.type_pion,"M");
            tabpions[j].missile.positions.position_x=100;
            tabpions[j].missile.positions.position_y=100;
            tabpions[j].missile.positions.positionfutur_x=0;
            tabpions[j].missile.positions.positionfutur_y=0;
            tabpions[j].missile.num_joueur=j+1;
            tabpions[j].missile.puissance=1000;
            tabpions[j].missile.deja_deplace=0;
            tabpions[j].missile.dans_reserve=1;

            printf("\n\n\t\tle missile %d appartient au joueur %d\n\n",tabpions[j].missile.num_piece,tabpions[j].missile.num_joueur);


    }

}

//******************************************INITIALISATIONS_cases***********************************************//

//je remplirai ici avec toi car tu à fais le tableau et moi le système de coordonnées...

//****************************************

