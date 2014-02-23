#include "header.h"

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

        draw_sprite(page, multi_x2, 200, 10);
        draw_sprite(page, multi_x4, 230, 10);

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
    return 0;
}

void zoom(int x, int y, int multi, BITMAP *map, BITMAP *big_map)
{
    x=multi*x-(100/multi);
    y=multi*y-(75/multi);

    if(x<multi*0)           x=multi*0;
    if(x>=multi*800-200)    x=multi*800-200;

    if(y<multi*0)           y=multi*0;
    if(y>=multi*600-150)    y=multi*600-150;

    blit(big_map, page, x, y, 0, 0, 200, 150);
}
