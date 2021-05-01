#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "definition.h"
#include "Initialisation.h"
#include "affichage.h"
#include "cases.h"

//environnement de tests


int main(){

    /*S_joueur tabinfos[NBjoueurs];
    S_unitjoueur tabpions[NBjoueurs];

    initialisation_joueurs(tabinfos);

    system("CLS");

    initialisation_pieces(tabpions);*/


    /*char texte[DIMSTRLONG]={'\0'};

    printf("\tquel texte voulez vous que j'ecrive de façon belle ?:");
    scanf("%s",texte);

    ecriture(texte);*/

     //INITIALISATION*

    //S_cases c1={HG,vert};
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
    S_cases c81={HG,jaune};

    //initialisation du tableau
    S_cases Tabcases[9][9] = {{{HG,vert},c2,c3,c4,c5,c6,c7,c8,c9},
                              {c10,c11,c12,c13,c14,c15,c16,c17,c18},
                              {c19,c20,c21,c22,c23,c24,c25,c26,c27},
                              {c28,c29,c30,c31,c32,c33,c34,c35,c36},
                              {c37,c38,c39,c40,c41,c42,c43,c44,c45},
                              {c46,c47,c48,c49,c50,c51,c52,c53,c54},
                              {c55,c56,c57,c58,c59,c60,c61,c62,c63},
                              {c64,c65,c66,c67,c68,c69,c70,c71,c72},
                              {c73,c74,c75,c76,c77,c78,c79,c80,c81}};

    //printf("DANS MAIN : %d \n",Tabcases[8][8].couleur);
    affiche_plateau(Tabcases);

    return 0;
}



