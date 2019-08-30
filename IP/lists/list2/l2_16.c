#include <stdio.h>
#include <math.h>

int leValTam(int min, int max);
int processa(int *vet, int tam);
void imprime(int cont, int *vetor, int n, int k);

int main(){
	int i, cont;
	
	int n = leValTam(-1, 1001);
	int k = leValTam(-1, 1001);
	
	int vetor[n];
	
	imprime(processa(vetor, n), vetor, n, k);
}

int leValTam(int min, int max){
    int t;    
    do {
        scanf("%d", &t);
    } while(t < min || t > max);
    return t;
}

int processa(int *vetor, int tam){
    int i, cont = 0;
    for(i = 0; i < tam; i++){
		scanf("%d", &vetor[i]);
		cont += vetor[i] <= 0 ? 1 : 0;
	}
	return cont;
}

void imprime(int cont, int *vetor, int n, int k){
	int i;
	if(cont >= k){
		printf("NAO\n");
		
		for(i = n - 1; i >= 0; i--){
			vetor[i] < 0 ? printf("%d\n", i + 1):1;
		}
		
	} else {
		printf("SIM\n");
	}
}