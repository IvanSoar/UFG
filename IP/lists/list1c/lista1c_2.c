#include <stdio.h>
#include <math.h>

int main() {

    int numero, i;

    scanf("%i", &numero);

    float fah[numero+1], cel[numero+1];

    for(i = 0; i < numero; i++){
        scanf("%f", &fah[i]);
        cel[i] = (5 * (fah[i]-32))/9;
    }

    for(i = 0; i < numero; i++){
        printf("%.2f FAHRENHEIT EQUIVALE A %.2f CELSIUS\n", fah[i], truncf(cel[i]*100.0)/100.0);
    }

    return 0;
}
