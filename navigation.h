#ifndef NAVIGATION_H_INCLUDED
#define NAVIGATION_H_INCLUDED

<<<<<<< HEAD

=======
void zoom(int x, int y, int multi, BITMAP *big_map);

int navigation(int start, t_ancre* ancre);

void affiche_points(t_ancre* ancre);

void affiche_trajets(t_ancre* ancre, t_lieux lieu, BITMAP* depart, BITMAP* possible);

int approche(int x_souris, int y_souris, int x_point, int y_point);

int menuPause();

int choix_trajet();

void affiche_trajet_seul(t_ancre *ancre, int n);
>>>>>>> Projet final

#endif // NAVIGATION_H_INCLUDED
