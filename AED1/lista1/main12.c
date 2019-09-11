#include<stdio.h>
#include<stdlib.h>

int** alocaMatriz(int, int);
void imprimeMatriz(int **, int, int);
int** inverteMatriz(int **, int);
int calculaDeterminante(int *, int);
int deletaLinhaColuna(int *, int *, int, int, int);
int** matrizOrdemMenor(int **, int);
int** transpoeMatriz(int **, int, int);

int main()
{
    //declarações
    int linhas, colunas;
    char operador;
    int** matrizTransposta;
    int** matrizInversa;
    int determinante = 0;

    //entradas
    scanf("%d %d", &linhas, &colunas);
    int** matriz = alocaMatriz(linhas, colunas);
    getchar();
    scanf("%c", &operador);

    //verifica ordem de acordo com a operação
    if(operador == 'I' || operador == 'D' && linhas != colunas){
        printf("ERROR\n");
        return 0;
    }

    //verifica operação e imprime resultados
    switch(operador){
        case 'I': 
            imprimeMatriz(inverteMatriz(matriz, linhas), linhas, colunas);
            break;
        case 'D':
            printf("%d\n", calculaDeterminante(*matriz, linhas));
            break;

        case 'T':
            imprimeMatriz(transpoeMatriz(matriz, colunas, linhas), colunas, linhas);
            break;
    }
}

int** alocaMatriz(int linhas, int colunas){
    int i, j;
    int** matriz = (int**) malloc(sizeof(int*) * linhas);
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (int*) malloc(sizeof(int) * colunas);
        for (j = 0; j < colunas; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }
    return matriz;
}

void imprimeMatriz(int** matriz, int linhas, int colunas){
    int i, j;
    for (i = 0; i < linhas; i++)
    {
        for (j = 0; j < colunas; j++)
        {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int** inverteMatriz(int** matriz, int tamanho)
{

}

int calculaDeterminante(int *matriz, int tamanho)
{
    int determinante = 0, *matriz2, i;

    if(tamanho == 0)
    return 0;

    if(tamanho == 1)
    return *matriz;

    matriz2 = (int *) malloc(sizeof(int) * tamanho * tamanho);

    for(i = 0; i < tamanho; i++)
    {
        deletaLinhaColuna(matriz, matriz2, 0, i, tamanho); 
        
        if(i % 2)
            determinante -= calculaDeterminante(matriz2, tamanho - 1) * *(matriz + i); //Se for par soma determinante de m2
        else
            determinante += calculaDeterminante(matriz2, tamanho - 1) * *(matriz + i); //Se impar subtrai a determ. de m2
    }
    return determinante;
}

int deletaLinhaColuna(int *matriz, int *matriz2, int linha, int coluna, int tamanho)
{
  int cont;

  // Copia a Matriz m para m2
  for(cont = 0; cont < tamanho * tamanho; cont++)
      *(matriz2 + cont) = *(matriz + cont);

  // Exclui a linha lin ( A ultima linha eh excluida automaticamente atraves
  // da expressao s*(s-1) )
  for(cont = 0; cont < tamanho *(tamanho - 1); cont++)
     if(cont >= (linha * tamanho))
        *(matriz2 + cont) = *(matriz2 + cont + tamanho);

  //Exclui a coluna col ( A ultima coluna eh excluida automaticamente atraves
  // da expressao (s-1)*(s-1) )
  for(cont = 0; cont < (tamanho - 1) * (tamanho - 1); cont++)
     if(!((cont - coluna) % tamanho))
        *(matriz2 + cont) = *(matriz2 + cont + 1);
        
  return 0;
}

int** matrizOrdemMenor(int** matriz, int tamanho)
{

}

int** transpoeMatriz(int** matriz, int linhas, int colunas)
{
    int i, j;
    int** resultado = (int**) malloc(sizeof(int*) * linhas);
    for (i = 0; i < linhas; i++)
    {
        resultado[i] = (int*) malloc(sizeof(int) * colunas);
        for (j = 0; j < colunas; j++)
        {
            resultado[i][j] = matriz[j][i];
        }
    }
    return resultado;
}