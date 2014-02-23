#include "header.h"

BITMAP *page;
BITMAP *pageCachee;

// Regroupe les initialisations d'allegro, mode graphique, clavier, souris
void lancerToutAllegro(int largeur, int hauteur)
{
    allegro_init();
    install_keyboard();
    install_mouse();

    /// OUVERTURE MODE GRAPHIQUE (ouverture fenetre allegro)
    set_color_depth(desktop_color_depth());
    if (set_gfx_mode(GFX_AUTODETECT_WINDOWED,largeur,hauteur,0,0)!=0)
    {
        allegro_message("probleme mode graphique : %s", allegro_error);
        allegro_exit();
        exit(EXIT_FAILURE);
    }

    //show_mouse(screen); // Affiche pointeur de souris en mode allegro

    // CREATION DU BUFFER D'AFFICHAGE, la taille de l'ecran
    page=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(page);
    pageCachee=create_bitmap(SCREEN_W,SCREEN_H);
    clear_bitmap(pageCachee);
}


BITMAP *chargerImage(char *nomFichierImage)
{
    BITMAP *bmp;
    bmp=load_bitmap(nomFichierImage,NULL);
    if (bmp==NULL)
    {
        allegro_message("pas pu trouver/charger %s",nomFichierImage);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    printf("Image chargee : %s\n", nomFichierImage);
    return bmp;
}

SAMPLE *chargerSon(char *nomFichierSon)
{
    SAMPLE *son;
    son=load_sample(nomFichierSon);
    if (!son)
    {
        allegro_message("pas pu trouver/charger %s",nomFichierSon);
        allegro_exit();
        exit(EXIT_FAILURE);
    }
    printf("Son chargee : %s\n", nomFichierSon);
    return son;
}

float valeurAbsolue(float i)
{
    if(i<0)
    {
        i=-i;
    }
    return i;
}
