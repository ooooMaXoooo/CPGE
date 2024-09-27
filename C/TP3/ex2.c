#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

/************************** PROTOTYPES **************************/

// affiche les n première valeur du tableau tab
void afficheTab(int tab[], int n);

// surcharge de la fonction afficheTab pour afficher un tableau de booléen
void afficheTabBool(bool tab[], int n);

// retourne le nombre de pic dans le tableau tab de taille n >= 3
int recherchePic(int tab[], int n);

// Modifie le tableau indice de taille n de sorte à avoir pour tout 0 < i < n :
//      false    si tab[i] n'est pas un pic
//      true     sinon
//
// le tabeau est passé par adresse, il n'y a donc pas besoin de retourner qqlch
void indicePics(int tab[], int n, bool indices[]);


/************************** CORPS FONCTIONS **************************/
void afficheTab(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%2d] :\t%d\n", i, tab[i]);
    }
}

void afficheTabBool(bool tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        if (tab[i])
        {
            printf("true\n");
        }else{
            printf("false\n");
        }
        
    }
}

int recherchePic(int tab[], int n)
{
    int nbPics = 0;
    for( int i = 1; i < n-1;)
    {
        if (tab[i] > tab[i+1] && tab[i] > tab[i-1])
        {
            nbPics++;
            i += 2;                                                // on augmente de deux car si on trouve un pic, alors le prochain élement ne pourra pas en etre un.
        }
        else
        {
            i++;                                                   // on incremente notre boucle de 1 car si on ne trouve pas de pic, il est possible que l'element d'après en soit un
        }


    }
    return nbPics;
}

void indicesPics(int tab[], int n, bool indices[])
{
    for( int i = 1; i < n-1;)
    {
        if (tab[i] > tab[i+1] && tab[i] > tab[i-1])
        {
            indices[i] = true;
            i += 2;                                                // on augmente de deux car si on trouve un pic, alors le prochain élement ne pourra pas en etre un.
        }
        else
        {
            indices[i] = false;
            i++;                                                   // on incremente notre boucle de 1 car si on ne trouve pas de pic, il est possible que l'element d'après en soit un
        }
    }
}

/************************** FONCTIONS TESTS **************************/

void testTab()
{
    int tab[5] = {0,1,2,3,4};

    afficheTab(tab, 5);
}

void testPics()
{
    int tab[7] = {0,6,-5,42,21,22,-100};
    bool indicePics[7] = {0,0,0,0,0,0,0};

    indicesPics(tab, 7, indicePics);
    afficheTabBool(indicePics, 7);
    assert(recherchePic(tab, 7) == 3);
}


/************************** ENTRY POINT **************************/
int main()
{
    //testTab();
    testPics();

    return 0;
}