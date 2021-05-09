#ifndef DEFINITION_H_INCLUDED
#define DEFINITION_H_INCLUDED
#include <stdbool.h>

#define CBC 3 //nombre de croiseurs, bombardiers, chars par joueur
#define NBMEGAMISSILE 1
#define NBJOUEURS 4
#define NBCASES 9
#define CDT 6 //nombre de chasseurs, Destroyers, tanks par joueur
#define NBSOLDATS 9
#define NBPOWERS 10
//#define DIMJpions 100
#define DIMSTR 2
#define DIM_RESERVE_JOUEUR 4
#define DIM_NOM_CASES 2
#define NB_TYPE_UNITE 9
#define DIMSTRLONG 50
#define NBORDRES 5
#define NBPIECESJOUEUR 37-4





struct coordonnees{
    int position_x;
    int position_y;
    int positionfutur_x;
    int positionfutur_y;

};
typedef struct coordonnees S_coordonees;

typedef enum
{
    type_chasseur=0, //int 0 <==> chasseur
    type_destroyer,
    type_bombardier,
    type_croiseur,
    type_soldat,
    type_tank,
    type_char,
    type_megamissile,
    type_regiment,
    type_piece_inexistante,
    taille_enum_pion, //=10
}enum_type_pion;

static const bool pion_type_eau[taille_enum_pion]= {false, //chasseur
                                                    true, //destroyer
                                                    false, //bombardier
                                                    true, //croiseur
                                                    false, //soldat
                                                    false, //tank
                                                    false, //char
                                                    false, //megamissile
                                                    false, //regiment
                                                    false, //inexstante -> non applicable
                                                    }; //static const : on definit le tableau de boolean



static const int pion_limite_deplacement[taille_enum_pion]= {5, //chasseur
                                                             1, //destroyer
                                                             5, //bombardier
                                                             1, //croiseur
                                                             2, //soldat
                                                             3, //tank
                                                             3, //char
                                                             -1, //megamissile -> non applicable, illimité
                                                             2, //regiment
                                                             -1, //inexstante -> non applicable, pas de deplacement
                                                             }; //static const : on definit le tableau de boolean

struct pions{
    //char type_pion[DIMSTR];
    enum_type_pion type_pion; //type des pions est fixe de type enum_type_pion
    S_coordonees positions;
    int puissance;
    int deja_deplace;  //1=oui, 0=non
    int dans_reserve;  //1=oui, 0=non
    int rcbc_pion;     // 1=oui rcbc in game, 0=non pion normal ou rcbc pas en game
};
typedef struct pions S_pions;


/*struct unitjoueur{

    S_pions chasseurs[CDT+18];
    S_pions destroyers[CDT+18];
    S_pions tanks[CDT+18];
    S_pions regiments[RCBC+9];
    S_pions bombardiers[RCBC+9];
    S_pions croiseurs[RCBC+9];
    S_pions chars[RCBC+9];
    S_pions soldats[NBSOLDATS+27];
    S_pions missile;

};
typedef struct unitjoueur S_unitjoueur;

struct unitjoueur{  //ancien prog juste je garde au cas ou
    S_pions chasseursD[CDT];
    S_pions destroyersD[CDT];
    S_pions tanksD[CDT];
    S_pions regimentD[RCBC];
    S_pions bombardierD[RCBC];
    S_pions croiseurD[RCBC];
    S_pions charsD[RCBC];
    S_pions soldatsD[NBsoldats];
    S_pions missileD[MM];

};
typedef struct reservedepart S_unitjoueur;*/

static const int joueur_vers_couleur[]={4,10,8,1};

struct joueur{
    int power;
    int numero_joueur;  //1=rouge, 2=vert, 3=jaune; 4=bleu
    int etat;     //1=en jeu, 0=hors jeu
    int deja_donne_ordre;    //1=oui, 0=non
    int nbactionTour;
    int nbpions;
    S_pions * tabpion; //declaration d'un tableau de pions
    int nbpions_reserve;
    S_pions* tabpion_reserve;
};
typedef struct joueur S_joueur;

/*
struct cases{

    char type_case[DIMnom_case];
    int couleur_case; //1=rouge, 2=vert, 3=jaune; 4=bleu

};
typedef struct cases S_cases;
*/
typedef enum{
    type_deplacement=0,
    type_achat,
    type_echange,
    type_sortie,
}enum_types_ordre;

struct feuille_ordre{
    void * ordre[NBORDRES]; //pointeur de type inconnu
    enum_types_ordre type[NBORDRES];
    int nb_ordre;
};
typedef struct feuille_ordre S_feuille_ordres;

struct ordre_deplacement{
    int position_arrive_x;
    int position_arrive_y;
    bool valide; //0=false et 1=true
    int num_joueur;
    int num_pion; // 5   0 1 2 -> supprimés
};
typedef struct ordre_deplacement S_ordre_deplacement;

struct ordre_achat{
    bool valide;
    int num_joueur;
    enum_type_pion type_pion;
};
typedef struct ordre_achat S_ordre_achat;

static const int prix[taille_enum_pion]={5, //chasseur
                                         10, //destroyer
                                         -1, //non applicable
                                         -1, ////non applicable
                                         2, //soldat
                                         3, //tank
                                         -1, ////non applicable
                                         -1, ////non applicable
                                         -1, ////non applicable
                                         -1, //inexstante -> non applicable
                                         }; //static const : on definit le tableau de boolean


//S_joueur tabinfos[NBjoueurs];   //deja dans le main.c
//S_unitjoueur tabpions[NBjoueurs];

//S_ordres tab_ordres[NBJOUEURS][NBORDRES];

#endif // DEFINITION_H_INCLUDED
