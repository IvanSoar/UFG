#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c, delta, x1, x2, aux;

    scanf("%f %f %f", &a, &b, &c);

    delta = (b*b)-(4*a*c);

    if(delta > 0) {
        printf("RAIZES DISTINTAS\n");

        x1 = ((b*-1)+sqrt(delta))/(2*a);
        x2 = ((b*-1)-sqrt(delta))/(2*a);

        if(x1 < x2) {
            aux = x1;
            x1 = x2;
            x1 = aux;
        }

        printf("X1 = %.2f\n", truncf(x1*100.0)/100.0);
        printf("X2 = %.2f\n", truncf(x2*100.0)/100.0);
    }

    if(delta == 0) {
        printf("RAIZ UNICA\n");

        x1 = (b*-1)/(2*a);

        printf("X1 = %.2f\n", truncf(x1*100.0)/100.0);
    }

    if(delta < 0) {
        printf("RAIZES IMAGINARIAS\n");
    }

    return 0;
}
