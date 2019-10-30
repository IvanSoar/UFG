#include <stdio.h>
#include <stdlib.h>

char **alocaMatriz(int);
void imprimeMatriz(char **, int);

int main(int argc, char const *argv[])
{
    int tamanho, casos, i, range;

    scanf("%d", &casos);
    for (i = 0; i < casos; i++)
    {
        scanf("%d", &tamanho);
        scanf("%d", &range);

        char **miniMundo = alocaMatriz(tamanho);
        //imprimeMatriz(miniMundo, tamanho);
    }
    

    return 0;
}

char **alocaMatriz(int tamanho){
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

void imprimeMatriz(char ** matriz, int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            printf("%c ", matriz[i][j]);
        }
        printf("\n");
    }
}