#include<stdio.h>
#include<stdlib.h>

int validaEntradaI(int min, int max);

int** criaMatrizContigua(int i, int j);
int** criaMatrizSegmentada(int i, int j);
int* criaMatrizPrimitiva(int i, int j);

void populaMatriz(int** matriz, int linhas, int colunas);
void imprimeMatriz(int** matriz, int linhas, int colunas);

void populaMatrizPrimitiva(int* vet, int linhas, int colunas);
void imprimeMatrizPrimitiva(int* vet, int linhas, int colunas);

int main(){
    int qtdLinhas;
    int qtdColunas;
    
    qtdLinhas = validaEntradaI(1, 10);
    qtdColunas = validaEntradaI(1, 10);
    
    //int** matrizDinamica = criaMatrizContigua(qtdLinhas, qtdColunas);
    //int** matrizDinamica = criaMatrizSegmentada(qtdLinhas, qtdColunas);
    int* matrizDinamica = criaMatrizPrimitiva(qtdLinhas, qtdColunas);
    
    if(!matrizDinamica){
	    printf("Sem memória suficiente!");
    } else {
    	//populaMatriz(matrizDinamica, qtdLinhas, qtdColunas);
    	//imprimeMatriz(matrizDinamica, qtdLinhas, qtdColunas);
    	
    	populaMatrizPrimitiva(matrizDinamica, qtdLinhas, qtdColunas);
    }
}

int validaEntradaI(int min, int max){
    int a;
    do {
        scanf("%d", &a);
    } while (a < min || a > max);
    return a;
}

int** criaMatrizContigua(int linhas, int colunas){
    int i;
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    if(!matriz){
        return 0;
    } else {
        matriz[0] = (int*) malloc(linhas * colunas * sizeof(int));
        if(!matriz[0]){
            free(matriz);
            return 0;
        } else {
            for(i = 1; i < linhas; i++){
                matriz[i] = matriz[i - 1] + colunas;
            }
            return matriz;
        }
    }
}

int** criaMatrizSegmentada(int linhas, int colunas){
    int i, j;
    int** matriz = (int**) malloc(linhas * sizeof(int*));
    if(!matriz){
        return 0;
    } else {
    
    for(i = 0; i < linhas; i++){
    	matriz[i] = (int*) malloc(colunas * sizeof(int));
    	if(!matriz[i]){
    		for(j = 0; j < i; j++){
    			free(matriz[j]);
    		}
   			free(matriz);
    		return 0;
    	}
    }    
    return matriz;
    }
}

int* criaMatrizPrimitiva(int i, int j){
	int *vet = (int*) malloc(sizeof(int) * i * j);
	return vet;
}

void populaMatriz(int** matriz, int linhas, int colunas){
	int i, j;
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

void populaMatrizPrimitiva(int* vet, int linhas, int colunas){
	int i, j;
	for(i = 0; i < linhas; i++){
		for(j = 0; j < colunas; j++){
			scanf("%d", &vet[i * colunas + j]);
		}
	}
}

void imprimeMatriz(int** matriz, int linhas, int colunas){
	int i, j;
	for(i = 0; i < linhas; i++){
		printf("linha %d: ", i + 1);
		for(j = 0; j < colunas; j++){
			printf("%d", matriz[i][j]);
			j < colunas - 1 ? printf(",") : 1;
		}
		printf("\n");
	}
}
