#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// renvoie si le mot est un palindrone
bool estPalindrome(char mot[])
{
    size_t len = strlen(mot);
    bool cond = true;

    for (int i = 0; i < len/2; i++)
    {
        cond = cond && mot[i] == mot[len - i - 1];
    }

    return cond;
}


int main()
{
    int recommencer = 1;
    char mot[100];
    mot[99] = 0;

    while(recommencer)
    {
        printf("Entrer un mot :\n");
        scanf("%s", mot);
        fflush(stdin);
        
        printf("\tMot de longueur : %d\n", strlen(mot));
        if(estPalindrome(mot))
        {
            printf("\tLe mot \"%s\" est un palindrome", mot);
        }
        else
        {
            printf("\tLe mot \"%s\" n'est pas un palindrome\n", mot);
        }
        

        printf("\nSouhaitez-vous faire un nouveau test (1 pour oui) ?\n");
        scanf("%d", &recommencer);
        fflush(stdin);
    }


    return 0;
}