#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

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
    return (S_game){-1,p1,joueurs};
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


bool verifier_case_juste(int x, int y, S_plateau plateau, S_pions pion)
{
    //printf("type %d  at %d %d -> %d vs %d \n",pion.type_pion,x,y,pion_type_eau[pion.type_pion],plateau.cases[y-1][x-1].terrain);

    if(pion_type_eau[pion.type_pion]!=(plateau.cases[y-1][x-1].terrain==eau)) // pion eau sur terre ou pion terre sur eau
    {
        if(!pion_type_eau[pion.type_pion]) { //pion type terre
            //printf("Pion terre sur eau\n");
            return false;
        }
        else { //pion type eau
            if( (x ==3 && y ==3) || (x ==3 && y ==7) || (x ==7 && y ==3) || (x ==7 && y ==7)){ //les centres des iles
                //printf("Pion eau sur terre\n");

                return false;
            }
            else {
                //printf("Pion eau sur cote\n");
                //ne fait rien -> case cotière autorisé
            }
        }
    }
    else
    {
        printf("Bon type de pion pour la case\n");
    }

    return true;
}


#define round(a) ((int)((a)+0.5f))

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

bool verifier_chemin(S_plateau plateau, S_pions pion, int x_destination, int y_destination)
{
    //printf("verifier_chemin type %d; x%d, y%d, destx %d, desty%d\n",pion.type_pion,pion.positions.position_x,pion.positions.position_y,x_destination,y_destination);

    if(pion.type_pion == type_megamissile) return true; // megamissile n'ont pas de conditino

    int x1 = pion.positions.position_x; //x de départ
    int y1 = pion.positions.position_y; //y de départ
    int x2 = x_destination; //x de fin
    int y2 = y_destination; //y de fin
    int dx = x2-x1; //distance a bouger sur l'axe x
    int dy = y2-y1; //distance a bouger sur l'axe y

    int nombre_de_tour = max(dx,dy); //distance sur le plus grand axe -> si on avance de 4 horizontal et 1 vertical, il faut 4 tours

    float add_x = dx/(float)nombre_de_tour; //déplacement à chaque tour sur l'axe X (peut être plus petit de 1)
    float add_y = dy/(float)nombre_de_tour; //déplacement à chaque tour sur l'axe Y (peut être plus petit de 1)
    float actuellement_x_float = x1; //positon actuelle sur l'axe X SUR LA LIGNE DROITE (donc pas en case entière)
    float actuellement_y_float = y1; //positon actuelle sur l'axe Y SUR LA LIGNE DROITE (donc pas en case entière)

    //printf("addx%f addy%f nbrtour%d dx%d dy%d\n",add_x,add_y,nombre_de_tour,dx,dy);

    if(nombre_de_tour > pion_limite_deplacement[pion.type_pion])
    {
        printf("Pion trop loin\n");
        return false;
    }


    int nb_chgmt_couleur=0;
    int actuellement_x = x1;
    int actuellement_y = y1;
    while(!(actuellement_x == x2 && actuellement_y == y2))   //tant qu'on est pas arrivé
    {

        int ancienne_couleur=plateau.cases[y1][x1].joueur;
        actuellement_x_float += add_x; //position actuelle en mouvement sur l'axe x
        actuellement_y_float += add_y; //position actuelle en mouvement sur l'axe y
        actuellement_x = round(actuellement_x_float); // on arrondi
        actuellement_y = round(actuellement_y_float); // on arrondi

        printf("-%d-%d-\n",actuellement_x,actuellement_y);


        int nouvelle_couleur=plateau.cases[actuellement_y][actuellement_x].joueur;


        bool case_juste = verifier_case_juste(actuellement_x,actuellement_y,plateau,pion);
        printf("resultat case juste initial -> %d\n",case_juste);

        if(!case_juste) {

            printf("Cas faux, tentative d'alternatifs...\n");
            //cas alternatifs
            int alt_actuellement_x = -1; // -1 n'en n'as pas
            int round_x_plus = round(actuellement_x_float+0.05f);
            if(round_x_plus != actuellement_x) {
                alt_actuellement_x = round_x_plus;
            }
            int round_x_moins = round(actuellement_x_float-0.05f);
            if(round_x_moins != actuellement_x) {
                alt_actuellement_x = round_x_moins;
            }

            int alt_actuellement_y = -1; // -1 n'en n'as pas
            int round_y_plus = round(actuellement_y_float+0.05f);
            if(round_y_plus != actuellement_y) {
                alt_actuellement_y = round_y_plus;
            }
            int round_y_moins = round(actuellement_y_float-0.05f);
            if(round_y_moins != actuellement_y) {
                alt_actuellement_y = round_y_moins;
            }

            assert(alt_actuellement_x == -1 || alt_actuellement_y == -1); // necessite 4 cases d'eau cotes a cotes -> impossible

            if(alt_actuellement_x != -1) {
                case_juste = verifier_case_juste(alt_actuellement_x,actuellement_y,plateau,pion);
                printf("Alternative X trouvee, resultat %d...\n",case_juste);
            }

            if(!case_juste) {
                if(alt_actuellement_y != -1) {
                    case_juste = verifier_case_juste(actuellement_x,alt_actuellement_y,plateau,pion);
                    printf("Alternative Y trouvee, resultat %d...\n",case_juste);
                }

            }

        }


        if(!case_juste)
        {
            printf("Case fausse %d %d\n",actuellement_x, actuellement_y);
            return false;
        }
        else
        {
            if(nouvelle_couleur!=ancienne_couleur)
            {
                nb_chgmt_couleur++;
                //printf("Changement de couleur %d\n",(*nb_chgmt_couleur));
            }

            if(nb_chgmt_couleur>1)
            {
                printf("Pion trop de changement de couleur\n");
                return false;
            }
            else {
                printf("Case jsute\n");
            }
        }


    }

    return true;
}

