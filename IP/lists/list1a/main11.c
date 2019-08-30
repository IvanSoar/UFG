#include <stdio.h>
#include <math.h>

int main(){

    int numero, num1, num2, num3, saida;

    scanf("%i", &numero);

    num2 = (numero/10)%10;
    num3 = numero%10;
    num1 = (numero-num2*10-num3)/100;

    saida = num3*100 + num2 * 10 + num1;

    printf("%i\n", saida);

    return 0;
}
