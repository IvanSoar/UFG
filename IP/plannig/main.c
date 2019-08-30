#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Indice{
	char * nome;
	long int ind;
} indice;

void exitError();
int pesquisa(indice * vetor, char * buff, int numEntradas);
void insere(indice ** vIndice, int * tamanhoVetor, int * numEntradas, char * buff);
void imprime(indice * vetor, int tamanho);

int main(){
	int tamanhoVetor = 0;
	int numEntradas = 0;	
	indice * vIndice = (indice *) malloc(sizeof(indice) * tamanhoVetor);
	vIndice ? 1 : exitError();
	
	int tempCount = 5;
	while(tempCount--){
		char buff[100];
		int resPesquisa;
		printf("Digite o nome: ");
		scanf("%[^\n]", buff);
		getchar();
		resPesquisa = pesquisa(vIndice, buff, numEntradas);
		if(resPesquisa >= 0){
			printf("O contato de %s já está salvo no índice %d.\n", buff, resPesquisa);
			exit(getchar());
		} else {
			insere(&vIndice, &tamanhoVetor, &numEntradas, buff);
		}
	}
	imprime(vIndice, numEntradas);
}

void exitError(){
	fprintf(stderr, "Erro de alocacao de memoria. Fechando o programa...");
	exit(getchar());
}

int pesquisa(indice * vetor, char * buff, int numEntradas){
	int inicio = 0;
	int fim = numEntradas - 1;
	int meio = (inicio + fim)/2;
	int resCompara = strcmp(vetor[meio].nome, buff);
	while(inicio <= fim){
		if(resCompara == 0){
			return meio;
		} else if(resCompara > 0){
			fim = meio - 1;
		} else {
			inicio = meio + 1;
		}
	}
	return -1;
}

void insere(indice ** vIndice, int * tamanhoVetor, int * numEntradas, char * buff){
	indice * temp = * vIndice;
	if(* tamanhoVetor == * numEntradas){
		* tamanhoVetor++;
		temp = (indice *) realloc(vIndice, sizeof(indice) * (* tamanhoVetor));
		printf("1\n");
		temp ? 1 : exitError();
	}
	temp[* numEntradas].nome = (char *) malloc((strlen(buff) + 1) * sizeof(char));
	printf("2\n");
	temp[* numEntradas].nome ? * numEntradas++ : exitError();
	strcpy(temp[* numEntradas].nome, buff);
	printf("%s\n", temp[*numEntradas].nome);
}

void imprime(indice * vetor, int tamanho){
	int i;
	for(i = 0; i < tamanho; i++){
		printf("%s\n", vetor[i].nome);
	}
	exit(getchar());
}