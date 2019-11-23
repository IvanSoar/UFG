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
int subconjunto(conjunto *, conjunto *);        // #10 ok
conjunto *complemento(conjunto *, conjunto *);  // #11 ok
conjunto *uniao(conjunto *, conjunto *);        // #12 ok
conjunto *interseccao(conjunto *, conjunto *);  // #13 

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

int subconjunto(conjunto * pConjuntoA, conjunto * pConjuntoB)
{
    if(pConjuntoA->contagemElementos <= pConjuntoB->contagemElementos)
    {
        int i;
        for (i = 0; i < pConjuntoA->contagemElementos; i++)
        {
            if(!pertenceConjunto(pConjuntoA->elementos[i], pConjuntoB))
            {
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

conjunto *complemento(conjunto *pConjuntoA, conjunto *pConjuntoB)
{
    conjunto *conjuntoComplemento;
    criaConjunto(&conjuntoComplemento);
    int i;
    for (i = 0; i < pConjuntoB->contagemElementos; i++)
    {
        if(!pertenceConjunto(pConjuntoB->elementos[i], pConjuntoA))
        {
            insereElementoConjunto(pConjuntoB->elementos[i], &conjuntoComplemento);
        }
    }
    return conjuntoComplemento;
}

conjunto *uniao(conjunto *pConjuntoA, conjunto *pConjuntoB)
{
    conjunto *conjuntoUniao;
    criaConjunto(&conjuntoUniao);

    int i, j;
    for (i = 0, j = 0; i < pConjuntoA->contagemElementos, j < pConjuntoB->contagemElementos; i++, j++)
    {
        insereElementoConjunto(pConjuntoA->elementos[i], &conjuntoUniao);
        insereElementoConjunto(pConjuntoB->elementos[j], &conjuntoUniao);
    }
    return conjuntoUniao;
}

conjunto *interseccao(conjunto *pConjuntoA, conjunto *pConjuntoB)
{
    
}

/**/

int main()
{
    conjunto * conjuntoA;
    criaConjunto(&conjuntoA);

    conjunto *conjuntoB;
    criaConjunto(&conjuntoB);

    insereElementoConjunto(1, &conjuntoA);
    insereElementoConjunto(2, &conjuntoA);
    
    insereElementoConjunto(2, &conjuntoB);
    insereElementoConjunto(3, &conjuntoB);

    imprimeElementosConjunto(conjuntoA);
    imprimeElementosConjunto(conjuntoB);

    conjunto * complementoAB = complemento(conjuntoA, conjuntoB);
    conjunto * uniaoAB = uniao(conjuntoA, conjuntoB);

    imprimeElementosConjunto(complementoAB);
    imprimeElementosConjunto(uniaoAB);

    printf("%s\n", subconjunto(conjuntoA, conjuntoB) ? "O conjunto A e subconjunto do B" : "O conjunto A nao e subconjunto do B");
    printf("%s\n", conjuntosIdenticos(conjuntoA, conjuntoB) ? "Os conjuntos sao identicos" : "Os conjuntos nao sao identicos");
}