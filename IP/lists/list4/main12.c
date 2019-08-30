#include<stdio.h>
#include<stdlib.h>

int ** criaMatriz(int qtdLinhas, int qtdColunas);
void populaMatriz(int ** matriz, int altura, int largura);
void imprimeSegurancaEsquinas(int ** matriz, int altura, int largura);

int main(){
	int ** matrizEsquinas;
	int ordem;
	
	scanf("%d", &ordem);
	ordem++;
	
	matrizEsquinas = criaMatriz(ordem, ordem);
	populaMatriz(matrizEsquinas, ordem, ordem);
	imprimeSegurancaEsquinas(matrizEsquinas, ordem, ordem);
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

void imprimeSegurancaEsquinas(int ** matriz, int altura, int largura){
	int i, j, soma;
	for(i = 0; i < altura - 1; i++){
		for(j = 0; j < largura - 1; j++){
			soma = matriz[i][j] + matriz[i + 1][j] + matriz[i][j + 1] + matriz[i + 1][j + 1];
			if(soma >= 2){
				printf("S");
			} else {
				printf("U");
			}
			soma = 0;
		}
		printf("\n");
	}
}