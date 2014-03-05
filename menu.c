#include "header.h"

BITMAP* intermediaire(float f, BITMAP *image1, BITMAP* image2)
{
    BITMAP *image_inter;
    image_inter=create_bitmap(800,600);
    int x,y,r1,r2,ri,v1,v2,vi,b1,b2,bi,c1,c2,ci;

    for(y=0; y<image_inter->h; y++)
    {
        for(x=0; x<image_inter->w; x++)
        {
            c1=getpixel(image1,x,y);
            r1=getr(c1);
            v1=getg(c1);
            b1=getb(c1);

            c2=getpixel(image2,x,y);
            r2=getr(c2);
            v2=getg(c2);
            b2=getb(c2);

            ri=(1.0-f)*r1+f*r2;
            vi=(1.0-f)*v1+f*v2;
            bi=(1.0-f)*b1+f*b2;

            ci=makecol(ri,vi,bi);
            putpixel(image_inter,x,y,ci);
        }
    }

    return image_inter;
}

void initialiserSons()
{
    //A implementer si on a le temps
}

<<<<<<< HEAD
int menu()
{

    BITMAP *image1;
    BITMAP *image2;
    BITMAP *itineraire, *parcours, *quit;
    BITMAP *finale;
    float inter;
=======
void fondu()
{
    BITMAP *image1;
    BITMAP *image2;

    BITMAP *finale;
    float inter;

    image1=chargerImage("images/ECE.bmp");

    image2=chargerImage("images/menu.bmp");

    blit(image1,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    blit(image1,page,0,0,0,0,SCREEN_W,SCREEN_H);

    rest(1500);

    for(inter=0; inter<=1.00; inter+=0.03)
    {
        finale=intermediaire(inter,image1,image2);
        blit(finale,page,0,0,0,0,finale->w,finale->h);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }
}

int menu()
{

    BITMAP *image2;
    BITMAP *itineraire, *parcours, *quit;
>>>>>>> Projet final
    int itineraire_x, itineraire_y, parcours_x, parcours_y, quit_x, quit_y;

    static int precClic=0, nouvClic=0;

    itineraire_x=350;
    itineraire_y=220;
    parcours_x=350;
    parcours_y=320;
    quit_x=350;
    quit_y=420;

<<<<<<< HEAD
    image1=chargerImage("images/ECE.bmp");

=======
>>>>>>> Projet final
    image2=chargerImage("images/menu.bmp");

    itineraire=chargerImage("images/itineraire.bmp");

    parcours=chargerImage("images/navigation.bmp");

    quit=chargerImage("images/quitter.bmp");

    //initialiserSons();

    show_mouse(screen);

<<<<<<< HEAD
    blit(image1,page,0,0,0,0,SCREEN_W,SCREEN_H);
    for(inter=0; inter<=1.00; inter+=0.03)
    {
        finale=intermediaire(inter,image1,image2);
        blit(finale,page,0,0,0,0,finale->w,finale->h);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
    }

=======
>>>>>>> Projet final
    while(!key[KEY_ESC])
    {

        blit(image2,page,0,0,0,0, SCREEN_W,SCREEN_H);
        draw_sprite(page, itineraire, itineraire_x, itineraire_y);
        draw_sprite(page, parcours, parcours_x, parcours_y);
        draw_sprite(page, quit, quit_x, quit_y);

        if(mouse_b && mouse_x<itineraire_x+itineraire->w && mouse_x>itineraire_x && mouse_y<itineraire_y+itineraire->h && mouse_y>itineraire_y)
        {
            precClic=nouvClic;
            nouvClic=mouse_b;
            //if (!precClic && nouvClic) play_sample(touche, 400, 128, 700, 0);
            return 1;
        }

        if(mouse_b && mouse_x<parcours_x+parcours->w && mouse_x>parcours_x && mouse_y<parcours_y+parcours->h && mouse_y>parcours_y)
        {
            precClic=nouvClic;
            nouvClic=mouse_b;
            //if (!precClic && nouvClic) play_sample(touche, 400, 128, 700, 0);
            return 2;
        }

        if(mouse_b && mouse_x<quit_x+quit->w && mouse_x>quit_x && mouse_y<quit_y+quit->h && mouse_y>quit_y)
        {
            return 0;
        }
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(20);

    }

    return 0;
}
