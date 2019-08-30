#include <stdio.h>

int main(){

    int cont = 0;
    int i, alunos, presenca;
    scanf("%d %d", &alunos, &presenca);

    int vetor[alunos];

    for(i = 0; i < alunos; i++){
        scanf("%d", &vetor[i]);
        cont += vetor[i] <= 0 ? 1 : 0;
    }

    if(cont < presenca){
        printf("SIM\n");
    } else {
        printf("NAO\n");
        while(alunos--){
            if(vetor[alunos] <= 0){
                printf("%d\n", alunos + 1);
            }
        }
    }

    return 0;
}
