#include <stdio.h>

int fibonacci(int);
void fibonacciOrdinal(int);

int main()
{
    int ordinal;
    scanf("%d", &ordinal);
    fibonacciOrdinal(ordinal);
}

int fibonacci(int numero)
{
    if(numero < 2) {
        return numero;
    } else {        
        return fibonacci(numero - 1) + fibonacci(numero - 2);
    }
}

void fibonacciOrdinal(int numero){
    numero > 0? fibonacciOrdinal(numero - 1):1;
    printf("%d ",fibonacci(numero));
}