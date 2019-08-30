#include <stdio.h>
#include <math.h>

int main() {

    float a, b, c, peri, area, dife;
    int flag = 0;

    scanf("%f %f %f", &a, &b, &c);

    dife = b - c;
    if(dife < 0) {
        dife *= -1;
    }
    if (dife < a && a < b  + c) {
        flag = 1;
    }

    dife = a - c;
    if(dife < 0) {
        dife *= -1;
    }
    if (dife < b && b < a  + c) {
        flag = 1;
    }

    dife = a - b;
    if(dife < 0) {
        dife *= -1;
    }
    if (dife < c && c < a  + b) {
        flag = 1;
    }

    if (flag == 1) {
        peri = a + b + c;
        printf("Perimetro = %.1f\n", peri);
    } else {
        area = ((a+b)*c)/2;
        printf("Area = %.1f\n", area);
    }

    return 0;
}
