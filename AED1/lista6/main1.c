#include <stdio.h>
#include <stdlib.h>
#define CAPACIDADE_INICIAL_CONJUNTO 10

/**/

typedef struct tipoPersonalizado conjunto;

void imprimeElementosConjunto(conjunto *);
void verificaCapacidade(conjunto **);
void ordenaConjunto(conjunto *);

int criaConjunto(conjunto **);                  //  #1 ok
int conjuntoVazio(conjunto *);                  //  #2 ok
int insereElementoConjunto(int, conjunto **);   //  #3 ok
int excluiElementoConjunto(int, conjunto **);   //  #4 ok
int tamanhoConjunto(conjunto *);                //  #5 ok
int maior(int, conjunto *);                     //  #6 ok
int menor(int, conjunto *);                     //  #7 ok
int pertenceConjunto(int, conjunto *);          //  #8 ok
int conjuntosIdenticos(conjunto *, conjunto *); //  #9 ok

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
        return 1;
    }
    else
    {
        return 0;
    }
}

int conjuntoVazio(conjunto * pConjunto)
{
    return pConjunto->contagemElementos == 0 ? 1 : 0;
}

int insereElementoConjunto(int elemento, conjunto ** pConjunto)
{
    verificaCapacidade(pConjunto);
    if(pertenceConjunto(elemento, (*pConjunto))){
        return 0;
    } else {
        (*pConjunto)->elementos[(*pConjunto)->contagemElementos] = elemento;
        (*pConjunto)->contagemElementos++;
        ordenaConjunto((*pConjunto));
        return 1;
    }
}

void verificaCapacidade(conjunto ** pConjunto)
{
    if((*pConjunto)->contagemElementos == (*pConjunto)->capacidade)
    {
        (*pConjunto)->capacidade *= 2;
        (*pConjunto)->elementos = (int *) realloc((*pConjunto)->elementos, sizeof(int) * (*pConjunto)->capacidade);
    }
}

int pertenceConjunto(int elemento, conjunto * pConjunto)
{
    int i;
    for (i = 0; i < pConjunto->contagemElementos; i++)
    {
        if(pConjunto->elementos[i] == elemento){
            return 1;
        }
    }
    return 0;
}

void imprimeElementosConjunto(conjunto * pConjunto)
{
    int i;
    if (pConjunto->contagemElementos == 0)
    {
        printf("Conjunto vazio.\n");
    }
    else
    {
        printf("{");
        for (i = 0; i < pConjunto->contagemElementos; i++)
        {
            printf("%d", pConjunto->elementos[i]);
            printf("%s", i < pConjunto->contagemElementos - 1 ? ", " : "");
        }
        printf("}\n");
    }
}

int excluiElementoConjunto(int elemento, conjunto ** pConjunto)
{
    int i, indice;
    if(pertenceConjunto(elemento, (*pConjunto))){
        for (i = 0; i < (*pConjunto)->contagemElementos; i++)
        {
            if((*pConjunto)->elementos[i] == elemento){
                indice = i;
                break;
            }
        }

        for (i = indice; i < (*pConjunto)->contagemElementos - 1; i++){
            (*pConjunto)->elementos[i] = (*pConjunto)->elementos[i + 1];
        }

        (*pConjunto)->contagemElementos--;
    } else {
        printf("Solicitacao de exclusao sem sucesso. Elemento nao encontrado.\n");
        return 0;
    }
}

int tamanhoConjunto(conjunto * pConjunto)
{
    return pConjunto->contagemElementos;
}

int maior(int elemento, conjunto * pConjunto)
{
    int contador = 0, i;
    for (i = 0; i < pConjunto->contagemElementos; i++)
    {
        contador += pConjunto->elementos[i] > elemento ? 1 : 0;
    }
    return contador;
}

int menor(int elemento, conjunto *pConjunto)
{
    int contador = 0, i;
    for (i = 0; i < pConjunto->contagemElementos; i++)
    {
        contador += pConjunto->elementos[i] < elemento ? 1 : 0;
    }
    return contador;
}

void ordenaConjunto(conjunto * pConjunto)
{
    int i, j;
    for (i = 0; i < pConjunto->contagemElementos - 1; i++)
    {
        for (j = i; j < pConjunto->contagemElementos; j++)
        {
            if(pConjunto->elementos[i] > pConjunto->elementos[j]){
                int aux = pConjunto->elementos[i];
                pConjunto->elementos[i] = pConjunto->elementos[j];
                pConjunto->elementos[j] = aux;
            }
        }
    }
}

int conjuntosIdenticos(conjunto * pConjuntoA, conjunto * pConjuntoB)
{
    int i, qtdA = pConjuntoA->contagemElementos;
    if(qtdA == pConjuntoB->contagemElementos)
    {
        for (i = 0; i < qtdA; i++)
        {
            if(pConjuntoA->elementos[i] != pConjuntoB->elementos[i]){
                return 0;
            }
        }
        return 1;
    }
    else
    {
        return 0;
    }
}

/**/

int main()
{
    conjunto * conjuntoA;
    criaConjunto(&conjuntoA);

    conjunto *conjuntoB;
    criaConjunto(&conjuntoB);

    insereElementoConjunto(5, &conjuntoA);
    insereElementoConjunto(55, &conjuntoA);
    insereElementoConjunto(25, &conjuntoA);
    insereElementoConjunto(75, &conjuntoA);
    insereElementoConjunto(45, &conjuntoA);

    insereElementoConjunto(5, &conjuntoB);
    insereElementoConjunto(15, &conjuntoB);
    insereElementoConjunto(25, &conjuntoB);
    insereElementoConjunto(35, &conjuntoB);
    insereElementoConjunto(45, &conjuntoB);

    excluiElementoConjunto(55, &conjuntoA);
    excluiElementoConjunto(75, &conjuntoA);
    excluiElementoConjunto(15, &conjuntoB);
    excluiElementoConjunto(35, &conjuntoB);

    imprimeElementosConjunto(conjuntoA);
    imprimeElementosConjunto(conjuntoB);

    printf("%s\n", conjuntosIdenticos(conjuntoA, conjuntoB) ? "Os conjuntos sao identicos" : "Os conjuntos nao sao identicos");
}