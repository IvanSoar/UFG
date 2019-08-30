#include <stdio.h>
#include <math.h>

int main(){

    int numero, num1, num2, num3, num4, saida;

    scanf("%i", &numero);

    num2 = (numero/10)%10;
    num3 = numero%10;
    num1 = (numero-num2*10-num3)/100;

    num4 = (num1 + num2 * 3 + num3 * 5)%7;

    saida = num1*1000 + num2 * 100 + num3 * 10 + num4;

    printf("O NOVO NUMERO E = %i\n", saida);

    return 0;
}
