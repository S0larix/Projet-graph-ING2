#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

typedef struct lieux
{
    int ordre;
    int altitude;
    char nom[20];
}t_lieux;

typedef struct trajet
{
    int numero_trajet;
    char nom[20];
    char type[5];
    int depart;
    int arrivee;
}t_trajet;

typedef struct ancre
{
    int nb_lieu;
    int nb_trajet;
    t_lieux* tab_lieu;
    t_trajet* tab_trajet;
}t_ancre;

#endif // STRUCTURES_H_INCLUDED
