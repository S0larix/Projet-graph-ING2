#include "header.h"

// Param�tres :
/// adjacencePoids :
/// ordre : nombre de sommets
/// s : num�ro de sommet de r�f�rence
///  l : tableau dynamique allou� des longueurs minimales des sommets depuis s
///  pred : tableau dynamique allou� des pr�d�cesseurs des sommets

void dijkstra (float**adjacencePoids, int ordre, int s, float *l, int *pred)
{
/// Variables locales
    int *marques ; /// tableau dynamique indiquant si les sommets sont marqu�s ou non
    int x, y, xmin, compteur ; /// num�ros de sommets interm�diaires
    float min ; /// distance minimale du prochain sommet � marquer
    int nb = 0 ; /// nombre de sommets marqu�s initialis� � 0

/// Allouer le tableau marques de taille � ordre �

    marques = (int *) malloc(ordre*sizeof(int));

/// Initialiser le marquage � 0 et les longueurs minimales � l'INFINI
    for(compteur=0 ; compteur < ordre; compteur++)
    {
        marques[compteur]=0;
        l[compteur]= INFINI;
    }

/// Initialiser longueur de s nombre de sommets marqu�s � 0
    l[s] = nb = 0 ;
    //pred[s]=s;
/// Tant que les sommets ne sont pas tous marqu�s
    while (nb<ordre)
    {
        /// Initialiser la longueur minimale � l'infini
        min = INFINI;

/// Pour tous les sommets x non marqu�s de longueur minimale
/// Stocker le sommet � xmin � de longueur minimale
        for (x=0 ; x<ordre ; x++)
        {
            if (!marques[x] && l[x]<min )
            {
                xmin = x ;
                min = l[x] ;
            }
        }
/// Marquer le sommet de longueur minimale � xmin � et incr�menter � nb �
        marques[xmin] = 1 ;
        nb++ ;
/// Pour tous les sommets y adjacents � � xmin � et non marqu�s
/// Chercher la plus petite distance de y � � xmin �
/// Stocker le pr�d�cesseur � xmin � de y
        for (y=0 ; y<ordre ; y++)
            if (adjacencePoids[xmin][y] && !marques[y] &&
                    l[xmin]+ adjacencePoids[xmin][y]<l[y])
            {
                l[y] = l[xmin] + adjacencePoids[xmin][y] ;
                pred[y] = xmin ;
            }
    }
}
