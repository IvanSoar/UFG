#include <stdio.h>
#include <stdlib.h>

char **alocaMatriz(int);
int resultado(char **, int, int);
void liberaMatriz(char**, int);

int main()
{
    int tamanho, casos, i, range;

    scanf("%d", &casos);
    for (i = 0; i < casos; i++)
    {
        scanf("%d", &tamanho);
        scanf("%d", &range);

        char **miniMundo = alocaMatriz(tamanho);

        printf("%d\n", resultado(miniMundo, tamanho, range));

        liberaMatriz(miniMundo, tamanho);
    }

    return 0;
}

char **alocaMatriz(int tamanho)
{
    int i, j;
    char **temp = (char **)malloc(sizeof(char*) * tamanho);
    for (i = 0; i < tamanho; i++)
    {
        temp[i] = (char *)malloc(sizeof(char) * tamanho);
        for (j = 0; j < tamanho; j++)
        {
            getchar();
            scanf("%c", &temp[i][j]);
        }        
    }
    return temp;
}

int resultado(char **matriz, int tamanho, int range)
{
    int i, j, k, contador = 0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            if(matriz[i][j] == 'P')
            {
                int min = j - range < 0 ? 0 : j - range;
                int max = j + range > tamanho ? tamanho : j + range;

                for (k = min; k <= max; k++)
                {
                    if(matriz[i][k] == 'L'){
                        matriz[i][k] = 'X';
                        contador++;
                        break;
                    }
                }
            }
        }
    }
    return contador;
}

void liberaMatriz(char **matriz, int tamanho){
    int i;
    for (i = 0; i < tamanho; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}