#include "header.h"

void calcul_temps_trajet(t_ancre* ancre)
{
    int i;
    for(i=0; i<ancre->nb_trajet; i++)
    {
        if(strcmp(ancre->tab_trajet[i].type,"V")==0)
        {
            ancre->tab_trajet[i].temps=abs(3*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude)));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"B")==0)
        {
            ancre->tab_trajet[i].temps=abs(2.4*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude)));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"R")==0)
        {
            ancre->tab_trajet[i].temps=abs(1.8*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude)));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"N")==0)
        {
            ancre->tab_trajet[i].temps=abs(1.2*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude)));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"KL")==0)
        {
            ancre->tab_trajet[i].temps=abs(0.1*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude)));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"SURF")==0)
        {
            ancre->tab_trajet[i].temps=abs(6*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude)));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"TPH")==0)
        {
            ancre->tab_trajet[i].temps=(240+abs(1.2*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude))));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"TC")==0)
        {
            ancre->tab_trajet[i].temps=(120+abs(1.8*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude))));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"TSD")==0)
        {
            ancre->tab_trajet[i].temps=(60+abs(1.8*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude))));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"TS")==0)
        {
            ancre->tab_trajet[i].temps=(60+abs(2.4*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude))));
        }
        else if(strcmp(ancre->tab_trajet[i].type,"TK")==0)
        {
            ancre->tab_trajet[i].temps=(60+abs(2.4*((ancre->tab_lieu[ancre->tab_trajet[i].depart-1].altitude)-(ancre->tab_lieu[ancre->tab_trajet[i].arrivee-1].altitude))));
        }
        ancre->tab_trajet[57].temps=30*60;
        ancre->tab_trajet[58].temps=30*60;
        ancre->tab_trajet[59].temps=40*60;
        ancre->tab_trajet[60].temps=40*60;
    }

}

float** creation_mat_adj(t_ancre* ancre)
{
    float** tab;
    int i,j/*,nb*/;
    //FILE*fp;
    /*fp=fopen("data/matrice_base.txt","r");
    fscanf(fp,"%d",&nb);
    //printf("%d",nb);
    tab=(float**)malloc(nb*sizeof(float*));
    for(i=0; i<nb; i++)
        tab[i]=(float*)malloc(nb*sizeof(float));

    for(i=0; i<nb; i++)
    {
        for(j=0; j<nb; j++)
        {
            fscanf(fp,"%f",&(tab[i][j]));
            //printf("%f\n",tab[i][j]);
        }
    }*/

    //printf("%d",ancre->nb_lieu);
    tab=(float**)malloc(ancre->nb_lieu*sizeof(float*));
    for(i=0; i<ancre->nb_lieu; i++)
        tab[i]=(float*)malloc(ancre->nb_lieu*sizeof(float));
    for(i=0; i<ancre->nb_lieu; i++)
    {
        for(j=0; j<ancre->nb_lieu; j++)
        {
            tab[i][j]=0.0;
            //printf("%f ", tab[i][j]);
            //printf("%d %d\n",i,j);
        }
    }

    for(i=0; i<ancre->nb_trajet; i++)
    {
        if(tab[(ancre->tab_trajet[i].depart)-1][(ancre->tab_trajet[i].arrivee)-1]==0.0)
            tab[(ancre->tab_trajet[i].depart)-1][(ancre->tab_trajet[i].arrivee)-1]=(float)ancre->tab_trajet[i].temps;

        if(tab[(ancre->tab_trajet[i].depart)-1][(ancre->tab_trajet[i].arrivee)-1]>(float)ancre->tab_trajet[i].temps)
            tab[(ancre->tab_trajet[i].depart)-1][(ancre->tab_trajet[i].arrivee)-1]=(float)ancre->tab_trajet[i].temps;
    }

    /*fp=fopen("data/matrice.txt","w");

    for(i=0; i<ancre->nb_lieu; i++)
    {
        for(j=0; j<ancre->nb_lieu; j++)
        {
            fprintf(fp,"%.2f ",tab[i][j]);
        }
        fprintf(fp,"\n");
    }

    free(fp);*/

    return tab;
}
