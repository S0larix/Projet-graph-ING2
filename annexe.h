#ifndef ANNEXE_H_INCLUDED
#define ANNEXE_H_INCLUDED

typedef struct lieux
{
    int ordre;
    int altitude;
    int x, y;
    char nom[20];
}t_lieux;

typedef struct trajet
{
    int numero_trajet;
    char nom[20];
    char type[5];
    int depart;
    int arrivee;
    int temps;
}t_trajet;

typedef struct ancre
{
    int nb_lieu;
    int nb_trajet;
    t_lieux* tab_lieu;
    t_trajet* tab_trajet;
}t_ancre;

/*typedef struct point
{
    int x, y;
    int col;
    int nb_trajet;
    struct point** trajet;
}t_point;

t_point **alloc_trajet(int n);

t_point *alloc_point();*/

#endif // ANNEXE_H_INCLUDED
