#include <stdio.h>

int main(){
    int a, b, max;
    char opr;
    int res;

    scanf("%d", &max);
    scanf("%d %c %d", &a, &opr, &b);

    if(opr == '+'){
        res = a + b;
    } else if (opr == 'x'){
        res = a * b;
    }

    //printf("%d\n", res);

    if(res > max){
        printf("overflow\n");
    } else {
        printf("no overflow\n");
    }
}
