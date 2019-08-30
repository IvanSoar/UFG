#include<stdio.h>

int leValTam();
int elementoValido(int *vet, int ind);
void populaVetor(int *vet, int tam);
void imprimeUniao(int *vet1, int *vet2 , int tam1, int tam2);
void imprimeInter(int *vet1, int *vet2 , int tam1, int tam2);

int main(){
	int tamA = leValTam();
	int tamB = leValTam();
	
	int A[tamA];
	int B[tamB];

	populaVetor(A, tamA);
	populaVetor(B, tamB);
	
	imprimeUniao(A, B, tamA, tamB);
	imprimeInter(A, B, tamA, tamB);
}

int leValTam(){
	int t;	
	do {
		scanf("%d", &t);
	} while(t < 1 || t > 100);	
	return t;
}

int elementoValido(int *vet, int ind){
	int i, flag = 1;
	if(ind > 0){
		for(i = 0; i < ind; i++){
			flag = vet[ind] == vet[ind - 1] ? 0 : flag;
			if(flag == 0){
				break;
			}
		}
	} else {
		flag = 1;
	}
	return flag;
}

void populaVetor(int *vet, int tam){
	int i;
	for(i = 0; i < tam; i++){
		do {
			scanf("%d", &vet[i]);
		} while (!elementoValido(vet, i));
	}
}

void imprimeUniao(int *vet1, int *vet2 , int tam1, int tam2){
	int i, j, flag = 1;
	
	printf("(");	
	for(i = 0; i < tam1; i++){
		printf("%d", vet1[i]);
		tam1 > 0 && i != tam1 - 1 ? printf(",") : 1;
	}	
	for(i = 0; i < tam2; i++){
		for(j = 0; j < tam1; j++){
			flag = vet2[i] == vet1[j] ? 0 : flag;
		}
		printf(",");
		flag == 1 ? printf("%d", vet2[i]) : 1;
		flag = 1;
	}	
	printf(")");
	printf("\n");
}

void imprimeInter(int *vet1, int *vet2 , int tam1, int tam2){
	int i, j, flag = 0;	
	printf("(");	
	for(i = 0; i < tam2; i++){
		for(j = 0; j < tam1; j++){
			if(vet1[j] == vet2[i]){
				flag == 1 ? printf(",") : 1;
				printf("%d", vet1[j]);
				flag = 1;
			}
		}
	}	
	printf(")");
	printf("\n");
}