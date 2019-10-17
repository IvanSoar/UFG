#include <stdio.h>
#include <math.h>

int main()
{
    int a, b, c, k, casos, i;
    double x1, delta;

    scanf("%d", &casos);
    while (casos--)
    {
        scanf("%d %d %d %d", &a, &b, &c, &k);

        c = c - k;
        delta = pow(b, 2.0) - (4.0 * a * c);
        x1 = (-b + sqrt(delta)) / (2.0 * a);
        int result = ceil(x1);
        printf("%d\n", result);
    }

    return 0;
}