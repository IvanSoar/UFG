#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
    int dia;
    int mes;
    int ano;
} data;

typedef struct Aluno{
    int matricula;
    data nascimento;
    char * nome;
} aluno;

void troca(aluno * a, aluno * b);
void ordenaTurma(aluno * turma, int tam);

int main(){
    int i;
    int numAlunos;
    char buff[200];

    scanf("%d", &numAlunos);
    aluno turma[numAlunos];
    for(i = 0; i < numAlunos; i++){
        scanf("%d", &turma[i].matricula);
        scanf("%d", &turma[i].nascimento.dia);
        scanf("%d", &turma[i].nascimento.mes);
        scanf("%d", &turma[i].nascimento.ano);
        getchar();
        scanf("%[^\n]", &buff);
        turma[i].nome = (char *) malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(turma[i].nome, buff);
    }

    ordenaTurma(turma, numAlunos);

    for(i = 0; i < numAlunos; i++){
        printf("Matric: %d Nome: %s Data Nasc: %d/%d/%d\n", turma[i].matricula, turma[i].nome, turma[i].nascimento);
    }

    return 0;
}
void troca(aluno * a, aluno * b){
    aluno aux = * a;
    *a = * b;
    * b = aux;
}
void ordenaTurma(aluno * turma, int tam){
    int i, j;
    for(i = 0; i < tam - 1; i++){
        for(j = i + 1; j < tam; j++){
            if(turma[i].nascimento.ano < turma[j].nascimento.ano){
                troca(&turma[i], &turma[j]);
            }
            if(turma[i].nascimento.ano <= turma[j].nascimento.ano && turma[i].nascimento.mes < turma[j].nascimento.mes){
                troca(&turma[i], &turma[j]);
            }
            if(turma[i].nascimento.ano <= turma[j].nascimento.ano && turma[i].nascimento.mes <= turma[j].nascimento.mes && turma[i].nascimento.dia < turma[j].nascimento.dia){
                troca(&turma[i], &turma[j]);
            }
        }
    }
}