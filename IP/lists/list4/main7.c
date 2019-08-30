#include<stdio.h>
#include<stdlib.h>
#define ORDEMMATRIZ 6

int entradaValidada(int min, int max);
int ** inicializaMatriz(int qtdLinhas, int qtdColunas, int minRange, int maxRange);
int somaAmpulheta(int iCantoSupDir, int jCantoSupDir, int **matriz);

int main(){
	int minRange = -9;
	int maxRange = 9;
	int soma = minRange * 7;
	int maiorSomaAmpulheta = minRange * 7;
	int i, j;
	
	//cria um matriz com valores inputados e validados de acordo com minRange e maxRange
	int ** matrizQuadrada = inicializaMatriz(ORDEMMATRIZ, ORDEMMATRIZ, minRange, maxRange);
	
	if(matrizQuadrada){		
		for(i = 0; i < ORDEMMATRIZ - 2; i++){
			for(j = 0; j < ORDEMMATRIZ - 2; j++){
				soma = somaAmpulheta(i, j, matrizQuadrada);
				maiorSomaAmpulheta = soma > maiorSomaAmpulheta ? soma : maiorSomaAmpulheta;
			}
		}
	} else {
		printf("Sem memória suficiente!");
	}
	printf("%d\n", maiorSomaAmpulheta);
}

int entradaValidada(int min, int max){
	int a;
	do {
		scanf("%d", &a);
	} while(a < min || a > max);
	return a;
}

int ** inicializaMatriz(int qtdLinhas, int qtdColunas, int minRange, int maxRange){
	/**
	Cria uma matriz com "qtdLinhas" e "qtdColunas", inicializa cada
	elemento com a chamda da função entradaValidada, que retorna um
	valor entre "minRange" e "maxRange" inclusos de acordo com a 
	entrada do usuário e retorna o endereço	de memória da matriz.
	**/
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
					matriz[i][j] = entradaValidada(minRange, maxRange);
				}
			}
		}    
    return matriz;
    }
}

int somaAmpulheta(int iCantoSupDir, int jCantoSupDir, int **matriz){
	/**
	Soma os valores dos elementos de indice em formato
	de ampulheta, a partir do indice do canto superior 
	direito.
	**/
	int i, j, soma = 0;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			soma += i == 1 && (j == 0 || j == 2) ? 0 : matriz[i + iCantoSupDir][j + jCantoSupDir];
		}
	}
	return soma;
}