#include <stdio.h>
#include <stdlib.h>

typedef struct Celula {
    int x, y, status;
} celula;

int percorreLabirinto(celula**, int, int);
celula** alocaMatrizCelulas(int, int);

int main()
{
    int linhas, colunas, i, j, xInicial, yInicial, resultado;

    scanf("%d %d", &linhas, &colunas);
    celula** labirinto = alocaMatrizCelulas(linhas, colunas);

    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            // scanf("%d %d", labirinto[i][j].x, labirinto[i][j].y);
            // printf("status (%d x %d): %d\n", labirinto[i][j].x, labirinto[i][j].y, labirinto[i][j].status);
        }        
    }

    //scanf("%d %d", &xInicial, &yInicial);

    //resultado = percorreLabirinto(labirinto, xInicial, yInicial);

    //resultado == 0 ? printf("PRESO\n") : printf("VENCE\n");
}

celula** alocaMatrizCelulas(int linhas, int colunas)
{
    int i, j;
    celula** matriz = (celula**) malloc(sizeof(celula*) * linhas);
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (celula*) malloc(sizeof(celula) * colunas);
        for(j = 0; j < colunas; j++)
        {
            matriz[i][j].status = 0;
            printf("Alocado (%d x %d): status %d\n", i + 1, j + 1, matriz[i][j].status);
        }
    }
    return matriz;
}

int percorreLabirinto(celula **labirinto, int x, int y)
{
   printf("%d\n", labirinto[0][0].status);
   return 1;
}
