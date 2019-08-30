#include <stdio.h>
#include <string.h>

int inverte(int a);

int main(){

int casos;
    scanf("%d", &casos);

    while(casos--){
        int num, rev;
        scanf("%d", &num);
        rev = inverte(num);
        if(num == rev){
            printf("sim ");
        } else {
            printf("nao ");
        }
    }
    printf("\n");
}

int inverte(int x){
    int a = x / 1000;
    int b = x / 100 % 10;
    int c = x % 100 / 10;
    int d = x % 10;

    return d * 1000 + c * 100 + b * 10 + a;
}
