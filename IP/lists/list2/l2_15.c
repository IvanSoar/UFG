#include <stdio.h>
 
int leValTam(int min, int max);
void populaVetor(int *vet, int tam);
void menorIntervalo(int *vetor, int n);
 
int main(){
    int  i, n = leValTam(1, 10);
	
	for(i = 0; i < n; i++){
		int t = leValTam(2, 1000), vet[t];
		populaVetor(vet, t);
		menorIntervalo(vet, t);
	}
}
 
void menorIntervalo(int *vetor, int n){
    int i, j, iter, dist, menorDist;
	iter = 0;
    for(i = 0; i < n - 1; i++){
        for (j = i + 1; j < n; j++){
            dist = vetor[i] - vetor[j];
            dist = dist < 0 ? dist * (-1) : dist;
			
			j == 1 ? menorDist = dist : 1;
            menorDist = dist < menorDist ? dist : menorDist;
			iter++;
        }
    }
    printf("%d %d\n", menorDist, iter);
}

int leValTam(int min, int max){
    int t;    
    do {
        scanf("%d", &t);
    } while(t < min || t > max);
    return t;
}

void populaVetor(int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
		vet[i] = leValTam(-1001, 1001);
	}
}