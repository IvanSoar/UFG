#include<stdio.h>
#include<stdlib.h>

int entradaValidada(int min, int max);
double ** retornaMatrizZerada(int altura, int largura);
void populaMatriz(double ** matriz, int ordem);
void multiplicaMatrizes(double ** matriz1, double ** matriz2, double ** matrizProduto, int ordem);
void imprimeMatriz(double ** matriz, int ordem);

int main(){
	int ordem = entradaValidada(1, 10);
	int i, potencia;
	double ** matrizInicial = retornaMatrizZerada(ordem, ordem);
	double ** matrizResultado = retornaMatrizZerada(ordem, ordem);
	
	scanf("%d", &potencia);
	
	populaMatriz(matrizInicial, ordem);
	
	multiplicaMatrizes(matrizInicial, multiplicaMatrizes(matrizInicial, matrizInicial, ordem), matrizResultado, ordem);
	
	imprimeMatriz(matrizResultado, ordem);
}

int entradaValidada(int min, int max){
	int valor;
	scanf("%d", &valor);
	if(valor < min || valor > max){
		exit(1);
	} else {
		return valor;
	}
}

double ** retornaMatrizZerada(int altura, int largura){
	int i, j;
	double ** matriz = (double **) malloc(altura * sizeof(double *));
	
	if(!matriz){
		exit(1);
	}
	
	matriz[0] = (double *) malloc(altura * largura * sizeof(double));
	
	if(!matriz[0]){
		free(matriz);
		exit(1);
	}
	
	for(i = 1; i < altura; i++){
		matriz[i] = matriz[i - 1] + largura;
	}
	
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			matriz[i][j] = 0.0;
		}
	}
	
	return matriz;
}

void populaMatriz(double ** matriz, int ordem){
	int i, j, buffer;
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			scanf("%d", &buffer);
			matriz[i][j] = (double)buffer;
		}
	}
}

void multiplicaMatrizes(double ** matriz1, double ** matriz2, double ** matrizProduto, int ordem){
	int i, j, k;
	double soma = 0;
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			for(k = 0; k < ordem; k++){
				soma += matriz1[i][k] * matriz2[k][j];
			}
			matrizProduto[i][j] *= soma;
		}
	}
}

void imprimeMatriz(double ** matriz, int ordem){
	int i, j;
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			printf("%.3lf ", matriz[i][j]);
		}
		printf("\n");
	}
}