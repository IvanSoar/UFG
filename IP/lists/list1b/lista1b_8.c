#include <stdio.h>
#include <math.h>

int main(){

    int ano;

    scanf("%i", &ano);

    if(ano > 1582 && ano%4 == 0 && ano%100 !=0){
            printf("ANO BISSEXTO");
    }
    else {
            if(ano > 1582 && ano%4 == 0 && ano%400 ==0){
                    printf("ANO BISSEXTO");
            }
            else {
                printf("ANO NAO BISSEXTO");
            }
    }

    return 0;
}

