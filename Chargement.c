#include "header.h"

t_ancre* chargement_lieux_trajets()
{
    ///variables
    FILE * fp;
    t_ancre* ancre;
    int i;

    ///allocation ancre
    if(!(ancre=(t_ancre*)malloc(1*sizeof(t_ancre))))
    {
        printf("erreur allocation ancre\n");
        exit(0);
    }

    ///ouverture fichier
    if(!(fp=fopen("data_arcs.txt","r")) )
    {
        printf("erreur ouverture fichier\n");
        exit(0);
    }

    ///Allocation lieux
    fscanf(fp,"%d",&ancre->nb_lieu);
    printf("%d\n",ancre->nb_lieu);
    if(!(ancre->tab_lieu=(t_lieux*)malloc((ancre->nb_lieu)*sizeof(t_lieux))))
    {
        printf("erreur allocation tableau lieux\n");
        exit(0);
    }
    for(i=0;i<ancre->nb_lieu;i++)
    {
        fscanf(fp,"%d",&ancre->tab_lieu[i].ordre);
        fscanf(fp,"%s",&ancre->tab_lieu[i].nom);
        fscanf(fp,"%d",&ancre->tab_lieu[i].altitude);
    }


    ///Allocation trajet
    fscanf(fp,"%d",&(ancre->nb_trajet));
    printf("%d\n",ancre->nb_trajet);
    if(!(ancre->tab_trajet=(t_trajet*)malloc(ancre->nb_lieu*sizeof(t_trajet))))
    {
        printf("erreur allocation tableau trajet\n");
        exit(0);
    }
    for(i=0;i<ancre->nb_trajet;i++)
    {
        fscanf(fp,"%d",&(ancre->tab_trajet[i].numero_trajet));
        printf("%d ",ancre->tab_trajet[i].numero_trajet);
        fscanf(fp,"%s",&(ancre->tab_trajet[i].nom));
        printf("%s ",ancre->tab_trajet[i].nom);
        fscanf(fp,"%s",&(ancre->tab_trajet[i].type));
        printf("%s ",ancre->tab_trajet[i].type);
        fscanf(fp,"%d",&(ancre->tab_trajet[i].depart));
        printf("%d ",ancre->tab_trajet[i].depart);
        fscanf(fp,"%d",&(ancre->tab_trajet[i].arrivee));
        printf("%d\n",ancre->tab_trajet[i].arrivee);
    }

    ///liberation pointeur
    free(fp);

    return ancre;
}


void afficher_lieux_trajets(t_ancre* ancre)
{
    int i;
    for(i=0;i<ancre->nb_lieu;i++)
    {
        printf("%d ",ancre->tab_lieu[i].ordre);
        printf("%s ",ancre->tab_lieu[i].nom);
        printf("%d\n",ancre->tab_lieu[i].altitude);
    }
    for(i=0;i<ancre->nb_trajet;i++)
    {
        printf("%d ",ancre->tab_trajet[i].numero_trajet);
        printf("%s ",ancre->tab_trajet[i].nom);
        printf("%s ",ancre->tab_trajet[i].type);
        printf("%d ",ancre->tab_trajet[i].depart);
        printf("%d\n",ancre->tab_trajet[i].arrivee);
    }
}
