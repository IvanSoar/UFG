#include <stdio.h>

void verificaCafes(int *, int, int);

int main(int argc, char const *argv[])
{
    int i, qtdRestaurantes;
    scanf("%d", &qtdRestaurantes);

    int restaurantes[qtdRestaurantes];
    for (i = 0; i < qtdRestaurantes; i++)
    {
        scanf("%d", &restaurantes[i]);
    }

    int dias, valor;
    scanf("%d", &dias);

    for (i = 0; i < dias; i++)
    {
        scanf("%d", &valor);
        verificaCafes(restaurantes, qtdRestaurantes, valor);
    }
    return 0;
}

void verificaCafes(int *restaurantes, int qtdRestaurantes, int valor)
{
    int i, contador = 0;
    int vetorCont[qtdRestaurantes];
    for (i = 0; i < qtdRestaurantes; i++)
    {
        vetorCont[i] = 0;
    }

    for (i = 0; i < qtdRestaurantes; i++)
    {
        if (valor % restaurantes[i] < valor)
        {
            vetorCont[i]++;
            contador++;
        }
        else
        {
            vetorCont[i] = 0;
        }
    }

    if (contador > 0)
    {
        printf("%d ", contador);
        for (i = 0; i < qtdRestaurantes; i++)
        {
            vetorCont[i] != 0 ? printf("%d ", i + 1) : 1;
        }
    }
    else
    {
        printf("%d", contador);
    }

    printf("\n");
}