#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <math.h>

/************************** PROTOTYPES **************************/

// affiche les n première valeur du tableau tab
void afficheTab(int tab[], int n);

// remplit le tableau tab de taille n par des valeurs aleatoire entre 0 et 10 compris
void remplitTab(int tab[], int n);

//retourne la valeur minimal d'un tableau non-vide d'entier et de taille n
int mini(int tab[], int n);

//retourne l'indice de la valeur minimal d'un tableau non-vide d'entier et de taille n.
//Si il existe plusieurs indices, l'indice retourné sera le dernier.
int indiceMini(int tab[], int n);

// affecte la moyenne et la variance des valeurs du tableau t de taille n.
// stat doit avoir une taille >= 2
void Stat(int tab[], int n, float stat[]);



/************************** CORPS FONCTIONS **************************/
void afficheTab(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%2d] : %d\n", i, tab[i]);
    }
}

void remplitTab(int tab[], int n)
{
    for(int i = 0; i < n; i++)
    {
        tab[i] = rand() % 11;
    }
}

int mini(int tab[], int n)
{
    int min = tab[0];

    for (int i = 0; i < n; i++)
    {
        if (tab[i] < min)
        {
            min = tab[i];
        }
    }

    return min;
}

int indiceMini(int tab[], int n)
{
    int min = tab[0];
    int indice = 0;

    for (int i = 0; i < n; i++)
    {
        if (tab[i] <= min)
        {
            min = tab[i];
            indice = i;
        }
    }

    return indice;
}


void Stat(int tab[], int n, float stat[])
{
    float var = 0;
    float moy = 0;
    for (int i = 0; i < n; i++)
    {
        moy += tab[i];
    }
    moy /= n;

    for (int i = 0; i < n; i++)
    {
        var += (tab[i] - moy)*(tab[i] - moy);
    }
    var /= n;

    stat[0] = moy;
    stat[1] = var;
}

/************************** FONCTIONS TESTS **************************/

void testTab()
{
    int tab[5] = {0,1,2,3,4};

    remplitTab(tab, 5);
    afficheTab(tab, 5);
}

void testMini()
{
    int tab[6] = {5,4,7,2,-42};

    assert(mini(tab, 6) == -42);
}

void testIndiceMini()
{
    int tab[7] = {5,4,7,2,-42, 5};

    assert(indiceMini(tab, 7) == 4);
}

void testStat()
{
    int tab[10] = {0,1,2,3,4,5,6,7,8,9};
    int n = 10;
    float stat[2];

    Stat(tab, n, stat);

    assert(abs(stat[0] - 4.5) < 10e-15);
    assert(abs(stat[1] - 8.25) < 10e-15);

}


/************************** ENTRY POINT **************************/

int main()
{
    srand(time(NULL));

    testTab();
    testMini();
    testIndiceMini();
    testStat();

    return 0;
}