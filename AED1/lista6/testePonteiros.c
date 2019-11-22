#include <stdio.h>
#include <stdlib.h>
#define CAPACIDADE_INICIAL_CONJUNTO 10

/**/

typedef struct tipoPersonalizado conjunto;
int criaConjunto(conjunto **);
int conjuntoVazio(conjunto *);
int insereElementoConjunto(int, conjunto **);
int verificaCapacidade(conjunto **);
int pertenceConjunto(int , conjunto *);
void imprimeElementosConjunto(conjunto *);

/**/

typedef struct tipoPersonalizado
{
    int *elementos;
    int contagemElementos;
    int capacidade;
} conjunto;

int criaConjunto(conjunto ** pConjunto)
{
    (*pConjunto) = (conjunto *)malloc(sizeof(conjunto) * CAPACIDADE_INICIAL_CONJUNTO);
    if ((*pConjunto))
    {
        (*pConjunto)->contagemElementos = 0;
        (*pConjunto)->capacidade = CAPACIDADE_INICIAL_CONJUNTO;
        (*pConjunto)->elementos = (int *)malloc(sizeof(int) * (*pConjunto)->capacidade);
        printf("%p\n", (*pConjunto));
        return 1;
    }
    else
    {
        return 0;
    }
}

int conjuntoVazio(conjunto * pConjunto){
    return pConjunto->contagemElementos == 0 ? 1 : 0;
}

int insereElementoConjunto(int elemento, conjunto ** pConjunto){
    verificaCapacidade(pConjunto);
    if(pertenceConjunto(elemento, *pConjunto)){
        return 0;
    } else {
        (*pConjunto)->elementos[(*pConjunto)->contagemElementos] = elemento;
        (*pConjunto)->contagemElementos++;
        return 1;
    }
}

int verificaCapacidade(conjunto ** pConjunto){
    return 1;
}

int pertenceConjunto(int elemento, conjunto * pConjunto){
    return 0;
}

void imprimeElementosConjunto(conjunto * pConjunto){
    int i;
    printf("{ ");
    for (i = 0; i < pConjunto->contagemElementos; i++)
    {
        printf("%d", pConjunto->elementos[i]);
        printf("%s", i < pConjunto->contagemElementos - 1 ? ", " : "");
    }
    printf(" }");
}

/**/

int main()
{
    conjunto * estrutura;
    criaConjunto(&estrutura);

    printf("%p\n", estrutura);

    insereElementoConjunto(5, &estrutura);
    insereElementoConjunto(10, &estrutura);
    insereElementoConjunto(15, &estrutura);
    insereElementoConjunto(16, &estrutura);

    if(conjuntoVazio(estrutura)){
        printf("Conjunto vazio.\n");
    } else {
        printf("Conjunto nao vazio.\n");
        imprimeElementosConjunto(estrutura);
    }
}