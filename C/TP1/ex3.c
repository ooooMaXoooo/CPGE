#include <stdio.h>
#include <assert.h>

// retourne la somme des inverses des entiers de 1 à nb avec un for*
// retourne 0 si nb = 0
double somme_for(unsigned int nb)
{
    double res = 0;
    // on utlise une boucle avec la décrémentation pour éviter "l'absorption" des petites valeurs
    for(int i = nb; i > 0; i--)
    {
        res += 1/(double)i;
    }
    return res;
}

double somme_while(unsigned int nb)
{
    assert(nb != 0);
    double res = 0;
    int i = 1;
    for(; i < nb+1; )
    {
        res += 1/(double)i++;
    }

    return res;
}

int main(int argc, char* arv[])
{
    int nb = 1;
    
    printf("nombre de termes : ");
    scanf("%d", &nb);
    fflush(stdin);

    printf("\nSomme for : %f\n", somme_for(nb));
    printf("Somme while : %f\n", somme_while(nb));

    return 0;
}