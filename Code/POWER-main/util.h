#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#define round(a) ((int)((a)+0.5f))


void rajouter(void** tableau,int taille_element, int* taille_tableau,void* element);
void supprimer(void* tableau, int taille_element, int *taille_tableau,int indice);


#endif // UTIL_H_INCLUDED
