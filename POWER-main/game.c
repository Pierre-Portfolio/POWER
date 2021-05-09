#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "definition.h"
#include "Initialisation.h"
#include "affichage.h"
#include "plateau.h"
#include "game.h"
#include "util.h"

#define round(a) ((int)((a)+0.5f))

#define max(a,b) \
   ({ __typeof__ (a) _a = (a); \
       __typeof__ (b) _b = (b); \
     _a > _b ? _a : _b; })

//initialisation de la partie
S_game creer_game()
{
    S_plateau p1= {initialisation_cases()};
    S_joueur * joueurs=initialisation_joueurs();
    return (S_game)
    {
        -1,p1,joueurs
        };
}

int saisieAction(int nbcoup)
{
    if(nbcoup==0) return 6;

    //demander a l'utilisateur ce qu'il souhaite faire
    int nombreEntre = -1;
    while ((nombreEntre < 0) || (nombreEntre > 6))
    {
        printf("Quelle action souhaitez vous faire ?\n");
        printf("0 : zoom sur les unite d'une case ou la reserve\n");
        printf("1 : deplacer un pion\n");
        printf("2 : achat de pions\n");
        printf("3 : sortie de pions\n");
        printf("4 : fusion de pions\n");
        printf("5 : lancement de missile\n");
        printf("6 : Fin de tour\n");
        scanf("%d", &nombreEntre);
        //system("CLS");
    }
    return nombreEntre;
}

