#include <stdio.h>
#include <stdlib.h>

int calculaPresos(char **, int, int);
char **alocaMundo(int);
int verificaAlcance(char **, int, int, int, int);

int main()
{
    int i, j, k, casos = 0;
    int tamanhoMundo, alcancePolicial;
    scanf("%d", &casos);

    for (i = casos; i > 0 && i < 11; i--)
    {
        scanf("%d %d", &tamanhoMundo, &alcancePolicial);

        char **mundo = alocaMundo(tamanhoMundo);

        for (j = 0; j < tamanhoMundo; j++)
        {
            for (k = 0; k < tamanhoMundo; k++)
            {
                getchar();
                scanf("%c", &mundo[j][k]);
            }
        }

        printf("%d\n", calculaPresos(mundo, tamanhoMundo, alcancePolicial));
    }

    return 0;
}

int calculaPresos(char **mundo, int tamanhoMundo, int alcancePolicial)
{
    int i, j, conta = 0;
    for (i = 0; i < tamanhoMundo; i++)
    {
        for (j = 0; j < tamanhoMundo; j++)
        {
            if (mundo[i][j] == 'P')
            {
                conta += verificaAlcance(mundo, tamanhoMundo, alcancePolicial, i, j);
            }
        }
    }
    return conta;
}

char **alocaMundo(int tamanhoMundo)
{
    int j;
    char **mundo = (char **)malloc(sizeof(char *) * tamanhoMundo);
    for (j = 0; j < tamanhoMundo; j++)
    {
        mundo[j] = (char *)malloc(sizeof(char) * tamanhoMundo);
    }
    return mundo;
}

int verificaAlcance(char **mundo, int tamanho, int alcance, int i, int j)
{
    if ((j - alcance >= 0) && mundo[i][j - alcance] == 'L')
    {
        return 1;
    }
    else if ((j + alcance < tamanho) && mundo[i][j + alcance] == 'L')
    {
        return 1;
    }
    
    return 0;
}