#include <stdio.h>
#define HALLEY 1986
#define DELAY 76

int calcula(int);

int main(){
    int anoAtual;
-
    scanf("%d", &anoAtual);

    printf("%d\n", calcula(anoAtual));
}

int calcula(int ano){
    if(ano % HALLEY <= 0){
        return HALLEY + DELAY;
    } else {
        return (((ano - HALLEY) / DELAY + 1) * DELAY) + HALLEY;
    }
}
