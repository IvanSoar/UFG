#include<stdio.h>

int main(){

    int pedras, sapos, i, j, posInicial, distPulo;

    scanf("%d %d", &pedras, &sapos);

    int caminho[pedras];
    for(i = 0; i < pedras; i ++){
        caminho[i] = 0;
    }

    for(i = 0; i < sapos; i++){
        scanf("%d %d", &posInicial, &distPulo);
        for(j = posInicial - 1; j < pedras; j += distPulo){
            caminho[j] = 1;
        }
        for(j = posInicial - 1; j >= 0; j -= distPulo){
            caminho[j] = 1;
        }
    }

    for(i = 0; i < pedras; i++){
        printf("%d\n", caminho[i]);
    }

    return 0;
}