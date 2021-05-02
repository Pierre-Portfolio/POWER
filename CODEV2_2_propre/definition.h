#ifndef DEFINITION_H_INCLUDED
#define DEFINITION_H_INCLUDED

#define RCBC 3 //nombre de régiments, croiseurs, bombardiers, chars par joueur
#define MM 1
#define NBjoueurs 4
#define NBcases 9
#define CDT 6 //nombre de chasseurs, Destroyers, tanks par joueur
#define NBsoldats 9
#define NBpower 10
//#define DIMJpions 100
#define DIMSTR 2
#define DIMreserve_joueurs 4
#define DIMnom_case 2
#define NBtype_unite 9
#define DIMSTRLONG 50
#define NBordres 5



struct coordonnees{
    int position_x;
    int position_y;
    int positionfutur_x;
    int positionfutur_y;

} ;
typedef struct coordonnees S_coordonees;


struct pions{
    char type_pion[DIMSTR];
    S_coordonees positions;
    int puissance;
    int num_joueur;
    int num_piece;
    int deja_deplace;  //1=oui, 0=non
    int dans_reserve;  //1=oui, 0=non
    int rcbc_pion;     // 1=oui rcbc in game, 0=non pion normal ou rcbc pas en game
};
typedef struct pions S_pions;


struct unitjoueur{

    S_pions chasseurs[CDT+18];
    S_pions destroyers[CDT+18];
    S_pions tanks[CDT+18];
    S_pions regiments[RCBC+9];
    S_pions bombardiers[RCBC+9];
    S_pions croiseurs[RCBC+9];
    S_pions chars[RCBC+9];
    S_pions soldats[NBsoldats+27];
    S_pions missile;

};
typedef struct unitjoueur S_unitjoueur;

/*struct unitjoueur{  //ancien prog juste je garde au cas ou
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


struct joueur{
    int power;
    int numero_joueur;  //1=rouge, 2=vert, 3=jaune; 4=bleu
    int etat;     //1=en jeu, 0=hors jeu
    int deja_donne_ordre;    //1=oui, 0=non

};
typedef struct joueur S_joueur;

struct cases{

    char type_case[DIMnom_case];
    int couleur_case; //1=rouge, 2=vert, 3=jaune; 4=bleu

};
typedef struct cases S_cases;

struct feuille_ordre{

    char type_ordre[DIMSTR];
    int position_depart_x;
    int position_depart_y;
    int position_arrive_x;
    int position_arrive_y;

};
typedef struct feuille_ordre S_ordres;



//S_joueur tabinfos[NBjoueurs];   //deja dans le main.c
//S_unitjoueur tabpions[NBjoueurs];

S_ordres tab_ordres[NBjoueurs][NBordres];

#endif // DEFINITION_H_INCLUDED
