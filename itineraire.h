#ifndef ITINERAIRE_H_INCLUDED
#define ITINERAIRE_H_INCLUDED

<<<<<<< HEAD

=======
int itineraire(int start, t_ancre* ancre);

void choix_itineraire(t_ancre* ancre, BITMAP* depart, BITMAP* arrivee,BITMAP* maps);

int menuPause2();

void choix_point(t_ancre* ancre, BITMAP* depart);

void afficher_tout_itineraire(t_ancre *ancre, int *pred, float *l);

void calcul_itineraire(t_ancre *ancre, float **tab, float *l, int *pred);

t_trajet cherche_court_trajet(t_ancre *ancre, int depart, int arrivee);

void afficher_itineraire(t_ancre *ancre, int* pred, float* l,BITMAP* escale,BITMAP* arrivee,BITMAP* depart);

void afficher_tout_itineraire_ecran(t_ancre *ancre, int *pred, float *l);
>>>>>>> Projet final

#endif // ITINERAIRE_H_INCLUDED
