#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED


typedef enum {
  ile = 0,
  eau,
  HG,
  taille_enum_terrains,
} terrains;

static const char * affichage_3lettre_terrain[taille_enum_terrains] = {"ILE", //ile
                                                                       "EAU", //eau
                                                                       "HG ", //HG
                                                                       };

struct cases{
    terrains terrain; // 1 = ile, 2 = eau, 3 = HG
    int joueur; //1 = rouge, 2=vert, 3=jaune; 4=bleu
};
typedef struct cases S_cases;

#endif // CASES_H_INCLUDED
