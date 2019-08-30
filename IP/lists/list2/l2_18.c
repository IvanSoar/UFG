#include<stdio.h>
#define T 11

int prod();
void verifica(int vet[]);

int main(){
	int n, i, j, cpf[T];
	
	scanf("%d", &n);
	
	for(i = 0; i < n; i++){
		for(j = 0; j < T; j++){
			scanf("%d", &cpf[j]);
		}		
		verifica(cpf);
	}	
}

int prod(){}
void verifica(int vet[]){
	int i, b1 = 0, b2 = 0;
	
	for(i = 0; i < 9; i++){
		b1 += vet[i] * (i + 1);
		//printf("%d * %d = %d - %d\n", vet[i], i + 1, vet[i] * (i + 1), b1);
	}
	
	for(i = 0; i < 9; i++){
		b2 += vet[i] * (9 - i);
		//printf("%d, %d\n", i, 9 - i);
	}
	
	b1 %= 11;
	b2 %= 11;
	
	//printf("%d, %d\n", b1, b2);
	b1 == vet[9] && b2 == vet[10] ? printf("CPF valido\n") : printf("CPF invalido\n");
}