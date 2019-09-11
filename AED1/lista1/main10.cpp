#include <iostream>
#include <cmath>
#define PI 3.14159265

int circulo(int);
int elipse(int, int);
int triangulo(int, int, int);
int trapezio(int, int, int);

int main()
{
    int casos;
    char figura;

    std::cin >> casos;

    for (int i = 0; i < casos; i++)
    {
        std::cin >> figura;
        switch(figura)
        {
            case 'C':
                int raio;
                std::cin >> raio;
                std::cout << circulo(raio) << std::endl;
            break;

            case 'E':
                int raioMaior, raioMenor;
                std::cin >> raioMaior;
                std::cin >> raioMenor;
                std::cout << elipse(raioMaior, raioMenor) << std::endl;
            break;

            case 'T':
                int ladoA, ladoB, ladoC;
                std::cin >> ladoA;
                std::cin >> ladoB;
                std::cin >> ladoC;
                std::cout << triangulo(ladoA, ladoB, ladoC) << std::endl;
            break;

            case 'Z':
                int baseMaior, baseMenor, altura;
                std::cin >> baseMaior;
                std::cin >> baseMenor;
                std::cin >> altura;
                std::cout << trapezio(baseMaior, baseMenor, altura) << std::endl;
            break;
        }
    }    
}

int circulo(int raio)
{
    return (raio * raio * PI) + 0.5;
}

int elipse(int raioMaior, int raioMenor)
{
    return (raioMaior * raioMenor * PI) + 0.5;
}

int triangulo(int ladoA, int ladoB, int ladoC)
{
    double semiperimetro = (ladoA + ladoB + ladoC) / 2.0;
    return (sqrt(semiperimetro * (semiperimetro - ladoA) * (semiperimetro - ladoB) * (semiperimetro - ladoC))) + 0.5;
}

int trapezio(int baseMaior, int baseMenor, int altura)
{
    return ((baseMaior + baseMenor) / 2.0)  * altura;
}