#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c, d, aux;

    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);
    scanf("%f", &d);

    if(b < a){
        aux = b;
        b = a;
        a = aux;
    }

    if(c < b){
        aux = c;
        c = b;
        b = aux;
    }

    if(d < c){
        aux = d;
        d = c;
        c = aux;
    }

    if(b < a){
        aux = b;
        b = a;
        a = aux;
    }

    if(c < b){
        aux = c;
        c = b;
        b = aux;
    }

    printf("%.2f, %.2f, %.2f, %.2f\n", a, b, c, d);

    return 0;
}
