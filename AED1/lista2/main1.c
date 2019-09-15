#include <stdio.h>

int naturais(int);

int main()
{
    int numero;
    scanf("%d", &numero);
    
    naturais(numero);
    
    printf("\n");
}

int naturais(int numero)
{
    if(numero - 1 > 0)
        naturais(numero - 1);

    printf("%d ", numero);
}