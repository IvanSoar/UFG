#include<stdio.h>
#include<stdlib.h>

int entradaValidada(int min, int max);
int ** retornaMatrizZerada(int altura, int largura);
void populaMatriz(int ** matriz, int altura, int largura);
void troca(int * a, int * b);
void ordenaColunas(int ** matriz, int altura, int largura);
void imprimeMatriz(int ** matriz, int altura, int largura);

int main(){
	int ordem = entradaValidada(2, 1000);
	int ** matriz = retornaMatrizZerada(ordem, ordem);
	
	populaMatriz(matriz, ordem, ordem);
	
	ordenaColunas(matriz, ordem, ordem);
	
	imprimeMatriz(matriz, ordem, ordem);
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

int ** retornaMatrizZerada(int altura, int largura){
	int i, j;
	int ** matriz = (int **) malloc(altura * sizeof(int *));
	
	if(!matriz){
		exit(1);
	}
	
	matriz[0] = (int *) malloc(altura * largura * sizeof(int));
	
	if(!matriz[0]){
		free(matriz);
		exit(1);
	}
	
	for(i = 1; i < altura; i++){
		matriz[i] = matriz[i - 1] + largura;
	}
	
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			matriz[i][j] = 0;
		}
	}
	
	return matriz;
}

void populaMatriz(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

void troca(int * a, int * b){
	int aux = * a;
	* a = * b;
	*b = aux;
}

void ordenaColunas(int ** matriz, int altura, int largura){
	int i, j, k;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura - 1; j++){
			for(k = j + 1; k < largura; k++){
				if(matriz[j][i] > matriz[k][i]){
					troca(&matriz[j][i], &matriz[k][i]);
				}
			}
		}
	}
}

void imprimeMatriz(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}



