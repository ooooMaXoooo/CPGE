#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>

// affiche un matrice de taille 2x3
void afficheMatrice(int matrice[2][3])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            printf("%d\t",matrice[i][j]);
        }
        printf("\n");
    }
}

// remplit une matric de taille 2x3 par desvaleurs aleatoire entre 0 et 100
void remplitMatrice(int matrice[2][3])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            matrice[i][j] = rand() % 101;
        }
        printf("\n");
    }
}




int minimum(int mat[2][3])
{
    int min = mat[0][0];
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            if (min > mat[i][j])
            {
                min = mat[i][j];
            }
        }
        printf("\n");
    }
    return min;
}


void coordMini(int mat[2][3], int coord[2])
{
    int Xmin = 0;
    int Ymin = 0;
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            if (mat[Ymin][Xmin] > mat[i][j])
            {
                Xmin = j;
                Ymin = i;
            }
        }
    }

    coord[0] = Ymin;
    coord[1] = Xmin;
}



void lineariseMat(int mat[2][3], int matLin[6])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            matLin[3*i+j] = mat[i][j];
        }
    }
}

void lineariseMat_0(int mat[2][3], int matLin[6])
{
    for(int i = 0; i < 6; i++)
    {
        matLin[i] = mat[i/3][i%3];
    }
}

void somme(int m1[2][3], int m2[2][3], int somme[2][3])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            somme[i][j] = m1[i][j] + m2[i][j];
        }
    }
}

void produit(int m1[2][3], int m2[2][3], int produit[2][3])
{
    for(int i = 0; i < 2; i++)
    {
        for(int j =0; j < 3; j++)
        {
            produit[i][j] = m1[i][j] * m2[i][j];
        }
    }
}






void testMat()
{
    int mat[2][3];
    
    remplitMatrice(mat);
    afficheMatrice(mat);
}

void testMinMat(){
    
    int mat[2][3] = {{0,1,2},{3,-4,5}};

    assert(minimum(mat) == -4);
}

void testCoordMinMat()
{
    int mat[2][3] = {{0,1,2},{3,-4,5}};
    int minCoord[2] = {-1,-1};

    coordMini(mat, minCoord);

    printf("%d-%d\n", minCoord[0], minCoord[1]);
}

void testLin()
{
    int mat[2][3] = {{0,1,2},{3,4,5}};
    int lin[6];

    lineariseMat(mat, lin);

    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", lin[i]);
    }
    printf("\n");
}

void testLin_0()
{
    int mat[2][3] = {{0,1,2},{3,4,5}};
    int lin[6];

    lineariseMat_0(mat, lin);

    for (int i = 0; i < 6; i++)
    {
        printf("%d\t", lin[i]);
    }
    printf("\n");
}


int main(int argc, char* argv [])
{
    srand(time(NULL));

    /*int mat[2][3] = {{0,1,2},{3,4,5}};

    afficheMatrice(mat);*/

    testMat();
    testMinMat();
    testCoordMinMat();
    testLin_0();


    return 0;

}