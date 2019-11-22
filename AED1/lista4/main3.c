#include<stdio.h>

void ordenaCrescente(int *, int);
void troca(int *, int *);

int main(int argc, char const *argv[])
{
    int casos;
    scanf("%d", &casos);

    while(casos--){
        int pessoas, i;
        scanf("%d", &pessoas);

        int vetor[pessoas];
        for (i = 0; i < pessoas; i++)
        {
            scanf("%d", &vetor[i]);
        }

        ordenaCrescente(vetor, pessoas);

        for (i = 0; i < pessoas; i++)
        {
            printf("%d ", vetor[i]);
        }

        printf("\n");
    }

    return 0;
}


void ordenaCrescente(int *vetor, int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (vetor[i] > vetor[j])
            {
                troca(&vetor[i], &vetor[j]);
            }
        }
    }
}

void troca(int *a, int *b)
{
    int aux = *a;
    *a = *b;
    *b = aux;
}