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
        printf("0 : Zoom sur les unite d'une case ou la reserve\n");
        printf("1 : Deplacer un pion\n");
        printf("2 : Achat de pions\n");
        printf("3 : Sortie de pions\n");
        printf("4 : Fusion de pions\n");
        printf("5 : Lancement de missile\n");
        printf("6 : Fin de mon tour\n");
        scanf("%d", &nombreEntre);
        fflush(stdin);
        //system("CLS");
    }
    return nombreEntre;
}

void afficher_les_types_de_pion()
{
    //afficher les types de pions pouvant etre achetes
    for(int i = 0 ; i < taille_enum_pion-1 ; i++) //sauf piece innexistante
    {
        printf("%d : %s\n",i,nom_type_pions[i]);
    }
}

bool verifier_case_terrain(int x, int y, S_plateau plateau, S_pions pion)
{
#ifdef DEBUG
    printf("type %d  at %d %d -> %d vs %d \n",pion.type_pion,x,y,pion_type_eau[pion.type_pion],plateau.cases[y-1][x-1].terrain);
#endif

    if(pion_type_eau[pion.type_pion]!=(plateau.cases[y-1][x-1].terrain==eau)) // pion eau sur terre ou pion terre sur eau
    {
        if(!pion_type_eau[pion.type_pion])   //pion type terre
        {
#ifdef DEBUG
            printf("Pion terre sur eau\n");
#endif
            return false;
        }
        else   //pion type eau
        {
            if( (x ==3 && y ==3) || (x ==3 && y ==7) || (x ==7 && y ==3) || (x ==7 && y ==7))  //les centres des iles
            {
#ifdef DEBUG
                printf("Pion eau sur terre\n");
#endif
                return false;
            }
            else
            {
#ifdef DEBUG
                printf("Pion eau sur cote\n");
#endif
                //ne fait rien -> case coti�re autoris�
            }
        }
    }
    else
    {
#ifdef DEBUG
        printf("Bon type de pion pour la case\n");
#endif
    }

    return true;
}

bool verifier_chemin(S_plateau plateau, S_pions pion, int x_destination, int y_destination)
{
#ifdef DEBUG
    printf("verifier_chemin type %d; x%d, y%d, destx %d, desty%d\n",pion.type_pion,pion.positions.position_x,pion.positions.position_y,x_destination,y_destination);
#endif

    if(pion.type_pion == type_megamissile)
    {
        return true; // megamissile n'ont pas de conditino
    }

    int x1 = pion.positions.position_x; //x de d�part
    int y1 = pion.positions.position_y; //y de d�part
    int x2 = x_destination; //x de fin
    int y2 = y_destination; //y de fin
    int dx = abs(x2-x1); //distance a bouger sur l'axe x
    int dy = abs(y2-y1); //distance a bouger sur l'axe y

    int nombre_de_tour = max(dx,dy); //distance sur le plus grand axe -> si on avance de 4 horizontal et 1 vertical, il faut 4 tours

    float add_x = (x2-x1)/(float)nombre_de_tour; //d�placement � chaque tour sur l'axe X (peut �tre plus petit de 1)
    float add_y = (y2-y1)/(float)nombre_de_tour; //d�placement � chaque tour sur l'axe Y (peut �tre plus petit de 1)
    float actuellement_x_float = x1; //positon actuelle sur l'axe X SUR LA LIGNE DROITE (donc pas en case enti�re)
    float actuellement_y_float = y1; //positon actuelle sur l'axe Y SUR LA LIGNE DROITE (donc pas en case enti�re)

#ifdef DEBUG
    printf("addx%f addy%f nbrtour%d dx%d dy%d\n",add_x,add_y,nombre_de_tour,dx,dy);
#endif

    if(nombre_de_tour > pion_limite_deplacement[pion.type_pion])
    {
        printf("L'unite ne peut se deplacer aussi loin !\n");
        return false;
    }
#ifdef DEBUG
    printf("apres limite deplacement\n");

#endif

    int nb_chgmt_couleur=0;
    int actuellement_x = x1;
    int actuellement_y = y1;
    while(!(actuellement_x == x2 && actuellement_y == y2))   //tant qu'on est pas arriv�
    {
#ifdef DEBUG
        printf("actuellement x %d   actuellement y %d\n",actuellement_x,actuellement_y);
#endif
        int ancienne_couleur=plateau.cases[actuellement_y-1][actuellement_x-1].joueur;
        actuellement_x_float += add_x; //position actuelle en mouvement sur l'axe x
        actuellement_y_float += add_y; //position actuelle en mouvement sur l'axe y
        actuellement_x = round(actuellement_x_float); // on arrondi
        actuellement_y = round(actuellement_y_float); // on arrondi

        assert(actuellement_x > 0 && actuellement_x < 10 && actuellement_y > 0 && actuellement_y < 10);

#ifdef DEBUG
        printf("-%d-%d-\n",actuellement_x,actuellement_y);
#endif


        int nouvelle_couleur=plateau.cases[actuellement_y-1][actuellement_x-1].joueur;


        bool case_bon_type_terrain = verifier_case_terrain(actuellement_x,actuellement_y,plateau,pion);
#ifdef DEBUG
        printf("resultat case juste initial -> %d\n",case_bon_type_terrain);
#endif

        if(!case_bon_type_terrain)
        {

#ifdef DEBUG
            printf("Cas faux, tentative d'alternatifs...\n");
#endif
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
                case_bon_type_terrain = verifier_case_terrain(alt_actuellement_x,actuellement_y,plateau,pion);
                nouvelle_couleur=plateau.cases[actuellement_y-1][alt_actuellement_x-1].joueur;
#ifdef DEBUG
                printf("Alternative X trouvee, resultat %d...\n",case_bon_type_terrain);
#endif
            }

            if(!case_bon_type_terrain)
            {
                if(alt_actuellement_y != -1)
                {
                    case_bon_type_terrain = verifier_case_terrain(actuellement_x,alt_actuellement_y,plateau,pion);
                    nouvelle_couleur=plateau.cases[alt_actuellement_y-1][actuellement_x-1].joueur;
#ifdef DEBUG
                    printf("Alternative Y trouvee, resultat %d...\n",case_bon_type_terrain);
#endif
                }

            }

        }


        if(!case_bon_type_terrain)
        {
#ifdef DEBUG
            printf("Case fausse %d %d\n",actuellement_x, actuellement_y);
#endif
            printf("Le type de terrain ne correspond pas\n");
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
                printf("Le pion ne peut pas rentrer et sortir d'un territoire en un tour\n");
                return false;
            }
            else
            {
#ifdef DEBUG
                printf("Case jsute\n");
#endif
            }
        }


    }

    printf("Le deplacement est possible pour cette unite\n");

    return true;
}



