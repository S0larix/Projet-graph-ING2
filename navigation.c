#include "header.h"

<<<<<<< HEAD
int navigation(int start)
{
    BITMAP *map, *big_map, *big_map2, *map_zoom, *loupe, *multi_x2, *multi_x4;
    int multi=1;
    int x, y, i, j; //au cas ou

    show_mouse(screen);

    map=chargerImage("images/map.bmp");

    big_map=chargerImage("images/big_map.bmp");

    big_map2=chargerImage("images/big_map2.bmp");

    loupe=chargerImage("images/loupe_trou.bmp");

    multi_x2=chargerImage("images/x2.bmp");

    multi_x4=chargerImage("images/x4.bmp");

    map_zoom=map;

    while(!key[KEY_ESC])
    {

        blit(map,page,0,0,0,0, SCREEN_W,SCREEN_H);

        zoom(mouse_x, mouse_y, multi, page, map_zoom);
=======
int navigation(int start, t_ancre* ancre)
{
    BITMAP *map, *big_map, *big_map2, *map_zoom, *loupe, *multi_x2, *multi_x4, *depart, *possible, *back, *tool;
    int i, multi=2, menuu;
    int c=0;

    map=chargerImage("images/map_bis.bmp");
    big_map=chargerImage("images/big_map_bis.bmp");
    big_map2=chargerImage("images/big_map2_bis.bmp");
    loupe=chargerImage("images/loupe_bis.bmp");
    multi_x2=chargerImage("images/x2.bmp");
    multi_x4=chargerImage("images/x4.bmp");
    depart=chargerImage("images/depart.bmp");
    possible=chargerImage("images/possible.bmp");
    tool=chargerImage("images/tool.bmp");
    back=chargerImage("images/home.bmp");

    map_zoom=big_map;

    while(!key[KEY_ESC])
    {

        blit(map,page,0,0,0,0, SCREEN_W,SCREEN_H);

        affiche_points(ancre);

        if(mouse_b && mouse_x<800 && mouse_x>775 && mouse_y>0 && mouse_y<25)
        {
            c=0;
            return 3;
        }


        if(mouse_b && mouse_x<770 && mouse_x>745 && mouse_y>0 && mouse_y<25)
        {
            c=0;
            menuu=menuPause();
        }


        if(menuu==1)
        {
            for(i=0; i<ancre->nb_lieu; i++)
            {
                if(approche(mouse_x, mouse_y, ((ancre->tab_lieu[i].x)/4), ((ancre->tab_lieu[i].y)/4)))
                    affiche_trajets(ancre, ancre->tab_lieu[i], depart, possible);
            }
        }

        if(menuu==2)
        {
            if(!c)
            {
                c=choix_trajet();
            }
            affiche_trajet_seul(ancre, c);
        }

        zoom(mouse_x, mouse_y, multi, map_zoom);
>>>>>>> Projet final

        draw_sprite(page, multi_x2, 200, 10);
        draw_sprite(page, multi_x4, 230, 10);

<<<<<<< HEAD
=======
        draw_sprite(page, back, 775, 0);
        draw_sprite(page, tool, 745, 0);

>>>>>>> Projet final
        if(mouse_b && mouse_x<200+multi_x2->w && mouse_x>200 && mouse_y<10+multi_x2->h && mouse_y>10)
        {
            multi=2;
            map_zoom=big_map;
        }

        if(mouse_b && mouse_x<230+multi_x4->w && mouse_x>230 && mouse_y<10+multi_x4->h && mouse_y>10)
        {
            multi=4;
            map_zoom=big_map2;
        }

        draw_sprite(page, loupe, 0, 0);
        blit(page,screen,0,0,0,0,SCREEN_W,SCREEN_H);
        rest(20);

    }
<<<<<<< HEAD
    return 0;
}

void zoom(int x, int y, int multi, BITMAP *map, BITMAP *big_map)
=======

    destroy_bitmap(map);
    destroy_bitmap(big_map);
    destroy_bitmap(big_map2);
    destroy_bitmap(loupe);
    destroy_bitmap(multi_x2);
    destroy_bitmap(multi_x4);
    destroy_bitmap(depart);
    destroy_bitmap(possible);
    destroy_bitmap(tool);
    destroy_bitmap(back);
    return 0;
}

void zoom(int x, int y, int multi, BITMAP *big_map)
>>>>>>> Projet final
{
    x=multi*x-(100/multi);
    y=multi*y-(75/multi);

    if(x<multi*0)           x=multi*0;
    if(x>=multi*800-200)    x=multi*800-200;

    if(y<multi*0)           y=multi*0;
    if(y>=multi*600-150)    y=multi*600-150;

    blit(big_map, page, x, y, 0, 0, 200, 150);
}
<<<<<<< HEAD
=======

void affiche_points(t_ancre* ancre)
{
    int i;

    for(i=0;i<ancre->nb_lieu;i++)
    {
        circlefill(page, (ancre->tab_lieu[i].x)/4, (ancre->tab_lieu[i].y)/4, 2, makecol(0,0,255));
        textprintf_ex(page, font, ((ancre->tab_lieu[i].x)/4)-5, ((ancre->tab_lieu[i].y)/4)+5, makecol(0,0,0), -1, "%d", ancre->tab_lieu[i].ordre);
    }
}

void affiche_trajets(t_ancre* ancre, t_lieux lieu, BITMAP* depart, BITMAP* possible)
{
    int i, temp, x, y, cpt=0;

    draw_sprite(page, depart, ((lieu.x)/4)-12, ((lieu.y)/4)-22);
    textprintf_ex(page, font, 275, 10, makecol(0,255,0), -1, "Point %d : %s", lieu.ordre, lieu.nom);

    for(i=0;i<=ancre->nb_trajet;i++)
    {
        if(lieu.ordre==ancre->tab_trajet[i].depart)
        {
            temp=ancre->tab_trajet[i].arrivee-1;
            if(lieu.ordre!=ancre->tab_lieu[temp].ordre)
            {
                x=((ancre->tab_lieu[temp].x)/4)-12;
                y=((ancre->tab_lieu[temp].y)/4)-22;
                draw_sprite(page, possible, x, y);
                textprintf_ex(page, font, 275, 20+cpt*10, makecol(255,153,0), -1, "Point %d : %s", ancre->tab_lieu[temp].ordre, ancre->tab_lieu[temp].nom);
                cpt++;
            }
        }
    }
}

int approche(int x_souris, int y_souris, int x_point, int y_point)
{
    if(x_souris+12<=x_point+18 && x_souris+12>=x_point+8 && y_souris+22<=y_point+25 && y_souris+22>=y_point+15)
        return 1;
    return 0;
}

int menuPause()
{
    int choix=0;
    int i, j;
    int c, r, v, b;
    int rbin, vbin, bbin;
    BITMAP *masque_image;
    BITMAP *point, *trajet;

    rest(300);

    point = chargerImage("images/point.bmp");
    trajet = chargerImage("images/trajet.bmp");
    masque_image = create_bitmap(SCREEN_W,SCREEN_H);

    for(i=0; i<SCREEN_W; i++)
        for(j=0; j<SCREEN_H; j++)
        {
            c=getpixel(page, i, j);
            r=getr(c);
            v=getg(c);
            b=getb(c);

            //Binarisation de l'image
            if(r<200) rbin=0;
            else rbin=55;
            if(v<200) vbin=0;
            else vbin=55;
            if(b<200) bbin=0;
            else bbin=55;

            putpixel(masque_image, i, j, makecol(rbin, vbin, bbin));
        }

    while (!choix)
    {
        blit(masque_image, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        draw_sprite(page, point, 100, 265);
        draw_sprite(page, trajet, 450, 265);

        if(mouse_b && mouse_x<350 && mouse_x>100 && mouse_y<340 && mouse_y>265)
            return 1;

        if(mouse_b && mouse_x<700 && mouse_x>450 && mouse_y<340 && mouse_y>265)
            return 2;

        masked_blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    rest(50);
    return 0;
}

int choix_trajet()
{
    int choix=0;
    int i, j, k;
    int c, r, v, b;
    int rbin, vbin, bbin;
    BITMAP *masque_image;
    BITMAP *liste_trajet;

    rest(300);

    liste_trajet = chargerImage("images/liste_trajet.bmp");
    masque_image = create_bitmap(SCREEN_W,SCREEN_H);

    for(i=0; i<SCREEN_W; i++)
        for(j=0; j<SCREEN_H; j++)
        {
            c=getpixel(page, i, j);
            r=getr(c);
            v=getg(c);
            b=getb(c);

            //Binarisation de l'image
            if(r<200) rbin=0;
            else rbin=55;
            if(v<200) vbin=0;
            else vbin=55;
            if(b<200) bbin=0;
            else bbin=55;

            putpixel(masque_image, i, j, makecol(rbin, vbin, bbin));
        }

    while (!choix)
    {
        blit(masque_image, page, 0, 0, 0, 0, SCREEN_W, SCREEN_H);

        draw_sprite(page, liste_trajet, 0, 0);

        k=0;

        for(i=0; i<8; i++)
        {
            for(j=0; j<13; j++)
            {
                k++;
                if(mouse_b && mouse_x<65+j*60 && mouse_x>1+j*60 && mouse_y<65+i*60 && mouse_y>15+i*60)
                    return k;
            }
        }

        /*for(i=0; i<13; i++)
        {
            for(j=0; j<13; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65 && mouse_y>15)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=13; j<26; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+60 && mouse_y>15+60)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=26; j<39; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+2*60 && mouse_y>15+2*60)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=39; j<52; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+3*60 && mouse_y>15+3*60)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=52; j<65; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+4*60 && mouse_y>15+4*60)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=65; j<78; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+5*60 && mouse_y>15+5*60)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=78; j<91; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+6*60 && mouse_y>15+6*60)
                    return j+1;
            }
        }

        for(i=0; i<13; i++)
        {
            for(j=91; j<95; j++)
            {
                if(mouse_b && mouse_x<65+i*60 && mouse_x>1+i*60 && mouse_y<65+7*60 && mouse_y>15+7*60)
                    return j+1;
            }
        }*/

        masked_blit(page, screen, 0, 0, 0, 0, SCREEN_W, SCREEN_H);
    }
    rest(50);
    return 0;
}

void affiche_trajet_seul(t_ancre *ancre, int c)
{
    int n, i;
    n=c-1;

    for(i=0; i<1; i++)
    {
        line(page, ((ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x)/4)-i, ((ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y)/4)-i, ((ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x)/4)-i, ((ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)/4)-i, makecol(0,255,0));
        line(page, ((ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x)/4)+i, ((ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y)/4)+i, ((ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x)/4)+i, ((ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)/4)+i, makecol(0,255,0));
    }

    textprintf_ex(page, font, 275, 10, makecol(0,255,0), -1, "Trajet numero %d", ancre->tab_trajet[n].numero_trajet);
    textprintf_ex(page, font, 275, 20, makecol(0,255,0), -1, "Nom du trajet : %s", ancre->tab_trajet[n].nom);
    textprintf_ex(page, font, 275, 30, makecol(0,255,0), -1, "%d : %s", ancre->tab_lieu[ancre->tab_trajet[n].depart-1].ordre, ancre->tab_lieu[ancre->tab_trajet[n].depart-1].nom);
    textprintf_ex(page, font, 275, 40, makecol(0,255,0), -1, "%d : %s", ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].ordre, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].nom);

    /*

    int i, j;
    int x_min, x_max, y_min, y_max;

    //printf("depart : %d arrivee : %d\n", ancre->tab_trajet[n].depart, ancre->tab_trajet[n].arrivee);

    if(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x<ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x && ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y<ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)
    {
        //printf("1 : %d %d / %d %d ", ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x, ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y);

        x_min=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x)/4;
        x_max=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x)/4;

        y_min=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y)/4;
        y_max=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)/4;

        for(i=y_min; i<y_max; i++)
        {
            for(j=x_min; j<x_max; j++)
            {
                circlefill(page, j, i, 2, makecol(0,255,0));
            }
        }
    }

    if(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x>ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x && ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y>ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)
    {
        //printf("2 : %d %d / %d %d ", ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x, ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y);

        x_max=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x)/4;
        x_min=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x)/4;

        y_max=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y)/4;
        y_min=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)/4;

        for(i=y_min; i<y_max; i++)
        {
            for(j=x_min; j<x_max; j++)
            {
                circlefill(page, j, i, 2, makecol(0,255,0));
            }
        }
    }

    if(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x>ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x && ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y<ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)
    {
        //printf("3: %d %d / %d %d ", ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x, ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y);

        x_max=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x)/4;
        x_min=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x)/4;

        y_min=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y)/4;
        y_max=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)/4;

        for(i=y_min; i<y_max; i++)
        {
            for(j=x_max; j>x_min; j--)
            {
                circlefill(page, j, i, 2, makecol(0,255,0));
            }
        }
    }

    if(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x<ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x && ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y>ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)
    {
        //printf("4 : %d %d / %d %d ", ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x, ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x, ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y);

        x_min=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].x)/4;
        x_max=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].x)/4;

        y_max=(ancre->tab_lieu[ancre->tab_trajet[n].depart-1].y)/4;
        y_min=(ancre->tab_lieu[ancre->tab_trajet[n].arrivee-1].y)/4;

        for(i=y_max; i>y_min; i--)
        {
            for(j=x_min; j<x_max; j++)
            {
                circlefill(page, j, i, 2, makecol(0,255,0));
            }
        }
    }

    */
}

>>>>>>> Projet final
