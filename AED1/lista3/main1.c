#include <stdio.h>

typedef struct Racional
{
    int numerador;
    int denominador;
} racional;

racional retornaRacionalPos(int);

int gcd(int, int);

int main()
{
    int entrada;
    scanf("%d", &entrada);

    while (entrada != 0)
    {
        racional temp = retornaRacionalPos(entrada);

        printf("%d/%d\n", temp.numerador, temp.denominador);

        scanf("%d", &entrada);
    }

    return 0;
}

racional retornaRacionalPos(int pos)
{

    int d, n, contador = 0;
    racional temp;

    for (d = 1; contador <= pos; d++)
    {
        for (n = 0; n <= d; n++)
        {
            if (gcd(n, d) == 1)
            {
                contador++;
                if (contador == pos)
                {
                    temp.numerador = n;
                    temp.denominador = d;
                }
            }
        }
    }
    return temp;
}

int gcd(int num1, int num2)
{
    if (num2 == 0)
    {
        return num1;
    }
    else
    {
        return gcd(num2, num1 % num2);
    }
}