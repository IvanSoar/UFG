#include<stdio.h>
#include<stdlib.h>

int ** criaMatriz(int qtdLinhas, int qtdColunas);
void populaMatriz(int ** matriz, int largura, int altura);
void imprimeMatriz(int ** matriz, int largura, int altura);
int somaDiagonal(int ** matriz, int ordem);
void operaMatriz(int ** matriz1, int ** matriz2, int valor, int largura, int altura);

int main(){
	int** matriz, matrizModificada;
	int ordem, traco;
	
	scanf("%d", &ordem);
	
	matriz = criaMatriz(ordem, ordem);
	populaMatriz(matriz, ordem, ordem);
	traco = somaDiagonal(matriz, ordem);
	
	matrizModificada = criaMatriz(ordem, ordem);	
	operaMatriz(matriz, matrizModificada, traco, ordem, ordem);
	
	imprimeMatriz(matrizModificada, ordem, ordem);
}

int ** criaMatriz(int qtdLinhas, int qtdColunas){
    int ** matriz = (int **) malloc(qtdLinhas * sizeof(int *));
	int i, j;
    if(!matriz){
		//verifica se o vetor foi criado com sucesso.
        return 0;
    } else {    
		for(i = 0; i < qtdLinhas; i++){
			matriz[i] = (int *) malloc(qtdColunas * sizeof(int));
			if(!matriz[i]){
				//verifica se houve falha na criaçao do vetor.
				for(j = 0; j < i; j++){
					//libera a memória dos vetores criados anteriormente.
					free(matriz[j]);
				}
				//libera a memória do vetor de vetores.
				free(matriz);
				return 0;
			} else {
				for(j = 0; j < qtdColunas; j++){
					matriz[i][j] = 0;
				}
			}
		}    
    return matriz;
    }
}

void populaMatriz(int ** matriz, int largura, int altura){
	int i, j;
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

void imprimeMatriz(int ** matriz, int largura, int altura){
	int i, j;
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

int somaDiagonal(int ** matriz, int ordem){
	int i, j, soma = 0;
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			soma += i == j ? matriz[i][j] : 0;
		}
	}
	return soma;
}

void operaMatriz(int ** matriz1, int ** matriz2, int valor, int largura, int altura){
	int i, j;
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			matriz2[i][j] = (valor * matriz1[i][j]) + matriz1[j][i];
		}
	}
}


















