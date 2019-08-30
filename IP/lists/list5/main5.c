#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Curso{
    int cod;
    double valorCred;
    char * nome;
} curso;

typedef struct Aluno{
    char * nome;
    int codCurso;
    int cred;
} aluno;

int main(){
    int i, j;
    int numCursos, numAlunos;
    double tempValor;
    char buff[100];
    
    scanf("%d", &numCursos);
    curso vetorCursos[numCursos];
    for(i = 0; i < numCursos; i++){
        scanf("%d", &vetorCursos[i].cod);
        scanf("%lf", &vetorCursos[i].valorCred);
        getchar();
        scanf("%[^\n]", &buff);
        vetorCursos[i].nome = (char *) malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(vetorCursos[i].nome, buff);
    }

    scanf("%d", &numAlunos);
    aluno vetorAlunos[numAlunos];
    for(i = 0; i < numAlunos; i++){
        getchar();
        scanf("%[^\n]", &buff);
        vetorAlunos[i].nome = (char *) malloc(strlen(buff) * sizeof(char) + 1);
        strcpy(vetorAlunos[i].nome, buff);
        scanf("%d", &vetorAlunos[i].codCurso);
        scanf("%d", &vetorAlunos[i].cred);

        printf("Aluno(a): %s ", vetorAlunos[i].nome);
        
        for(j = 0; j < numCursos; j++){
            if(vetorAlunos[i].codCurso == vetorCursos[j].cod){
                printf("Curso: %s ", vetorCursos[j].nome);
                tempValor = vetorCursos[j].valorCred;
            }
        }

        printf("Num. Creditos: %d ", vetorAlunos[i].cred);
        printf("Valor Credito: %.2f ", tempValor);
        printf("Mensalidade: %.2f\n", vetorAlunos[i].cred * tempValor);
    }
    return 0;
}
