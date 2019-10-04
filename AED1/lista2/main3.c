#include<stdio.h>
#include<stdlib.h>

char** inicializaCampoDeBatalha(int, int);
int batalhaNaval(char**, int);
void imprimeCampo(char**, int, int);
int verificaNavios(char**, int, int);

int main()
{
    int linhas, colunas;
    scanf("%d %d", &linhas, &colunas);
    getchar();

    char** tabuleiro = inicializaCampoDeBatalha(linhas, colunas);

    imprimeCampo(tabuleiro, linhas, colunas);

    int numDisparos;
    scanf("%d", &numDisparos);

    int naviosDestruidos = batalhaNaval(tabuleiro, numDisparos);

    printf("%d\n", naviosDestruidos);

    return 0;
}

char** inicializaCampoDeBatalha(int linhas, int colunas)
{
    int i, j;
    char** matriz = (char**) malloc(sizeof(char*) * linhas);
    for (i = 0; i < linhas; i++)
    {
        matriz[i] = (char*) malloc(sizeof(char) * colunas);
        for (j = 0; j < colunas; j++)
        {
            scanf("%c", &matriz[i][j]);
            getchar();
        }
    }
    return matriz;
}

int batalhaNaval(char** tabuleiro, int disparos)
{
    int i, x, y;
    for(i = 0; i < disparos; i++){
        scanf("%d %d", &x, &y);
        tabuleiro[x][y] = tabuleiro[x][y] == 'a' ? tabuleiro[x][y] : '0';
        tabuleiro[x][y] = tabuleiro[x][y] == '#' ? tabuleiro[x][y] : '.';
    }

    return verificaNavios(tabuleiro, 0, 0);
}

void imprimeCampo(char** campoBatalha, int linhas, int colunas)
{
    int i, j;
    for(i = 0; i < linhas; i++){
        for(j = 0; j < colunas; j++){
            printf("%c ", campoBatalha[i][j]);
        }
        printf("\n");
    }
}

int verificaNavios(char** tabuleiro, int x, int y){
    int i, j;

    if(){

    }
}