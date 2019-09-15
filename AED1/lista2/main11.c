#include <stdio.h>

void converte(int);

int main()
{
    int numero, casos, i;
    scanf("%d", &casos);

    for (i = 0; i < casos; i++)
    {
        scanf("%d", &numero);
        converte(numero);
        printf("\n");
    }    
}

void converte(int numero)
{
    if(numero > 0)
    {
        converte(numero / 2);
        printf("%d", numero % 2);
    }    
}