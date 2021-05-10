#include "game.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <unistd.h>

#include "definition.h"
#include "initialisation.h"
#include "affichage.h"
#include "plateau.h"
#include "util.h"
#include "ordres.h"
#include "noms_joueurs.h"
#include "noms_pions.h"

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
    if(nbcoup==0) return saisie_fintour;

    //demander a l'utilisateur ce qu'il souhaite faire
    int nombreEntre = -1;
    while ((nombreEntre < 0) || (nombreEntre > taille_saisie_joueur))
    {
        printf("Quelle action souhaitez vous faire ?\n");
        printf("%d : Zoom sur les unite d'une case ou la reserve\n",saisie_zoom);
        printf("%d : Deplacer un pion\n",saisie_deplacer);
        printf("%d : Achat de pions\n",saisie_achat);
        printf("%d : Sortie de pions\n",saisie_sortie);
        printf("%d : Fusion de pions\n",saisie_echange);
        printf("%d : Lancement de missile\n",saisie_lancement);
        printf("%d : Fin de mon tour\n",saisie_fintour);
        scanf("%d", &nombreEntre);
        fflush(stdin);
        //system("CLS");
    }
    return nombreEntre;
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
                j--; //on recule tous les éléments d'une case donc reculer le compteur pour ne pas zaper un element, on supprime la case sur laquelle on est
            }

        }
#ifdef DEBUG
        printf("verification inexistance reserve joueur %d (%d en réserve)\n",i,g1->joueurs_partie[i].nbpions_reserve);
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

void actions_de_fin_de_tour(S_game * g1)
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
                    printf("Le joueur %s gagne sur le joueur %s\n",joueur_nom[i],joueur_nom[j]);

                    g1->gagnant_partie = i;

                    /*
                    g1->joueurs_partie[j].en_jeu = false;
                    g1->joueurs_partie[j].nbpions = 0;
                    g1->joueurs_partie[j].nbpions_reserve = 0;
                    g1->joueurs_partie[j].power = 0;

                    bool seul = true;
                    for(int k = 0 ; k < NBJOUEURS ; k++)
                    {
                        if(j != k && g1->joueurs_partie[j].en_jeu)
                        {
                            seul = false;
                        }
                    }
                    if(seul){
                        g1->gagnant_partie = i;
                    }
                    */

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

void faire_payer_piece(S_game * g1, int num_joueur)
{

    int min_power = 9999;
    int min_indice = -1;
    bool en_reserve = false;
    for(int j=0; j<g1->joueurs_partie[num_joueur].nbpions; j++)
    {
        if(g1->joueurs_partie[num_joueur].tabpion[j].puissance < min_power)
        {
            min_power = g1->joueurs_partie[num_joueur].tabpion[j].puissance;
            min_indice = j;
        }
    }
    if(min_indice == -1)
    {
        en_reserve = true;
        for(int j=0; j<g1->joueurs_partie[num_joueur].nbpions_reserve; j++)
        {
            if(g1->joueurs_partie[num_joueur].tabpion_reserve[j].puissance < min_power)
            {
                min_power = g1->joueurs_partie[num_joueur].tabpion_reserve[j].puissance;
                min_indice = j;
            }
        }
    }

    if(min_indice == -1)
    {
        printf("Le joueur %s n'a plus de pieces pour payer ! La honte !\n", joueur_nom[num_joueur]);
        return;
    }

    S_pions * tab = en_reserve?g1->joueurs_partie[num_joueur].tabpion_reserve:g1->joueurs_partie[num_joueur].tabpion;

    enum_type_pion type = tab[min_indice].type_pion;

    printf("Le joueur %s a perdu une piece %s pour payer son ammende!\n", joueur_nom[num_joueur], nom_type_pions[type]);

    if(pion_type_deamelioration[type] == type_piece_inexistante)  // si ca ne se dés-améliore pas
    {
        tab[min_indice].type_pion = type_piece_inexistante;
    }
    else
    {

    }
}

