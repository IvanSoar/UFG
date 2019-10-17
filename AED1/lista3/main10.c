#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define TAM_MAX 1000
#define MAX_VALOR 1000
#define MIN_VALOR -1000

int **geraMatrizRandom(int, int, int);
int **geraMatrizZerada(int);
void imprimeMatriz(int **, int);
int multiplicaMatrizes(int **, int **, int **, int);

int main()
{
    srand(time(NULL));
    int n = (rand() % TAM_MAX) + 1;

    int i, j;

    int **matrizA = geraMatrizRandom(n, MAX_VALOR, MIN_VALOR);
    int **matrizB = geraMatrizRandom(n, MAX_VALOR, MIN_VALOR);
    int **matrizResultado = geraMatrizZerada(n);

    int contadorPassos = multiplicaMatrizes(matrizA, matrizB, matrizResultado, n);

    printf("%d\n", n);
    printf("\n");
    imprimeMatriz(matrizA, n);
    printf("\n");
    imprimeMatriz(matrizB, n);
    printf("\n");
    imprimeMatriz(matrizResultado, n);
    printf("\n");
    printf("%d\n", contadorPassos);
}

int **geraMatrizRandom(int ordem, int max, int min)
{
    int **temp = (int **)malloc(sizeof(int *) * ordem);
    int i, j;
    for (i = 0; i < ordem; i++)
    {
        temp[i] = (int *)malloc(sizeof(int) * ordem);
        for (j = 0; j < ordem; j++)
        {
            temp[i][j] = (rand() % abs(min) + abs(max)) - min;
        }
    }
    return temp;
}

int **geraMatrizZerada(int ordem)
{
    int **temp = (int **)malloc(sizeof(int *) * ordem);
    int i, j;
    for (i = 0; i < ordem; i++)
    {
        temp[i] = (int *)malloc(sizeof(int) * ordem);
        for (j = 0; j < ordem; j++)
        {
            temp[i][j] = 0;
        }
    }
    return temp;
}

void imprimeMatriz(int **matriz, int ordem)
{
    int i, j;

    for (i = 0; i < ordem; i++)
    {
        for (j = 0; j < ordem; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int multiplicaMatrizes(int **mA, int **mB, int **mR, int o)
{
    int i, j, k, contador = 0;
    for (i = 0; i < o; i++)
    {
        for (j = 0; j < o; j++)
        {
            for (k = 0; k < o; k++)
            {
                mR[i][j] += (mA[i][k] * mB[k][j]);
                contador++;
            }
        }
    }
    return contador;
}