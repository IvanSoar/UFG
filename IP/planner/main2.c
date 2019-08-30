#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CONTATO{
    char *nome;
    int tamNome;
} contato;

int main(){
    FILE * fpContatos;
    contato * vetContatos = NULL;
    contato * novosContatos = NULL;

    vetContatos = leArquivo(fpContatos);
    if(!vetContatos){
        vetContatos = criaArquivo(fpContatos);
    }

    int comando = 0;
    while(comando){
        switch (comando){
            case 1: adicionaContato(); break;
            case 2: imprimeContatosRecentes(); break;
            case 3: imprimeContatosSalvos(); break;
            case 4: salvaContatos(); break;
            case 0: sairSemSalvar(); break;
        }
    }

    fclose(fpContatos);
}

contato * leArquivos(FILE * fp){
    contato * vet = NULL;
    int tamanhoVet;
    fp = fopen("contatos.ivz","rb");
    if(!fp){
        return vet;
    } else {
        fseek(fp, 0, SEEK_SET);
        if(fread(tamanhoVet, sizeof(int), 1, fp) == 0){
            fprintf(stderr,"Arquivo de dados presente, porem vazio!\n");
        } else {
            vet = alocaVetor(tamanhoVet);
        }
    }
    fclose(fp);
    return vet;
}