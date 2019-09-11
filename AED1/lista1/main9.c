#include <stdio.h>
#include <stdlib.h>

int* stringInt(char*);

int main()
{
    char string1[50];
    char string2[50];
    int resultado[10000];
    int i, casos, l;

    scanf("%d", &casos);

    for(l = 0; l < casos; l++){
        scanf("%s", string1);
        scanf("%s", string2);

        int* numero1= stringInt(string1);
        int* numero2 = stringInt(string2);

        int menor = numero1[0] > numero2[0] ? numero2[0] : numero1[0];
        int auxiliar = 0;

        for (i = 0; i < menor; i++)
        {
            resultado[i] = numero1[i+1] * numero2[i+1] + auxiliar;

            if(resultado[i] > 9){
                auxiliar = resultado[i] / 10;
                resultado[i] %= 10;
            } else {
                auxiliar = 0;
            }
        }

        int* vetorMaior = numero1[0] > numero2[0] ? numero1 : numero2;

        for (i = menor; i < vetorMaior[0]; i++)
        {
            resultado[i] = vetorMaior[i + 1] + auxiliar;

            if(resultado[i] > 9){
                auxiliar = resultado[i] / 10;
                resultado[i] %= 10;
            } else {
                auxiliar = 0;
            }
        }

        if(auxiliar > 0){
            resultado[vetorMaior[0]] = auxiliar;
            resultado[vetorMaior[0] + 1] = -1;
        } else {
            resultado[vetorMaior[0]] = -1;
        }
        

        int tamanhoResultado = 0;
        for (i = 0; resultado[i] != -1; i++)
        {
            tamanhoResultado++;
        }

        for (i = tamanhoResultado - 1; i >=0; i--)
        {
            printf("%d", resultado[i]);
        }
        printf("\n");
    }
}

int* stringInt(char* string)
{
    int tamanho, i, j;
    for (i = 0;; i++)
    {
        if(string[i] == '\0')
        {
            tamanho = i;
            break;
        }
    }

    int* vetor = (int*) malloc((sizeof(int) * tamanho) + 1);
    
    vetor[0] = tamanho;

    for (i = tamanho - 1, j = 1; i >= 0; i--, j++)
    {
        vetor[j] = string[i] - '0';
    }
    
    return vetor;
}