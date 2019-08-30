#include<stdio.h>
#include<stdlib.h>

int entradaValidada(int min, int max);
int ** inicializaMatrizZero(int qtdLinhas, int qtdColunas);
void populaBorda(int ** matriz, int largura, int altura, int espessura, int valor);
void imprimeMatriz(int ** matriz, int largura, int altura);

int main(){
	int largura, altura, espessura, valor;
	int ** matriz;
	
	scanf("%d %d %d %d", &largura, &altura, &espessura, &valor);
	
	if(largura > 100 || altura >= 100 || largura < 1 || largura < 1 || espessura < 0 || valor < 0 || valor > 9){
		exit(1);
	}
	
	matriz = inicializaMatrizZero(largura, altura);
	
	if(matriz){
		populaBorda(matriz, largura, altura, espessura, valor);
		imprimeMatriz(matriz, largura, altura);
	}
}

int ** inicializaMatrizZero(int qtdLinhas, int qtdColunas){
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
				//A matriz foi criada com sucesso, em seguida, será populada;
				for(j = 0; j < qtdColunas; j++){
					matriz[i][j] = 0;
				}
			}
		}    
    return matriz;
    }
}

void populaBorda(int ** matriz, int largura, int altura, int espessura, int valor){
	int i, j, k;
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			matriz[i][j] = i < espessura || j < espessura || i >= largura - espessura || j >= altura - espessura ? valor : matriz[i][j];
		}
	}
}

void imprimeMatriz(int ** matriz, int largura, int altura){
	int i, j;
	printf("P2\n%d %d\n255\n", largura, altura);
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}