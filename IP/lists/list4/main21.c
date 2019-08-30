#include<stdio.h>
#include<stdlib.h>

int entradaValida(int min, int max);

int main(){
    int i;
    int matriz[6][6] = {{0,63,210,190,-1,190},
                        {63,0,160,150,95,10},
                        {210,160,0,10,1,10},
                        {190,150,10,0,10,20},
                        {10,95,7,21,0,80},
                        {190,2,-1,41,80,0}};

    int qtdCidadesVisitadas = entradaValida(0, 100);

    if(qtdCidadesVisitadas == 0 || qtdCidadesVisitadas == 1){
        printf("0\n");
    } else {
        int rota[qtdCidadesVisitadas];
        int soma = 0;

        for(i = 0; i < qtdCidadesVisitadas; i++){
            scanf("%d", &rota[i]);
        }

        for(i = 0; i < qtdCidadesVisitadas - 1; i++){
            if(rota[i] < 0 || rota[i] > 5 || rota[i + 1] < 0 || rota[i + 1] > 5 || matriz[rota[i]][rota[i + 1]] == -1){
                printf("rota invalida!\n");
                exit(1);
            } else {
                soma += matriz[rota[i]][rota[i + 1]];
            }
        }
        printf("%d\n", soma);
    }
}

int entradaValida(int min, int max){
    int valor;
    scanf("%d", &valor);
    if(valor < min || valor > max){
        printf("rota invalida!\n");
        exit(1);
    }
    return valor;
}