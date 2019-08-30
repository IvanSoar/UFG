#include <stdio.h>

int main() {

    int carbono, dureza, resist, grau;

    scanf("%d", &carbono);
    scanf("%d", &dureza);
    scanf("%d", &resist);

    if(carbono < 7){
        if(dureza > 50){
            if(resist > 80000){
                grau = 10;
            } else {
                grau = 9;
            }
        } else {
            grau = 8;
        }
    } else {
        grau = 7;
    }

    printf("ACO DE GRAU = %d", grau);

    return 0;
}
