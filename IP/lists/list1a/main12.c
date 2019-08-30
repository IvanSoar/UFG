#include <stdio.h>
#include <math.h>

int main(){

    int valor, notas100, notas50, notas10, moeda;

    scanf("%i", &valor);

    notas100 = valor/100;
    notas50 = valor%100/50;
    notas10 = valor%100%50/10;
    moeda = valor%100%50%10;

    printf("NOTAS DE 100 = %i\n", notas100);
    printf("NOTAS DE 50 = %i\n", notas50);
    printf("NOTAS DE 10 = %i\n", notas10);
    printf("MOEDAS DE 1 = %i\n", moeda);

    return 0;
}
