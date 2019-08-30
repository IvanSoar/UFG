#include <stdio.h>
#include <math.h>

int main() {

    int numero, milhar, centena, dezena, unidade;

    scanf("%i", &numero);

    if(numero <= 0 || numero > 9999) {

        printf("Numero invalido!");

    } else {

        milhar = numero / 1000;
        centena = (numero - milhar*1000)/100;
        dezena = (numero - milhar * 1000 - centena*100)/10;
        unidade = numero - milhar * 1000 - centena*100 - dezena*10;

        if (numero > 999 && numero < 10000) {
            printf("(quarta ordem) ");
        }
        if (numero > 99 && numero < 1000 ) {
            printf("(terceira ordem) ");
        }
        if (numero > 9 && numero  < 100) {
            printf("(segunda ordem) ");
        }
        if (numero < 10) {
            printf("(primeira ordem) ");
        }

        printf("%i = ", numero);

        if(milhar != 0 ) {
            if(milhar == 1) {
                printf("%i unidade de milhar", milhar);
            } else {
                printf("%i unidades de milhar", milhar);
            }
        }

        if(milhar != 0 && centena+dezena+unidade != 0) {
            printf(" + ");
        }

        if(centena != 0 ) {
            if(centena == 1) {
                printf("%i centena", centena);
            } else {
                printf("%i centenas", centena);
            }
        }

        if(centena != 0 && dezena+unidade != 0) {
            printf(" + ");
        }

        if(dezena != 0 ) {
            if(dezena == 1) {
                printf("%i dezena", dezena);
            } else {
                printf("%i dezenas", dezena);
            }
        }

        if(dezena != 0 && unidade != 0) {
            printf(" + ");
        }

        if(unidade != 0 ) {
            if(unidade == 1) {
                printf("%i unidade", unidade);
            } else {
                printf("%i unidades", unidade);
            }
        }

        printf(" = ");

        if(milhar != 0) {
            printf("%i", milhar*1000);
        }

        if(milhar != 0 && centena+dezena+unidade != 0) {
            printf(" + ");
        }

        if(centena != 0) {
            printf("%i", centena*100);
        }

        if(centena != 0 && dezena+unidade != 0) {
            printf(" + ");
        }

        if(dezena != 0) {
            printf("%i", dezena*10);
        }

        if(dezena != 0 && unidade != 0) {
            printf(" + ");
        }

        if(unidade != 0) {
            printf("%i", unidade);
        }
    }
}
