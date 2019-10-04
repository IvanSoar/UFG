#include <stdio.h>
#include <string.h>

int contaVogais(char *);
int verificaTamanhoPalavra(char *);

int main()
{
    int casos, i;
    scanf("%d", &casos);
    while (casos--)
    {
        char palavra[10001];
        scanf("%s", &palavra);

        printf("%d\n", contaVogais(palavra));
    }
    return 0;
}

int contaVogais(char *palavra)
{
    char vogais[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    int i, j, contador = 0;
    int tamanhoPalavra = verificaTamanhoPalavra(palavra);

    for (i = 0; i < tamanhoPalavra; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if (palavra[i] == vogais[j] || palavra[i] == vogais[j] - '0')
            {
                contador++;
                break;
            }
        }
    }

    return contador;
}

int verificaTamanhoPalavra(char *palavra)
{
    int i = 0, contador = 0;
    while (1)
    {
        if (palavra[i] != '\0')
        {
            contador++;
            i++;
        }
        else
        {
            break;
        }
    }
    return contador;
}