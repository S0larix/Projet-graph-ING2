#include "header.h"

int main()
{
    ///variables
    t_ancre* ancre;

    int start=1;
    srand(time(NULL));
    lancerToutAllegro(800, 600);

    ///allocation graph
    ancre=chargement_lieux_trajets();

    ///test affichage points
    //afficher_lieux_trajets(ancre);

    ///Pour le son
    /*if (install_sound(DIGI_AUTODETECT, MIDI_NONE, "") != 0)
    {
        allegro_message("Error initializing sound system");
        return 0;
    }*/

    while (!key[KEY_ESC]&& start!=0)
    {
        clear_bitmap(page);
        start = menu();

        /*if(start==1)
            start = itineraire(start);*/

        if(start==2)
            start = navigation(start);

        masked_blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H) ;
        rest(20);
    }
    return 0;
}
END_OF_MAIN();