void * deplacerPion(S_plateau plateau,S_feuille_ordres feuille_ordre, S_joueur le_joueur, int num_joueur)
{
    int x, y;
    enum_type_pion type_pion;
    printf("Dans quelle case est le pion que vous souhaitez deplacer ?\nEn x (horizontal) : \n");
    scanf("%d",&x);
    fflush(stdin);
    printf("En y (vertical) : \n");
    scanf("%d",&y);
    fflush(stdin);

    afficher_les_types_de_pion();

    printf("Quel type de pion voulez-vous deplacer ? (Veuillez entrer l'indice a gauche du pion)\n");
    scanf("%d",(int*)(&type_pion));
    fflush(stdin);


    int dest_x, dest_y; //dest -> destination
    printf("Ou souhaitez-vous aller ?\nEn x (horizontal) : \n");
    scanf("%d",&dest_x);
    fflush(stdin);
    printf("En y (vertical) : \n");
    scanf("%d",&dest_y);
    fflush(stdin);


    S_ordre_deplacement * ordre = (S_ordre_deplacement *) malloc(sizeof(S_ordre_deplacement));
    if(ordre == NULL)
    {
        printf("Erreur memoire\n");
        exit(1);
    }

    ordre->num_joueur = num_joueur;
    ordre->position_arrive_x = dest_x;
    ordre->position_arrive_y = dest_y;
    ordre->position_x = x;
    ordre->position_y = y;
    ordre->type_pion = type_pion;



    return ordre;
}

void * lancer_missile(S_feuille_ordres feuille_ordre, S_joueur le_joueur, int num_joueur)
{
    bool vers_reserve = false;

    int joueur_reserve_cible = -1;
    int x, y;
    enum_type_pion type_pion;
    printf("Dans quelle case est le missile ?\nEn x (horizontal) : \n");
    scanf("%d",&x);
    fflush(stdin);
    printf("En y (vertical) : \n");
    scanf("%d",&y);
    fflush(stdin);

    int dest_x, dest_y; //dest -> destination
    printf("Ou souhaitez-vous l'envoyer ? (Ou R pour viser une reserve) \nEn x (horizontal) : \n");
    int num = scanf("%d",&dest_x);
    fflush(stdin);
    if(num!=1)  // R
    {
        vers_reserve = true;
        printf("Joueur cible ? \n");
        scanf("%d",&joueur_reserve_cible);
        fflush(stdin);
        joueur_reserve_cible--; //commence de 1, conversion vers debut � 0
    }
    else
    {
        printf("En y (vertical) : \n");
        scanf("%d",&dest_y);
        fflush(stdin);
    }


    S_ordre_lancement * ordre = (S_ordre_lancement *) malloc(sizeof(S_ordre_lancement));
    if(ordre == NULL)
    {
        printf("Erreur memoire\n");
        exit(1);
    }

    ordre->num_joueur = num_joueur;
    ordre->position_x = x;
    ordre->position_y = y;
    ordre->position_arrive_x = dest_x;
    ordre->position_arrive_y = dest_y;
    ordre->vers_reserve = vers_reserve;
    ordre->joueur_reserve_cible = joueur_reserve_cible;

    return ordre;
}

