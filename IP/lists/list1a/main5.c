#include <stdio.h>
#include <math.h>

int main(){

    float a, b, c, delta;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    delta = pow(b, 2) - 4 * a * c;

    printf("O VALOR DE DELTA E = %.2f", truncf(delta*100.0)/100.0);


}
