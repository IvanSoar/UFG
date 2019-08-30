#include <stdio.h>
#include <math.h>

int main() {

    int a, b, c, aux;
    char um, dois, tres;

    scanf("%d %d %d\n", &a, &b, &c);
    scanf("%c%c%c", &um, &dois, &tres);

    if(b < a) {
        aux = a;
        a = b;
        b = aux;
    }

    if(c < b) {
        aux = c;
        c = b;
        b = aux;
    }

    if(b < a) {
        aux = a;
        a = b;
        b = aux;
    }

    if (um == 'A') {
        printf("%d ", a);
    }

    if (um == 'B') {
        printf("%d ", b);
    }

    if (um == 'C') {
        printf("%d ", c);
    }

    if (dois == 'A') {
        printf("%d ", a);
    }

    if (dois == 'B') {
        printf("%d ", b);
    }

    if (dois == 'C') {
        printf("%d ", c);
    }

    if (tres == 'A') {
        printf("%d", a);
    }

    if (tres == 'B') {
        printf("%d", b);
    }

    if (tres == 'C') {
        printf("%d", c);
    }

    return 0;
}
