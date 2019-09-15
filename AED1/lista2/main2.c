#include <stdio.h>

int fibonacci(int);

int main()
{
    int ordinal;
    scanf("%d", &ordinal);

    printf("%d", fibonacci(ordinal));
}

int fibonacci(int numero)
{
    if(numero == 0)
        return 0;

    if(numero == 1 || numero == 2)
        return 1;

    printf("%d ", fibonacci(numero - 1) + fibonacci(numero - 2));
}