void* achat(S_joueur joueur, int num_joueur)
{

    enum_type_pion type;

    afficher_les_types_de_pion();

    printf("Quelle piece voulez-vous acheter avec vos powers ? \n");
    scanf("%d",(int*)(&type));
    fflush(stdin);
    S_ordre_achat * ordre = (S_ordre_achat *) malloc(sizeof(S_ordre_achat));

    if(ordre==NULL)
    {
        printf("erreur memoire\n");
        exit(1); //arret d'urgence
    }

    ordre->type_pion=type;
    ordre->num_joueur=num_joueur;

    return ordre;
}
void* sortie(S_joueur joueur,S_feuille_ordres feuille_ordre, int num_joueur)
{
    enum_type_pion type=type_piece_inexistante;

    afficher_les_types_de_pion();

    printf("Quel type de pion voulez-vous sortir ? (Veuillez entrer l'indice a gauche du pion)\n");
    scanf("%d",(int*)(&type));
    fflush(stdin);


    S_ordre_sortie * ordre = (S_ordre_sortie *) malloc(sizeof(S_ordre_sortie));

    if(ordre==NULL)
    {
        printf("erreur memoire\n");
        exit(1); //arret d'urgence
    }

    ordre->num_joueur=num_joueur;
    ordre->type_pion=type;

    return ordre;
}
void* echange(S_joueur joueur,S_feuille_ordres feuille_ordre, int num_joueur)
{
    int x, y;
    enum_type_pion type_pion;
    bool depuis_reserve = false;
    bool pour_missile = false;
    printf("De quelle case proviennent les unites a fusionner (R pour la reserve) ?\nEn x (horizontal) : \n");
    int num = scanf("%d",&x); //scanf renvoie le nb de nombres(%..)qu'il a reussi a scaner. si %d%d, il renvoie 2 par exemple si scan de 2 %d reussi
    fflush(stdin);
    if(num!=1)  // R
    {
        depuis_reserve = true;
    }
    else
    {
        printf("En y (vertical) : \n");
        scanf("%d",&y);
        fflush(stdin);
    }

    afficher_les_types_de_pion();
    printf("M pour tout echanger contre un missile\n");

    printf("Quel type de pion souhaitez-vous fusionner ?\n");
    num = scanf("%d",(int*)(&type_pion));
    fflush(stdin);
    if(num != 1){
        pour_missile = true;
    }


    S_ordre_echange * ordre = (S_ordre_echange *) malloc(sizeof(S_ordre_echange));
    if(ordre == NULL)
    {
        printf("Erreur memoire\n");
        exit(1);
    }

    ordre->position_x = x;
    ordre->position_y = y;
    ordre->type_pion = type_pion;
    ordre->depuis_reserve = depuis_reserve;
    ordre->num_joueur = num_joueur;
    ordre->pour_missile = pour_missile;

    return ordre;
}

bool executer_ordre_deplacement(S_game * g1, S_ordre_deplacement * deplacement)
{
    int indice_pion=-1;
    S_joueur le_joueur = g1->joueurs_partie[deplacement->num_joueur];
    for(int i=0; i<le_joueur.nbpions; i++)
    {
        if(le_joueur.tabpion[i].positions.position_x==deplacement->position_x && le_joueur.tabpion[i].positions.position_y==deplacement->position_y && le_joueur.tabpion[i].type_pion==deplacement->type_pion)
        {
            enum_types_ordre dernier_action = le_joueur.tabpion[i].dernier_ordre_du_tour;

            if(dernier_action == type_aucun_ordre)  // le pion ne peut bouger qui si il n'a rien fait avant durant ce tour
            {
                indice_pion=i;
            }

        }

    }

    if(deplacement->type_pion == type_megamissile)  //missile non deplacable
    {
        printf("Ordre de deplacement impossible, les pions de type %s ne peuvent pas se d�placer\n",nom_type_pions[deplacement->type_pion]);
        return false;
    }

    if(indice_pion == -1)
    {
        printf("Ordre de deplacement impossible, il n'y a pas de pion libre de ce type en %d.%d\n",deplacement->position_x,deplacement->position_y);
        return false;
    }


    if(deplacement->position_arrive_x < 1 || deplacement->position_arrive_x > NBCASES || deplacement->position_arrive_y < 1 || deplacement->position_arrive_y > NBCASES) {
        printf("Ordre de deplacement impossible, %d.%d n'est pas sur le plateau\n", deplacement->position_arrive_x,deplacement->position_arrive_x);
        return false;
    }

    bool juste = verifier_chemin(g1->plateau_partie, le_joueur.tabpion[indice_pion], deplacement->position_arrive_x, deplacement->position_arrive_y);

    if(!juste)
    {
        printf("Ordre de deplacement impossible, la piece ne peut pas se rendre en %d.%d\n",deplacement->position_arrive_x,deplacement->position_arrive_y);
        return false;
    }


    g1->joueurs_partie[deplacement->num_joueur].tabpion[indice_pion].positions.position_x = deplacement->position_arrive_x;
    g1->joueurs_partie[deplacement->num_joueur].tabpion[indice_pion].positions.position_y = deplacement->position_arrive_y;

    g1->joueurs_partie[deplacement->num_joueur].tabpion[indice_pion].dernier_ordre_du_tour = type_deplacement;

    printf("Joueur %s deplace un pion %s de %d.%d vers %d.%d\n",joueur_nom[deplacement->num_joueur],nom_type_pions[deplacement->type_pion],deplacement->position_x,deplacement->position_y,deplacement->position_arrive_x,deplacement->position_arrive_y);

    return true;
}

