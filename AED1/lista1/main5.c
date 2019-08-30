#include <stdio.h>

int converte(int);
void seleciona(int);

int main(){
    int casos;
    scanf("%d", &casos);

    while(casos--){
        int num;
        scanf("%d", &num);
        converte(num);
        printf("\n");
    }
}

int converte(int num){
    if (num >= 4){
        converte(num / 4);
        seleciona(num % 4);
    } else {
        seleciona(num % 4);
    }
}

void seleciona(int a){
    switch(a){
    case 0 : printf("A"); break;
    case 1 : printf("C"); break;
    case 2 : printf("G"); break;
    case 3 : printf("T"); break;
    }
}
