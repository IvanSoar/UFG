#include<stdio.h>

void troca(int *, int *);
void bolha(int *, int , int *);

int main(int argc, char const *argv[])
{
    int i, casos, vagoes;

    scanf("%d", &casos);

    while(casos--){
        scanf("%d", &vagoes);
        int ordemInicial[vagoes];
        int contador = 0;

        for (i = 0; i < vagoes; i++)
        {
            scanf("%d", &ordemInicial[i]);
        }

        bolha(ordemInicial, vagoes, &contador);

        printf("%d\n", contador);
    }

    return 0;
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}

void bolha(int *vetor, int tamanho, int *contador)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                troca(&vetor[i], &vetor[j]);
                *contador = *contador + 1;
            }
        }
    }
}