bool executer_ordre_lancement(S_game * g1, S_ordre_lancement * lancement)
{
    int num_pion = -1;

    S_joueur le_joueur = g1->joueurs_partie[lancement->num_joueur];
    for(int i=0; i<le_joueur.nbpions; i++)
    {
        if(le_joueur.tabpion[i].positions.position_x==lancement->position_x && le_joueur.tabpion[i].positions.position_y==lancement->position_y && le_joueur.tabpion[i].type_pion==type_megamissile)
        {

            enum_types_ordre dernier_action = le_joueur.tabpion[i].dernier_ordre_du_tour;

            if(dernier_action == type_aucun_ordre)  // le missile ne peut etre lanc� qui si il n'a rien fait avant durant ce tour
            {
                num_pion=i;
            }


        }

    }
    if(num_pion == -1)
    {
        printf("Ordre de lancement impossible, il n'y a pas de missile libre en %d.%d\n", lancement->position_x,lancement->position_y);
        return false;
    }

    g1->joueurs_partie[lancement->num_joueur].tabpion[num_pion].type_pion = type_piece_inexistante;
    g1->joueurs_partie[lancement->num_joueur].tabpion[num_pion].dernier_ordre_du_tour = type_lancement;


    if(!lancement->vers_reserve)
    {
        if(lancement->position_arrive_x < 1 || lancement->position_arrive_x > NBCASES || lancement->position_arrive_y < 1 || lancement->position_arrive_y > NBCASES) {
            printf("Ordre de lancement impossible, %d.%d n'est pas sur le plateau\n", lancement->position_arrive_x,lancement->position_arrive_x);
            return false;
        }


        printf("BOOM : Toutes les unties presente dans la case cible en %d.%d ont ete tueees \n",lancement->position_arrive_x,lancement->position_arrive_y);
        for(int i=0; i<NBJOUEURS; i++) //calcul du nombre d'egalites par case
            for(int j = 0 ; j < g1->joueurs_partie[i].nbpions ; j++)
                if(g1->joueurs_partie[i].tabpion[j].positions.position_x == lancement->position_arrive_x &&
                        g1->joueurs_partie[i].tabpion[j].positions.position_y == lancement->position_arrive_y)
                    g1->joueurs_partie[i].tabpion[j].type_pion = type_piece_inexistante;

    }
    else
    {
        if(lancement->joueur_reserve_cible < 0 || lancement->joueur_reserve_cible >= NBJOUEURS) {
            printf("Ordre de lancement impossible, %d n'est pas un joueur\n", lancement->joueur_reserve_cible+1);
            return false;
        }

        printf("BOOM : Tout le monde meurt dans la reserve du joueur %s\n",joueur_nom[lancement->joueur_reserve_cible]);
        for(int j = 0 ; j < g1->joueurs_partie[lancement->joueur_reserve_cible].nbpions_reserve ; j++)
            g1->joueurs_partie[lancement->joueur_reserve_cible].tabpion_reserve[j].type_pion = type_piece_inexistante;

    }


    return true;
}

bool executer_ordre_achat(S_game * g1, S_ordre_achat * l_achat)
{

    bool valide = false;
    bool pion_invalide = (l_achat->type_pion<0 || l_achat->type_pion>=taille_enum_pion || prix[l_achat->type_pion]==-1);
    if(pion_invalide)
    {
        printf("Ordre d'achat invalide, ce type de pion ne s'achete pas\n");
        return false;
    }

    if(g1->joueurs_partie[l_achat->num_joueur].power<prix[l_achat->type_pion]) //s'assure que l'utilisateur rentre un bon num�ro de type
    {
        printf("Ordre d'achat invalide, vous n'avez pas assez de power (%d/%d)\n",g1->joueurs_partie[l_achat->num_joueur].power,prix[l_achat->type_pion]);
        return false;
    }

    g1->joueurs_partie[l_achat->num_joueur].power-=prix[l_achat->type_pion];      //equivaut a x=x-...

    S_pions pion = creer_pion_de_type(l_achat->type_pion,100,100);

    rajouter((void*)&g1->joueurs_partie[l_achat->num_joueur].tabpion_reserve,sizeof(S_pions),
             &g1->joueurs_partie[l_achat->num_joueur].nbpions_reserve,
             (void*)&pion);

    g1->joueurs_partie[l_achat->num_joueur].tabpion_reserve[g1->joueurs_partie[l_achat->num_joueur].nbpions_reserve-1].dernier_ordre_du_tour = type_achat; // on note sur le tout dernier pion (celui  qu'on vient de rajotuer) qu'il vient d'apparaitre

    printf("Joueur %s achete un pion %s pour %d power\n",joueur_nom[l_achat->num_joueur],nom_type_pions[l_achat->type_pion],prix[l_achat->type_pion]);

    return true;
}

