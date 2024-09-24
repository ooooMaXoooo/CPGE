#include <stdio.h>
#include <stdlib.h>

int terme_Fibo_R(unsigned int n)
{
    if (n < 2)
    {
        return 1;
    }
    else{
        return terme_Fibo_R(n-1)+terme_Fibo_R(n-2);
    }
}


int terme_Fibo_I(unsigned int n)
{
    unsigned int b = 1, a = 0;;
    unsigned int res = 1;
    for (int i = 1; i < n; i++)
    {
        a = res;
        res += b;
        b = a;
    }

    return res;
}



void affich_fib(unsigned int n, int recursive)
{
    if (!recursive)
    {
        printf("Iteratif :\n");
        for (int i = 0; i < n + 1;i++)
        {
            printf("\t[%d] : %d\n", i, terme_Fibo_I(i));
        }
    }
    else
    {
        printf("Recursif :\n");
        for (int i = 0; i < n + 1; i++)
        {
            printf("\t[%d] : %d\n", i, terme_Fibo_R(i));
        }
    }
}


int main(int argc, char* argv[])
{
    int choix = 0;
    unsigned int terme;

    if(argc > 2)
    {
        affich_fib(atoi(argv[2]), atoi(argv[1]));
    }
    else
    {
        printf("Quel rang : ");
        scanf("%d", &terme);

        printf("Iteratif(0) ou recursif(1) : ");
        scanf("%d", &choix);

        affich_fib(terme, choix);
    }

    return 0;
}