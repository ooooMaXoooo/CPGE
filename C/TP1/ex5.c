/* Le jeu du plus ou moins, 14/09/2024, version 1.0
 *      Le jeu du plus ou moins consiste à deviner un nombre aléatoire choisi par l'ordinateur.
 *      Le joueur dispose de 10 essais pour trouver le nombre mystère, on lui indiquera si sa proposition est supérieur ou inférieur
 *          au nombre mystère.
 *      
 *      On ajoute un système permettant au joueur de relancer une partie si il le souhaite.
 * 
 * Lemoine Maxence
 */

/******************** IMPORT DES BIBLIOTHEQUES ********************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>




/******************** FONCTIONS ********************/

/* 
 * @param ptr_prop 
 *  un pointeur sur la proposition du joueur
 *
 * @param ptr_nbMystere
 *  un pointeur sur le nombre mystere
 * 
 * @result un booléen, vrai si la proposition du joueur est correcte
 */
bool verif_proposition(int* ptr_prop, int* ptr_nbMystere);






/******************** CORPS DES FOCNTIONS ********************/
bool verif_proposition(int* ptr_prop, int* ptr_nbMystere)
{
    if(*ptr_prop < *ptr_nbMystere)
    {
        printf("\n\tLe nombre est plus grand\n\n");
    }
    else if (*ptr_prop > *ptr_nbMystere)
    {
        printf("\n\tLe nombre est moins grand\n\n");
    }
    else
    {
        return true;
    }

    return false;
}





/******************** POINT D'ENTREE ********************/
int main(int argc, char* argv[])
{
    /******************* VARIABLES *********************/
    // variables de l'ordinateur
    const int mini =0, maxi = 100;         // les variables mini et maxi ne vont pas changer, on les déclarent constantes pour optimiser
    int nb_mystere;

    char rejouer = 1;                      // rejouer en char pour occuper le moins d'espace possible. Initialisation a 1 pour la premiere boucle iteration

    bool gagner = false;                   // gagner = true quand le joueur devine le nombre



    // variables du joueur
    int nb_essais = 10;
    int proposition = -1;                  // initialisation de proposition à -1 pour lancer la seconde boucle while




    srand(time(NULL));                     // rajoute de l'aléatoire



    /******************* GAME LOOP **********************/
    while(rejouer)
    {
        // initialise les variables pour preparer une partie
        nb_mystere = (rand() % (maxi - mini + 1)) + mini;
        nb_essais = 10;
        gagner = false;
        proposition = -1;

        // Explication du jeu
        printf("\n\t\t*********************************************\n");
        printf("L'ordinateur a choisi un nombre entre 0 et 100, devinez le en moins de 10 essais\n");
        printf("\t\t*********************************************\n\n");


        while (nb_essais != 0 && !gagner)
        {
            printf("[essais restant(s) : %d]\t Quel nombre proposez vous : ", nb_essais);
            scanf_s("%d", &proposition);
            fflush(stdin);

            if(verif_proposition(&proposition, &nb_mystere))
            {
                gagner = true;
            }

            nb_essais--;

            
        }
        if(gagner)
        {
            printf("Vous avez trouver le nombre en %d essai(s)\n", 10 - nb_essais);
        }else {
            printf("Vous n'avez pas reussi a trouver le nombre en moins de 10 essais\n");
        }

        printf("\t\t*********************************************\n");
        printf("Voulez-vous rejouer ?\n\t- 0 pour non\n\t- 1 pour oui\n");
        scanf_s("%d", &rejouer);
        fflush(stdin);
        printf("\n\n\n");

    }

    return 0;
}