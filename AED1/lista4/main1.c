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
    int i;
    if (tamanho < 1)
        return;

    for (i = 0; i < tamanho; i++)
        if (vetor[i] > vetor[i + 1])
        {
            troca(&vetor[i], &vetor[i + 1]);
            *contador = *contador + 1;
        }

    bolha(vetor, tamanho - 1, contador);
}