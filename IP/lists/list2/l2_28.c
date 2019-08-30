#include <stdio.h>

int leValTam();
int elementoValido(int k);
void populaVetor(int *vet, int tam);
void imprimeIntercalado(int *vet1, int *vet2, int vt1, int vt2);
void troca(int *a, int *b);
void ordena(int *vet, int t);

int main(){
	int n1 = leValTam();
    int n2 = leValTam();
	
	int v1[n1];
    int v2[n2];
	
	populaVetor(v1, n1);
    populaVetor(v2, n2);
	
	imprimeIntercalado(v1, v2, n1, n2);
}

 
int leValTam(){
    int t;    
    do {
        scanf("%d", &t);
    } while(t <= 0 || t > 500000);
    return t;
}

int elementoValido(int k){
	int flag = k >= 0 && k <= 999999 ? 1 : 0;
    return flag;
}

void populaVetor(int *vet, int tam){
    int i;
    for(i = 0; i < tam; i++){
        do {
            scanf("%d", &vet[i]);			
        } while (!elementoValido(vet[i]));
    }
}

void imprimeIntercalado(int *vet1, int *vet2, int vt1, int vt2){
	int i, j, t = vt1 + vt2;
	int vetOrd[t];
	
	for(i = 0; i < t; i++){
		i < vt1 ? vetOrd[i] = vet1[i] : 1;
		i >= vt1 ? vetOrd[i] = vet2[i - vt1] : 1;
	}
	
	ordena(vetOrd, t);
	
	for(i = 0; i < t; i++){
		printf("%d\n", vetOrd[i]);
	}
}

void troca(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void ordena(int *vet, int t){
	int i, j;
	for(i = 0; i < t - 1; i++){
		for(j = i + 1; j < t; j++){
			vet[i] > vet[j] ? troca(&vet[i], &vet[j]) : 1;
		}
	}
}