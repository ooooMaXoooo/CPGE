/* Ce programme sert à calculer les surfaces et les volumes de certaines figures géométriques.
 *
 * Maxence lemoine, 19/09/2024, v1.0
 */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

const float PI = 3.1415926;


//////////////////////////////////////////////////////////////// PROTOTYPES ////////////////////////////////////////////////////////////////

/*surfaces*/

/// @brief retourne l'aire d'un rectangle de dimension l par L
/// @param l la largeur du rectangle
/// @param L la longeur du rectangle
double rectangle(double l, double L);

/// @brief retourne l'aire d'un disque de rayon r
/// @param r la rayon du disque
double disque(double r);

/// @brief retourne l'aire exterieur d'un cyclindre de rayon r et de hauteur h
/// @param r le rayon du cylindre
/// @param h la hauteur du cylindre
double surfaceCylindre(double r, double h);

/// @brief retourne l'aire exterieur d'un esphere de rayon r
/// @param r la rayon de la sphere
double surfaceSphere(double r);



/*volumes*/

/// @brief retourne la volume d'un prisme droit de dimension l par L par h
/// @param l la largeur de la base prisme
/// @param L la longeur de la base prisme
/// @param h le hauteur du prisme
double volumePrisme(double l, double L, double h);

/// @brief retoune la valeure du volume d'un cylindre de rayon r et de hauteur h
/// @param r le rayon du cylindre
/// @param h la hauteur du cylindre
double volumeCylindre(double r, double h);

/// @brief retourne le volume d'un cone de rayon r et de hauteur h
/// @param r le rayon du cone
/// @param h la hauteur du cone
double volumeCone(double r, double h);

/// @brief retourne le volume d'une sphere de rayon r
/// @param r le rayon de la sphere 
double volumeSphere(double r);



/*autre fonctions*/

/// @brief affiche le menu des choix possible dans la console
/// @return la fonction retourne 0 si il n'y a aucune erreur
int affiche_menu();

/// @brief demande une valeur à l'utilisateur en affichant le {texte} et change directememnt la valeur de {var}
/// @param text la texte qui s'affiche a l'utilisateur
/// @param var la variable a changer
void demande_valeur(char texte[], double *var); // En cours d'écriture




//////////////////////////////////////////////////////////////// CORPS DES FONCTIONS ////////////////////////////////////////////////////////////////

/* Surface */

double rectangle(double l, double L)
{
    return l*L;
}

double disque(double r)
{
    return PI * r * r;
}

double surfaceCylindre(double r, double h)
{
    return 2*PI*r*h;
}

double surfaceSphere(double r)
{
    return 4*PI*r*r;
}

/* Volumes*/

double volumePrisme(double l, double L, double h)
{
    return rectangle(l,L) * h;
}

double volumeCylindre(double r, double h)
{
    return disque(r) * h;
}

double volumeCone(double r, double h)
{
    return disque(r) * h / 3;
}

double volumeSphere(double r)
{
    return 4 * PI * r * r / 3;
}


/*autre fonctions*/

int affiche_menu()
{
    printf("Choix du calcul a effectuer\n");
    for(int i = 0; i < 27; printf("-", i++));
    printf("\n\t");
    printf("1-Surface rectangle\n\t");
    printf("2-Surface disque\n\t");
    printf("3-Surface lateral cylindre\n\t");
    printf("4-Surface sphere\n\t");
    printf("5-Volume primse droit\n\t");
    printf("6-Volume cylindre\n\t");
    printf("7-Volume cone\n\t");
    printf("8-Volume sphere\n");

    return 0;
}

void demande_valeur(char texte[], double *var)
{
    while(true)
    {
        printf("%s", texte);
        scanf("%lf", var);
        fflush(stdin);

        if (*var > 0)
        {
            break;
        }

        printf("Donner une valeur correcte. (%f)\n\n", *var);
    }
}




//////////////////////////////////////////////////////////////// ENTRY POINT ////////////////////////////////////////////////////////////////

int main(int argc, char* argv[])
{
    /* variables relatives aux formes geométrique*/
    double r = -1, h = -1, l = -1, L = -1;

    /* variables relatives aux formes geométrique*/
    int choix = 0;



    affiche_menu();

    // recuperer le choix de l'utilisateur
    while(true)
    {
        printf("\nVotre choix : ");
        scanf("%d", &choix);
        fflush(stdin);

        if (choix > 0 && choix < 9)
        {
            break;
        }
        printf("Votre choix n'est pas valide. Recommencer.\n");
    }

    // gerer les choix de l'utilisateur
    // si le choix de l'utilisateur est 1 ou 5
    if(choix % 4 == 1)
    {
        demande_valeur("Longeur : ", &L);
        demande_valeur("largeur : ", &l);
        if(choix == 4)
        {
            demande_valeur("hauteur : ", &h);
            printf("le volume du prisme droit est %.2f", volumePrisme(l,L,h));
        }
        else{
            printf("la surface du rectangle est %.2f", rectangle(l,L));
        }
    } else 
    {
        demande_valeur("rayon : ", &r);

        if (choix == 2)
        {
            printf("la surface du disque est %.2f", disque(r));
        } else if (choix == 3)
        {
            demande_valeur("hauteur : ", &h);
            printf("la surface lateral du cylindre est %.2f", surfaceCylindre(r, h));
        } else if (choix == 4)
        {
            printf("la surface de la shpere est %.2f", surfaceSphere(r));
        } else if (choix == 6)
        {
            demande_valeur("hauteur : ", &h);
            printf("le volume du cylindre est %.2f", volumeCylindre(r, h));
        } else if (choix == 7)
        {
            demande_valeur("hauteur : ", &h);
            printf("le volume du cone est %.2f", volumeCone(r, h));
        } else if (choix == 8)
        {
            printf("le volume du cylindre est %.2f", volumeSphere(r));
        }
        else{
            printf("Erreur de prog : le choix n'est pas pris en compte [choix : %d]", choix);
        }
    }

    printf("\n");
    return 0;
}