#ifndef TADS_1_H
#define TADS_1_H

typedef struct conjunto Conjunto;
int criaConjunto(Conjunto*);
int conjuntoVazio(Conjunto*);
int insereElementoConjunto(int, Conjunto*);
void imprimeElementos(Conjunto*);

#endif