#include <stdio.h>
#include <assert.h>

/*
 * retourne la longueur d'une chaîne de caractère (mot) envoyé en parametre
 */
int longueur(char mot[])
{
    char* c = mot;
    while(*c != '\0')
    {
        c++;
    }

    return c - mot;
}

// renvoie le nombre d'occurence d'une lettre dans un mot
int rechercheMot(char mot[], char e)
{
    int count = 0;
    for(int i = 0; i < longueur(mot); i++)
    {
        if (mot[i] == e)
            count++;
    }

    return count;
}

void test_longueur()
{
    char mot[7] = "testest";

    assert(longueur(mot) == 7);
}

void test_rechercheMot()
{
    char mot[7] = "testest";

    assert(rechercheMot(mot, 'e') == 2);
}

int main()
{
    test_longueur();
    test_rechercheMot();

    return 0;
}