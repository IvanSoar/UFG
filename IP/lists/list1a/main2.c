#include <stdio.h>
#include <math.h>

int main(){

    float salario, kw, custoPorKw, custoTotal, custoComDesconto;

    scanf("%f", &salario);
    scanf("%f", &kw);

    custoPorKw = salario*0.7;
    custoTotal = custoPorKw*kw;
    custoComDesconto = custoTotal*0.9;

    printf("Custo por kW: R$ %.2f\n", truncf(custoPorKw)/100.0);
    printf("Custo do consumo: R$ %.2f\n", truncf(custoTotal)/100.0);
    printf("Custo com desconto: R$ %.2f\n", truncf(custoComDesconto)/100.0);

    return 0;
}
