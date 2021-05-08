#include "stdio.h"
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "cases.h"
#include "plateau.h"
#include <assert.h>



//******************************************************************INITIALISATIONS******************************************************************//


//******************************************INITIALISATIONS_joueurs***********************************************//

S_joueur * initialisation_joueurs() //Renvoie les infos de chaque joueur sous forme de tableau 1D
{
    //system("CLS");
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
        tabjoueur[i].tabpion=initialisation_pieces(i); //chaque joueur recoit ses pions
        tabjoueur[i].nbpions=NBPIECESJOUEUR;
        tabjoueur[i].tabpion_reserve=NULL;
        tabjoueur[i].nbpions_reserve=0;
        tabjoueur[i].nbactionTour = 5;

        //printf("\n\njoueur %d initialise**********************************",i+1);
        //printf("\n\tle numero du joueur est :%d",tabjoueur[i].numero_joueur);
        //printf("\n\tSon nombre de power est :%d",tabjoueur[i].power);
    }
    return tabjoueur;
}


//******************************************INITIALISATIONS_pieces***********************************************//
S_pions chasseur(int position_x,int position_y) //initialisation d'un pion de type chasseur
{
    S_pions resultat;
    resultat.type_pion=type_chasseur;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=5;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions destroyer(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_destroyer;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=10;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions tank(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_tank;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=3;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions regiment(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_regiment;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=20;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions bombardier(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_bombardier;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=25;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions croiseur(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_croiseur;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=50;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions un_char(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_char;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=30;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions soldat(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_soldat;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=2;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}
S_pions megamissile(int position_x,int position_y)
{
    S_pions resultat;
    resultat.type_pion=type_megamissile;
    resultat.positions.position_x=position_x;
    resultat.positions.position_y=position_y;
    resultat.positions.positionfutur_x=0;
    resultat.positions.positionfutur_y=0;
    resultat.puissance=1000;
    resultat.deja_deplace=0;
    resultat.dans_reserve=1;
    resultat.rcbc_pion=0;

    return resultat;
}

S_pions creer_pion_de_type(enum_type_pion type_pion){

    switch(type_pion){

        case type_chasseur : return chasseur(100,100);
        case type_destroyer : return destroyer(100,100);
        case type_tank : return tank(100,100);
        case type_regiment : return regiment(100,100);
        case type_bombardier : return bombardier(100,100);
        case type_croiseur : return croiseur(100,100);
        case type_char : return un_char(100,100);
        case type_soldat : return soldat(100,100);
        case type_megamissile : return megamissile(100,100);

        default : assert(0); //== assert(false)

    }
}


S_pions * initialisation_pieces(int num_joueur)
{
    S_pions * tabpions=(S_pions*)malloc (sizeof(S_pions)*NBPIECESJOUEUR);           //declaration d'un tableau de pions pour chaque joueur
    if(tabpions==NULL)                                                            //verifier que le pointeur ne soit pas nul : eviter les crashs
    {
        printf("ERREUR MEMOIRE : veillez relancer une partie\n");
        exit(1); //arret d'urgence
    }
    int position_x, position_y;
    switch(num_joueur)
    {
        case 0: position_x=1; position_y=1; break;
        case 1: position_x=9; position_y=1; break;
        case 2: position_x=9; position_y=9; break;
        case 3: position_x=1; position_y=9; break;
        default: assert(0); //assert n'est pas 1, donc fausse ==> crash propre
    }
    int k=0;                            //garder l'indice pour faire la liste
    for(int i=0;i<CDT;i++)
    {
        tabpions[k]=chasseur(position_x,position_y);
        k++;
    }
    for(int i=0;i<CDT;i++)
    {
        tabpions[k]=destroyer(position_x,position_y);
        k++;
    }
    for(int i=0;i<CDT;i++)
    {
        tabpions[k]=tank(position_x,position_y);
        k++;
    }
    for(int i=0;i<CBC;i++)
    {
        tabpions[k]=bombardier(position_x,position_y);
        k++;
    }
    for(int i=0;i<CBC;i++)
    {
        tabpions[k]=croiseur(position_x,position_y);
        k++;
    }
    for(int i=0;i<CBC;i++)
    {
        tabpions[k]=un_char(position_x,position_y);
        k++;
    }
    for(int i=0;i<NBSOLDATS;i++)
    {
        tabpions[k]=soldat(position_x,position_y);
        k++;
    }
    for(int i=0;i<NBMEGAMISSILE;i++)
    {
        tabpions[k]=megamissile(position_x,position_y);
        k++;
    }
    assert(k==NBPIECESJOUEUR); //verifier que toutes les cases des pieces du joueur sont remplies
    return tabpions;

}

//******************************************INITIALISATIONS_cases***********************************************//
//S_plateau initialisation_cases()
S_cases ** initialisation_cases()
{
    //initialisation du tableau de cases
    S_cases  **Tabcases =  (S_cases*)malloc(9 * sizeof(S_cases**));
    for (int i = 0; i < 9; ++i) {
        Tabcases[i] = (S_cases*)malloc(9 * sizeof(S_cases));
    }

    S_cases TabcasesOrigine[9][9]= {{{HG,0},{eau,-1},{eau,-1},{eau,-1},{ile,-1},{eau,-1},{eau,-1},{eau,-1},{HG,1}},
                                            {{eau,-1},{ile,0},{ile,0},{ile,0},{eau,-1},{ile,1},{ile,1},{ile,1},{eau,-1}},
                                            {{eau,-1},{ile,0},{ile,0},{ile,0},{eau,-1},{ile,1},{ile,1},{ile,1},{eau,-1}},
                                            {{eau,-1},{ile,0},{ile,0},{ile,0},{eau,-1},{ile,1},{ile,1},{ile,1},{eau,-1}},
                                            {{ile,-1},{eau,-1},{eau,-1},{eau,-1},{ile,-1},{eau,-1},{eau,-1},{eau,-1},{ile,-1}},
                                            {{eau,-1},{ile,3},{ile,3},{ile,3},{eau,-1},{ile,2},{ile,2},{ile,2},{eau,-1}},
                                            {{eau,-1},{ile,3},{ile,3},{ile,3},{eau,-1},{ile,2},{ile,2},{ile,2},{eau,-1}},
                                            {{eau,-1},{ile,3},{ile,3},{ile,3},{eau,-1},{ile,2},{ile,2},{ile,2},{eau,-1}},
                                            {{HG,3},{eau,-1},{eau,-1},{eau,-1},{ile,-1},{eau,-1},{eau,-1},{eau,-1},{HG,2}}};

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