void * deplacerPion(S_plateau plateau, S_joueur le_joueur, int num_joueur)
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

    int dest_x, dest_y; //dest -> destination
    printf("Ou souhaitez-vous aller ?\nEn x (horizontal) : \n");
    scanf("%d",&dest_x);
    printf("En y (vertical) : \n");
    scanf("%d",&dest_y);

    bool juste = verifier_chemin(plateau, le_joueur.tabpion[indice_pion], dest_x, dest_y);

    printf("verifier chemin -> %d \n", juste);

    S_ordre_deplacement * ordre = malloc(sizeof(S_ordre_deplacement));
    if(ordre == NULL)
    {
        printf("Erreur memoire\n");
        exit(1);
    }

    ordre->num_joueur = num_joueur;
    ordre->num_pion = indice_pion;
    ordre->position_arrive_x = dest_x;
    ordre->position_arrive_y = dest_y;
    ordre->valide = juste;

    return ordre;
}


void echangePower()
{
    //code check
}

void exectuer_deplacement(S_game * g1, S_ordre_deplacement * deplacement){
    //a remplir
}

void executer_ordre(S_game * g1, S_feuille_ordres feuille_ordre[NBJOUEURS])
{
    for(int i = 0 ; i < NBJOUEURS ; i++){
        for(int j = 0 ; j < feuille_ordre[i].nb_ordre ; j++){
            switch(feuille_ordre[i].type){
                case type_achat: break;
                case type_deplacement:
                    S_ordre_deplacement * deplacement = (S_ordre_deplacement *) feuille_ordre[i].ordre;
                    //maintenant on a notre deplacement
                    exectuer_deplacement(g1,deplacement);
                    break;
                case type_sortir: break;
                case type_echange: break;
                default : assert(0);
            }

        }
    }
}

S_game jouer_game(S_game g1)
{
    while(g1.gagnant_partie == -1)                     //boucle du jeu
    {
        // pour le tour de chaque joueur
        int result;
        S_feuille_ordres feuille_ordre[NBJOUEURS];
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
                void * ordre;
                switch(result)
                {
                case 0:
                    zoom(g1.joueurs_partie);
                    break;//joueur_partie sans [] car on veut les pions de tous les joueurs
                case 1: //'1' = code ascii
                    ordre = deplacerPion(g1.plateau_partie, g1.joueurs_partie[i], i);
                    feuille_ordre[i].ordre[5-g1.joueurs_partie[i].nbactionTour] = ordre;
                    feuille_ordre[i].type[5-g1.joueurs_partie[i].nbactionTour] = type_deplacement;
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

            feuille_ordre[i].nb_ordre = 5-g1.joueurs_partie[i].nbactionTour;

            // on reset le nbr d'action
            //g1.joueurs_partie.nbactionTour = 5;
        }




        // on execute les coups de chaque joueur
        //executer_ordre(&g1, feuille_ordre);

        //resolution
        //resolution_du_tour(&g1);

        //exectuer les actions de tout les tours
        //actions_du_tour(&g1);

        // on verifie si c'est la fin de la partie
        //verifier_victoire(&g1);
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
