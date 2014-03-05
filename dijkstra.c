#include "header.h"

// Paramètres :
/// adjacencePoids :
/// ordre : nombre de sommets
/// s : numéro de sommet de référence
///  l : tableau dynamique alloué des longueurs minimales des sommets depuis s
///  pred : tableau dynamique alloué des prédécesseurs des sommets

void dijkstra (float**adjacencePoids, int ordre, int s, float *l, int *pred)
{
/// Variables locales
    int *marques ; /// tableau dynamique indiquant si les sommets sont marqués ou non
    int x, y, xmin, compteur ; /// numéros de sommets intermédiaires
    float min ; /// distance minimale du prochain sommet à marquer
    int nb = 0 ; /// nombre de sommets marqués initialisé à 0

/// Allouer le tableau marques de taille « ordre »

    marques = (int *) malloc(ordre*sizeof(int));

/// Initialiser le marquage à 0 et les longueurs minimales à l'INFINI
    for(compteur=0 ; compteur < ordre; compteur++)
    {
        marques[compteur]=0;
        l[compteur]= INFINI;
    }

/// Initialiser longueur de s nombre de sommets marqués à 0
    l[s] = nb = 0 ;
    //pred[s]=s;
/// Tant que les sommets ne sont pas tous marqués
    while (nb<ordre)
    {
        /// Initialiser la longueur minimale à l'infini
        min = INFINI;

/// Pour tous les sommets x non marqués de longueur minimale
/// Stocker le sommet « xmin » de longueur minimale
        for (x=0 ; x<ordre ; x++)
        {
            if (!marques[x] && l[x]<min )
            {
                xmin = x ;
                min = l[x] ;
            }
        }
/// Marquer le sommet de longueur minimale « xmin » et incrémenter « nb »
        marques[xmin] = 1 ;
        nb++ ;
/// Pour tous les sommets y adjacents à « xmin » et non marqués
/// Chercher la plus petite distance de y à « xmin »
/// Stocker le prédécesseur « xmin » de y
        for (y=0 ; y<ordre ; y++)
            if (adjacencePoids[xmin][y] && !marques[y] &&
                    l[xmin]+ adjacencePoids[xmin][y]<l[y])
            {
                l[y] = l[xmin] + adjacencePoids[xmin][y] ;
                pred[y] = xmin ;
            }
    }
}
