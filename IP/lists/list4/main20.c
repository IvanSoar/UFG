#include<stdio.h>
#include<stdlib.h>

int entradavalida(int min, int max);
int ** retornaMatrizZerada(int altura, int largura);
void popula(int ** matriz, int altura, int largura);
int * procuraMenor(int ** matriz, int altura, int largura);
int * procuraMaior(int ** matriz, int altura, int largura);
void troca(int * a, int * b);
void imprime(int ** matriz, int altura, int largura);

int main(){
	int altura = entradavalida(2, 1000);
	int largura = entradavalida(2, 1000);
	int ** matriz = retornaMatrizZerada(altura, largura);
	
	popula(matriz, altura, largura);
	
	int * coordMenor = procuraMenor(matriz, altura, largura);
	int * coordMaior = procuraMaior(matriz, altura, largura);
	
	troca(&matriz[coordMenor[0]][coordMenor[1]], &matriz[coordMaior[0]][coordMaior[1]]);
	
	imprime(matriz, altura, largura);
}

int entradavalida(int min, int max){
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

void popula(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

int * procuraMenor(int ** matriz, int altura, int largura){
	int i, j;
	int menor = matriz[0][0];
	int * coords = (int *) malloc(2 * sizeof(int));
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			if(matriz[i][j] < menor){
				menor = matriz[i][j];
				coords[0] = i;
				coords[1] = j;
			}			
		}
	}
	return coords;
}

int * procuraMaior(int ** matriz, int altura, int largura){
	int i, j;
	int maior = matriz[0][0];
	int * coords = (int *) malloc(2 * sizeof(int));
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			if(matriz[i][j] > maior){
				maior = matriz[i][j];
				coords[0] = i;
				coords[1] = j;
			}			
		}
	}
	return coords;
}

void troca(int * a, int * b){
	int aux = * a;
	* a = * b;
	* b = aux;
}

void imprime(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}