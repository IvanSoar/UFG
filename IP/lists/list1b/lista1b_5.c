#include <stdio.h>
#include <math.h>

int main(){

    float nota;
    char conceito;

    scanf("%f", &nota);

    if(nota < 6.0){conceito = 'D';}
    if(nota >= 6.0 && nota < 7.5){conceito = 'C';}
    if(nota >= 7.5 && nota < 9.0){conceito = 'B';}
    if(nota >= 9.0){conceito = 'A';}

    printf("NOTA = %.1f CONCEITO = %c", nota, conceito);

    return 0;
}
