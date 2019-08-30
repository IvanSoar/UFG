#include <stdio.h>
#include <math.h>

int main() {

    int numero, a, b, c, d, e;

    scanf("%d", &numero);

    if(numero >= 100000) {
        printf("NUMERO INVALIDO");
    } else {

        if(numero <= 999 && numero > 99) {
            a = numero/100;
            b = numero%100/10;
            c = numero%100%10;

            if(a == c){
                printf("PALINDROMO");
            } else {
                printf("NAO PALINDROMO");
            }
        }

        if(numero <= 9999 && numero > 999) {
            a = numero/1000;
            b = numero%1000/100;
            c = numero%1000%100/10;
            d = numero%1000%100%10;

            if(a == d && b == c){
                printf("PALINDROMO");
            } else {
                printf("NAO PALINDROMO");
            }
        }

        if(numero <= 99999 && numero > 9999) {
            a = numero/10000;
            b = numero%10000/1000;
            c = numero%10000%1000/100;
            d = numero%10000%1000%100/10;
            e = numero%10000%1000%100%10;

            if(a == e && b == d){
                printf("PALINDROMO");
            } else {
                printf("NAO PALINDROMO");
            }
        }
    }
    return 0;
}
