#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define qtdAlunos 3

typedef struct aluno{
	int matricula;
	float nota;
	int tamNome;
	char * nome;
} ALUNO;

void leArquivoBinarioALUNO(ALUNO * turma, FILE * arquivo);

int main(){
	int i;
	ALUNO turma[qtdAlunos];
	
	FILE * pAlunos;
	pAlunos = fopen("MeuArquivo", "rb");
	
	leArquivoBinarioALUNO(turma, pAlunos);
	
	printf("matricula\tnome\t\tnota\n");
	for(i = 0; i < qtdAlunos; i++){
		printf("%d\t%s\t%.2f\n", turma[i].matricula, turma[i].nome, turma[i].nota);
	}
}

void leArquivoBinarioALUNO(ALUNO * turma, FILE * arquivo){
	int i;
	
	for(i = 0; i < qtdAlunos; i++){
		fread(&turma[i].matricula, sizeof(int), 1, arquivo);
		fread(&turma[i].nota, sizeof(float), 1, arquivo);
		fread(&turma[i].tamNome, sizeof(int), 1, arquivo);
	
		turma[i].nome = (char *) malloc(turma[i].tamNome + 1);
		
		if(!turma->nome){
			printf("Falha no Malloc!\n");
			exit(1);
		}
	
		fread(turma[i].nome, turma[i].tamNome, 1, arquivo);
		
		turma[i].nome[turma[i].tamNome] = '\0';
	}
}
