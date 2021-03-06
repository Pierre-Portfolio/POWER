#include "affichage.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <windows.h>

#include "definition.h"
#include "initialisation.h"
#include "noms_pions.h"

static const char * affichage_3lettre_terrain[taille_enum_terrains] = {"ILE", //ile
                                                                       "EAU", //eau
                                                                       "HG ", //HG
                                                                      };

void color (int couleurDuTexte, int couleurDuFond)   //programme couleurs present sur OS
{
    HANDLE H = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(H, couleurDuFond*16+couleurDuTexte);
}
// 0.Noir
// 1.Bleu fonc?
// 2.Vert fonc?
// 3.Turquoise
// 4.Rouge fonc?
// 5.Violet
// 6.Vert caca d'oie
// 7.Gris clair
// 8.Gris fonc?
// 9.Bleu fluo
// 10.Vert fluo
// 11.Turquoise
// 12.Rouge fluo
// 13.Violet 2
// 14.Jaune
// 15.Blanc*/



void affiche_barre_status(S_joueur * joueur_partie)
{

    printf("\n");
    printf("\t\t\t\t\t\t   Unites presentes dans le plateau/reserve :");
    printf("\n\n\t");
    for(int i=0; i<NBJOUEURS; i++)
    {

        print_color(i);

        printf("\t%2d/%2d %4d Power\t",joueur_partie[i].nbpions,joueur_partie[i].nbpions_reserve,joueur_partie[i].power);
        print_color(-1);

    }
    printf("%c\n\n",255);
}

void affiche_plateau2(S_plateau p1, S_joueur* joueurs_partie)
{

    printf("  ");
    for(int x=1; x<=NBCASES; x++)
    {

        print_case_num(x);
    }
    printf("\n");
    for(int y=1; y<=NBCASES; y++)
    {
        printf("  ");
        for(int x=1; x<=NBCASES; x++)
        {
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_dessus();
            print_color(-1);
        }
        printf("%c\n",255);
        printf("  ");
        for(int x=1; x<=NBCASES; x++)
        {
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_power1(joueurs_partie,x,y,p1.cases[y-1][x-1].joueur);
            print_color(-1);
        }
        printf("%c\n",255);
        printf("%d ",y);
        for(int x=1; x<=NBCASES; x++)
        {
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_terrain(p1.cases[y-1][x-1]);
            print_color(-1);
        }
        printf("%c\n",255);
        printf("  ");
        for(int x=1; x<=NBCASES; x++)
        {
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_power2(joueurs_partie,x,y,p1.cases[y-1][x-1].joueur);
            print_color(-1);
        }
        printf("%c\n",255);
        printf("  ");
        for(int x=1; x<=NBCASES; x++)
        {
            print_color(p1.cases[y-1][x-1].joueur);
            print_case_dessous();
            print_color(-1);
        }
        printf("%c\n",255);
    }

    affiche_barre_status(joueurs_partie);
}

void print_case_num(int num_case)
{
    printf("       %d        ",num_case);
}

void print_case_dessus ()
{
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c ",201,205,205,205,205,205,205,205,205,205,205,205,205,187);
}

void print_case_power1(S_joueur* joueurs_partie, int x, int y, int copie_color_case)
{
    printf(" %c",186); //debut

    if(somme_powers_a(x,y,joueurs_partie,0) > 0)
    {
        print_color(0);
        printf("%04d",somme_powers_a(x,y,joueurs_partie,0));
        print_color(copie_color_case);
    }
    else printf("    ");

    printf("    "); //milieu

    if(somme_powers_a(x,y,joueurs_partie,1) > 0)
    {
        print_color(1);
        printf("%04d",somme_powers_a(x,y,joueurs_partie,1));
        print_color(copie_color_case);
    }
    else printf("    ");

    printf("%c ",186); //fin
}

void print_case_power2(S_joueur* joueurs_partie, int x, int y, int copie_color_case)
{
    printf(" %c",186);
    if(somme_powers_a(x,y,joueurs_partie,3) > 0)
    {
        print_color(3);
        printf("%04d",somme_powers_a(x,y,joueurs_partie,3));
        print_color(copie_color_case);
    }
    else printf("    ");
    printf("    ");
    if(somme_powers_a(x,y,joueurs_partie,2) > 0)
    {
        print_color(2);
        printf("%04d",somme_powers_a(x,y,joueurs_partie,2));
        print_color(copie_color_case);
    }
    else printf("    ");
    printf("%c ",186);
}

