#include <stdio.h>
#include <time.h>
#include <assert.h>
#include <stdlib.h>

// affiche un matrice de taille 3x3
void afficheMatrice(int matrice[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            printf("%d\t",matrice[i][j]);
        }
        printf("\n");
    }
}

// modifie M tq M devient la matrice identité de taille 3x3
void diag(int M[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            M[i][j] = (i == j) ? 1 : 0;
        }
    }
}

// remplit une matrice 3x3 par des 1
void ones(int M[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            M[i][j] = 1;
        }
    }
}

// remplit une matrice 3x3 par des 0
void zeros(int M[3][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            M[i][j] = 0;
        }
    }
}


// remplit une matrice de taille 3x3 par desvaleurs aleatoire entre 0 et 5
void remplitMatrice(int matrice[2][3])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j =0; j < 3; j++)
        {
            matrice[i][j] = rand() % 6;
        }
        printf("\n");
    }
}

//calcul le produit matriciel de A par B et le stock dans C
void produitMatrice(int A[3][3], int B[3][3], int C[3][3])
{
    // on met C à 0 pour ajouter nos termes sans récuperer ce qu'il y avait dans la mémoire auparavant
    zeros(C);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for(int k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}





int main()
{
    srand(time(NULL));
    int A[3][3] = {{1,2,3}, {1,2,3}, {1,2,3}};
    int B[3][3] = {{10,20,30}, {10,20,30}, {10,20,30}};
    int M[3][3];


    produitMatrice(A, B, M);

    afficheMatrice(M);

    return 0;
}