// Retourne false en cas d'ordre invalide
bool executer_ordre_echange(S_game * g1, S_ordre_echange * echange)
{
    enum_type_pion nouveau;
    if(!echange->pour_missile)
    {
        int indice_pion[3];
        for(int i = 0 ; i < 3 ; i++) indice_pion[i]=-1;

        for(int z=0 ; z < 3 ; z++)
        {
            S_pions * tab = g1->joueurs_partie[echange->num_joueur].tabpion;
            int nb = g1->joueurs_partie[echange->num_joueur].nbpions;
            if(echange->depuis_reserve)
            {
                tab = g1->joueurs_partie[echange->num_joueur].tabpion_reserve;
                nb = g1->joueurs_partie[echange->num_joueur].nbpions_reserve;
            }

            for(int i=0; i<nb; i++)
            {
                if((echange->depuis_reserve || (tab[i].positions.position_x==echange->position_x && tab[i].positions.position_y==echange->position_y)) && tab[i].type_pion==echange->type_pion)
                {
                    bool deja_en_indice = false;
                    for(int j = 0 ; j < 3 ; j++)
                    {
                        if(i == indice_pion[j])
                        {
                            deja_en_indice = true;
                        }
                    }

                    bool disponible = true;

                    enum_types_ordre dernier_action = tab[i].dernier_ordre_du_tour;

                    if(dernier_action == type_sortie)  // le pion ne peut etre fusionne apres avoir ete sorti
                    {
                        disponible = false;
                    }

                    if( !deja_en_indice && disponible /*&&!possede_deja_ordre(feuille_ordre, num_joueur, i, depuis_reserve)*/)
                    {

                        indice_pion[z]=i;
                        break; //n'avoir qu'un seul pion qui repond aux conditions du if

                    }

                }
            }
        }
        printf("[DEBUG]indices choisis :%d %d %d\n",indice_pion[0],indice_pion[1],indice_pion[2]);

        if(indice_pion[2] == -1)
        {
            printf("Ordre d'echange invalide, il n'y a pas 3 pi�ce de ce type disponible en %d.%d\n",echange->position_x,echange->position_y);
            return false;
        }

        nouveau = pion_type_amelioration[echange->type_pion];

        if(nouveau == type_piece_inexistante)
        {
            printf("Ordre d'echange invalide, ce type de pieces ne peuvent etre fusionnees\n");
            return false;
        }

        S_pions** tab;
        int * nb;

        if(echange->depuis_reserve)
        {
            tab =&g1->joueurs_partie[echange->num_joueur].tabpion_reserve;
            nb = &g1->joueurs_partie[echange->num_joueur].nbpions_reserve;
        }
        else
        {
            tab = &g1->joueurs_partie[echange->num_joueur].tabpion;
            nb = &g1->joueurs_partie[echange->num_joueur].nbpions;
        }


        (*tab)[ (*nb)-1].dernier_ordre_du_tour = type_echange;

        for(int i = 0 ; i < 3 ; i++)
        {
            (*tab)[indice_pion[i]].type_pion = type_piece_inexistante;
        }

        if(!echange->depuis_reserve){
            printf("Joueur %s echange 3 pions %d pour un pion %s en %d.%d\n",joueur_nom[echange->num_joueur],
            nom_type_pions[echange->type_pion],
            nom_type_pions[nouveau],
            echange->position_x,
            echange->position_y);
        } else {
            printf("Joueur %s echange 3 pions %d pour un pion %s dans sa reserve\n",joueur_nom[echange->num_joueur],
            nom_type_pions[echange->type_pion],
            nom_type_pions[nouveau]);
        }

        S_pions pion = creer_pion_de_type(nouveau,echange->position_x,echange->position_y);
        rajouter((void**)tab,sizeof(S_pions),
                 nb,
                 (void*)&pion);

    } else {
        nouveau = type_megamissile;
        int somme = echange->depuis_reserve?somme_powers_reserve(g1->joueurs_partie,echange->num_joueur):somme_powers_a(echange->position_x,echange->position_y,g1->joueurs_partie,echange->num_joueur);
        if(somme < 100)
        {
            printf("Ordre d'echange invalide, il n'y a pas 100 de power comme requis (seulement %d puissance en %d.%d)\n",somme,echange->position_x,echange->position_y);
            return false;
        }

        if(echange->depuis_reserve){
            for(int i = 0 ; i < g1->joueurs_partie[echange->num_joueur].nbpions_reserve ; i++){
                g1->joueurs_partie[echange->num_joueur].tabpion_reserve[i].type_pion = type_piece_inexistante;
            }
            printf("La reserve du joueur %s est videe\n",joueur_nom[echange->num_joueur]);
        }
        else{
            for(int i = 0 ; i < g1->joueurs_partie[echange->num_joueur].nbpions ; i++){
                if(g1->joueurs_partie[echange->num_joueur].tabpion[i].positions.position_x == echange->position_x &&
                   g1->joueurs_partie[echange->num_joueur].tabpion[i].positions.position_y == echange->position_y)
                   {
                        g1->joueurs_partie[echange->num_joueur].tabpion[i].type_pion = type_piece_inexistante;
                   }
            }
            printf("Les pions de la case du joueur %s sont videe\n",echange->position_x,echange->position_y,joueur_nom[echange->num_joueur]);
        }

        S_pions** tab;
        int * nb;

        if(echange->depuis_reserve)
        {
            tab =&g1->joueurs_partie[echange->num_joueur].tabpion_reserve;
            nb = &g1->joueurs_partie[echange->num_joueur].nbpions_reserve;
        }
        else
        {
            tab = &g1->joueurs_partie[echange->num_joueur].tabpion;
            nb = &g1->joueurs_partie[echange->num_joueur].nbpions;
        }
        if(!echange->depuis_reserve){
            printf("Joueur %s echange tout les pions dans sa reserve pour un missile\n",joueur_nom[echange->num_joueur]);
        } else {
            printf("Joueur %s echange tout les pions a la case %d.%d pour un missile\n",joueur_nom[echange->num_joueur],
            echange->position_x,
            echange->position_y);
        }
        S_pions pion = creer_pion_de_type(nouveau,echange->position_x,echange->position_y);
        rajouter((void**)tab,sizeof(S_pions),
                 nb,
                 (void*)&pion);
    }




    return true;
}

