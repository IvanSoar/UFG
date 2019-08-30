#include <stdio.h>
#include <stdlib.h>

void escreveDados(FILE * arquivo, int tam, int * vetor);
int leDados(FILE * arquivo, int * vetor);
void imprimeDados(int * vetor, int tamanho);
int insereDados(int cont, int * vet);
int * realocaVetor(int * vet, int tamanho);

int main(){
    int contador = 0;
    int * vetor = NULL;
    FILE * arquivo = NULL;
    
    arquivo = fopen("dados","rb");

    if(!arquivo){
        arquivo = fopen("dados","wb");

        contador = insereDados(contador, vetor);
        
        escreveDados(arquivo, contador, vetor);
        fprintf(stderr,"Arquivo criado!");
    } else {
        contador = leDados(arquivo, vetor);
        imprimeDados(vetor, contador);
    }

    fclose(arquivo);
    return 0;
}

void escreveDados(FILE * arquivo, int tam, int * vetor){
    int i;
    fseek(arquivo, 0, SEEK_SET);
    fwrite(&tam, sizeof(int), 1, arquivo);
    for(i = 0; i < tam; i++){
        fwrite(&vetor[i], sizeof(int), 1, arquivo);
    }
}

int leDados(FILE * arquivo, int * vetor){
    int i;
    int tamanho;
    fseek(arquivo, 0, SEEK_SET);
    fread(&tamanho, sizeof(int), 1, arquivo);
    for(i = 0; i < tamanho; i++){
        fread(&(vetor[i]), sizeof(int), 1, arquivo);
    }
    return tamanho;
}

void imprimeDados(int * vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        fprintf(stderr,"%d\n", vetor[i]);
    }    
}

int insereDados(int cont, int * vet){
    int valor;
    fscanf(stdin, "%d", &valor);
    while(valor > 0){
        vet = realocaVetor(vet, cont + 1);
        vet[cont] = valor;
        cont++;
        fscanf(stdin, "%d", &valor);
    }
    return cont;
}

int * realocaVetor(int * vet, int tamanho){
    int * temp = (int *) realloc(vet, sizeof(int) * tamanho);
    if(!temp){
        fprintf(stderr, "Falha de alocação de memória!\n");
        exit(1);
    }
    return temp;
}