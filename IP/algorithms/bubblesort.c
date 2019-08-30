//
//  bubblesort.c
//  
//
//  Created by Thierson Couto Rosa on 24/04/18.
//
//

#include <stdio.h>
//Declaracao dos prototipos das funcoes

void troca(int *p, int*q);
void bubblesort(int *vet, int n);
void selectionsort(int* vet, int n);
void imprimeVet(int vet[], int n);


int main(){
	int v[6], i;
	for (i=0; i<6; i++) {
    scanf("%d", &v[i]);
	}
	imprimeVet(v,6);
	//bubblesort(v,6);
	selectionsort(v,6);
	imprimeVet(v,6);
	return(0);
}
void troca(int *p, int*q){
	int aux;
	aux=*p;
	*p=*q;
	*q=aux;
}
void bubblesort(int *vet, int n){
	int i,j,trocou;
	for (j=0; j<n; j++) {
    trocou=0;
		for(i=0;i<n-1;i++){
			if (vet[i]>vet[i+1]) {
				troca(&vet[i], &vet[i+1]);
				trocou=1;
			}
		}
		if (!trocou) {
			break;
		}
	}
}
void selectionsort(int* vet, int n){
	int i,j,menor, ind_menor;
	for (j=0; j<n-1; j++) {
    menor=vet[j];
		ind_menor=j;
		for (i=j+1; i<n; i++) {
			if(vet[i]<menor){
				menor=vet[i];
				ind_menor=i;
			}
		}
		troca(&vet[j], &vet[ind_menor]);
	}
}

void imprimeVet(int vet[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", vet[i]);
	}
	printf("\n");
}
