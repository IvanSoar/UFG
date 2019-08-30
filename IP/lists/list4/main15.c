#include<stdio.h>
#include<stdlib.h>

int validaEntrada(int min, int max);
int ** retornaMatrizZerada(int altura, int largura);
void populaMatriz(int ** matriz, int altura, int largura);
void imprimeExpiral(int ** matriz, int altura, int largura);

int main(){
	int ** matriz;	
	
	int altura = validaEntrada(1, 10);
	int largura = validaEntrada(1, 10);
	
	matriz = retornaMatrizZerada(altura, largura);
	
	populaMatriz(matriz, altura, largura);
	
	imprimeExpiral(matriz, altura, largura);
}

int validaEntrada(int min, int max){
	int valor;
	scanf("%d", &valor);
	if(valor < min || valor > max){
		printf("Dimensao invalida\n");
		exit(1);
	} else {
		return valor;
	}
}

int ** retornaMatrizZerada(int altura, int largura){
	//matriz contigua será utilizada, arbitraiamente, para fins de treinamento.
	
	int i, j;
	int ** matriz = (int **) malloc(altura * sizeof(int *));
	
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

void imprimeExpiral(int ** matriz, int altura, int largura){
	int i, j, k, cont, max;
	i = j = k = cont = 0;
	max = altura * largura;
	
	while(1){
		for(j = k; j < largura - k; j++){
			printf("%d ", matriz[k][j]);
			cont++;
		}
		
		if(cont >= max){break;}
		
		for(i = k + 1; i < altura - k; i++){
			printf("%d ", matriz[i][largura - k - 1]);
			cont++;
		}
		
		if(cont >= max){break;}
		
		for(j = largura - k - 2; j > k - 1; j--){
			printf("%d ", matriz[altura - k - 1][j]);
			cont++;
		}
		
		if(cont >= max){break;}
		
		for(i = altura - k - 2; i > k; i--){
			printf("%d ", matriz[i][k]);
			cont++;
		}
		
		if(cont >= max){break;}
		k++;
	}
}
