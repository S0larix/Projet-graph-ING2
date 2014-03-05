#include "header.h"

<<<<<<< HEAD
=======
int booleen1=0;
int booleen2=0;
int booleen3=0;
t_lieux pt_depart;
t_lieux pt_arrivee;

t_lieux pt_depart_bis;
t_lieux pt_arrivee_bis;

int itineraire(int start, t_ancre* ancre)
{
    BITMAP *map, *big_map, *big_map2, *map_zoom, *loupe, *multi_x2, *multi_x4, *depart, *arrivee, *escale, *tool, *back;
    int menuu, multi=2;
    float **tab;

    int *pred;
    float *l;

    map=chargerImage("images/map_bis.bmp");
    big_map=chargerImage("images/big_map_bis.bmp");
    big_map2=chargerImage("images/big_map2_bis.bmp");
    loupe=chargerImage("images/loupe_bis.bmp");
    multi_x2=chargerImage("images/x2.bmp");
    multi_x4=chargerImage("images/x4.bmp");
    depart=chargerImage("images/depart.bmp");
    arrivee=chargerImage("images/arrivee.bmp");
    escale=chargerImage("images/escale.bmp");
    tool=chargerImage("images/tool.bmp");
    back=chargerImage("images/home.bmp");

    map_zoom=big_map;

    while(!key[KEY_ESC])
    {

        blit(map,page,0,0,0,0, SCREEN_W,SCREEN_H);

        affiche_points(ancre);

        if(mouse_b && mouse_x<800 && mouse_x>775 && mouse_y>0 && mouse_y<25)
        {
            return 3;
        }


        if(mouse_b && mouse_x<770 && mouse_x>745 && mouse_y>0 && mouse_y<25)
        {
            menuu=menuPause2();
        }


        if(menuu==1)
        {
            /*pt_depart.altitude=0;
            pt_depart.nom[0]='\0';
            pt_depart.ordre=0;
            pt_depart.x=0;
            pt_depart.y=0;*/

            pred=(int*)calloc(ancre->nb_lieu,sizeof(int));
            l=(float*)calloc(ancre->nb_lieu,sizeof(float));
            tab=creation_mat_adj(ancre);

            choix_itineraire(ancre, depart, arrivee,map);
            //if(pt_depart.ordre!=6 && pt_depart.ordre!=28 && pt_depart.ordre!=29)
                calcul_itineraire(ancre,tab,l,pred);
            if(booleen3==1)
            {
            afficher_itineraire(ancre, pred, l,escale,arrivee,depart);
            rest(5000);
            }

            free(tab);
            free(l);
            free(pred);
        }

        if(menuu==2)
        {
            pred=(int*)calloc(ancre->nb_lieu,sizeof(int));
            l=(float*)calloc(ancre->nb_lieu,sizeof(float));
            tab=creation_mat_adj(ancre);

            choix_point(ancre, depart);
            if(booleen2==1)
            {
                dijkstra(tab, ancre->nb_lieu, pt_depart_bis.ordre-1, l, pred);
                afficher_tout_itineraire(ancre, pred, l);
                booleen2=0;
            }
            afficher_tout_itineraire_ecran(ancre, pred, l);

            free(tab);
            free(l);
            free(pred);
        }

        zoom(mouse_x, mouse_y, multi, map_zoom);

        draw_sprite(page, multi_x2, 200, 10);
        draw_sprite(page, multi_x4, 230, 10);

        draw_sprite(page, back, 775, 0);
        draw_sprite(page, tool, 745, 0);

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

    destroy_bitmap(map);
    destroy_bitmap(big_map);
    destroy_bitmap(big_map2);
    destroy_bitmap(loupe);
    destroy_bitmap(multi_x2);
    destroy_bitmap(multi_x4);
    destroy_bitmap(depart);
    destroy_bitmap(arrivee);
    destroy_bitmap(escale);
    destroy_bitmap(tool);
    destroy_bitmap(back);
    return 0;
}

void choix_itineraire(t_ancre* ancre, BITMAP* depart, BITMAP* arrivee,BITMAP* maps)
{
    int i, j;

    for(j=0; j<ancre->nb_lieu; j++)
    {
        if(approche(mouse_x, mouse_y, ((ancre->tab_lieu[j].x)/4), ((ancre->tab_lieu[j].y)/4)) && mouse_b&2 && !(booleen2) /*&& pt_depart.ordre!=ancre->tab_lieu[j].ordre*/)
        {
            draw_sprite(page, arrivee, ((ancre->tab_lieu[j].x)/4)-12, ((ancre->tab_lieu[j].y)/4)-22);
            blit(maps,screen,((pt_arrivee.x)/4)-12,((pt_arrivee.y)/4)-22,((pt_arrivee.x)/4)-12,((pt_arrivee.y)/4)-22,25,25);
            pt_arrivee=ancre->tab_lieu[j];
            booleen2=1;
        }
    }

    for(i=0; i<ancre->nb_lieu; i++)
    {
        if(approche(mouse_x, mouse_y, ((ancre->tab_lieu[i].x)/4), ((ancre->tab_lieu[i].y)/4)) && mouse_b&1 && !(booleen1))
        {
            if(ancre->tab_lieu[i].ordre==6 || ancre->tab_lieu[i].ordre==28 || ancre->tab_lieu[i].ordre==29)
            {
                textprintf_ex(page, font, 275, 10, makecol(0,255,0), -1, "Itineraire non disponible");
            }
            else
            {
                draw_sprite(page, depart, ((ancre->tab_lieu[i].x)/4)-12, ((ancre->tab_lieu[i].y)/4)-22);
                blit(maps,screen,((pt_depart.x)/4)-12,((pt_depart.y)/4)-22,((pt_depart.x)/4)-12,((pt_depart.y)/4)-22,25,25);
                pt_depart=ancre->tab_lieu[i];
                booleen1=1;
            }

        }
    }

    draw_sprite(page, depart, ((pt_depart.x)/4)-12, ((pt_depart.y)/4)-22);
    draw_sprite(page, arrivee, ((pt_arrivee.x)/4)-12, ((pt_arrivee.y)/4)-22);
}

int menuPause2()
{
    int choix=0;
    int i, j;
    int c, r, v, b;
    int rbin, vbin, bbin;
    BITMAP *masque_image;
    BITMAP *point, *trajet;

    rest(300);

    ///Il faut creer des images pour ces deux parametres
    point = chargerImage("images/seul.bmp");
    trajet = chargerImage("images/tous.bmp");
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

void choix_point(t_ancre* ancre, BITMAP* depart)
{
    int i;

    for(i=0; i<ancre->nb_lieu; i++)
    {
        if(approche(mouse_x, mouse_y, ((ancre->tab_lieu[i].x)/4), ((ancre->tab_lieu[i].y)/4)) && mouse_b && !(booleen2))
        {
            draw_sprite(page, depart, ((ancre->tab_lieu[i].x)/4)-12, ((ancre->tab_lieu[i].y)/4)-22);
            pt_depart_bis=ancre->tab_lieu[i];
            booleen2=1;
        }
    }
    draw_sprite(page, depart, ((pt_depart_bis.x)/4)-12, ((pt_depart_bis.y)/4)-22);
}

void afficher_tout_itineraire(t_ancre *ancre, int *pred, float *l)
{
    int pt_fin, pt_pred, i;

    //pred[pt_depart.ordre] = -1;
    //printf("%d", pt_depart.ordre);

    for(i=0;i<ancre->nb_lieu;i++)
    {
        //printf("Temps de %d a %d : %.2f sec\n", pt_depart_bis.ordre, i+1, l[i]);
        pt_fin=i+1;
        pt_pred=pred[i];
        if (pred[i]==-1)
        {
            //
        }
        else
        {
            //printf("Itineraire le plus rapide : %d ", pt_fin);
            while (pt_fin!=pt_arrivee_bis.ordre)
            {
                pt_fin=pt_pred;
                if(pt_fin!=0)
                {
                    //printf(" %d ", pt_fin+1);
                }
                if (pred[pt_fin]!=-1)
                {
                    pt_pred=pred[pt_fin];
                }
            }
        }
        //printf("\n\n");
    }

    //rectfill(page, 500, 50, 750, 550, makecol(0,51,102));
    //rectfill(page, 725, 50, 750, 75, makecol(255,255,255));
}

void calcul_itineraire(t_ancre *ancre, float **tab, float *l, int *pred)
{
    int tampon;

    if(booleen1==1 && booleen2==1)
    {
        dijkstra(tab, ancre->nb_lieu, pt_depart.ordre-1, l, pred);
        printf("Temps de %d a %d : %.2f \n", pt_depart.ordre, pt_arrivee.ordre, l[pt_arrivee.ordre-1]);
        textprintf_ex(screen, font, 275, 10, makecol(255,153,0), -1, "Itineraire le plus rapide : ");
        tampon=pt_arrivee.ordre-1;
        if(pred[tampon]==-1)
        {}
        else
        {
            //printf("Itineraire le plus rapide : ");
            do{
                //if(tampon!=0)
                    //printf("%d<-", (tampon+1));
                if (pred[tampon]!=-1)
                    tampon=pred[tampon];
            }while(tampon!=pt_depart.ordre-1);
            //printf("%d\n",pt_depart.ordre);
        }
        booleen1=0;
        booleen2=0;
        booleen3=1;
    }
    //textprintf_ex(page, font, 275, 20, makecol(255,153,0), -1, "Temps de %d a %d : %.2f", pt_depart.ordre, pt_arrivee.ordre, l[pt_arrivee.ordre]);
    //textprintf_ex(page, font, 275, 30, makecol(255,153,0), -1, "Itineraire le plus rapide : ");
}

t_trajet cherche_court_trajet(t_ancre *ancre, int depart, int arrivee)
{
    int i;
    t_trajet temporaire;

    temporaire.arrivee=0;
    temporaire.depart=0;
    temporaire.numero_trajet=0;
    temporaire.temps=0;

    for(i=0; i<ancre->nb_trajet; i++)
    {
        if(ancre->tab_trajet[i].depart==depart && ancre->tab_trajet[i].arrivee==arrivee)
        {
            if(!temporaire.numero_trajet)
                temporaire=ancre->tab_trajet[i];

            if(temporaire.temps>ancre->tab_trajet[i].temps)
                temporaire=ancre->tab_trajet[i];
        }
    }

    return temporaire;
}

void afficher_itineraire(t_ancre *ancre, int* pred, float* l,BITMAP* escale,BITMAP* arrivee,BITMAP* depart)
{
    int tampon,i=0, j=0;
    tampon=pt_arrivee.ordre-1;
    t_trajet trajet;
    //rectfill(page, 500, 50, 750, 550, makecol(0,51,102));
    textprintf_ex(screen,font,275,20,makecol(0,255,0),-1,"%d",pt_arrivee.ordre);
    textprintf_ex(screen,font,275,30,makecol(255,153,0),-1,"Trajets a prendre :");
    do{
        if(tampon!=0 && tampon!=pt_arrivee.ordre-1)
        {
            textprintf_ex(screen,font,275+i*40,20,makecol(255,255,0),-1,"<-%d",tampon+1);
            draw_sprite(screen,escale,((ancre->tab_lieu[tampon].x)-48)/4,((ancre->tab_lieu[tampon].y)-88)/4);
        }
        trajet=cherche_court_trajet(ancre,pred[tampon]+1,tampon+1);
        if (pred[tampon]!=-1)
            tampon=pred[tampon];
        //trajet=cherche_court_trajet(ancre,pred[tampon],tampon);
        textprintf_ex(screen,font,275,40+j*10,makecol(0,0,255),-1,"%s", trajet.nom);
        i++;
        j++;
    }while(tampon!=pt_depart.ordre-1);
    textprintf_ex(screen,font,275+i*40,20,makecol(255,0,0),-1,"<- %d",pt_depart.ordre);
    draw_sprite(screen, depart, ((ancre->tab_lieu[pt_depart.ordre-1].x)/4)-12, ((ancre->tab_lieu[pt_depart.ordre-1].y)/4)-22);
    draw_sprite(screen, arrivee, ((ancre->tab_lieu[pt_arrivee.ordre-1].x)/4)-12, ((ancre->tab_lieu[pt_arrivee.ordre-1].y)/4)-22);

    booleen3=0;
}

void afficher_tout_itineraire_ecran(t_ancre *ancre, int *pred, float *l)
{
    int i;

    rectfill(page, 500, 50, 790, 425, makecol(0,51,102));

    for(i=0;i<ancre->nb_lieu;i++)
    {
        //printf("Temps de %d a %d : %.2f sec\n", pt_depart_bis.ordre, i+1, l[i]);
        textprintf_ex(page, font, 505, 55+i*10, makecol(255,255,255), -1, "Temps de %d a %d : %.2f sec", pt_depart_bis.ordre, i+1, l[i]);
        /*pt_fin=i+1;
        pt_pred=pred[i];
        if (pred[i]==-1)
        {
            //
        }
        else
        {
            printf("Itineraire le plus rapide : %d ", pt_fin);
            while (pt_fin!=pt_arrivee_bis.ordre)
            {
                pt_fin=pt_pred;
                if(pt_fin!=0)
                {
                    printf(" %d ", pt_fin+1);
                }
                if (pred[pt_fin]!=-1)
                {
                    pt_pred=pred[pt_fin];
                }
            }
        }
        //printf("\n\n");*/
    }

    //rectfill(page, 725, 50, 750, 75, makecol(255,255,255));
}
>>>>>>> Projet final
