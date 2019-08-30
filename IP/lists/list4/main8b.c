#include<stdio.h>
#include<stdlib.h>

int ** criaMatriz(int qtdLinhas, int qtdColunas, int valorInicia);
void imprimeMatriz(int ** matriz, int largura, int altura);
void quadrado(int ** matriz, int ordem, int x, int y, int valor, int raio, int modo);

int main(){
	int ** matrizPGM;
	int ordem, valor, x, y, raio, modo;
	
	scanf("%d", &ordem);
	scanf("%d", &valor);
	
	matrizPGM = criaMatriz(ordem, ordem, valor);
	
	scanf("%d", &x);
	scanf("%d", &y);
	while(x != -1 && y != -1){
		
		scanf("%d", &valor);
		scanf("%d", &raio);
		scanf("%d", &modo);
		
		if(raio * 2 < ordem){
			quadrado(matrizPGM, ordem, x, y, valor, raio, modo);
		}
		
		scanf("%d", &x);
		scanf("%d", &y);
	} 
	
	imprimeMatriz(matrizPGM, ordem, ordem);
}

int ** criaMatriz(int qtdLinhas, int qtdColunas, int valorInicia){
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
					matriz[i][j] = valorInicia;
				}
			}
		}    
    return matriz;
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

void quadrado(int ** matriz, int ordem, int x, int y, int valor, int raio, int modo){	
	int i, j;
	if(modo == 1){			
		for(i = 0; i < ordem; i++){
			for(j = 0; j < ordem; j++){
				matriz[i][j] = i == x - raio && (j <= y + raio && j >= y - raio) ? valor : matriz[i][j];
				matriz[i][j] = i == x + raio && (j <= y + raio && j >= y - raio) ? valor : matriz[i][j];
				matriz[i][j] = j == y - raio && (i <= x + raio && i >= x - raio) ? valor : matriz[i][j];
				matriz[i][j] = j == y + raio && (i <= x + raio && i >= x - raio) ? valor : matriz[i][j];
			}		
		}
	} else {
		for(i = 0; i < ordem; i++){
			for(j = 0; j < ordem; j++){
				matriz[i][j] = i >= x - raio && i <= x + raio && j >= y - raio && j <= y + raio ? valor : matriz[i][j];
			}		
		}
	}
}