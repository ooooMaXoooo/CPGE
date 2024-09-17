#include <stdio.h>
#include <assert.h>

double somme_for(unsigned int nb)
{
    assert(nb != 0);
    double res = 0;
    for(int i = 1; i < nb+1; i++)
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