#include <stdio.h>
#include <math.h>

int main() {

    int i;
    float a, b, c, aux;

    scanf("%d", &i);
    scanf("%f", &a);
    scanf("%f", &b);
    scanf("%f", &c);

    if(b < a){
        aux = a;
        a = b;
        b = aux;
    }

    if(c < b){
        aux = b;
        b = c;
        c = aux;
    }

    if(b < a){
        aux = a;
        a = b;
        b = aux;
    }

    if (i == 1){
        printf("%.2f %.2f %.2f\n", a, b, c);
    }

    if (i == 2){
        printf("%.2f %.2f %.2f\n", c, b, a);
    }

    if (i == 3){
        printf("%.2f %.2f %.2f\n", b, c, a);
    }

    return 0;
}