bool verifier_case_juste(int x, int y, S_plateau plateau, S_pions pion)
{
    //printf("type %d  at %d %d -> %d vs %d \n",pion.type_pion,x,y,pion_type_eau[pion.type_pion],plateau.cases[y-1][x-1].terrain);

    if(pion_type_eau[pion.type_pion]!=(plateau.cases[y-1][x-1].terrain==eau)) // pion eau sur terre ou pion terre sur eau
    {
        if(!pion_type_eau[pion.type_pion])   //pion type terre
        {
            //printf("Pion terre sur eau\n");
            return false;
        }
        else   //pion type eau
        {
            if( (x ==3 && y ==3) || (x ==3 && y ==7) || (x ==7 && y ==3) || (x ==7 && y ==7))  //les centres des iles
            {
                //printf("Pion eau sur terre\n");

                return false;
            }
            else
            {
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

bool verifier_chemin(S_plateau plateau, S_pions pion, int x_destination, int y_destination)
{
    //[INSTRUMENTALISATION DE DEBUG] printf("verifier_chemin type %d; x%d, y%d, destx %d, desty%d\n",pion.type_pion,pion.positions.position_x,pion.positions.position_y,x_destination,y_destination);

    if(pion.type_pion == type_megamissile){
        return true; // megamissile n'ont pas de conditino
    }

    int x1 = pion.positions.position_x; //x de départ
    int y1 = pion.positions.position_y; //y de départ
    int x2 = x_destination; //x de fin
    int y2 = y_destination; //y de fin
    int dx = abs(x2-x1); //distance a bouger sur l'axe x
    int dy = abs(y2-y1); //distance a bouger sur l'axe y

    int nombre_de_tour = max(dx,dy); //distance sur le plus grand axe -> si on avance de 4 horizontal et 1 vertical, il faut 4 tours

    float add_x = (x2-x1)/(float)nombre_de_tour; //déplacement à chaque tour sur l'axe X (peut être plus petit de 1)
    float add_y = (y2-y1)/(float)nombre_de_tour; //déplacement à chaque tour sur l'axe Y (peut être plus petit de 1)
    float actuellement_x_float = x1; //positon actuelle sur l'axe X SUR LA LIGNE DROITE (donc pas en case entière)
    float actuellement_y_float = y1; //positon actuelle sur l'axe Y SUR LA LIGNE DROITE (donc pas en case entière)

   //[INSTRUMENTALISATION DE DEBUG]  printf("addx%f addy%f nbrtour%d dx%d dy%d\n",add_x,add_y,nombre_de_tour,dx,dy);

    if(nombre_de_tour > pion_limite_deplacement[pion.type_pion])
    {
        printf("Le deplacement est trop grand\n");
        return false;
    }
    //[INSTRUMENTALISATION DE DEBUG] printf("apres limite deplacement\n");

    int nb_chgmt_couleur=0;
    int actuellement_x = x1;
    int actuellement_y = y1;
    while(!(actuellement_x == x2 && actuellement_y == y2))   //tant qu'on est pas arrivé
    {
        //[INSTRUMENTALISATION DE DEBUG] printf("actuellement x %d   actuellement y %d\n",actuellement_x,actuellement_y);
        int ancienne_couleur=plateau.cases[actuellement_y-1][actuellement_x-1].joueur;
        actuellement_x_float += add_x; //position actuelle en mouvement sur l'axe x
        actuellement_y_float += add_y; //position actuelle en mouvement sur l'axe y
        actuellement_x = round(actuellement_x_float); // on arrondi
        actuellement_y = round(actuellement_y_float); // on arrondi

        assert(actuellement_x > 0 && actuellement_x < 10 && actuellement_y > 0 && actuellement_y < 10);

        //[INSTRUMENTALISATION DE DEBUG] printf("-%d-%d-\n",actuellement_x,actuellement_y);


        int nouvelle_couleur=plateau.cases[actuellement_y-1][actuellement_x-1].joueur;


        bool case_juste = verifier_case_juste(actuellement_x,actuellement_y,plateau,pion);
        //[INSTRUMENTALISATION DE DEBUG] printf("resultat case juste initial -> %d\n",case_juste);

        if(!case_juste)
        {

            //[INSTRUMENTALISATION DE DEBUG] printf("Cas faux, tentative d'alternatifs...\n");
            //cas alternatifs
            int alt_actuellement_x = -1; // -1 n'en n'as pas
            int round_x_plus = round(actuellement_x_float+0.25f);
            if(round_x_plus != actuellement_x)
            {
                alt_actuellement_x = round_x_plus;
            }
            int round_x_moins = round(actuellement_x_float-0.25f);
            if(round_x_moins != actuellement_x)
            {
                alt_actuellement_x = round_x_moins;
            }

            int alt_actuellement_y = -1; // -1 n'en n'as pas
            int round_y_plus = round(actuellement_y_float+0.25f);
            if(round_y_plus != actuellement_y)
            {
                alt_actuellement_y = round_y_plus;
            }
            int round_y_moins = round(actuellement_y_float-0.25f);
            if(round_y_moins != actuellement_y)
            {
                alt_actuellement_y = round_y_moins;
            }

            assert(alt_actuellement_x == -1 || alt_actuellement_y == -1); // necessite 4 cases d'eau cotes a cotes -> impossible

            if(alt_actuellement_x != -1)
            {
                case_juste = verifier_case_juste(alt_actuellement_x,actuellement_y,plateau,pion);
                nouvelle_couleur=plateau.cases[actuellement_y-1][alt_actuellement_x-1].joueur;
                //[INSTRUMENTALISATION DE DEBUG] printf("Alternative X trouvee, resultat %d...\n",case_juste);
            }

            if(!case_juste)
            {
                if(alt_actuellement_y != -1)
                {
                    case_juste = verifier_case_juste(actuellement_x,alt_actuellement_y,plateau,pion);
                    nouvelle_couleur=plateau.cases[alt_actuellement_y-1][actuellement_x-1].joueur;
                    //[INSTRUMENTALISATION DE DEBUG] printf("Alternative Y trouvee, resultat %d...\n",case_juste);
                }

            }

        }


        if(!case_juste)
        {
            //[INSTRUMENTALISATION DE DEBUG] printf("Case fausse %d %d\n",actuellement_x, actuellement_y);
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
                printf("Le pion change trop de fois de couleur\n");
                return false;
            }
            else
            {
                //[INSTRUMENTALISATION DE DEBUG] printf("Case jsute\n");
            }
        }


    }

    return true;
}



void * deplacerPion(S_plateau plateau,S_feuille_ordres feuille_ordre, S_joueur le_joueur, int num_joueur)
{
    int x, y;
    enum_type_pion type_pion;
    printf("Dans quelle case est le pion que vous souhaitez deplacer ?\nEn x (horizontal) : \n");
    scanf("%d",&x);
    printf("En y (vertical) : \n");
    scanf("%d",&y);
    affiche_mes_unites_numerotees(x,y,le_joueur);

    ////if(decompte_unite!=0){la suite...} else {printf("vous ne possedez aucune unite dans la case %d.%d\---nordre impossible---\n",&x,&y)}


    printf("Quel pion voulez-vous deplacer ? (Veuillez entrer l'indice a droite du pion)\n");
    scanf("%d",(int*)(&type_pion));
    int indice_pion=-1;
    for(int i=0; i<le_joueur.nbpions; i++)
    {
        if(le_joueur.tabpion[i].positions.position_x==x && le_joueur.tabpion[i].positions.position_y==y && le_joueur.tabpion[i].type_pion==type_pion)
        {
            if(!possede_deja_ordre(feuille_ordre, num_joueur, i, false)) //si aucun ordre lui a deja ete donne
            {
                indice_pion=i;
                break; //pour n'avoir qu'un seul pion qui repond aux conditions du if
            }
        }

    }
    //[INSTRUMENTALISATION DE DEBUG] printf("indice choisis : %d\n",indice_pion);

    int dest_x, dest_y; //dest -> destination
    printf("Ou souhaitez-vous aller ?\nEn x (horizontal) : \n");
    scanf("%d",&dest_x);
    printf("En y (vertical) : \n");
    scanf("%d",&dest_y);

    bool juste=false;
    if(indice_pion!=-1)
    {

        juste = verifier_chemin(plateau, le_joueur.tabpion[indice_pion], dest_x, dest_y);

        printf("verification du chemin : 0 chemin invalide ou 1 chemin valide %d \n", juste);

    }

    if(type_pion == type_megamissile){ //missile non deplacable
        juste = false;
    }


    S_ordre_deplacement * ordre = (S_ordre_deplacement *) malloc(sizeof(S_ordre_deplacement));
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

void * lancer_missile(S_feuille_ordres feuille_ordre, S_joueur le_joueur, int num_joueur)
{
    bool vers_reserve = false;
    int joueur_reserve_cible = -1;
    int x, y;
    printf("Dans quelle case est le missile que vous souhaitez lancer ?\nEn x (horizontal) : \n");
    scanf("%d",&x);
    printf("En y (vertical) : \n");
    scanf("%d",&y);


    int indice_pion=-1;
    for(int i=0; i<le_joueur.nbpions; i++)
    {
        if(le_joueur.tabpion[i].positions.position_x==x && le_joueur.tabpion[i].positions.position_y==y && le_joueur.tabpion[i].type_pion==type_megamissile )
        {
            if(!possede_deja_ordre(feuille_ordre, num_joueur, i, false))
            {
                indice_pion=i;
                break; //n'avoir qu'un seul pion qui repond aux conditions du if
            }
        }

    }
    printf("indice choisis : %d\n",indice_pion);

    int dest_x, dest_y; //dest -> destination
    printf("Ou souhaitez-vous le lancer (Ou R pour viser une reserve) ?\nEn x (horizontal) : \n");
    int num = scanf("%d",&dest_x);
    if(num!=1)  // R
    {
        fflush(stdin);
        vers_reserve = true;
        printf("Joueur cible ? \n");
        scanf("%d",&joueur_reserve_cible);
    }
    else
    {
        printf("En y (vertical) : \n");
        scanf("%d",&dest_y);
    }
    S_ordre_lancement * ordre = (S_ordre_lancement *) malloc(sizeof(S_ordre_lancement));
    if(ordre == NULL)
    {
        printf("Erreur memoire\n");
        exit(1);
    }

    joueur_reserve_cible--; //commence de 1, conversion vers debut à 0

    bool valide = (indice_pion!=-1);
    if(vers_reserve && (joueur_reserve_cible < 0 || joueur_reserve_cible >= NBJOUEURS)){
        valide = false;
    }

    ordre->num_joueur = num_joueur;
    ordre->num_pion = indice_pion;
    ordre->position_arrive_x = dest_x;
    ordre->position_arrive_y = dest_y;
    ordre->vers_reserve = vers_reserve;
    ordre->joueur_reserve_cible = joueur_reserve_cible;
    ordre->valide = valide;

    return ordre;
}

void* achat(S_joueur joueur, int num_joueur)
{

    enum_type_pion type;

    //afficher les types de pions pouvant etre achetes

    printf("Quelle piece voulez-vous acheter avec vos powers ? \n");
    scanf("%d",(int*)(&type));
    S_ordre_achat * ordre = (S_ordre_achat *) malloc(sizeof(S_ordre_achat));

    if(ordre==NULL)
    {
        printf("erreur memoire\n");
        exit(1); //arret d'urgence
    }

    ordre->type_pion=type;
    ordre->num_joueur=num_joueur;

    if(type>=0&&type<taille_enum_pion&&prix[type]!=-1) //s'assure que l'utilisateur rentre un bon numéro de type
    {
        if(joueur.power>=prix[type])
        {
            ordre->valide=true;
            return ordre;
        }
    }
    ordre->valide=false;
    return ordre;
}
void* sortie(S_joueur joueur,S_feuille_ordres feuille_ordre, int num_joueur)
{

    enum_type_pion type;

    affiche_mes_unites_reserve(joueur,true);

    printf("Quelle piece voulez-vous sortir ? \n");
    scanf("%d",(int*)(&type));

    S_ordre_sortie * ordre = (S_ordre_sortie *) malloc(sizeof(S_ordre_sortie));

    if(ordre==NULL)
    {
        printf("erreur memoire\n");
        exit(1); //arret d'urgence
    }

    ordre->num_joueur=num_joueur;
    ordre->valide=false;

    for(int i = 0 ; i < joueur.nbpions_reserve ; i++)
    {
        if(joueur.tabpion_reserve[i].type_pion == type)
        {
            if(!possede_deja_ordre(feuille_ordre, num_joueur, i, true))
            {
                ordre->valide=true;
                ordre->indice_pion=i;
                break;
            }
        }
    }


    return ordre;
}
void* echange(S_joueur joueur,S_feuille_ordres feuille_ordre, int num_joueur)
{
    int x, y;
    enum_type_pion type_pion;
    bool depuis_reserve = false;
    printf("De quelle case sont les pion que vous souhaitez pour fusion (R pour la reserve) ?\nEn x (horizontal) : \n");
    int num = scanf("%d",&x); //scanf renvoie le nb de nombres(%..)qu'il a reussi a scaner. si %d%d, il renvoie 2 par exemple si scan de 2 %d reussi
    if(num!=1)  // R
    {
        fflush(stdin);
        affiche_mes_unites_reserve(joueur,true);
        depuis_reserve = true;
    }
    else
    {
        printf("En y (vertical) : \n");
        scanf("%d",&y);
        affiche_mes_unites_numerotees(x,y,joueur);
    }
    printf("Quel pion voulez-vous faire fusion ?\n");
    scanf("%d",(int*)(&type_pion));

    int indice_pion[3];
    for(int i = 0 ; i < 3 ; i++) indice_pion[i]=-1;

    for(int z=0 ; z < 3 ; z++)
    {
        S_pions * tab = joueur.tabpion;
        int nb = joueur.nbpions;
        if(depuis_reserve)
        {
            tab = joueur.tabpion_reserve;
            nb = joueur.nbpions_reserve;
        }

        for(int i=0; i<nb; i++)
        {
            if((depuis_reserve || (tab[i].positions.position_x==x && tab[i].positions.position_y==y)) && tab[i].type_pion==type_pion)
            {
                bool deja_en_indice = false;
                for(int j = 0 ; j < 3 ; j++)
                {
                    if(i == indice_pion[j])
                    {
                        deja_en_indice = true;
                    }
                }
                if(!possede_deja_ordre(feuille_ordre, num_joueur, i, depuis_reserve) && !deja_en_indice)
                {
                    indice_pion[z]=i;
                    break; //n'avoir qu'un seul pion qui repond aux conditions du if
                }
            }
        }
    }
    printf("indices choisis :%d %d %d\n",indice_pion[0],indice_pion[1],indice_pion[2]);


    S_ordre_echange * ordre = (S_ordre_echange *) malloc(sizeof(S_ordre_echange));
    if(ordre == NULL)
    {
        printf("Erreur memoire\n");
        exit(1);
    }

    ordre->valide = false;
    if(indice_pion[2]!=-1 && pion_type_amelioration[type_pion] != type_piece_inexistante)
    {
        ordre->valide = true;
        ordre->type_pion = pion_type_amelioration[type_pion];
    }

    ordre->num_joueur = num_joueur;
    ordre->indice_pion1 = indice_pion[0];
    ordre->indice_pion2 = indice_pion[1];
    ordre->indice_pion3 = indice_pion[2];
    ordre->depuis_reserve = depuis_reserve;

    return ordre;
}



bool possede_deja_ordre(S_feuille_ordres feuille_ordre,int num_joueur, int indice_pion, bool en_reserve)
{



    printf("verif deja ordre\n");
    for(int i=0; i<feuille_ordre.nb_ordre; i++)
    {
        printf("ordre %d\n",i);
        S_ordre_deplacement * deplacement;
//        S_ordre_achat * l_achat;
        S_ordre_sortie * sortie;
        S_ordre_echange * echange;

        switch(feuille_ordre.type[i])
        {
        case type_achat:
            //l_achat = (S_ordre_achat *) feuille_ordre.ordre[i]; //convertir l'ordre en ordre de deplacement
            //maintenant on a notre deplacement
            //****************//il n'y a pas de pion dans un achat car il apparait apres, au tour suivant. il ne peut donc pas deja avoir un ordre
            break;
        case type_deplacement:
            deplacement = (S_ordre_deplacement *) feuille_ordre.ordre[i]; //convertir l'ordre en ordre de deplacement
            //maintenant on a notre deplacement
            if(!en_reserve && deplacement->num_joueur==num_joueur&&deplacement->num_pion==indice_pion)
            {
                return true;
            } //return en vrai ou faux
            break;
        case type_sortie:
            sortie = (S_ordre_sortie *) feuille_ordre.ordre[i]; //convertir l'ordre en ordre de deplacement
            //maintenant on a notre deplacement
            if(en_reserve && sortie->num_joueur==num_joueur&&sortie->indice_pion==indice_pion)
            {
                return true;
            } //return en vrai ou faux
            break;
        case type_echange:
            echange = (S_ordre_echange *) feuille_ordre.ordre[i]; //convertir l'ordre en ordre de deplacement
            //maintenant on a notre deplacement
            if(en_reserve == echange->depuis_reserve && echange->num_joueur==num_joueur)
            {
                if(echange->indice_pion1 == indice_pion || echange->indice_pion2 == indice_pion || echange->indice_pion3 == indice_pion)
                {
                    return true;
                }
            } //return en vrai ou faux
            break;
        default :
            assert(0);
        }
    }
    printf("pas deja ordre\n");
    return false;
}
bool executer_ordre_deplacement(S_game * g1, S_ordre_deplacement * deplacement)
{
    if(!deplacement->valide) //s'il n'est pas valide
    {
        printf("Ordre deplacement invalide\n");
        return false;
    }
    g1->joueurs_partie[deplacement->num_joueur].tabpion[deplacement->num_pion].positions.position_x = deplacement->position_arrive_x;
    g1->joueurs_partie[deplacement->num_joueur].tabpion[deplacement->num_pion].positions.position_y = deplacement->position_arrive_y;

    return true;
}

bool executer_ordre_lancement(S_game * g1, S_ordre_lancement * lancement)
{
    if(!lancement->valide) //s'il n'est pas valide
    {
        printf("Ordre lancement invalide\n");
        return false;
    }
    g1->joueurs_partie[lancement->num_joueur].tabpion[lancement->num_pion].type_pion = type_piece_inexistante;

    if(!lancement->vers_reserve)
    {
        printf("MISSILE : Toutes les untiees presente dans la case cible en %d %d ont ete tueees \n",lancement->position_arrive_x,lancement->position_arrive_y);
        for(int i=0; i<NBJOUEURS; i++) //calcul du nombre d'egalites par case
            for(int j = 0 ; j < g1->joueurs_partie[i].nbpions ; j++)
                if(g1->joueurs_partie[i].tabpion[j].positions.position_x == lancement->position_arrive_x &&
                g1->joueurs_partie[i].tabpion[j].positions.position_y == lancement->position_arrive_y)
                    g1->joueurs_partie[i].tabpion[j].type_pion = type_piece_inexistante;

    }
    else
    {
        printf("MISSILE : Tout le monde meurt dans la reserve du joueur %d\n",lancement->joueur_reserve_cible+1);
        for(int j = 0 ; j < g1->joueurs_partie[lancement->joueur_reserve_cible].nbpions_reserve ; j++)
            g1->joueurs_partie[lancement->joueur_reserve_cible].tabpion_reserve[j].type_pion = type_piece_inexistante;

    }


    return true;
}

bool executer_ordre_achat(S_game * g1, S_ordre_achat * l_achat)
{

    if(!l_achat->valide)  //vrai si valide faux et vrai sinon
    {

        printf("Ordre d'achat invalide\n");
        return false;
    }

    g1->joueurs_partie[l_achat->num_joueur].power-=prix[l_achat->type_pion];      //equivaut a x=x-...

    S_pions pion = creer_pion_de_type(l_achat->type_pion,100,100);

    rajouter((void*)&g1->joueurs_partie[l_achat->num_joueur].tabpion_reserve,sizeof(S_pions),
             &g1->joueurs_partie[l_achat->num_joueur].nbpions_reserve,
             (void*)&pion);

    return true;
}

// Retourne false en cas d'ordre invalide
bool executer_ordre_echange(S_game * g1, S_ordre_echange * echange)
{
    if(!echange->valide)  //vrai si valide faux et vrai sinon
    {

        printf("Ordre d'echange invalide\n");
        return false;
    }

    S_pions ** tab;
    int * nb;

    if(echange->depuis_reserve)
    {
        tab = &g1->joueurs_partie[echange->num_joueur].tabpion_reserve;
        nb = &g1->joueurs_partie[echange->num_joueur].nbpions_reserve;
    }
    else
    {
        tab = &g1->joueurs_partie[echange->num_joueur].tabpion;
        nb = &g1->joueurs_partie[echange->num_joueur].nbpions;
    }

    S_pions pion = creer_pion_de_type(echange->type_pion,(*tab)[echange->indice_pion1].positions.position_x,(*tab)[echange->indice_pion1].positions.position_y);

    printf("Rajouter sur le tableau par fusion un pion de type %d, pos %d %d\n",
           echange->type_pion,
           (*tab)[echange->indice_pion1].positions.position_x,
           (*tab)[echange->indice_pion1].positions.position_y);

    rajouter((void*)tab,sizeof(S_pions),
             nb,
             (void*)&pion);

    //[INSTRUMENTALISATION DE DEBUG] printf("Marquer pour supprimer pion 1, indice %d\n",echange->indice_pion1);
    (*tab)[echange->indice_pion1].type_pion = type_piece_inexistante;

    //[INSTRUMENTALISATION DE DEBUG] printf("Marquer pour supprimer pion 2, indice %d\n",echange->indice_pion2);
    (*tab)[echange->indice_pion2].type_pion = type_piece_inexistante;

    //[INSTRUMENTALISATION DE DEBUG] printf("Marquer pour supprimer pion 3, indice %d\n",echange->indice_pion3);
    (*tab)[echange->indice_pion3].type_pion = type_piece_inexistante;

    return true;
}

bool executer_ordre_sortie(S_game * g1, S_ordre_sortie * sortie)
{

    if(!sortie->valide)  //vrai si valide faux et vrai sinon
    {

        printf("Ordre de sortie invalide\n");
        return false;
    }

    g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[sortie->indice_pion].positions.position_x = hq_x[sortie->num_joueur];
    g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[sortie->indice_pion].positions.position_y = hq_y[sortie->num_joueur];

    printf("Rajouter sur le tableau un pion, pos %d %d\n",
           g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[sortie->indice_pion].positions.position_x,
           g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[sortie->indice_pion].positions.position_y);

    rajouter((void*)&g1->joueurs_partie[sortie->num_joueur].tabpion,sizeof(S_pions),
             &g1->joueurs_partie[sortie->num_joueur].nbpions,
             (void*)&g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[sortie->indice_pion]);

    printf("Le supprimer, indice %d (joueur %d)\n",sortie->indice_pion,sortie->num_joueur);
    supprimer(g1->joueurs_partie[sortie->num_joueur].tabpion_reserve,sizeof(S_pions),
              &g1->joueurs_partie[sortie->num_joueur].nbpions_reserve,
              sortie->indice_pion);

    return true;
}

void executer_ordre(S_game * g1, S_feuille_ordres feuille_ordre[NBJOUEURS])
{
    for(int i = 0 ; i < NBJOUEURS ; i++)
    {
        int nb_ordre_valide = 0;
        for(int j = 0 ; j < feuille_ordre[i].nb_ordre ; j++)
        {
            printf("%d %d %d\n",i,j,feuille_ordre[i].nb_ordre);

            S_ordre_deplacement * deplacement;
            S_ordre_achat * l_achat;
            S_ordre_sortie * sortie;
            S_ordre_echange * echange;
            S_ordre_lancement * lancement;
            bool valide = false;

            switch(feuille_ordre[i].type[j])
            {
            case type_achat:
                l_achat = (S_ordre_achat *) feuille_ordre[i].ordre[j]; //convertir l'ordre en ordre de deplacement
                //maintenant on a notre deplacement
                valide=executer_ordre_achat(g1,l_achat);
                break;
            case type_deplacement:
                deplacement = (S_ordre_deplacement *) feuille_ordre[i].ordre[j]; //convertir l'ordre en ordre de deplacement
                //maintenant on a notre deplacement
                valide=executer_ordre_deplacement(g1,deplacement);
                break;
            case type_sortie:
                sortie = (S_ordre_sortie *) feuille_ordre[i].ordre[j]; //convertir l'ordre en ordre de deplacement
                valide=executer_ordre_sortie(g1,sortie);
                break;
            case type_echange:
                echange = (S_ordre_echange *) feuille_ordre[i].ordre[j];
                valide=executer_ordre_echange(g1,echange);
                break;
            case type_lancement:
                lancement = (S_ordre_lancement *) feuille_ordre[i].ordre[j];
                valide=executer_ordre_lancement(g1,lancement);
                break;
            default :
                assert(0);
            }
            free(feuille_ordre[i].ordre[j]); //liberer l'espace memoire

            if(valide){
                nb_ordre_valide++;
            }
        }
        if(nb_ordre_valide == 0){
            printf("%d perd un power pour ne pas avoir agit (ou que des ordres faux)\n",i);
            g1->joueurs_partie[i].power -= 1;
            if(g1->joueurs_partie[i].power < 0) g1->joueurs_partie[i].power = 0;
        }
    }

}

void supprimer_pieces_inexistantes(S_game * g1)
{

    for(int i=0; i<NBJOUEURS; i++)
    {
        //[INSTRUMENTALISATION DE DEBUG] printf("verification inexistance joueur %d\n",i);
        for(int j=0; j<g1->joueurs_partie[i].nbpions; j++)
        {

            if(g1->joueurs_partie[i].tabpion[j].type_pion==type_piece_inexistante)
            {

                //[INSTRUMENTALISATION DE DEBUG] printf("en train de sppr une piece\n");
                supprimer(g1->joueurs_partie[i].tabpion,sizeof(S_pions),&g1->joueurs_partie[i].nbpions,j);
                j--; //on recule tous les éléments d'une case donc reculer le compteur pour ne pas zaper un element, on supprime la case sur laquelle on est
            }

        }
        //[INSTRUMENTALISATION DE DEBUG] printf("verification inexistance reserve joueur %d (%d en réserve)\n",i,g1->joueurs_partie[i].nbpions_reserve);
        for(int j=0; j<g1->joueurs_partie[i].nbpions_reserve; j++)
        {
            //[INSTRUMENTALISATION DE DEBUG] printf("regarde l'indice %d\n",j);
            if(g1->joueurs_partie[i].tabpion_reserve[j].type_pion==type_piece_inexistante)
            {

                //[INSTRUMENTALISATION DE DEBUG] printf("en train de sppr une piece en reserve\n");
                supprimer(g1->joueurs_partie[i].tabpion_reserve,sizeof(S_pions),&g1->joueurs_partie[i].nbpions_reserve,j);
                j--; //on recule tous les éléments d'une case donc reculer le compteur pour ne pas zaper un element, on supprime la case sur laquelle on est
            }

        }
    }

}

bool decompte_egalite_combat(S_game*g1,int x,int y,int power_max,int indice_max) //compte le nombre d'egalite de combat dans une case
{
    int egalite_max=0;
    for(int i=0; i<NBJOUEURS; i++) //calcul du nombre d'egalites par case
        if(somme_powers_a(x,y,g1->joueurs_partie,i)==power_max && i!=indice_max)
            egalite_max++;
    return egalite_max>0;
}

int decompte_joueur_combat(S_game*g1,int x, int y) //compte le nombre de joueurs impliques dans un combat dans une case
{
    int nombre_de_joueurs=0;
    for(int i=0; i<NBJOUEURS; i++)
        if(somme_powers_a(x,y,g1->joueurs_partie,i)>0)
            nombre_de_joueurs++; //nombre de joueurs impliques dans un combat
    return nombre_de_joueurs;
}

void calcul_gagnant_combat(S_game * g1,int x, int y,int * power_max, int * indice_max) //Calcul le gagnant d'un combat dans une case
{
    *power_max=-1;
    *indice_max=-1;
    for(int i=0; i<NBJOUEURS; i++)
    {
        if(somme_powers_a(x,y,g1->joueurs_partie,i)>*power_max)
        {
            *power_max=somme_powers_a(x,y,g1->joueurs_partie,i);
            *indice_max=i;
        }
    }
    assert(*power_max!=-1);
}

bool multiple_gagnants_combat(S_game * g1,int x, int y, int * power_max, int * indice_max)
{
    calcul_gagnant_combat(g1,x,y,power_max,indice_max);
    return decompte_egalite_combat(g1,x,y,*power_max,*indice_max);
}

void resolution_des_combats(S_game*g1)
{
    for(int x=1; x<=NBCASES; x++)
    {
        for(int y=1; y<=NBCASES; y++)
        {
            //[INSTRUMENTALISATION DE DEBUG] printf("\tnous sommes a la case %d %d  -- %d %d %d %d\n",x,y,somme_powers_a(x,y,g1->joueurs_partie,0),somme_powers_a(x,y,g1->joueurs_partie,1),somme_powers_a(x,y,g1->joueurs_partie,2),somme_powers_a(x,y,g1->joueurs_partie,3));
            if((somme_powers_a(x,y,g1->joueurs_partie,0)+somme_powers_a(x,y,g1->joueurs_partie,1)+somme_powers_a(x,y,g1->joueurs_partie,2)+somme_powers_a(x,y,g1->joueurs_partie,3))>0)
            {
                //[INSTRUMENTALISATION DE DEBUG] printf("\tcombat trouve\n");
                int power_max,indice_max;
                while(decompte_joueur_combat(g1,x,y)>0 && multiple_gagnants_combat(g1,x,y,&power_max,&indice_max))
                {
                    //[INSTRUMENTALISATION DE DEBUG] printf("\tduplicata trouve resolution en cours\n");
                    for(int i=0; i<NBJOUEURS; i++)
                    {
                        if(somme_powers_a(x,y,g1->joueurs_partie,i)==power_max)
                        {
                            //[INSTRUMENTALISATION DE DEBUG] printf("\tjoueur %d dans le duplicata\n",i);

                            for(int j=0; j<g1->joueurs_partie[i].nbpions; j++)
                            {

                                if(g1->joueurs_partie[i].tabpion[j].positions.position_x==x && g1->joueurs_partie[i].tabpion[j].positions.position_y==y)
                                {
                                    //[INSTRUMENTALISATION DE DEBUG] printf("\tpiece %d dans le duplicata\n",j);

                                    g1->joueurs_partie[i].tabpion[j].type_pion=type_piece_inexistante;
                                }
                            }
                        }
                    }
                }

                if(decompte_joueur_combat(g1,x,y)>1)
                {
                    //[INSTRUMENTALISATION DE DEBUG] printf("\treste apres duplicata, %d est gagnant\n",indice_max);

                    for(int i=0; i<NBJOUEURS; i++)
                    {
                        if(i!=indice_max)
                        {
                            //[INSTRUMENTALISATION DE DEBUG] printf("\tjoueur %d est perdant\n",i);

                            for(int j=0; j<g1->joueurs_partie[i].nbpions; j++)
                            {
                                if(g1->joueurs_partie[i].tabpion[j].positions.position_x==x && g1->joueurs_partie[i].tabpion[j].positions.position_y==y)
                                {
                                    //[INSTRUMENTALISATION DE DEBUG] printf("\tpiece %d est perdue\n",j);

                                    rajouter((void*)&g1->joueurs_partie[indice_max].tabpion_reserve,sizeof(S_pions),&g1->joueurs_partie[indice_max].nbpions_reserve,(void*)g1->joueurs_partie[indice_max].tabpion+j); //dernier truc==&g1->joueurs_partie[indice_max].tabpion[j]
                                    g1->joueurs_partie[i].tabpion[j].type_pion=type_piece_inexistante;

                                }

                            }
                        }
                    }
                }
                else
                {
                    //[INSTRUMENTALISATION DE DEBUG] printf("\trien apres duplicata\n");
                }
            }
        }
    }
}

void actions_du_tour(S_game * g1)
{
    //ajout des power

    for(int i = 0 ; i < NBJOUEURS ; i++){
        bool present[NBJOUEURS];
        for(int z = 0 ; z < NBJOUEURS ; z++) present[z] = false;

        for(int x = 1 ; x <= NBCASES ; x++){
            for(int y = 1 ; y <= NBCASES ; y++){

                int joueur_case = g1->plateau_partie.cases[y-1][x-1].joueur;
                if(joueur_case != -1 && joueur_case != i)
                { //case ennemi
                    if(somme_powers_a(x,y,g1->joueurs_partie,i) > 0)
                    {
                        present[joueur_case] = true;
                    }
                }
            }
        }
        for(int z = 0 ; z < NBJOUEURS ; z++){
            if(present[z]){
                printf("Joueur %d gagne 1 power en occupant le territoire de %d\n",i,z);
                g1->joueurs_partie[i].power+=1;
            }
        }
    }
}

void verifier_victoire(S_game * g1)
{
    for(int i = 0 ; i < NBJOUEURS ; i++){
        for(int j = 0 ; j < NBJOUEURS ; j++){
            int x = hq_x[j];
            int y = hq_y[j];
            if(j != i) //case ennemi
            {
                if(somme_powers_a(x,y,g1->joueurs_partie,i) > 0)
                {
                    printf("Le joueur %d gagne\n",i);
                    g1->gagnant_partie = i;
                    return; // le premier dans l'ordre des aiguilles d'une montre, pas d'ex aequo
                }
            }
        }
    }
}

void zoom(S_joueur * joueurs_partie,int num_joueur) //Zoom de la case demandee
{
    int x,y;
    printf("Quelle case souhaitez-vous agrandir? (tapez R pour la reserve)\nEn x (horizontal) : \n");
    int num = scanf("%d",&x); //scanf renvoie le nb de nombres(%..)qu'il a reussi a scaner. si %d%d, il renvoie 2 par exemple si scan de 2 %d reussi
    if(num!=1)
    {

        affiche_mes_unites_reserve(joueurs_partie[num_joueur],false);
        fflush(stdin);
        return;

    }
    printf("En y (vertical) :\n");
    scanf("%d",&y);
    affiche_unites(x,y,joueurs_partie);
}

S_game jouer_game(S_game g1)
{


    printf("\t\t\t********************************Bienvenue dans une partie de POWER********************************\n\nNous vous invitons a etendre la console en plein ecran, afin de profiter d'une experience totale de la partie qui va demarer dans 5sec\n\n");
    sleep(6);
    while(g1.gagnant_partie == -1)                     //boucle du jeu
    {
        // pour le tour de chaque joueur
        int result;
        S_feuille_ordres feuille_ordre[NBJOUEURS];
        for (int i=0; i<NBJOUEURS; i++)
        {


            int action_restante = 5;
            printf("\n\n\n\n");
            affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
            feuille_ordre[i].nb_ordre = 0;
            printf("\t\t----------------Joueur %d------------------\n",i+1);
            do
            {
                // on demande au joueur de saisir son action

                printf("\t\t-----Nombre actions tour restantes %d-----\n\n",action_restante);

                result = saisieAction(action_restante);
                affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
                //printf("action valide detectee car entree = %d\n",result);
                void * ordre;
                switch(result)
                {
                case 0:
                    zoom(g1.joueurs_partie,i);//joueur_partie sans [] car on veut les pions de tous les joueurs
                    break;
                case 1:
                    ordre = deplacerPion(g1.plateau_partie,feuille_ordre[i], g1.joueurs_partie[i], i);
                    feuille_ordre[i].ordre[5-action_restante] = ordre;
                    feuille_ordre[i].type[5-action_restante] = type_deplacement;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = 5-action_restante;
                    break;
                case 2:
                    ordre = achat(g1.joueurs_partie[i], i);
                    feuille_ordre[i].ordre[5-action_restante] = ordre;
                    feuille_ordre[i].type[5-action_restante] = type_achat;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = 5-action_restante;
                    break;
                case 3:
                    ordre = sortie(g1.joueurs_partie[i], feuille_ordre[i], i);
                    feuille_ordre[i].ordre[5-action_restante] = ordre;
                    feuille_ordre[i].type[5-action_restante] = type_sortie;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = 5-action_restante;
                    break;
                case 4:
                    ordre = echange(g1.joueurs_partie[i], feuille_ordre[i], i);
                    feuille_ordre[i].ordre[5-action_restante] = ordre;
                    feuille_ordre[i].type[5-action_restante] = type_echange;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = 5-action_restante;
                    break;
                case 5:
                    ordre = lancer_missile(feuille_ordre[i], g1.joueurs_partie[i], i);
                    feuille_ordre[i].ordre[5-action_restante] = ordre;
                    feuille_ordre[i].type[5-action_restante] = type_lancement;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = 5-action_restante;
                    break;

                case 6:
                    printf("Votre tour est fini\n");
                    break;
                default:
                    printf("Erreur de saisie inconnue\n");
                }

            }
            while(result!=6);

            // on reset le nbr d'action
            //g1.joueurs_partie.nbactionTour = 5;
        }




        // on execute les coups de chaque joueur
        executer_ordre(&g1, feuille_ordre);

        //resolution
        resolution_des_combats(&g1);

        //nettoyage des pieces de type inexistantes des tableaux
        supprimer_pieces_inexistantes(&g1);

        //exectuer les actions de tout les tours
        actions_du_tour(&g1); //power

        // on verifie si c'est la fin de la partie
        verifier_victoire(&g1);
    }

    affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
    return g1;
}