S_game jouer_game(S_game g1)
{
    for(int i = 0 ; i < NBJOUEURS ; i++) g1.joueurs_partie[i].en_jeu = true;

    while(g1.gagnant_partie == -1)                     //boucle du jeu
    {
        // pour le tour de chaque joueur
        int result;
        S_feuille_ordres feuille_ordre[NBJOUEURS];
        for (int i=0; i<NBJOUEURS; i++)
        {
            if(!g1.joueurs_partie[i].en_jeu) continue;


            int action_restante = ACTIONPARTOUR;
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
                case saisie_zoom:
                    zoom(g1.joueurs_partie,i);//joueur_partie sans [] car on veut les pions de tous les joueurs
                    break;
                case saisie_deplacer:
                    ordre = deplacerPion(i);
                    feuille_ordre[i].ordre[ACTIONPARTOUR-action_restante] = ordre;
                    feuille_ordre[i].type[ACTIONPARTOUR-action_restante] = type_deplacement;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = ACTIONPARTOUR-action_restante;
                    break;
                case saisie_achat:
                    ordre = achat(i);
                    feuille_ordre[i].ordre[ACTIONPARTOUR-action_restante] = ordre;
                    feuille_ordre[i].type[ACTIONPARTOUR-action_restante] = type_achat;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = ACTIONPARTOUR-action_restante;
                    break;
                case saisie_sortie:
                    ordre = sortie(i);
                    feuille_ordre[i].ordre[ACTIONPARTOUR-action_restante] = ordre;
                    feuille_ordre[i].type[ACTIONPARTOUR-action_restante] = type_sortie;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = ACTIONPARTOUR-action_restante;
                    break;
                case saisie_echange:
                    ordre = echange(i);
                    feuille_ordre[i].ordre[ACTIONPARTOUR-action_restante] = ordre;
                    feuille_ordre[i].type[ACTIONPARTOUR-action_restante] = type_echange;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = ACTIONPARTOUR-action_restante;
                    break;
                case saisie_lancement:
                    ordre = lancer_missile(i);
                    feuille_ordre[i].ordre[ACTIONPARTOUR-action_restante] = ordre;
                    feuille_ordre[i].type[ACTIONPARTOUR-action_restante] = type_lancement;
                    action_restante--;
                    feuille_ordre[i].nb_ordre = ACTIONPARTOUR-action_restante;
                    break;

                case saisie_fintour:
                    printf("Votre tour est fini\n");
                    break;
                default:
                    printf("Erreur de saisie inconnue\n");
                }

            }
            while(result!=saisie_fintour);

            // on reset le nbr d'action
            //g1.joueurs_partie.nbactionTour = 5;
        }

#define LIGNE_POUR_VIDER_ECRAN 80
#define LIGNE_POUR_ESPACE 5

        for(int i = 0 ; i < LIGNE_POUR_VIDER_ECRAN ; i++)
        {
            printf("\n");
        }
        printf("-------------------------------------------------\n");
        printf("--------------------FIN DU TOUR------------------\n");
        printf("-------------------------------------------------\n");
        for(int i = 0 ; i < LIGNE_POUR_ESPACE ; i++)
        {
            printf("\n");
        }

        // on execute les coups de chaque joueur
        executer_ordre(&g1, feuille_ordre);

        //resolution
        resolution_des_combats(&g1);

        //nettoyage des pieces de type inexistantes des tableaux
        supprimer_pieces_inexistantes(&g1);

        //exectuer les actions de tout les tours
        actions_de_fin_de_tour(&g1); //power

        // on verifie si c'est la fin de la partie
        verifier_victoire(&g1);

        for(int i = 0 ; i < LIGNE_POUR_ESPACE ; i++)
        {
            printf("\n");
        }
        system("PAUSE");

        for(int i = 0 ; i < LIGNE_POUR_VIDER_ECRAN ; i++)
        {
            printf("\n");
        }
        printf("-------------------------------------------------\n");
        printf("--------------------TOUR SUIVANT-----------------\n");
        printf("-------------------------------------------------\n");
        for(int i = 0 ; i < LIGNE_POUR_ESPACE ; i++)
        {
            printf("\n");
        }

    }

    affiche_plateau2(g1.plateau_partie,g1.joueurs_partie);
    return g1;
}
