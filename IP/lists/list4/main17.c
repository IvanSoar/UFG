#include<stdio.h>
#include<stdlib.h>
#define dezenas 6

int entradaValidada(int min, int max);
int ** retornaMatrizZerada(int altura, int largura);
void populaMatriz(int ** matriz, int altura, int largura);
int contaIguais(int * vetor, int * linhaMatriz);

int main(){
	int numeroApostas = entradaValidada(1, 50000);
	int ** matrizApostas = retornaMatrizZerada(numeroApostas, dezenas);
	int sorteio[dezenas];
	int i, contador, sena, quina, quadra;
	
	populaMatriz(matrizApostas, numeroApostas, dezenas);
	
	for(i = 0; i < dezenas; i++){
		sorteio[i] = entradaValidada(1, 60);
	}
	
	contador = sena = quina = quadra = 0;
	for(i = 0; i < numeroApostas; i++){
		contador = contaIguais(sorteio, matrizApostas[i]);
		switch(contador){
			case 6 : sena++; break;
			case 5 : quina++; break;
			case 4 : quadra++; break;
		}
	}
	
	sena > 0 ? printf("Houve %d acertador(es) da sena\n", sena) : printf("Nao houve acertador para sena\n");
	quina > 0 ? printf("Houve %d acertador(es) da quina\n", quina) : printf("Nao houve acertador para quina\n");
	quadra > 0 ? printf("Houve %d acertador(es) da quadra\n", quadra) : printf("Nao houve acertador para quadra\n");
}

int entradaValidada(int min, int max){
	int valor;
	scanf("%d", &valor);
	if(valor < min || valor > max){
		exit(1);
	} else {
		return valor;
	}
}

int ** retornaMatrizZerada(int altura, int largura){
	int i, j;
	int ** matriz = (int **) malloc(altura * sizeof(int *));
	
	if(!matriz){
		exit(1);
		}
	
	matriz[0] = (int *) malloc(altura * largura * sizeof(int));
	
	if(!matriz[0]){
		free(matriz);
		exit(1);
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
			matriz[i][j] = entradaValidada(1, 60);
		}
	}
}

int contaIguais(int * vetor, int * linhaMatriz){
	int i, j, cont = 0;
	for(i = 0; i < dezenas; i++){
		for(j = 0; j < dezenas; j++){
			if(vetor[i] == linhaMatriz[j]){
				cont++;
			}
		}
	}
	return cont;
}






