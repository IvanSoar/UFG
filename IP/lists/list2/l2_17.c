#include<stdio.h>

int contaUnicos(int vet[], int t);

int main(){
	int n, i, vetor[5000];
	
	scanf("%d", &n);
	
	for (i = 0; i < n; i++){
		scanf("%d", &vetor[i]);
	}
	
	printf("%d\n", contaUnicos(vetor, n));
}

int contaUnicos(int vet[], int t){
	int i, j, repetiu, cont = 0;
	
	for(i = 0; i < t; i++){
		for(j = 0; j < t; j++){
			repetiu = vet[i] == vet[j] && i != j ? 1 : 0;			
			if(repetiu){break;}
		}
		cont += repetiu ? 0 : 1;
	}	
	return cont;
}