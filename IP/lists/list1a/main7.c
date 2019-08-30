#include <stdio.h>
#include <math.h>

int main(){

    int hora, minuto, segundo;

    scanf("%d", &hora);
    scanf("%d", &minuto);
    scanf("%d", &segundo);

    printf("O TEMPO EM SEGUNDOS E = %.1d\n", hora*60*60+minuto*60+segundo);

    return 0;
}
