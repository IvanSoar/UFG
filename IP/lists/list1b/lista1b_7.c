#include <stdio.h>
#include <math.h>

int main(){

    int x, y;

    scanf("%i", &x);

    if (x < 1){y = x;}
    if (x == 1){y = 0;}
    if (x > 1){y = x*x;}

    printf("Y = %i\n", y);

    return 0;
}
