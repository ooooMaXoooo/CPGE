#include <stdio.h>
#include <assert.h>
#include <math.h>
#include <stdlib.h>

/*
 * Prend une temperature en Celsius temp et la convertie en farhenheit
 */
float farhenheit(float temp)
{
    return 9*temp/5 + 32;
}

/*
 * Prend une temperature en farhenheit temp et la convertie en Celsius
 */
float celsius(float temp)
{
    return (temp - 32)*5/9;
}



void test_farhenheit()
{
    float seuil = pow(10, -13);
    assert(abs(farhenheit(20.5) - 68.9) < seuil);
}


void test_celsius()
{
    float seuil = pow(10, -13);
    assert(abs(celsius(68.9) - 20.5) < seuil);
}



int main(int argc, char* argv[])
{
    int reponse;
    float temp;

    //////// test
    test_celsius();
    test_farhenheit();
    /////////////

    printf("Quelle conversion souhaitez-vous ?\n\t");
    printf("1 - Conversion Celsius vers Fahrenheit\n\t");
    printf("2 - Conversion Fahrenheit vers Celsius\n");

    scanf("%d", &reponse);
    fflush(stdin);

    if (reponse == 1)
    {
        printf("Temperature en degres Celsius a convertir : ");
        scanf("%f", &temp);
        fflush(stdin);

        printf("Une temperature de %.2f degres C correspond a %.2f degres F\n", temp, farhenheit(temp));
    }
    else if (reponse == 2){
        printf("Temperature en degres Fahrenheit a convertir : ");
        scanf("%f", &temp);
        fflush(stdin);

        printf("Une temperature de %.2f degres F correspond a %.2f degres C\n", temp, celsius(temp));
    }
    else
    {
        printf("cette option n'exsite pas\n");
    }



    return 0;
}