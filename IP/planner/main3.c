#include <stdio.h>
#include <stdlib.h>

int adicionaDados(int * vetor, int cont);
int * realocaVetor(int * vet, int tamanho);
void salvaDados(FILE * arquivo, int * vetor, int tamVet);
int leArquivo(FILE * arquivo, int * vetor);
void imprimeVetor(int * vetor, int tamanho);

int main(){
    FILE * arquivo = NULL;
    int * vetNumeros = NULL;
    int contador = 0;

    arquivo = fopen("dados", "rb");
    if(!arquivo){
        contador = adicionaDados(vetNumeros, contador);
        arquivo = fopen("dados","wb");
        salvaDados(arquivo, vetNumeros, contador);
        fclose(arquivo);
    } else {
        contador = leArquivo(arquivo, vetNumeros);
        imprimeVetor(vetNumeros, contador);
        fclose(arquivo);
    }    
}

int adicionaDados(int * vetor, int cont){
    int i, numBuff;
    fscanf(stdin, "%d", &numBuff);
    while(numBuff > 0){
        vetor = realocaVetor(vetor, cont + 1);
        vetor[cont] = numBuff;
        cont++;
        fscanf(stdin, "%d", &numBuff);
    }
    return cont;
}

int * realocaVetor(int * vet, int tamanho){
    int * novoVet = (int *)realloc(vet, sizeof(int) * tamanho);
    if(!novoVet){
        fprintf(stderr, "Erro de alocação de memória!\n");
        exit(1);
    }
    return novoVet;
}

void salvaDados(FILE * arquivo, int * vetor, int tamVet){
    int i;
    fseek(arquivo, 0, SEEK_SET);
    fwrite(&tamVet, sizeof(int), 1, arquivo);
    for(i = 0; i < tamVet; i++){
        fwrite(&(vetor[i]), sizeof(int), 1, arquivo);
    }
}

int leArquivo(FILE * arquivo, int * vetor){
    int i, tamanho;
    fseek(arquivo, 0, 0);
    fread(&tamanho, sizeof(int), 1, arquivo);
    fprintf(stderr, "%d\n", tamanho);
    vetor = realocaVetor(vetor, tamanho);
    for(i = 0; i < tamanho; i++){
        fread(&(vetor[i]), sizeof(int), 1, arquivo);
    }
    return tamanho;
}

void imprimeVetor(int * vetor, int tamanho){
    int i;
    for(i = 0; i < tamanho; i++){
        fprintf(stderr, "%d\n", vetor[i]);
    }
}