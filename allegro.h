#ifndef ALLEGRO_H_INCLUDED
#define ALLEGRO_H_INCLUDED

extern BITMAP *page;
extern BITMAP *pageCachee;

BITMAP* chargerImage(char *nomFichierImage);

SAMPLE* chargerSon(char *nomFichierSon);

void lancerToutAllegro(int largeur, int hauteur);

float valeurAbsolue(float i);

#endif // ALLEGRO_H_INCLUDED
