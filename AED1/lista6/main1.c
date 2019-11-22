#include<stdio.h>
#include<stdlib.h>

typedef struct conjunto Conjunto;
int criaConjunto(Conjunto *);
int conjuntoVazio(Conjunto *);
int insereElementoConjunto(int, Conjunto *);
void imprimeElementos(Conjunto *);

struct conjunto
{
    int *dadosConjunto;
    int contagemElementos;
    int TAMANHO_MAX_CONJUNTO;
};

int criaConjunto(Conjunto ** conj)
{
    *conj = (Conjunto *)malloc(sizeof(Conjunto));
    conj->contagemElementos = 0;
    conj->TAMANHO_MAX_CONJUNTO = 10;
    conj->dadosConjunto = (int *) malloc(sizeof(int) * conj->TAMANHO_MAX_CONJUNTO);
    printf("Cria Conjunto: %p\n", conj);
    return conj != NULL ? 1 : 0;
}

int conjuntoVazio(Conjunto *conj)
{
    printf("Conjunto Vazio: %p\n", conj);
    return conj->contagemElementos == 0 ? 1 : 0;
}

int insereElementoConjunto(int elemento, Conjunto *conj)
{
    if(conj->contagemElementos == conj->TAMANHO_MAX_CONJUNTO)
    {
        conj->dadosConjunto = (int *)realloc(conj->dadosConjunto, sizeof(int) * (conj->TAMANHO_MAX_CONJUNTO * 2));
    }

    conj->dadosConjunto[conj->contagemElementos] = elemento;
    conj->contagemElementos++;
    printf("Insere Elemento: %p\n", conj);
    return 1;
}

void imprimeElementos(Conjunto *conj)
{
    printf("Imprime Elementos: %p\n", conj);
    int i;
    printf("{");
    for (i = 0; i < conj->contagemElementos; i++)
    {
        printf("%d", conj->dadosConjunto[i]);
        if (i < conj->contagemElementos - 1)
        {
            printf(", ");
        }
    }
    printf("}\n");
}

int main(){
    Conjunto * C = NULL;

    if(criaConjunto(&C)){
        printf("Conjunto criado com endereço: %p\n", &C);
    } else {
        printf("Não foi possível a crição do conjunto solicitado!\n");
    }
 
    insereElementoConjunto(10, C);
 
    if(conjuntoVazio(C)){
        printf("O Conjunto esta vazio!\n");
    } else {
        printf("O Conjunto não esta vazio!\n");
    }
 
    imprimeElementos(C);
}