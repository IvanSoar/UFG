#include <stdio.h>
#include <math.h>

int main() {

    int x, y, i = 0;

    scanf("%d %d", &x, &y);

    if(x%2==0) {
        while(i < y){
            if(x % 2 == 0){
                printf("%d ", x);
                x++;
                i++;
            } else {
                x++;
            }
        }
    } else {
        printf("O PRIMEIRO NUMERO NAO E PAR");
    }

    return 0;
}
