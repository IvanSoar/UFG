#include <stdio.h>
#include <math.h>

int main() {

    int matricula, dependentes;
    float minimo, salario, imposto, bruto, liquido;

    scanf("%d %f %d %f %f", &matricula, &minimo, &dependentes, &salario, &imposto);

    if(salario / minimo > 12) {
        bruto = salario * 0.2;
    } else {
        if(salario / minimo > 5) {
            bruto = salario * 0.08;
        } else {
            bruto = 0;
        }
    }

    liquido = bruto - (dependentes * 300);

    printf("MATRICULA = %d\n", matricula);
    printf("IMPOSTO BRUTO = %.2f\n", truncf(bruto*100.0)/100.0);
    printf("IMPOSTO LIQUIDO = %.2f\n", truncf(liquido*100.0)/100.0);
    printf("RESULTADO = %.2f\n", truncf(((-imposto*salario)/100 + liquido)*100.0)/100.0);

    if(bruto - liquido > 0){
        printf("IMPOSTO A RECEBER\n");
    } else {
        if(bruto - liquido == 0){
            printf("IMPOSTO QUITADO\n");
        } else {
            printf("IMPOSTO A PAGAR\n");
        }
    }

    return 0;
}
