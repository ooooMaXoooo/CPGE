#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>


// créer un carré de Polybe
void genereCarre(char polybe[5][5])
{
    for (char i = 0; i < 21; i++)
    {
        polybe[i / 5][i%5] = 'a' + i;
        //printf("\t\ti : %2d --> i/5 = %2d   and    i mod5 = %2d\n", i, i/5, i%5);
    }

    //printf("\n\n");

    polybe[4][1] = 'v';
    polybe[4][2] = 'x';
    polybe[4][3] = 'y';
    polybe[4][4] = 'z';
}


// affiche un le carree de polybe
void afficheCarre(char carre[5][5])
{
    // on génère le carre de polybe
    genereCarre(carre);

    // les éléments sont stockés de façon continue dans la mémoire, on peut donc utiliser un pointeur pour aller au prochain élément du tableau.
    for(char* i = carre[0]; i - carre[0] < 25; i++)
    {
        if((i - carre[0]) % 5 == 0)
            printf("\n\t");
        printf("%c ", *i);
        fflush(stdout);
    }
}


// code une lettre avec le cryptage du carre de polybe
int encodeLettre(char lettre)
{
    if (lettre < 'v')
        return (int)(lettre - 'a');
    else if (lettre < 'x')
        return 22;
    else
        return (int)(lettre - 'a');
}

// decode une lettre suivant le cryptage du caree de polybe
char decode(int nb)
{
    assert(nb > -1 && nb < 26);

    nb += 97;

    if (nb < 'v')
        return (char)nb;
    else if (nb < 'x')
    {
        return rand() % 2 == 0 ? 'v' : 'w';
    }
    else
        return (char)(nb);
}



void test_encodeLettre()
{
    assert(encodeLettre('a') == 0);
    assert(encodeLettre('z') == 25);
    assert(encodeLettre('w') == encodeLettre('v'));
}



int main()
{
    char carre[5][5];


    srand(time(NULL));


    // tests
    test_encodeLettre();
    //afficheCarre(carre);

    for(int i = 0; i < 52; i++)
    {
        if(i % 26 == 0)
            printf("\n");
        printf("%c : %d\n", decode(i%26), i);
    }
    return 0;
}