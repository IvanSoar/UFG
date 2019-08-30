#include <stdio.h>
#include <math.h>

int main(){

    int a, b, c, d, soma, aux;

    scanf("%i", &a);
    scanf("%i", &b);
    scanf("%i", &c);
    scanf("%i", &d);

    if (d > c){
        aux = c;
        c = d;
        d = aux;
    }

    if (c > b){
        aux = b;
        b = c;
        c = aux;
    }

    if (b > a){
        aux = a;
        a = b;
        b = aux;
    }

    soma = d + c + b;

    printf("%i\n", soma);

    return 0;
}
