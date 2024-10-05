#include <stdio.h>

// affiche la table d'un entier n de 0 à 20 avec une boucle for
void table_for(int nb)
{
    for(int i = 0; i < 21; i++)
    {
        printf("%d * %d = %d\n", nb, i, nb*i);
        fflush(stdout);
    }
}

// affiche la table d'un entier n de 0 à 20 avec une boucle while
void table_while(int nb)
{
    int i = 0;
    while(i < 21)
    {
        printf("%d * %d = %d\n", nb, i, nb*i);
        fflush(stdout);

        i++;
    }
}


int main(int argc, char* argv[])
{
    table_for(9);
    printf("\n\n");
    table_while(9);
    return 0;
}