#ifndef CASES_H_INCLUDED
#define CASES_H_INCLUDED

typedef enum {
  rouge = 1,
  vert,
  jaune,
  bleu,
  neutre
} couleurs;

typedef enum {
  ile = 1,
  eau,
  HG
} terrains;

struct cases{
    terrains terrain; // 1 = ile, 2 = eau, 3 = HG
    couleurs couleur; //1 = rouge, 2=vert, 3=jaune; 4=bleu
};
typedef struct cases S_cases;

#endif // CASES_H_INCLUDED
