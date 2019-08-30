#include<stdio.h>
#include<stdlib.h>

typedef struct Fracao {
    int num;
    char nulo;
    int den;
    float valor;
} fracao;

int main(){
    int testes;
    int fracoes;
    int i, j, k;
    float valor;
    int flag = 0;

    scanf("%d", &testes);

    for(i = 0; i < testes; i++){
        scanf("%d", &fracoes);
        fracao vetor[fracoes];
        for(j = 0; j < fracoes; j++){
            scanf("%d/%d", &vetor[j].num, &vetor[j].den);
            vetor[j].valor = (float)vetor[j].num / (float)vetor[j].den;
        }
        printf("Caso de teste %d\n", i + 1);
        for(j = 0; j < fracoes - 1; j++){
            for(k = j + 1; k < fracoes; k++){
                if(vetor[j].valor == vetor[k].valor){
                    printf("%d/%d equivalente a %d/%d\n", vetor[j].num, vetor[j].den, vetor[k].num, vetor[k].den);
                    flag = 1;
                }
            }
        }
        if(flag == 0){
            printf("Nao ha fracoes equivalentes na sequencia\n");
        } else {
            flag = 0;
        }
    }

    

    return 0;
}
