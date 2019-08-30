#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Produto {
    char * nome;
    double preco;
} produto;

int main(){
    int testes, itensFeira, itensCompras, qtdComprada, i, j, k;
    double valorAPagar = 0.0;
    char buffer[10];
    scanf("%d", &testes);
    for(i = 0; i < testes; i++){

        scanf("%d", &itensFeira);
        produto feira[itensFeira];
        for(j = 0; j < itensFeira; j++){
           
            scanf("%s", buffer);
            scanf("%lf", &feira[j].preco);
            getchar();
            feira[j].nome = (char *) malloc(strlen(buffer) * sizeof(char) + 1);
            strcpy(feira[j].nome, buffer);
        }

        valorAPagar = 0.0;
        scanf("%d", &itensCompras);
        for(j = 0; j < itensCompras; j++){
           
            scanf("%s", buffer);
            scanf("%d", &qtdComprada);
            getchar();
            for(k = 0; k < itensFeira; k++){
                valorAPagar += strcmp(feira[k].nome, buffer) ? 0 : feira[k].preco * (double)qtdComprada;
            }
        }
        printf("R$ %.2f\n", valorAPagar);
    }

    return 0;
}