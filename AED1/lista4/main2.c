#include<stdio.h>

int contaPares(int *, int);
int contaImpares(int *, int);
void separaParesImpares(int*, int, int*, int*);
void ordenaCrescente(int *, int);
void ordenaDecrescente(int *, int);
void troca(int *, int *);

int main(int argc, char const *argv[])
{
    int quantidade, i;

    scanf("%d", &quantidade);

    int fila[quantidade];
    for (i = 0; i < quantidade; i++)
    {
        scanf("%d", &fila[i]);
    }

    int qtdPares = contaPares(fila, quantidade);
    int qtdImpares = contaImpares(fila, quantidade);
    int pares[qtdPares], impares[qtdImpares];

    separaParesImpares(fila, quantidade, pares, impares);
    ordenaCrescente(pares, qtdPares);
    ordenaDecrescente(impares, qtdImpares);

    for (i = 0; i < qtdPares; i++)
    {
        printf("%d ", pares[i]);
    }

    if(qtdPares > 0 && qtdImpares > 0)
    {
        printf("\n");
    }

    for (i = 0; i < qtdImpares; i++)
    {
        printf("%d ", impares[i]);
    }

    return 0;
}

int contaPares(int * vetor, int tam)
{
    int contador = 0, i;
    for (i = 0; i < tam; i++)
    {
        if(vetor[i] % 2 == 0)
        {
            contador++;
        }
    }
    return contador;
}

int contaImpares(int * vetor, int tam)
{
    int contador = 0;
    int i;
    for (i = 0; i < tam; i++)
    {
        if (vetor[i] % 2 == 1)
        {
            contador++;
        }
    }
    return contador;
}

void separaParesImpares(int * vetor, int tam, int * pares, int * impares)
{
    int i = 0, j = 0, k = 0;

    for (i = 0; i < tam; i++)
    {
        if(vetor[i] % 2 == 0)
        {
            pares[j] = vetor[i];
            j++;
        }
        else
        {
            impares[k] = vetor[i];
            k++;
        }
    }
}

void ordenaCrescente(int * vetor, int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if(vetor[i] > vetor[j]){
                troca(&vetor[i], &vetor[j]);
            }
        }       
    }   
}

void ordenaDecrescente(int * vetor, int tamanho)
{
    int i, j;
    for (i = 0; i < tamanho - 1; i++)
    {
        for (j = i + 1; j < tamanho; j++)
        {
            if (vetor[i] < vetor[j])
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