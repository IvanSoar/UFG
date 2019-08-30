#include <stdio.h>
#include <math.h>

int main() {

    float num1, num2, num3, aux;

    scanf("%f", &num1);
    scanf("%f", &num2);
    scanf("%f", &num3);

    if(num2 >= num1) {
        aux = num1;
        num1 = num2;
        num2 = aux;
    }

    if (num3 >= num1) {
        aux = num1;
        num1 = num3;
        num3 = aux;
    }

    if(num3 >= num2) {
        aux = num3;
        num3 = num2;
        num2 = aux;
    }

    printf("%.2f, %.2f, %.2f", truncf(num3*100.0)/100.0, truncf(num2*100.0)/100.0, truncf(num1*100.0)/100.0);

    return 0;
}
