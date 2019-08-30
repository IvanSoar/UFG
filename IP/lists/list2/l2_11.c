#include <stdio.h>

int leValTam();
void populaVetor(int *vet, int tam);
void imprimeNormal(int *vet, int t);
void imprimeInvertido(int *vet, int t);

int menor = 999999;
int maior = -999999; 

int main() {
    int i;
    int n = leValTam();
	int vet[n];
	
	populaVetor(vet, n);
	
    imprimeNormal(vet, n);
    imprimeInvertido(vet, n);
	
    printf("%d\n", maior);
    printf("%d\n", menor);  
} 

int leValTam(){
    int t;    
    do {
        scanf("%d", &t);
    } while(t <= 1 || t > 1000);
    return t;
}

void populaVetor(int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
		scanf("%d", &vet[i]);
		maior = vet[i] >= maior ? vet[i] : maior;
		menor = vet[i] <= menor ? vet[i] : menor;
    }
}
 
void imprimeNormal(int *vet, int t){
    int i;
    for(i = 0; i < t; i++){
        printf("%d", vet[i]);
		i < t - 1 ? printf(" ") : 1;
    }
    printf("\n");
}

void imprimeInvertido(int *vet, int t){
    int i;
    for(i = t - 1; i  >= 0 ; i--){
        printf("%d", vet[i]);
		i > 0 ? printf(" ") : 1;
    }
    printf("\n");
}