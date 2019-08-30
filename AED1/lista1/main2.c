#include <stdio.h>

int inverte(int*);

int main(){
    int a, b;

    scanf("%d %d", &a, &b);

    a = inverte(&a);
    b = inverte(&b);

    printf("%d\n", a > b ? a : b);
}

int inverte(int *a){
    return ((*a % 10) * 100) + ((*a % 100 / 10) * 10) + *a / 100;
}
