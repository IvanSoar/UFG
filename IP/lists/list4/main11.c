#include<stdio.h>
#include<stdlib.h>

int ** criaMatriz(int qtdLinhas, int qtdColunas);
void populaMatriz(int ** matriz, int altura, int largura);
void achouWally(int ** matriz, int altura, int largura);

int main(){
	int** matrizMundoDeWally;
	int altura, largura;
	
	scanf("%d", &altura);
	scanf("%d", &largura);
	
	matrizMundoDeWally = criaMatriz(altura, largura);
	populaMatriz(matrizMundoDeWally, altura, largura);
	
	achouWally(matrizMundoDeWally, altura, largura);
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

void populaMatriz(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

void achouWally(int ** matriz, int altura, int largura){
	int i, j, achou = 0;
	int acima, abaixo, esquerda, direita;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			acima = i == 0 ? matriz[altura - 1][j] : matriz[i - 1][j];
			abaixo = i == altura - 1 ? matriz[0][j] : matriz[i + 1][j];
			esquerda = j == 0 ? matriz[i][largura - 1] : matriz[i][j - 1];
			direita = j == largura - 1 ? matriz[i][0] : matriz[i][j + 1];	
			
			if(matriz[i][j] == 1111 && acima == 4 && esquerda == 0 && direita == 0 && abaixo == 8){
				printf("%d %d\n", i, j);
				achou = 1;
				break;
			}
		}
	}
	if(!achou){
		printf("WALLY NAO ESTA NA MATRIZ");
	}
}












