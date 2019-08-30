#include <stdio.h>
#include <math.h>

int main() {

    int n;
    float soma, i;

    scanf("%d", &n);

    if(n < 1) {
        printf("NUMERO INVALIDO");
    } else {
        for(i = 1.0; i <= n; i++) {
            soma += (1 / i);
        }
    }

    printf("%.6f\n", i, trunc(1/i*1000000.0)/1000000.0);

    return 0;
}
