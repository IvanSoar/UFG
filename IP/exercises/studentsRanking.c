#include<stdio.h>

struct aluno{
	int matricula;
	char nome[201];
	float nota;
	char e_mail[101];
};

void leDadosAluno(struct aluno* d){
	scanf("%d", &(d->matricula));
	getchar();
	scanf("%[^\n]", d->nome);
	getchar();
	scanf("%f", &(d->nota));
	getchar();
	scanf("%[^\n]", d->e_mail);
	getchar();

}
void troca( struct aluno* a, struct aluno*b){
	struct aluno aux;
	aux=*a;
	*a=*b;
	*b=aux;
}

void ordenaAlunos(struct aluno vet[], int tam){
	int i, j,imaior;
	float maior;
	for (i=0; i<tam; i++) {
    maior= vet[i].nota;
		imaior=i;
		for (j=i+1; j<tam; j++) {
			if (vet[j].nota> maior) {
				maior=vet[j].nota;
				imaior=j;
			}
			troca(&vet[i],&vet[imaior]);
		}
	}
}
void imprimeRanking(struct aluno vet[], int tam){
	int i,j;
	for (i=0; i<tam; i++) {
    printf("Matricula: %d, Nome: %s, Nota: %.2f, E_mail: %s\n", vet[i].matricula, vet[i].nome, vet[i].nota,vet[i].e_mail);
	}
}

int main(){
	struct aluno turma[5];
	int i;
	for (i=0; i<5; i++) {
    leDadosAluno(&turma[i]);
	}
	ordenaAlunos(turma,5);
	imprimeRanking(turma,5);

}