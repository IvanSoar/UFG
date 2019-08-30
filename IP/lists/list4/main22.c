#include<stdio.h>
#include<stdlib.h>
#define ordem 9
#define regiao 3

int entradavalida(int min, int max);
int ** retornaMatrizZerada(int altura, int largura);
void popula(int ** matriz, int altura, int largura);
int verificaRegioes(int ** matriz);
int verificaColunas(int ** matriz);
int verificaLinhas(int ** matriz);

int main(){
	int i, j;
	int ** matriz = retornaMatrizZerada(ordem, ordem);

	popula(matriz, ordem, ordem);

	if(verificaRegioes(matriz) && verificaColunas(matriz) && verificaLinhas(matriz)){
		printf("valido");
	} else {
		printf("invalido");
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
int entradavalida(int min, int max){
	int valor;
	scanf("%d", &valor);
	if(valor < min || valor > max){
		exit(1);
	} else {
		return valor;
	}
}
void popula(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			matriz[i][j] = entradavalida(1, 9);
		}
	}
}
int verificaRegioes(int ** matriz){
	int i, j, k, l, m;
	for(i = 0; i < ordem; i += regiao){
		for(j = 0; j < ordem; j += regiao){
			for(k = 0; k < regiao; k++){
				for(l = 0; l < regiao - 1; l++){
					for(m = l + 1; m < regiao; m++){
						if(matriz[k][m] == matriz[k][l]){
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}
int verificaColunas(int ** matriz){
	int i, j, k;
	for(i = 0; i < ordem;i++){
		for(j = 0; j < ordem - 1; j++){
			for(k = j + 1; k < ordem; k++){
				if(matriz[k][i] == matriz[j][i]){
					return 0;
				}
			}
		}
	}
	return 1;
}
int verificaLinhas(int ** matriz){
	int i, j, k;
	for(i = 0; i < ordem;i++){
		for(j = 0; j < ordem - 1; j++){
			for(k = j + 1; k < ordem; k++){
				if(matriz[i][k] == matriz[i][j]){
					return 0;
				}
			}
		}
	}
	return 1;
}