#include <stdio.h>
#include <math.h>

int main(){

    int codigo;
    float consumo, valorConta;
    char tipo;

    scanf("%i %f %c", &codigo, &consumo, &tipo);

    if(tipo == 'R'){
            valorConta = consumo*0.05+5.0;
    }

    if(tipo == 'C'){
            valorConta = ((consumo-80)*0.25)+500.0;
    }

    if(tipo == 'I'){
            valorConta = ((consumo-100)*0.04)+800.0;
    }

    printf("CONTA = %i\n", codigo);
    printf("VALOR DA CONTA = %.2f\n", truncf(valorConta*100.0)/100.0);

    return 0;
}
