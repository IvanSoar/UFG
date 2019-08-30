//
//  main.c
//  
//
//  Created by Thierson Couto Rosa on 21/06/18.
//
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Definicao do tipo struc para o indice de nome
typedef struct sin{
	char* nome;
	long int fp;
} TSindNome;






int pesqBin(TSindNome* vet, char* chave, int tam);
void ordena(TSindNome *v, int tam);
void insere(TSindNome**p, char* buf, int *tam_logico, int *tam_fisico);
void imprime(TSindNome *v, int tam_logico);
void limpaVetIndNome(TSindNome **v, int tam);

int main(){
//Declaracao do vetor dinamico que armazena os indices de nome e de telefone
	TSindNome *vetIndNome=NULL;
	char buffer[1000];
	int tam_fisico=5,tam_logico=0; //vetor esta incialmente sem elementos
	int casos;
	//pre-reservar um tamanho para o vetor de indice de nomes
	vetIndNome= (TSindNome*)malloc(sizeof(TSindNome)*5);
	if (!vetIndNome) {
    fprintf(stderr,"Nao ha memoria para executar o programa -terminando\n");
		exit(1);
	}
	printf("Digite o numero de casos de teste\n");
	scanf("%d", &casos);
	getchar();
	while(casos--) {
		int res;
		//ler um nome no buffer

		printf("Digite um nome\n");
		scanf("%[^\n]", buffer);
		getchar();
		//pesquisar o nome no vetor
		res=pesqBin(vetIndNome,buffer,tam_logico);
		if(res>=0){
			printf("Nome encontrado na posicao %d do vetor\n", res);
		}
		else{
				//inserir o nome no vetor
				insere(&vetIndNome, buffer, &tam_logico, &tam_fisico);
				//ordenar o vetor
				ordena(vetIndNome,tam_logico);
		}
	}
	imprime(vetIndNome, tam_logico);
	limpaVetIndNome(&vetIndNome,tam_logico);

	return(0);

}
int pesqBin(TSindNome* vet, char* chave, int tam){
	int inicio=0, meio, fim=tam-1, teste;
	while(inicio<=fim){
		meio=(inicio+fim)/2;
		teste=strcmp(chave,vet[meio].nome);
		if (teste==0) {//encontrou o nome procurado
			return(meio);
		}
		if (teste<0) {//procurar na metade inferior do vetor
			fim=meio-1;
		}
		else{ // procurar na metade superior do vetor.
			inicio=meio+1;
		}
	}
	return(-1);// um retorno igual a -1 significa que a chave nao esta no vetor
}
void insere(TSindNome**p, char* buf, int *tam_logico, int *tam_fisico){
//o parametro p armazena o endereco da variavel vetIndNome da funcao main
//isso e necessario, pois se realloc for chamado aqui nessa funcao, o endereco
//em vetIndNome precisa ser alterado para apontar para a nova area alocada. Para
//fazer essa alteracao p tem armazenar o endereco de vetIndNome. Mas vetIndNome
//e um ponteiro para o tipo TSindNome, entao o tipo de p e um ponteiro para
//ponteiro de TSindNome.

	TSindNome *x; //variavel auxiliar
	if (*tam_logico==*tam_fisico) {//o numero de elementos no vetor e
	//exatamente a quantidade de espacao alocada. Nao ha mais espaco para
	// a insercao. Temos que alocar para ampliar o vetor.
		(*tam_fisico)+=2;
    x=(TSindNome*)realloc(*p,sizeof(TSindNome)*(*tam_fisico));
		if (!x) {
			fprintf(stderr, "Nao ha memoria\n");
			exit(1);
		}

		*p=x;//Com esse comando a variavel vetIndNome da funcao main paca a apontar
		// para o endereco alocado por realloc para a expansao do vetor.
	}
	x=*p; //usando x em vez de *p para nao complicar a notacao.
	//Alocando espaco para o nome armazenar no vetor o nome que esta no buffer
	x[*tam_logico].nome=(char*)malloc( (strlen(buf)+1)*sizeof(char));
	if(!x[*tam_logico].nome){
		fprintf(stderr, "Nao ha memoria\n");
		exit(1);
	}
	strcpy(x[*tam_logico].nome, buf);
	(*tam_logico)++;// inserimos mais um elemento no vetor, entao o tamanho logico
	//aumentou de 1.
}

void ordena(TSindNome *v, int tam){
//selection sort normal. A diferenca e que os valores comparados sao strings.
//Logo, precisamos compara strings com strcmp().
	int indMenor,i,j;
	char nomeMen[500];
	for (i=0; i<tam-1;i++) {
		indMenor=i;
		strcpy(nomeMen,v[i].nome);
    for (j=i+1; j<tam; j++) {
			if (strcmp(v[j].nome,nomeMen)<0) {
					strcpy(nomeMen,v[j].nome);
					indMenor=j;
			}
		}
		TSindNome aux;
		aux=v[indMenor];
		v[indMenor]=v[i];
		v[i]=aux;
	}
}

void imprime(TSindNome *v, int tam_logico){
	int i;
	for (i=0; i<tam_logico; i++) {
    printf("%s\n", v[i].nome);
	}
}
void limpaVetIndNome(TSindNome **v, int tam){
	int i;
	TSindNome *x;
	x =*v;
	for (i=0; i<tam; i++) { //Percorrendo o vetor, liberando todas as strings
	//que foram alocadas para armazenar os nomes.
    free(x[i].nome);
	}
	free(x); //liberando o espaco ocupado pelo vetor de TSindNome

	*v=NULL;//Fazer a variavel vetIndNome da funcao main conter NULL para
	//indicar que o vetor foi totalmente desalocado.
}