bool executer_ordre_sortie(S_game * g1, S_ordre_sortie * sortie)
{

    int indice_pion = -1;

    for(int i = 0 ; i < g1->joueurs_partie[sortie->num_joueur].nbpions_reserve ; i++)
    {
        if(g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[i].type_pion == sortie->type_pion)
        {
            enum_types_ordre dernier_action = g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[i].dernier_ordre_du_tour; // rien n'est interdit avant de sortir, on a le droit d'acheter puis sortir

            indice_pion=i;
            break;
        }
    }

    if(indice_pion == -1)  //vrai si valide faux et vrai sinon
    {
        printf("Ordre de sortie invalide, pas de pion de ce type dans la r�serve\n");
        return false;
    }

    g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[indice_pion].positions.position_x = hq_x[sortie->num_joueur];
    g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[indice_pion].positions.position_y = hq_y[sortie->num_joueur];

    printf("Sortie sur le tableau du pion %s a la case %d.%d depuis la reserve\n",nom_type_pions[g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[indice_pion].type_pion],
           g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[indice_pion].positions.position_x,
           g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[indice_pion].positions.position_y);

    rajouter((void*)&g1->joueurs_partie[sortie->num_joueur].tabpion,sizeof(S_pions),
             &g1->joueurs_partie[sortie->num_joueur].nbpions,
             (void*)&g1->joueurs_partie[sortie->num_joueur].tabpion_reserve[indice_pion]);

    g1->joueurs_partie[sortie->num_joueur].tabpion[ g1->joueurs_partie[sortie->num_joueur].nbpions-1 ].dernier_ordre_du_tour = type_sortie;

    supprimer(g1->joueurs_partie[sortie->num_joueur].tabpion_reserve,sizeof(S_pions),
              &g1->joueurs_partie[sortie->num_joueur].nbpions_reserve,
              indice_pion);

    return true;
}

void reinitialiser_dernier_ordre_pion(S_game * g1)
{
    for(int i = 0 ; i < NBJOUEURS ; i++)
    {
        for(int j = 0 ; j < g1->joueurs_partie[i].nbpions ; j++)
        {
            g1->joueurs_partie[i].tabpion[j].dernier_ordre_du_tour = type_aucun_ordre;
        }
        for(int j = 0 ; j < g1->joueurs_partie[i].nbpions_reserve ; j++)
        {
            g1->joueurs_partie[i].tabpion_reserve[j].dernier_ordre_du_tour = type_aucun_ordre;
        }
    }
}



void executer_ordre(S_game * g1, S_feuille_ordres feuille_ordre[NBJOUEURS])
{
    reinitialiser_dernier_ordre_pion(g1);

    for(int i = 0 ; i < NBJOUEURS ; i++)
    {
        print_color(i);
        printf("On execute les ordres de %s : \n",joueur_nom[i]);
        print_color(-1);

        int nb_ordre_valide = 0;
        for(int j = 0 ; j < feuille_ordre[i].nb_ordre ; j++)
        {
#ifdef DEBUG
            printf("[DEBUG] Feuille d'ordre, joueur %d, ordre %d/%d\n",i,j,feuille_ordre[i].nb_ordre);
#endif

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

            if(valide)
            {
                nb_ordre_valide++;
            }
        }
        if(nb_ordre_valide == 0)
        {
            printf("Le joueur %s perd un power pour ne pas avoir agit (ou que des ordres faux).\n",joueur_nom[i]);
            g1->joueurs_partie[i].power -= 1;
            if(g1->joueurs_partie[i].power < 0){
                g1->joueurs_partie[i].power = 0;
                faire_payer_piece(g1,i);

            }
        }
        printf("\n");
    }

}

