#include<stdio.h>

void troca(int *a, int *b);
void ordena(int num[], int n);
void imprimePares(int num[], int n);
void imprimeImpares(int num[], int n);

int main(){
	int n, i;
	
	do {
		scanf("%d", &n);
	} while (n == 0 || n > 10000000);
	
	int num[n];
	
	for(i = 0; i < n; i++){
		scanf("%d", &num[i]);
		//printf("%d\n", num[i]);
	}	
	ordena(num, n);
	imprimePares(num, n);
	imprimeImpares(num, n);
}

void troca(int *a, int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

void ordena(int num[], int n){
	int i, j;
	for(i = 0; i < n - 1; i++){
		for(j = i + 1; j < n; j++){
			num[i] > num[j] ? troca(&num[i], &num[j]) : 1;
		}
	}	
}

void imprimePares(int num[], int n){
	int i;
	for(i = 0; i < n; i++){
		//printf("%d ", num[i]);
		num[i] % 2 == 0 ? printf("%d\n", num[i]) : 1;
	}
}

void imprimeImpares(int num[], int n){
	int i;
	for(i = n - 1; i >= 0; i--){
		num[i] % 2 != 0 ? printf("%d\n", num[i]) : 1;
	}
}