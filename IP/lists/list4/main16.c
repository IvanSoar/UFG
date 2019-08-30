#include<stdio.h>
#include<stdlib.h>

int entradaValidadaNoRange(int min, int max);
int ** retornaMatrizZeradaQuadrada(int ordem);
void populaMatrizQuadrada(int ** matriz, int ordem);
int procuraMatriz1EmMatriz2(int ** matriz1, int ordMatriz1, int ** matriz2, int ordMatriz2);

int main(){	
	int ordemLogotipo = entradaValidadaNoRange(1, 10);
	int ** logotipo = retornaMatrizZeradaQuadrada(ordemLogotipo);
	
	populaMatrizQuadrada(logotipo, ordemLogotipo);
	
	int ordemImagemVideo = entradaValidadaNoRange(1, 320);	
	int ** imagemVideo = retornaMatrizZeradaQuadrada(ordemImagemVideo);
	
	populaMatrizQuadrada(imagemVideo, ordemImagemVideo);
	
	if(procuraMatriz1EmMatriz2(logotipo, ordemLogotipo, imagemVideo, ordemImagemVideo)){
		printf("sim\n");
	} else {
		printf("nao\n");
	}
}

int entradaValidadaNoRange(int min, int max){
	int valor;
	scanf("%d", &valor);
	if(valor < min || valor > max){
		exit(1);
	} else {
		return valor;
	}
}

int ** retornaMatrizZeradaQuadrada(int ordem){
	int i, j;
	int ** matriz = (int **) malloc(ordem * sizeof(int *));
	
	if(!matriz){
		exit(1);
		}
	
	matriz[0] = (int *) malloc(ordem * ordem * sizeof(int));
	
	if(!matriz[0]){
		free(matriz);
		exit(1);
	}
	
	for(i = 1; i < ordem; i++){
		matriz[i] = matriz[i - 1] + ordem;
	}
	
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			matriz[i][j] = 0;
		}
	}
	
	return matriz;
}

void populaMatrizQuadrada(int ** matriz, int ordem){
	int i, j;
	for(i = 0; i < ordem; i++){
		for(j = 0; j < ordem; j++){
			matriz[i][j] = entradaValidadaNoRange(0, 255);
		}
	}
}

int procuraMatriz1EmMatriz2(int ** matriz1, int ordMatriz1, int ** matriz2, int ordMatriz2){
	int i, j, k, l, cont = 0;
	
	for(i = 0; i < ordMatriz2; i++){
		for(j = 0; j < ordMatriz2; j++){
			cont = 0;
			if(matriz2[i][j] == matriz1[0][0]){
				cont++;
				for(k = 1; k < ordMatriz1; k++){
					for(l = 1; l < ordMatriz1; l++){
						if(matriz2[i + k][j + l] == matriz1[k][l]){
							cont++;
						}
					}
				}
				if(cont == ordMatriz1 * ordMatriz1){
					return 1;
				}
			}
		}
	}
	
	return 0;
}