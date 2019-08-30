#include<stdio.h>
#include<stdlib.h>

int ** criaMatriz(int qtdLinhas, int qtdColunas);
void populaMatrizXadrez(int ** matriz, int largura, int altura);
void imprimeMatriz(int ** matriz, int largura, int altura);

int main(){
	int largura, altura;
	int ** matriz;
	
	scanf("%d %d", &largura, &altura);
	
	matriz = criaMatriz(largura, altura);
	
	if(!matriz){
		exit(1);
	}
	
	populaMatrizXadrez(matriz, largura, altura);
	imprimeMatriz(matriz, largura, altura);
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
			}
		}    
    return matriz;
    }
}

void populaMatrizXadrez(int ** matriz, int largura, int altura){
	int i, j;
	int k = 1;
	for(i = 0; i < largura; i++){
		for(j = 0; j < altura; j++){
			if((i + j) % 2 == 0){
				matriz[i][j] = 0;
			} else {
				matriz[i][j] = k;
				k++;
			}
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