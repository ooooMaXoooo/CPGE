#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include <math.h>


void afficheTab(int tab[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("[%d] :\t%d\n", i, tab[i]);
    }
}



/************************************* VARIABLES GLOBALES *************************************/
const int duree[6] = {0, 13, 23, 31, 40, 46};
const int n = 6;


/************************************* PROTOTYPES *************************************/

/// @brief retourne la duree entre deux arret
/// @param arret1 numero de l'arret 1
/// @param arret2 numero de l'arret 2
/// @return -1 si arret1 ou arret2 sont incorrects. la duree etntre les 2 arrets sinon
int dureeTrajet(uint8_t arret1, uint8_t arret2);

/// @brief calcul l'heure d'arrivée jusqu'à un arrêt {arret} en partant de Nantes à une heure {depart}. l'heure d'arrivée est stocker dans {arrivee}
/// @param depart tableau à 2 element sous le format [heure, minute]
/// @param arrivee tableau à 2 element sous le format [heure, minute]
/// @param arret l'arrêt dont on souhaite l'heure d'arrivee
void heureArrivee(int depart[], int arrivee[], int arret);

/// @brief calcul l'heure de depart {depart} à Nantes en sachant à quelle heure {arrivee} et quel arrêt {arret} depuis lesquels on part.
/// @param depart tableau à 2 element sous le format [heure, minute]
/// @param arrivee tableau à 2 element sous le format [heure, minute]
/// @param arret l'arrêt dont on souhaite l'heure d'arrivee
void heureDepart(int depart[], int arrivee[], int arret);

/************************************* CORPS DES FONCTIONS *************************************/

int dureeTrajet(uint8_t arret1, uint8_t arret2)
{
    if (arret1 < 0 || arret1 > n-1)
        return -1;
    if (arret2 < 0 || arret2 > n-1)
        return -1;

    return abs(duree[arret1] - duree[arret2]);
}


void heureArrivee(int depart[], int arrivee[], int arret)
{
    int duree = dureeTrajet(0, arret);

    assert(duree != -1);

    // on ajoute la duree aux minutes
    arrivee[1] = depart[1] + duree;
    arrivee[0] = depart[0];


    // mettre l'heure d'arrivée sous le bon format
    arrivee[0] = (arrivee[1] / 60 + arrivee[0]) % 24;          // on ajoute les minutes en trop et on met l'heure entre 0 et 23
    arrivee[1] %= 60;                                          // les minutes vont de 0 à 59 compris.
}

void heureDepart(int depart[], int arrivee[], int arret)
{
    int duree = dureeTrajet(0, arret);

    assert(duree != -1);

    // on ajoute la duree aux minutes
    depart[1] = arrivee[1]+60 - duree;
    depart[0] = arrivee[0];

    // mettre l'heure d'arrivée sous le bon format
    arrivee[0] = (arrivee[1] / 60 + arrivee[0]) % 24;          // on ajoute les minutes en trop et on met l'heure entre 0 et 23
    arrivee[1] %= 60;      
}


/************************************* FONCTIONS TESTS *************************************/
void test_dureeTrajet()
{
    assert(dureeTrajet(0, 5) == 46);
    assert(dureeTrajet(5, 0) == 46);

    // test des cas incorrects
    assert(dureeTrajet(-8, 1) == -1);
    assert(dureeTrajet(7, 6) == -1);

    assert(dureeTrajet(5, -42) == -1);
    assert(dureeTrajet(3, 10) == -1);
}

void test_heureArrivee()
{
    int depart[2] = {12, 21};
    int arrivee[2] = {-1, -1};

    heureArrivee(depart, arrivee, 4);

    assert(dureeTrajet(0, 4) == 40);

    assert(arrivee[0] == 13);
    assert(arrivee[1] == 1);
}

/************************************* ENTRY POINT *************************************/

int main(int argc, char* argv[])
{
    test_heureArrivee();

    printf("%d\n", -10%60);

    return 0;
}