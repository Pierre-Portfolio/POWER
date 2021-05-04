#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "cases.h"
#include "plateau.h"



//******************************************************************INITIALISATIONS******************************************************************//


//******************************************INITIALISATIONS_joueurs***********************************************//

S_joueur * initialisation_joueurs() //Renvoie les infos de chaque joueur sous forme de tableau 1D
{
    system("CLS");
    S_joueur * tabjoueur = (S_joueur * ) malloc (sizeof(S_joueur)*NBJOUEURS);
    if(tabjoueur==NULL)                                                            //verifier que le pointeur n pas nul : eviter les crashs
    {
        printf("ERREUR MEMOIRE : veillez relancer une partie\n");
        exit(1); //arret d'urgence
    }

    for(int i=0; i<NBJOUEURS; i++)
    {
        tabjoueur[i].etat=1;
        tabjoueur[i].numero_joueur=i+1;
        tabjoueur[i].power=10;
        tabjoueur[i].tabpion=initialisation_pieces(); //chaque joueur recoit ses pions
        tabjoueur[i].nbactionTour = 5;

        //printf("\n\njoueur %d initialise**********************************",i+1);
        //printf("\n\tle numero du joueur est :%d",tabjoueur[i].numero_joueur);
        //printf("\n\tSon nombre de power est :%d",tabjoueur[i].power);
    }
    return tabjoueur;
}


//******************************************INITIALISATIONS_pieces***********************************************//

S_unitjoueur * initialisation_pieces()
{

    system("CLS");
    int j,k;
    S_unitjoueur * tabpions=(S_unitjoueur*)malloc (sizeof(S_unitjoueur)*192);
    if(tabpions==NULL)                                                            //verifier que le pointeur ne soit pas nul : eviter les crashs
    {
        printf("ERREUR MEMOIRE : veillez relancer une partie\n");
        exit(1); //arret d'urgence
    }

    for(j=0;j<NBJOUEURS;j++){

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

            //printf("\nchasseur %d INITIALISE************:",tabpions[j].chasseurs[k].num_piece);

            //printf("\npositions chasseurs :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].chasseurs[k].positions.position_x,tabpions[j].chasseurs[k].positions.position_y,tabpions[j].chasseurs[k].positions.positionfutur_x,tabpions[j].chasseurs[k].positions.positionfutur_y);
            //printf("\n\n\t\tle chasseur %d appartient au joueur %d\n\n",tabpions[j].chasseurs[k].num_piece,tabpions[j].chasseurs[k].num_joueur);

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

            //printf("\ndestroyer %d INITIALISE************:",tabpions[j].destroyers[k].num_piece);

            //printf("\npositions destroyers :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].destroyers[k].positions.position_x,tabpions[j].destroyers[k].positions.position_y,tabpions[j].destroyers[k].positions.positionfutur_x,tabpions[j].destroyers[k].positions.positionfutur_y);
            //printf("\n\n\t\tle destroyer %d appartient au joueur %d\n\n",tabpions[j].destroyers[k].num_piece,tabpions[j].destroyers[k].num_joueur);

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
            //printf("\ntank %d INITIALISE************:",tabpions[j].tanks[k].num_piece);

            //printf("\npositions tanks :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].tanks[k].positions.position_x,tabpions[j].tanks[k].positions.position_y,tabpions[j].tanks[k].positions.positionfutur_x,tabpions[j].tanks[k].positions.positionfutur_y);
            //printf("\n\n\t\tle tank %d appartient au joueur %d\n\n",tabpions[j].tanks[k].num_piece,tabpions[j].tanks[k].num_joueur);

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
            //printf("\nregiment %d INITIALISE************:",tabpions[j].regiments[k].num_piece);

            //printf("\npositions regiments :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].regiments[k].positions.position_x,tabpions[j].regiments[k].positions.position_y,tabpions[j].regiments[k].positions.positionfutur_x,tabpions[j].regiments[k].positions.positionfutur_y);
            //printf("\n\n\t\tle regiment %d appartient au joueur %d\n\n",tabpions[j].regiments[k].num_piece,tabpions[j].regiments[k].num_joueur);

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
            //printf("\nbombardier %d INITIALISE************:",tabpions[j].bombardiers[k].num_piece);

            //printf("\npositions bombardiers :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].bombardiers[k].positions.position_x,tabpions[j].bombardiers[k].positions.position_y,tabpions[j].bombardiers[k].positions.positionfutur_x,tabpions[j].bombardiers[k].positions.positionfutur_y);
            //printf("\n\n\t\tle bombardier %d appartient au joueur %d\n\n",tabpions[j].bombardiers[k].num_piece,tabpions[j].bombardiers[k].num_joueur);

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
            //printf("\ncroiseur %d INITIALISE************:",tabpions[j].croiseurs[k].num_piece);

            //printf("\npositions croiseurs :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].croiseurs[k].positions.position_x,tabpions[j].croiseurs[k].positions.position_y,tabpions[j].croiseurs[k].positions.positionfutur_x,tabpions[j].croiseurs[k].positions.positionfutur_y);
            //printf("\n\n\t\tle croiseur %d appartient au joueur %d\n\n",tabpions[j].croiseurs[k].num_piece,tabpions[j].croiseurs[k].num_joueur);

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
            //printf("\nchar %d INITIALISE************:",tabpions[j].chars[k].num_piece);

            //printf("\npositions chars :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].chars[k].positions.position_x,tabpions[j].chars[k].positions.position_y,tabpions[j].chars[k].positions.positionfutur_x,tabpions[j].chars[k].positions.positionfutur_y);
            //printf("\n\n\t\tle char %d appartient au joueur %d\n\n",tabpions[j].chars[k].num_piece,tabpions[j].chars[k].num_joueur);


        }
        for(k=0; k<NBSOLDATS;k++){
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

            //printf("\nsoldat %d INITIALISE************:",tabpions[j].soldats[k].num_piece);

            //printf("\npositions soldats :\t\nposition en x : %d\nposition en y : %d\nposition_Futur en x : %d\nposition_Futur en y : %d",tabpions[j].soldats[k].positions.position_x,tabpions[j].soldats[k].positions.position_y,tabpions[j].soldats[k].positions.positionfutur_x,tabpions[j].soldats[k].positions.positionfutur_y);
            //printf("\n\n\t\tle soldat %d appartient au joueur %d\n\n",tabpions[j].soldats[k].num_piece,tabpions[j].soldats[k].num_joueur);


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

            //printf("\n\n\t\tle missile %d appartient au joueur %d\n\n",tabpions[j].missile.num_piece,tabpions[j].missile.num_joueur);


    }
    return tabpions;

}

