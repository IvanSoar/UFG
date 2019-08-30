#include<stdio.h>
#define T 9


void troca(int *a, int *b);
void ordena(int *vet);
int somaExcludente(int a, int b, int *vet);
void imprimeExcludente(int a, int b, int *vet);

int main(){
	int i, j, k, n;
	int noveAnoes[T];
	int flag;
	
	k = flag = 0;
	
	scanf("%d", &n);
	while(k < n){
		for(i = 0; i < T; i++){
			scanf("%d", &noveAnoes[i]);
		}
		
		ordena(noveAnoes);
		
		for(i = 0; i < T - 1; i++){
			if(flag == 0){
				for(j = i + 1; j < T; j++){
					if(somaExcludente(i, j, noveAnoes) == 100){
						flag = 1;
						imprimeExcludente(i, j, noveAnoes);
						break;				
					}
				}
			} else {
				break;
			}
		}
		k++;		
		flag = 0;
	}
}

int somaExcludente(int a, int b, int *vet){
	int i, soma = 0;
	for(i = 0; i < T; i++){
		soma += i == a || i == b ? 0 : vet[i];
	}
	return soma;
}

void imprimeExcludente(int a, int b, int *vet){
	int i;
	for(i = 0; i < T; i++){
		i == a || i == b ? 1 : printf("%d\n", vet[i]);
	}
}


void troca(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void ordena(int *vet){
	int i, j;
	for(i = 0; i < T - 1; i++){
		for(j = i + 1; j < T; j++){
			vet[i] > vet[j] ? troca(&vet[i], &vet[j]) : 1;
		}
	}
}







