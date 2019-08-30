#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void coverteIntEmVet(int numero, int t, int *vet);
int maiorNoIntervalo(int *num, int a, int b, int c);

int main(){
	int n, m, i, numero;
	
	scanf("%d %d", &n, &m);
	while(n * m != 0){			
		scanf("%d", &numero);			
		
		int k = 0;
		int num[n];
		
		coverteIntEmVet(numero, n, num);			
		
		for(i = 0; i < m; i++){
			k = maiorNoIntervalo(num, k, (n - m), i);
		}
		printf("\n");
		scanf("%d %d", &n, &m);
	}
}

void coverteIntEmVet(int numero, int t, int *vet){
	int i;
	char * str;
	sprintf(str, "%d", numero);	
	for(i = 0; i < t; i++){
		vet[i] = str[i] - '0';
	}
}

int maiorNoIntervalo(int *num, int a, int b, int c){
	int i, indMaior, maior = 0;
	for(i = a; i <= b + c; i++){
		if(num[i] >= maior){
			maior = num[i];
			indMaior = i;
		}
	}
	printf("%d", maior);	
	return indMaior + 1;
}