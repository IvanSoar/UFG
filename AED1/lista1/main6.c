#include<stdio.h>

int main(){

    int rotulos, tipos, i, temp;

    scanf("%d %d", &rotulos, &tipos);

    int menor = rotulos + 1;
    int embalagens[tipos];

    for(i = 0; i < tipos; i++){
        embalagens[i] = 0;
    }

    for(i = 0; i < rotulos; i++){
        scanf("%d", &temp);
        embalagens[temp - 1] += temp < tipos + 1 ? 1 : 0;
    }

    for(i = 0; i < tipos; i++){
        menor = menor > embalagens[i] ? embalagens[i] : menor;
    }

    printf("%d\n", menor);

    return 0;
}