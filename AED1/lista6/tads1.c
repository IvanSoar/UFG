#include <stdlib.h>
#include <stdio.h>
#include "tads1.h"

struct conjunto {
    char nomeConjunto;
    int * dadosConjunto;
    int contagemElementos;
};
 
int criaConjunto(Conjunto * conj){
    conj = (Conjunto*) malloc(sizeof(Conjunto));
    conj->contagemElementos = 0;
    conj->dadosConjunto = (int*) malloc(1);
    return conj != NULL ? 1 : 0;
}
 
int conjuntoVazio(Conjunto* conj){
    return conj->contagemElementos == 0 ? 1 : 0;
}
 
int insereElementoConjunto(int elemento, Conjunto* conj){
    conj->dadosConjunto = (int*) realloc(conj->dadosConjunto, sizeof(int) * (conj->contagemElementos + 1));
    conj->dadosConjunto[conj->contagemElementos] = elemento;
    conj->contagemElementos++;
    return 1;
}
 
void imprimeElementos(Conjunto * conj){
    int i;
    printf("{");
    for(i = 0; i < conj->contagemElementos; i++){
        printf("%d", conj->dadosConjunto[i]);
        if(i < conj->contagemElementos - 1){
            printf(", ");
        }
    }
    printf("}\n");
}