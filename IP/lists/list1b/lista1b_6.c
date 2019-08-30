#include <stdio.h>
#include <math.h>

int main(){

    float salario;

    scanf("%f", &salario);

    if(salario > 300){
        salario *= 1.3;
    }
    else {
        salario *= 1.5;
    }

    printf("SALARIO COM REAJUSTE = %.2f\n", truncf(salario*100.0)/100.0);

    return 0;
}
