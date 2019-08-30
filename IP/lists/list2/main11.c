#include <stdio.h>

int main(){
    int i, n;
    scanf("%d", &n);
    int vetor[n];
    int max, min;

    for(i = 0; i < n; i++){
        scanf("%d", &vetor[i]);
        max = i == 0 ? vetor[i] : vetor[i] > max ? vetor[i] : max;
        min = i == 0 ? vetor[i] : vetor[i] < min ? vetor[i] : min;
    }

    for(i = 0; i < n; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");

    while(n--){
        printf("%d ", vetor[n]);
    }
    printf("\n");

    printf("%d\n", max);
    printf("%d\n", min);

    return 0;
}
