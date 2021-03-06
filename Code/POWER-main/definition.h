#ifndef DEFINITION_H_INCLUDED
#define DEFINITION_H_INCLUDED


#define NBJOUEURS 4
#define NBCASES 9
#define NBORDRES 5
#define NBPIONTOTALDEBUT 8
#define NBPIONDEBUT 2
#define POWERDEBUTPARTIE 10
#define ACTIONPARTOUR 5

#include <stdbool.h>

//************************ DEFINITION DES PIONS ************************

struct coordonees {
    int position_x;
    int position_y;
    int positionfutur_x;
    int positionfutur_y;

};
typedef struct coordonees S_coordonees;

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
                                                    }; //static const : on definit le tableau de boolean comme un define qui ne bouge plus



static const int pion_limite_deplacement[taille_enum_pion]= {5, //chasseur
                                                             1, //destroyer
                                                             5, //bombardier
                                                             1, //croiseur
                                                             2, //soldat
                                                             3, //tank
                                                             3, //char
                                                             -1, //megamissile -> non applicable, illimit??
                                                             2, //regiment
                                                             -1, //inexstante -> non applicable, pas de deplacement
                                                             }; //static const : on definit le tableau de int comme un define qui ne bouge plus

static const enum_type_pion pion_type_amelioration[taille_enum_pion]= {type_bombardier, //chasseur
                                                                       type_croiseur, //destroyer
                                                                       type_piece_inexistante, //bombardier DEJA GROUPE 2
                                                                       type_piece_inexistante, //croiseur DEJA GROUPE 2
                                                                       type_regiment, //soldat
                                                                       type_char, //tank
                                                                       type_piece_inexistante, //char DEJA GROUPE 2
                                                                       type_piece_inexistante, //megamissile -> non applicable
                                                                       type_piece_inexistante, //regiment DEJA GROUPE 2
                                                                       type_piece_inexistante, //inexstante -> non applicable
                                                                       }; //static const : on definit le tableau d'enum comme un define qui ne bouge plus

static const enum_type_pion pion_type_deamelioration[taille_enum_pion]= {type_piece_inexistante, //chasseur
                                                                       type_piece_inexistante, //destroyer
                                                                       type_chasseur, //bombardier DEJA GROUPE 2
                                                                       type_destroyer, //croiseur DEJA GROUPE 2
                                                                       type_piece_inexistante, //soldat
                                                                       type_piece_inexistante, //tank
                                                                       type_tank, //char DEJA GROUPE 2
                                                                       type_piece_inexistante, //megamissile -> non applicable
                                                                       type_soldat, //regiment DEJA GROUPE 2
                                                                       type_piece_inexistante, //inexstante -> non applicable
                                                                       }; //static const : on definit le tableau d'enum comme un define qui ne bouge plus



typedef enum{
    type_deplacement=0,
    type_achat,
    type_echange,
    type_sortie,
    type_lancement,
    type_aucun_ordre,
}enum_types_ordre;

 struct pions{

    enum_type_pion type_pion; //type des pions est fixe de type enum_type_pion
    S_coordonees positions;
    int puissance;
    int deja_deplace;  //1=oui, 0=non
    int dans_reserve;  //1=oui, 0=non
    enum_types_ordre dernier_ordre_du_tour;
};
typedef struct pions S_pions;


static const int joueur_vers_couleur[]={4,10,6,1};


//************************ DEFINITION DES JOUEURS ************************

typedef struct {
    int power;
    int nbactionTour;
    int nbpions;
    S_pions * tabpion; //declaration d'un tableau de pions
    int nbpions_reserve;
    S_pions* tabpion_reserve;
    bool en_jeu;
} S_joueur;


//************************ DEFINITION DES ORDRES ************************



typedef struct {
    void * ordre[NBORDRES]; //void* = pointeur de type inconnu
    enum_types_ordre type[NBORDRES];
    int nb_ordre;
} S_feuille_ordres;

typedef struct{
    int position_x;
    int position_y;
    enum_type_pion type_pion;
    int position_arrive_x;
    int position_arrive_y;
    int num_joueur;
} S_ordre_deplacement;

typedef struct{
    int position_x;
    int position_y;
    enum_type_pion type_pion;
    int position_arrive_x;
    int position_arrive_y;
    bool vers_reserve;
    int joueur_reserve_cible;
    int num_joueur;
} S_ordre_lancement;

typedef struct {
    int num_joueur;
    enum_type_pion type_pion;
} S_ordre_achat;

typedef struct {
    int position_x;
    int position_y;
    enum_type_pion type_pion;
    int num_joueur;
} S_ordre_sortie;

typedef struct {
    int position_x;
    int position_y;
    enum_type_pion type_pion;
    bool depuis_reserve;
    int num_joueur;
    bool pour_missile;
} S_ordre_echange;

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


static const int hq_x[NBJOUEURS] = {1,    //haut gauche
                                    9,    //haut droite
                                    9,    //bas droite
                                    1,    //bas gauche
};
static const int hq_y[NBJOUEURS] = {1,    //haut gauche
                                    1,    //haut droite
                                    9,    //bas droite
                                    9,    //bas gauche
};

#endif // DEFINITION_H_INCLUDED
