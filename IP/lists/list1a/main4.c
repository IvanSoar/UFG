#include <stdio.h>
#include <math.h>

int main(){

    float raio, altura, valor, areaCir, areaLat, valorpi;

    scanf("%f", &raio);
    scanf("%f", &altura);

    valorpi = 3.14159;
    areaCir = valorpi*raio*raio;
    areaLat = 2*valorpi*raio*altura;
    valor = (2*areaCir+areaLat)*100;

    printf("O VALOR DO CUSTO E = %.2f\n", truncf(valor*100.0)/100.0);

}
