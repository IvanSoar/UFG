#include<stdio.h>
#include<stdlib.h>

int ** retornaMatrizZerada(int altura, int largura);
void populaMatriz(int ** matriz, int altura, int largura);
void calculaFreqMM(int ** matriz, int altura, int largura);

int main(){
	int altura, largura;
	
	scanf("%d %d", &altura, &largura);
	
	int ** matriz = retornaMatrizZerada(altura, largura);
	
	!matriz ? exit(1) : 1;
	
	populaMatriz(matriz, altura, largura);
	calculaFreqMM(matriz, altura, largura);
	//imprimeMatriz(matriz, altura, largura);
}

int ** retornaMatrizZerada(int altura, int largura){
	int ** matriz;
	int i, j;
	
	matriz = (int **) malloc(altura * sizeof(int *));
	if(!matriz){
		return 0;
	}
	
	matriz[0] = (int *) malloc(altura * largura * sizeof(int));
	if(!matriz[0]){
		free(matriz);
		return 0;
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

void populaMatriz(int ** matriz, int altura, int largura){
	int i, j;
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			scanf("%d", &matriz[i][j]);
		}
	}
}

void calculaFreqMM(int ** matriz, int altura, int largura){
	int i, j;
	int menor = 1000;
	int maior = 0;
	int contMaior, contMenor;
	
	contMaior = contMenor = 0;
	
	for(i = 0; i < altura; i++){
		for(j = 0; j < largura; j++){
			if(matriz[i][j] < menor){
				menor = matriz[i][j];
				contMenor = 1;
			} else if(matriz[i][j] > maior){
				maior = matriz[i][j];
				contMaior = 1;
			} else if(matriz[i][j] == menor){
				contMenor++;
			} else if(matriz[i][j] == maior){
				contMaior++;
			}
		}
	}
	
	float freqMenor = (float)contMenor * 100 / (altura * largura);
	float freqMaior = (float)contMaior * 100 / (altura * largura);
	
	printf("%d %.2f%%\n", menor, freqMenor);
	printf("%d %.2f%%\n", maior, freqMaior);
}
