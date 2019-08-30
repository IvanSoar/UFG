#include <stdio.h>
#include <math.h>

int main(){

    float altura, aresta, areaBase, volume;

    scanf("%f %f", &altura, &aresta);

    areaBase = (((aresta*aresta)*3)*sqrt(3))/2;
    volume = (areaBase*altura)/3;

    printf("O VOLUME DA PIRAMIDE E = %.2f METROS CUBICOS\n", truncf(volume*100.0)/100.0);

    return 0;
}
