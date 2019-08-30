#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct pontos4D {
    double u, x, y, z;
    double norma;
} pontos;

void troca(pontos * a, pontos * b);
void ordenaVetorPontos(pontos * vetor, int tam);

int main(){
    int i, j;
    int numPontos;

    scanf("%d", &numPontos);
    pontos vetorPontos[numPontos];
    for(i = 0; i < numPontos; i++){
        scanf("%lf %lf %lf %lf", &vetorPontos[i].u, &vetorPontos[i].x, &vetorPontos[i].y, &vetorPontos[i].z);
        vetorPontos[i].norma = sqrt(pow(vetorPontos[i].u, 2) + pow(vetorPontos[i].x, 2) + pow(vetorPontos[i].y, 2) + pow(vetorPontos[i].z, 2));
    }

    ordenaVetorPontos(vetorPontos, numPontos);

    for(i = 0; i < numPontos; i++){
        printf("Vetor: (%.2lf, %.2lf, %.2lf, %.2lf) Norma: %.2lf\n", vetorPontos[i].u, vetorPontos[i].x, vetorPontos[i].y, vetorPontos[i].z, vetorPontos[i].norma);
    }
    return 0;
}

void troca(pontos * a, pontos * b){
    pontos aux;
    aux = * a;
    * a = * b;
    * b = aux;
}

void ordenaVetorPontos(pontos * vetor, int tam){
    int i, j;
    for(i = 0; i < tam - 1; i++){
        for(j = i + 1; j < tam; j++){
            if(vetor[i].norma > vetor[j].norma){
                troca(&vetor[i], &vetor[j]);
            }
        }
    }
}