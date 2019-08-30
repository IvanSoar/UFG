#include <stdio.h>
#include <math.h>

int main(){

    int numero;

    scanf("%i", &numero);

    if (numero % 3 == 0 && numero % 5 == 0){
        printf("O NUMERO E DIVISIVEL\n");
    }
    else {
        printf("O NUMERO NAO E DIVISIVEL\n");
    }

    return 0;
}
