#include <stdio.h>
#include <math.h>

int main(){

    int horas;
    float hint, hqueb, valor;

    scanf("%i", &horas);

    hint = horas / 3 * 10;
    hqueb = horas % 3 * 5;
    valor = hint + hqueb;

    printf("O VALOR A PAGAR E = %.2f\n", truncf(valor*100.0)/100.0);

    return 0;
}
