#include <stdio.h>

int main(int argc, char* argv[])
{
    int a,b,c;

    printf("Donnez 3 entiers :\n");
    scanf("%d\n%d\n%d", &a, &b, &c);
    fflush(stdin);

    printf("\n");

    if (a <= b)
    {
        if (a <= c)
        {
            printf("%d\n", a);
            if (b <= c)
            {
                printf("%d\n%d\n", b, c);
            }
            else 
            {
                printf("%d\n%d\n", c, b);
            }
        }
        else
        {
            printf("%d\n%d\n%d\n", c, a, b);
        }
    }
    else
    {
        if(b <= c)
        {
            printf("%d\n", b);
            if (a <= c)
            {
                printf("%d\n%d\n", a, c);
            }
            else 
            {
                printf("%d\n%d\n", c, a);
            }
        }
        else
        {
            printf("%d\n%d\n%d\n", c, b, a);
        }
    }

    return 0;
}