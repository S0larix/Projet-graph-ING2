#include "header.h"

int main()
{
    ///Variables
    t_ancre* ancre;

    int start=1;
    srand(time(NULL));
    lancerToutAllegro(800, 600);

<<<<<<< HEAD
    ///allocation graph
=======
    ///Allocation graphe
>>>>>>> Projet final
    ancre=chargement_lieux_trajets();

    ///Test affichage points
    //afficher_lieux_trajets(ancre);

    ///Pour le son
    /*if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0)
    {
        allegro_message("Error initializing sound system");
        return 0;
    }*/

<<<<<<< HEAD
    while (!key[KEY_ESC]&& start!=0)
=======
    fondu();

    ///Demarrage menu
    while (!key[KEY_ESC] && start!=0)
>>>>>>> Projet final
    {
        clear_bitmap(page);
        start = menu();

<<<<<<< HEAD
        /*if(start==1)
            start = itineraire(start);*/

        if(start==2)
            start = navigation(start);
=======
        if(start==1)
        {
            start = itineraire(start, ancre);
        }

        if(start==2)
        {
            start = navigation(start, ancre);
        }
>>>>>>> Projet final

        masked_blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
        rest(20);
    }
<<<<<<< HEAD
=======
    destroy_bitmap(page);
    free(ancre->tab_trajet);
    free(ancre->tab_lieu);
    free(ancre);

>>>>>>> Projet final
    return 0;
}
END_OF_MAIN();
