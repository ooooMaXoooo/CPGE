#include <stdio.h>

int main(int argc, char* argv[])
{
    int recommencer = 1;

    short operateur;
    int a,b;

    while (recommencer)
    {
        operateur = -1;
        while (operateur < 0 || operateur > 4)
        {
            printf("Quelle operation souhaitez-vous realiser ?\n\t");
            printf("- 1 pour l'addition\n\t");
            printf("- 2 pour la soustraction\n\t");
            printf("- 3 pour la multiplication\n\t");
            printf("- 4 pour la division\n");
            scanf("%d", &operateur);
            fflush(stdin);
        }
        

        printf("Quel est le premier operande\n");
        scanf("%d", &a);
        fflush(stdin);

        b = 0;

        // on fait un do while pour demander dans tous les cas quel second operande l'utilisateur choisit
        // on utilise l'evaluation parresseuse pour verifier le cas ou b = 0 si l'operation est la division
        do
        {
            printf("Quel est le second operande\n");
            scanf("%d", &b);
            fflush(stdin);
        }while(operateur == 4 && !b );

        printf("Le resultat est : ");

        // on affiche le resultat à l'utilisateur
        if (operateur == 1)
            printf("%d + %d = %d", a,b,a+b);
        else if(operateur == 2)
            printf("%d - %d = %d", a,b,a-b);
        else if(operateur == 3)
            printf("%d * %d = %d", a,b,a*b);
        else if(operateur == 4)
            printf("%d / %d = %d", a,b,a/b);

        
        printf("\n###################\n");
        printf("Souhaitez-vous faire une nouvelle operation ?\n\t- 0 pour non\n\t- 1 pour oui\n");
        scanf("%d", &recommencer);
        printf("\n###################\n");
    }
    return 0;
}