void supprimer_pieces_inexistantes(S_game * g1)
{

    for(int i=0; i<NBJOUEURS; i++)
    {
#ifdef DEBUG
        printf("verification inexistance joueur %d\n",i);
#endif
        for(int j=0; j<g1->joueurs_partie[i].nbpions; j++)
        {

            if(g1->joueurs_partie[i].tabpion[j].type_pion==type_piece_inexistante)
            {

#ifdef DEBUG
                printf("en train de sppr une piece\n");
#endif
                supprimer(g1->joueurs_partie[i].tabpion,sizeof(S_pions),&g1->joueurs_partie[i].nbpions,j);
                j--; //on recule tous les �l�ments d'une case donc reculer le compteur pour ne pas zaper un element, on supprime la case sur laquelle on est
            }

        }
#ifdef DEBUG
        printf("verification inexistance reserve joueur %d (%d en r�serve)\n",i,g1->joueurs_partie[i].nbpions_reserve);
#endif
        for(int j=0; j<g1->joueurs_partie[i].nbpions_reserve; j++)
        {
#ifdef DEBUG
            printf("regarde l'indice %d\n",j);
#endif
            if(g1->joueurs_partie[i].tabpion_reserve[j].type_pion==type_piece_inexistante)
            {

#ifdef DEBUG
                printf("en train de sppr une piece en reserve\n");
#endif
                supprimer(g1->joueurs_partie[i].tabpion_reserve,sizeof(S_pions),&g1->joueurs_partie[i].nbpions_reserve,j);
                j--; //on recule tous les �l�ments d'une case donc reculer le compteur pour ne pas zaper un element, on supprime la case sur laquelle on est
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
#ifdef DEBUG
            printf("\tnous sommes a la case %d %d  -- %d %d %d %d\n",x,y,somme_powers_a(x,y,g1->joueurs_partie,0),somme_powers_a(x,y,g1->joueurs_partie,1),somme_powers_a(x,y,g1->joueurs_partie,2),somme_powers_a(x,y,g1->joueurs_partie,3));
#endif
            if((somme_powers_a(x,y,g1->joueurs_partie,0)+somme_powers_a(x,y,g1->joueurs_partie,1)+somme_powers_a(x,y,g1->joueurs_partie,2)+somme_powers_a(x,y,g1->joueurs_partie,3))>0)
            {
#ifdef DEBUG
                printf("\tcombat trouve, somme %d\n",somme_powers_a(x,y,g1->joueurs_partie,0)+somme_powers_a(x,y,g1->joueurs_partie,1)+somme_powers_a(x,y,g1->joueurs_partie,2)+somme_powers_a(x,y,g1->joueurs_partie,3));
#endif
                int power_max,indice_max;
                while(decompte_joueur_combat(g1,x,y)>0 && multiple_gagnants_combat(g1,x,y,&power_max,&indice_max))
                {
#ifdef DEBUG
                    printf("\tduplicata trouve resolution en cours\n");
#endif
                    for(int i=0; i<NBJOUEURS; i++)
                    {
                        if(somme_powers_a(x,y,g1->joueurs_partie,i)==power_max)
                        {
#ifdef DEBUG
                            printf("\tjoueur %d dans le duplicata\n",i);
#endif

                            for(int j=0; j<g1->joueurs_partie[i].nbpions; j++)
                            {

                                if(g1->joueurs_partie[i].tabpion[j].positions.position_x==x && g1->joueurs_partie[i].tabpion[j].positions.position_y==y)
                                {
#ifdef DEBUG
                                    printf("\tpiece %d dans le duplicata\n",j);
#endif

                                    g1->joueurs_partie[i].tabpion[j].type_pion=type_piece_inexistante;
                                }
                            }
                        }
                    }
                }

                if(decompte_joueur_combat(g1,x,y)>1)
                {
#ifdef DEBUG
                    printf("\treste apres duplicata, %d est gagnant\n",indice_max);
#endif

                    for(int i=0; i<NBJOUEURS; i++)
                    {
                        if(i!=indice_max)
                        {
#ifdef DEBUG
                            printf("\tjoueur %d est perdant\n",i);
#endif

                            for(int j=0; j<g1->joueurs_partie[i].nbpions; j++)
                            {
                                if(g1->joueurs_partie[i].tabpion[j].positions.position_x==x && g1->joueurs_partie[i].tabpion[j].positions.position_y==y)
                                {

#ifdef DEBUG
                                    printf("\tpiece %d est perdue\n",j);
#endif

                                    rajouter((void*)&g1->joueurs_partie[indice_max].tabpion_reserve,sizeof(S_pions),&g1->joueurs_partie[indice_max].nbpions_reserve,(void*)g1->joueurs_partie[indice_max].tabpion+j); //dernier truc==&g1->joueurs_partie[indice_max].tabpion[j]
                                    g1->joueurs_partie[i].tabpion[j].type_pion=type_piece_inexistante;

                                }

                            }
                        }
                    }
                }
                else
                {
#ifdef DEBUG
                    printf("\trien apres duplicata\n");
#endif // DEBUG
                }
            }
        }
    }
}

void actions_du_tour(S_game * g1)
{
    //ajout des power

    for(int i = 0 ; i < NBJOUEURS ; i++)
    {
        bool present[NBJOUEURS];
        for(int z = 0 ; z < NBJOUEURS ; z++) present[z] = false;

        for(int x = 1 ; x <= NBCASES ; x++)
        {
            for(int y = 1 ; y <= NBCASES ; y++)
            {

                int joueur_case = g1->plateau_partie.cases[y-1][x-1].joueur;
                if(joueur_case != -1 && joueur_case != i)
                {
                    //case ennemi
                    if(somme_powers_a(x,y,g1->joueurs_partie,i) > 0)
                    {
                        present[joueur_case] = true;
                    }
                }
            }
        }
        for(int z = 0 ; z < NBJOUEURS ; z++)
        {
            if(present[z])
            {
                printf("Joueur %s gagne 1 power en occupant le territoire du joueur %s\n",joueur_nom[i],joueur_nom[z]);
                g1->joueurs_partie[i].power+=1;
            }
        }
    }
}

void verifier_victoire(S_game * g1)
{
    for(int i = 0 ; i < NBJOUEURS ; i++)
    {
        for(int j = 0 ; j < NBJOUEURS ; j++)
        {
            int x = hq_x[j];
            int y = hq_y[j];
            if(j != i) //case ennemi
            {
                if(somme_powers_a(x,y,g1->joueurs_partie,i) > 0)
                {
                    printf("Le joueur %s gagne\n",joueur_nom[i]);
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
    fflush(stdin);
    if(num!=1)
    {

        affiche_mes_unites_reserve(joueurs_partie[num_joueur],false);
        return;

    }
    printf("En y (vertical) :\n");
    scanf("%d",&y);
    fflush(stdin);
    affiche_unites(x,y,joueurs_partie);
}

void separer_unites(S_game * g1, int num_joueur, int num_piece, bool en_reserve)
{
    S_pions ** tab = en_reserve?&g1->joueurs_partie[num_joueur].tabpion_reserve:&g1->joueurs_partie[num_joueur].tabpion;
    int * nb = en_reserve?&g1->joueurs_partie[num_joueur].nbpions_reserve:&g1->joueurs_partie[num_joueur].nbpions;

    enum_type_pion type_original = (*tab)[num_piece].type_pion;
    enum_type_pion type_separe = pion_type_deamelioration[type_original];

    assert(type_separe != type_piece_inexistante);

    S_pions pion = creer_pion_de_type(type_separe,(*tab)[num_piece].positions.position_x,(*tab)[num_piece].positions.position_y);

    printf("Rajout sur le tableau par separation de deux pions %s a la case %d.%d\n",
           nom_type_pions[type_separe],
           (*tab)[num_piece].positions.position_x,
           (*tab)[num_piece].positions.position_y);

    rajouter((void**)tab,sizeof(S_pions),
             nb,
             (void*)&pion);
    rajouter((void**)tab,sizeof(S_pions),
             nb,
             (void*)&pion);


    (*tab)[num_piece].type_pion = type_piece_inexistante;


}

void faire_payer_piece(S_game * g1, int num_joueur){

    int min_power = 9999;
    int min_indice = -1;
    bool en_reserve = false;
    for(int j=0; j<g1->joueurs_partie[num_joueur].nbpions; j++)
    {
        if(g1->joueurs_partie[num_joueur].tabpion[j].puissance < min_power){
            min_power = g1->joueurs_partie[num_joueur].tabpion[j].puissance;
            min_indice = j;
        }
    }
    if(min_indice == -1){
        en_reserve = true;
        for(int j=0; j<g1->joueurs_partie[num_joueur].nbpions_reserve; j++)
        {
            if(g1->joueurs_partie[num_joueur].tabpion_reserve[j].puissance < min_power){
                min_power = g1->joueurs_partie[num_joueur].tabpion_reserve[j].puissance;
                min_indice = j;
            }
        }
    }

    if(min_indice == -1){
        printf("Le joueur %s n'a plus de pieces pour payer ! La honte !\n", joueur_nom[num_joueur]);
        return;
    }

    S_pions * tab = en_reserve?g1->joueurs_partie[num_joueur].tabpion_reserve:g1->joueurs_partie[num_joueur].tabpion;

    enum_type_pion type = tab[min_indice].type_pion;

    printf("Le joueur %s a perdu une piece %s pour payer son ammende!\n", joueur_nom[num_joueur], nom_type_pions[type]);

    if(pion_type_deamelioration[type] == type_piece_inexistante){ // si ca ne se d�s-am�liore pas
        tab[min_indice].type_pion = type_piece_inexistante;
    } else {

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


            int action_restante = 5;
            printf("\n\n\n\n");
            affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
            feuille_ordre[i].nb_ordre = 0;
            printf("\t\t---------------- Joueur %6s ------------------\n",joueur_nom[i]);
            do
            {
                // on demande au joueur de saisir son action

                printf("\t\t      -----%d Actions restantes ce tour-----\n\n",action_restante);

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

        for(int i = 0 ; i < 70 ; i++){printf("\n");}
        printf("-------------------------------------------------\n");
        printf("--------------------FIN DU TOUR------------------\n");
        printf("-------------------------------------------------\n");
        for(int i = 0 ; i < 5 ; i++){printf("\n");}

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

        for(int i = 0 ; i < 5 ; i++){printf("\n");}
        system("PAUSE");

        for(int i = 0 ; i < 70 ; i++){printf("\n");}
        printf("-------------------------------------------------\n");
        printf("--------------------TOUR SUIVANT-----------------\n");
        printf("-------------------------------------------------\n");
        for(int i = 0 ; i < 5 ; i++){printf("\n");}

    }

    affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
    return g1;
}