//******************************************INITIALISATIONS_cases***********************************************//
//S_plateau initialisation_cases()
S_cases ** initialisation_cases()
{
    /*S_cases c1={HG,vert};
    S_cases c2={eau,neutre};
    S_cases c3={eau,neutre};
    S_cases c4={eau,neutre};
    S_cases c5={ile,neutre};
    S_cases c6={eau,neutre};
    S_cases c7={eau,neutre};
    S_cases c8={eau,neutre};
    S_cases c9={HG,bleu};
    S_cases c10={eau,neutre};
    S_cases c11={ile,vert};
    S_cases c12={ile,vert};
    S_cases c13={ile,vert};
    S_cases c14={eau,neutre};
    S_cases c15={ile,bleu};
    S_cases c16={ile,bleu};
    S_cases c17={ile,bleu};
    S_cases c18={eau,neutre};
    S_cases c19={eau,neutre};
    S_cases c20={ile,vert};
    S_cases c21={ile,vert};
    S_cases c22={ile,vert};
    S_cases c23={eau,neutre};
    S_cases c24={ile,bleu};
    S_cases c25={ile,bleu};
    S_cases c26={ile,bleu};
    S_cases c27={eau,neutre};
    S_cases c28={eau,neutre};
    S_cases c29={ile,vert};
    S_cases c30={ile,vert};
    S_cases c31={ile,vert};
    S_cases c32={eau,neutre};
    S_cases c33={ile,bleu};
    S_cases c34={ile,bleu};
    S_cases c35={ile,bleu};
    S_cases c36={eau,neutre};

    S_cases c37={ile,neutre};
    S_cases c38={eau,neutre};
    S_cases c39={eau,neutre};
    S_cases c40={eau,neutre};
    S_cases c41={ile,neutre};
    S_cases c42={eau,neutre};
    S_cases c43={eau,neutre};
    S_cases c44={eau,neutre};
    S_cases c45={ile,neutre};
    S_cases c46={eau,neutre};
    S_cases c47={ile,rouge};
    S_cases c48={ile,rouge};
    S_cases c49={ile,rouge};
    S_cases c50={eau,neutre};
    S_cases c51={ile,jaune};
    S_cases c52={ile,jaune};
    S_cases c53={ile,jaune};
    S_cases c54={eau,neutre};
    S_cases c55={eau,neutre};
    S_cases c56={ile,rouge};
    S_cases c57={ile,rouge};
    S_cases c58={ile,rouge};
    S_cases c59={eau,neutre};
    S_cases c60={ile,jaune};
    S_cases c61={ile,jaune};
    S_cases c62={ile,jaune};
    S_cases c63={eau,neutre};
    S_cases c64={eau,neutre};
    S_cases c65={ile,rouge};
    S_cases c66={ile,rouge};
    S_cases c67={ile,rouge};
    S_cases c68={eau,neutre};
    S_cases c69={ile,jaune};
    S_cases c70={ile,jaune};
    S_cases c71={ile,jaune};
    S_cases c72={eau,neutre};

    S_cases c73={HG,rouge};
    S_cases c74={eau,neutre};
    S_cases c75={eau,neutre};
    S_cases c76={eau,neutre};
    S_cases c77={ile,neutre};
    S_cases c78={eau,neutre};
    S_cases c79={eau,neutre};
    S_cases c80={eau,neutre};
    S_cases c81={HG,jaune};*/

    //initialisation du tableau de cases
    S_cases  **Tabcases =  (S_cases*)malloc(9 * sizeof(S_cases**));
    for (int i = 0; i < 9; ++i) {
        Tabcases[i] = (S_cases*)malloc(9 * sizeof(S_cases));
    }

            S_cases TabcasesOrigine[9][9]= {{{HG,vert},{eau,neutre},{eau,neutre},{eau,neutre},{ile,neutre},{eau,neutre},{eau,neutre},{eau,neutre},{HG,bleu}},
                                            {{eau,neutre},{ile,vert},{ile,vert},{ile,vert},{eau,neutre},{ile,bleu},{ile,bleu},{ile,bleu},{eau,neutre}},
                                            {{eau,neutre},{ile,vert},{ile,vert},{ile,vert},{eau,neutre},{ile,bleu},{ile,bleu},{ile,bleu},{eau,neutre}},
                                            {{eau,neutre},{ile,vert},{ile,vert},{ile,vert},{eau,neutre},{ile,bleu},{ile,bleu},{ile,bleu},{eau,neutre}},
                                            {{ile,neutre},{eau,neutre},{eau,neutre},{eau,neutre},{ile,neutre},{eau,neutre},{eau,neutre},{eau,neutre},{ile,neutre}},
                                            {{eau,neutre},{ile,rouge},{ile,rouge},{ile,rouge},{eau,neutre},{ile,jaune},{ile,jaune},{ile,jaune},{eau,neutre}},
                                            {{eau,neutre},{ile,rouge},{ile,rouge},{ile,rouge},{eau,neutre},{ile,jaune},{ile,jaune},{ile,jaune},{eau,neutre}},
                                            {{eau,neutre},{ile,rouge},{ile,rouge},{ile,rouge},{eau,neutre},{ile,jaune},{ile,jaune},{ile,jaune},{eau,neutre}},
                                            {{HG,rouge},{eau,neutre},{eau,neutre},{eau,neutre},{ile,neutre},{eau,neutre},{eau,neutre},{eau,neutre},{HG,jaune}}};

            for(int i=0; i<9;i++)
            {
                for(int j=0;j<9;j++)
                {
                    Tabcases[i][j]=TabcasesOrigine[i][j];
                }
            }
    //printf("DANS MAIN : %d \n",Tabcases[8][0].terrain);

    //S_plateau p1={**Tabcases};
    //printf("%s",p1.plateaux[8][8].terrain);
    return Tabcases;
}
