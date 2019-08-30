#include<stdio.h>
#include<stdlib.h>

int entradaValidada(int min, int max);
int ** inicializaMatrizZero(int qtdLinhas, int qtdColunas);
void populaBorda(int ** matriz, int largura, int altura, int espessura, int valor);
void imprimeMatriz(int ** matriz, int largura, int altura);

int main(){
	int largura = entradaValidada(1, 100);
	int altura = entradaValidada(1, 100);
	int espessura = entradaValidada(0, 100);
	int valor = entradaValidada(-9, 9);
	int ** matriz = inicializaMatrizZero(largura, altura);
	
	if(matriz){		
		
		populaBorda(matriz, largura, altura, espessura, valor);
		imprimeMatriz(matriz, largura, altura);
		
	} else {
		printf("Sem memória suficiente!");
	}	
}

int entradaValidada(int min, int max){
	int a;
	do {
		scanf("%d", &a);
	} while(a < min || a > max);
	return a;
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
	printf("p2\n%d %d\n255\n", largura, altura);
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}