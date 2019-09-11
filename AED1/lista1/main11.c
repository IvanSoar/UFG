#include<stdio.h>
#include<stdlib.h>

int** alocaMatriz(int, int);
void imprimeMatriz(int**, int, int);
int** somaMatrizes(int**, int**, int, int);
int** multiplicaMatrizes(int**, int**, int);

int main()
{
    int linhas, colunas;
    char operador;

    scanf("%d %d", &linhas, &colunas);

    int** matriz1 = alocaMatriz(linhas, colunas);

    getchar();
    scanf("%c", &operador);

    int** matriz2 = alocaMatriz(linhas, colunas);

    int** matrizResultante;

    if(operador == 'x' && linhas != colunas){
        printf("ERROR\n");
        return 0;
    }

    switch(operador){
        case '+': 
            matrizResultante = somaMatrizes(matriz1, matriz2, linhas, colunas);
            break;
        case 'x':
            matrizResultante = multiplicaMatrizes(matriz1, matriz2, linhas);
    }

    imprimeMatriz(matrizResultante, linhas, colunas);
}

int** alocaMatriz(int linhas, int colunas){
    int i, j;
    int** matriz = (int**) malloc(sizeof(int*) * linhas);
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * colunas);
        for (j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz;
}

void imprimeMatriz(int** matriz, int linhas, int colunas){
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** somaMatrizes(int** matriz1, int** matriz2, int linhas, int colunas)
{
    int i, j;
    int** matriz = (int**) malloc(sizeof(int*) * linhas);
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * colunas);
        for (j = 0; j < colunas; j++)
        {
            matriz[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return matriz;
}

int** multiplicaMatrizes(int** matriz1, int** matriz2, int tamanho)
{
    int i, j, k, l, resultado = 0;
    int** matriz = (int**) malloc(sizeof(int*) * tamanho);
    for (i = 0; i < tamanho; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * tamanho);
        for (j = 0; j < tamanho; j++)
        {
            for (k = 0; k < tamanho; k++)
            {
                resultado += matriz1[i][k] * matriz2[k][j];
            }
            matriz[i][j] = resultado;
            resultado = 0;
        }
    }
    return matriz;
}