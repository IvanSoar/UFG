#include <stdio.h>

int main(){
    int n, d, i, j, numero;
    scanf("%d %d", &n, &d);
    while(n * d != 0){
        scanf("%d", &numero);
        char strNum[n];
        sprintf(strNum, "%d", numero);
        for(i = 0; i < n - 1; i++){
            for(j = i + 1; j < n; j++){
                if(strNum[i] > strNum[j]){
                    int aux = strNum[i];
                    strNum[i] = strNum[j];
                    strNum[j] = aux;
                }
            }
        }
        for(i = d; i < n; i++){
            printf("%c", strNum[i]);
        }
        printf("\n");
        scanf("%d %d", &n, &d);
    }
    return 0;
}
