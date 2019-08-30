#include <stdio.h>
#include <math.h>

int main(){

    float a, b, c, x, area;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    x = (a+b+c)/2;
    area = sqrt(x*(x-a)*(x-b)*(x-c));

    printf("A AREA DO TRIANGULO E = %.2f\n", truncf(area*100.0)/100.0);

    return 0;
}
