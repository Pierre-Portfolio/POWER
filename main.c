#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "cases.h"

int main()
{
    //INITIALISATION
    S_cases c1={"HG","vert"};
<<<<<<< HEAD
    printf("%s ",c1.couleur);


=======
>>>>>>> 79808c08be2292613da5de23c58470a85a8c9b49
    S_cases c2={"eau","neutre"};
    S_cases c3={"eau","neutre"};
    S_cases c4={"eau","neutre"};
    S_cases c5={"ileN","neutre"};
    S_cases c6={"eau","neutre"};
    S_cases c7={"eau","neutre"};
    S_cases c8={"eau","neutre"};
    S_cases c9={"HG","bleu"};
    S_cases c10={"eau","neutre"};
    S_cases c11={"ile","vert"};
    S_cases c12={"ile","vert"};
    S_cases c13={"ile","vert"};
    S_cases c14={"eau","neutre"};
    S_cases c15={"ile","bleu"};
    S_cases c16={"ile","bleu"};
    S_cases c17={"ile","bleu"};
    S_cases c18={"eau","neutre"};
    S_cases c19={"eau","neutre"};
    S_cases c20={"ile","vert"};
    S_cases c21={"ile","vert"};
    S_cases c22={"ile","vert"};
    S_cases c23={"eau","neutre"};
    S_cases c24={"ile","bleu"};
    S_cases c25={"ile","bleu"};
    S_cases c26={"ile","bleu"};
    S_cases c27={"eau","neutre"};
    S_cases c28={"eau","neutre"};
    S_cases c29={"ile","vert"};
    S_cases c30={"ile","vert"};
    S_cases c31={"ile","vert"};
    S_cases c32={"eau","neutre"};
    S_cases c33={"ile","bleu"};
    S_cases c34={"ile","bleu"};
    S_cases c35={"ile","bleu"};
    S_cases c36={"eau","neutre"};

    S_cases c37={"ileW","neutre"};
    S_cases c38={"eau","neutre"};
    S_cases c39={"eau","neutre"};
    S_cases c40={"eau","neutre"};
    S_cases c41={"ileX","neutre"};
    S_cases c42={"eau","neutre"};
    S_cases c43={"eau","neutre"};
    S_cases c44={"eau","neutre"};
    S_cases c45={"ileE","neutre"};
    S_cases c46={"eau","neutre"};
    S_cases c47={"ile","rouge"};
    S_cases c48={"ile","rouge"};
    S_cases c49={"ile","rouge"};
    S_cases c50={"eau","neutre"};
    S_cases c51={"ile","jaune"};
    S_cases c52={"ile","jaune"};
    S_cases c53={"ile","jaune"};
    S_cases c54={"eau","neutre"};
    S_cases c55={"eau","neutre"};
    S_cases c56={"ile","rouge"};
    S_cases c57={"ile","rouge"};
    S_cases c58={"ile","rouge"};
    S_cases c59={"eau","neutre"};
    S_cases c60={"ile","jaune"};
    S_cases c61={"ile","jaune"};
    S_cases c62={"ile","jaune"};
    S_cases c63={"eau","neutre"};
    S_cases c64={"eau","neutre"};
    S_cases c65={"ile","rouge"};
    S_cases c66={"ile","rouge"};
    S_cases c67={"ile","rouge"};
    S_cases c68={"eau","neutre"};
    S_cases c69={"ile","jaune"};
    S_cases c70={"ile","jaune"};
    S_cases c71={"ile","jaune"};
    S_cases c72={"eau","neutre"};

    S_cases c73={"HG","rouge"};
    S_cases c74={"eau","neutre"};
    S_cases c75={"eau","neutre"};
    S_cases c76={"eau","neutre"};
    S_cases c77={"ileS","neutre"};
    S_cases c78={"eau","neutre"};
    S_cases c79={"eau","neutre"};
    S_cases c80={"eau","neutre"};
    S_cases c81={"HG","jaune"};


    S_cases Tabcases[lignes][colonnes]; //différence entre Tabcases et S_plateau?

    Tabcases[0][0]=c1;
    Tabcases[0][1]=c2;
    Tabcases[0][2]=c3;
    Tabcases[0][3]=c4;
    Tabcases[0][4]=c5;
    Tabcases[0][5]=c6;
    Tabcases[0][6]=c7;
    Tabcases[0][7]=c8;
    Tabcases[0][8]=c9;

    Tabcases[1][0]=c10;
    Tabcases[1][1]=c11;
    Tabcases[1][2]=c12;
    Tabcases[1][3]=c13;
    Tabcases[1][4]=c14;
    Tabcases[1][5]=c15;
    Tabcases[1][6]=c16;
    Tabcases[1][7]=c17;
    Tabcases[1][8]=c18;

    Tabcases[2][0]=c19;
    Tabcases[2][1]=c20;
    Tabcases[2][2]=c21;
    Tabcases[2][3]=c22;
    Tabcases[2][4]=c23;
    Tabcases[2][5]=c24;
    Tabcases[2][6]=c25;
    Tabcases[2][7]=c26;
    Tabcases[2][8]=c27;

    Tabcases[3][0]=c28;
    Tabcases[3][1]=c29;
    Tabcases[3][2]=c30;
    Tabcases[3][3]=c31;
    Tabcases[3][4]=c32;
    Tabcases[3][5]=c33;
    Tabcases[3][6]=c34;
    Tabcases[3][7]=c35;
    Tabcases[3][8]=c36;

    Tabcases[4][0]=c37;
    Tabcases[4][1]=c38;
    Tabcases[4][2]=c39;
    Tabcases[4][3]=c40;
    Tabcases[4][4]=c41;
    Tabcases[4][5]=c42;
    Tabcases[4][6]=c43;
    Tabcases[4][7]=c44;
    Tabcases[4][8]=c45;

    Tabcases[5][0]=c46;
    Tabcases[5][1]=c47;
    Tabcases[5][2]=c48;
    Tabcases[5][3]=c49;
    Tabcases[5][4]=c50;
    Tabcases[5][5]=c51;
    Tabcases[5][6]=c52;
    Tabcases[5][7]=c53;
    Tabcases[5][8]=c54;

    Tabcases[6][0]=c55;
    Tabcases[6][1]=c56;
    Tabcases[6][2]=c57;
    Tabcases[6][3]=c58;
    Tabcases[6][4]=c59;
    Tabcases[6][5]=c60;
    Tabcases[6][6]=c61;
    Tabcases[6][7]=c62;
    Tabcases[6][8]=c63;

    Tabcases[7][0]=c64;
    Tabcases[7][1]=c65;
    Tabcases[7][2]=c66;
    Tabcases[7][3]=c67;
    Tabcases[7][4]=c68;
    Tabcases[7][5]=c69;
    Tabcases[7][6]=c70;
    Tabcases[7][7]=c71;
    Tabcases[7][8]=c72;

    Tabcases[8][0]=c73;
    Tabcases[8][1]=c74;
    Tabcases[8][2]=c75;
    Tabcases[8][3]=c76;
    Tabcases[8][4]=c77;
    Tabcases[8][5]=c78;
    Tabcases[8][6]=c79;
    Tabcases[8][7]=c80;
    Tabcases[8][8]=c81;

    printf("DANS MAIN : %s \n",Tabcases[8][8].couleur);
    affiche_plateau(Tabcases);


    return 0;
}
