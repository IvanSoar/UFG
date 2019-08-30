#include <stdio.h>
#include <math.h>

int main(){

    float temper, chuva;

    scanf("%f", &temper);
    scanf("%f", &chuva);

    temper = 5*(temper-32)/9;
    chuva = chuva*25.4;

    printf("O VALOR EM CELSIUS = %.2f\n", truncf(temper*100.0)/100.0);
    printf("A QUANTIDADE DE CHUVA E = %.2f\n", truncf(chuva*100.0)/100.0);

    return 0;
}
