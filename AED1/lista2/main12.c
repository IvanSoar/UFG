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
            scanf("%d %d", &labirinto[i][j].x, &labirinto[i][j].y);
        }        
    }

    scanf("%d %d", &xInicial, &yInicial);

    resultado = percorreLabirinto(labirinto, xInicial, yInicial);

    resultado == 0 ? printf("PRESO\n") : printf("VENCE\n");
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
        }
    }
    return matriz;
}

int percorreLabirinto(celula **labirinto, int x, int y)
{
   if(labirinto[x][y].status == 1)
   {
       return 0;
   } else if(labirinto[x][y].x == 0 && labirinto[x][y].y == 0)
   {
       return 1;
   } else
   {
       labirinto[x][y].status = 1;
       percorreLabirinto(labirinto, labirinto[x][y].x,labirinto[x][y].y);
   }
}