void print_case_terrain (S_cases c)
{
    printf(" %c    %3s     %c ",186,affichage_3lettre_terrain[c.terrain],186);
}

void print_color(int num_joueur)
{
    if(num_joueur==-1)
    {
        color(15,0);
        return;
    }
    color(15,joueur_vers_couleur[num_joueur]);
}

void print_case_dessous ()
{
    printf(" %c%c%c%c%c%c%c%c%c%c%c%c%c%c ",200,205,205,205,205,205,205,205,205,205,205,205,205,188);
}

void affiche_unites(int x,int y,S_joueur* joueurs_partie)
{
    printf("Voici les unites presentes sur la case %d.%d\n",x,y);

    for(int i=0; i<NBJOUEURS; i++)
    {
        int decompte_unites[taille_enum_pion];
        for(int z = 0 ; z < taille_enum_pion ; z++) decompte_unites[z] = 0;
        for(int j=0; j<joueurs_partie[i].nbpions; j++)
        {
            if(joueurs_partie[i].tabpion[j].positions.position_x==x && joueurs_partie[i].tabpion[j].positions.position_y==y)
            {
                decompte_unites[joueurs_partie[i].tabpion[j].type_pion]++; //pour chaque pion de chaque joueur, on incremente si le pion est present sur la case
            }
        }
        print_color(i);
        affiche_decompte_unite(decompte_unites,false);
        print_color(-1);
    }
}

int affiche_mes_unites_numerotees(int x,int y,S_joueur le_joueur)   //S_joueur* <==> S_joueur[]
{
    printf("Voici les unites presentes sur la case %d.%d\n",x,y);

    int decompte_unites[taille_enum_pion]; //initialisation du tableau ? 0
    int decompte=0;
    for(int z = 0 ; z < taille_enum_pion ; z++) decompte_unites[z] = 0;
    for(int j=0; j<le_joueur.nbpions; j++)
    {
        if(le_joueur.tabpion[j].positions.position_x==x && le_joueur.tabpion[j].positions.position_y==y)
        {
            decompte_unites[le_joueur.tabpion[j].type_pion]++; //pour chaque pion de chaque joueur, on incremente si le pion est present sur la case
        }
    }
    for(int j=0; j<taille_enum_pion; j++)
        if(decompte_unites[j]>0)
            decompte++;
    if(decompte!=0)
    {

        affiche_decompte_unite(decompte_unites,true);
    }
    else
    {
        printf("Vous n'avez aucune unite dans la case %d.%d\n",x,y);
    }
    return decompte;
}

int affiche_mes_unites_reserve(S_joueur le_joueur,bool numerote)   //S_joueur* <==> S_joueur[]
{

    printf("Voici vos unites en reserve\n");

    int decompte = 0;
    int decompte_unites[taille_enum_pion];
    for(int z = 0 ; z < taille_enum_pion ; z++) decompte_unites[z] = 0;
    for(int j=0; j<le_joueur.nbpions_reserve; j++)
    {
        decompte_unites[le_joueur.tabpion_reserve[j].type_pion]++; //pour chaque pion de chaque joueur, on incremente si le pion est present sur la case
    }

    for(int j=0; j<taille_enum_pion; j++)
        if(decompte_unites[j]>0)
            decompte++;

    if(decompte!=0)
    {

        affiche_decompte_unite(decompte_unites,numerote);
    }
    else
    {
        printf("Vous n'avez aucune unite dans votre reserve.\n");
    }
    return decompte;
}

void affiche_decompte_unite(int decompte_unite[taille_enum_pion],bool numerote)
{
    for(int i=0; i<taille_enum_pion; i++)
    {
        if(decompte_unite[i]==0)continue; //on n'affiche rien si le decompte egale a 0; continue ignore la suite jusqu'a la fin de la boucle

        printf("%dx%s",decompte_unite[i],nom_type_pions[i]);
        if(numerote)
        {
            printf("   -%d-",i); //afficher la numerotation d'un pion ou pas
        }
        printf("\n");
    }
}

