#include <stdio.h>
#include <stdlib.h>

int contaLadroesPresos(char **, int, int);
int baculejo(char **, int, int, int, int);

int main()
{
    int i, j, casos, tamanhoMinimundo, distPL;
    scanf("%d", &casos);

    while (casos)
    {
        scanf("%d %d", &tamanhoMinimundo, &distPL);
        getchar();
        char **miniMundo = (char **)malloc(sizeof(char *) * tamanhoMinimundo);
        for (i = 0; i < tamanhoMinimundo; i++)
        {
            miniMundo[i] = (char *)malloc(sizeof(char) * tamanhoMinimundo);
        }

        for (i = 0; i < tamanhoMinimundo; i++)
        {
            for (j = 0; j < tamanhoMinimundo; j++)
            {
                scanf("%c", &miniMundo[i][j]);
                getchar();
            }
        }

        printf("%d\n", contaLadroesPresos(miniMundo, tamanhoMinimundo, distPL));

        casos--;
    }

    return 0;
}

int contaLadroesPresos(char **mundo, int tamanho, int distPL)
{
    int i, j, contador = 0;
    for (i = 0; i < tamanho; i++)
    {
        for (j = 0; j < tamanho; j++)
        {
            if (mundo[i][j] == 'P')
            {
                contador += baculejo(mundo, i, j, distPL, tamanho);
            }
        }
    }
    return contador;
}

int baculejo(char **mundo, int x, int y, int dist, int tam)
{
    int contador = 0;

    if (x + dist < tam && mundo[x + dist][y] == 'L')
    {
        mundo[x + dist][y] = 'X';
        contador++;
    }
    else if (x - dist >= 0 && mundo[x - dist][y] == 'L')
    {
        mundo[x - dist][y] = 'X';
        contador++;
    }
    return contador;
}