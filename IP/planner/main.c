#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CONTATO
{
    int codigo;
    char *nome;
    int tamNome;
} contato;

contato *adicionaContato(contato *agenda, int tamAgenda);
void organizaAgenda(contato *agenda, int tamAgenda);
void imprimeAgenda(contato *agenda, int tamAgenda);
void salvaAgenda(contato *agenda, int tamAgenda, FILE *pContatos);
int leAgenda(contato *agenda, FILE *pContatos);

int main()
{
    system("cls");
    FILE *pContatos;
    int i, j;
    int contadorContatos = 0;
    contato *agenda = NULL;
    contato *novosContatos = NULL;

    pContatos = fopen("./dados", "rb+");
    if (!pContatos)
    {
        fprintf(stderr, "Arquivo de dados nao encontrado. Criando...\n");
        pContatos = fopen("./dados", "wb+");
        if (!pContatos)
        {
            fprintf(stderr, "Sem memoria suficiente para executar o programa! Fechando...\n");
            return 1;
        }
        else
        {
            fprintf(stderr, "Arquivo de dados criado com sucesso!\n");
        }
    }
    else
    {
        contadorContatos = leAgenda(agenda, pContatos);
        if (!contadorContatos)
        {
            fprintf(stderr, "Arquivo sem dados\n");
        }
        else
        {
            fprintf(stderr, "Arquivos com %d contato(s) salvo(s).\n", contadorContatos);
        }
    }

    int comando;
    while (1)
    {
        printf("Digite 0 para sair, 1 para adicionar contatos, 2 para imprimir contatos.\n");
        scanf("%d", &comando);
        switch (comando)
        {
        case 0:
            fprintf(stderr, "Digite s para salvar ou qualquer tecla para sair e descartar todas as modificacoes.\n");
            getchar();
            if (getchar() == 's')
            {
                salvaAgenda(agenda, contadorContatos, pContatos);
                fclose(pContatos);
                return 0;
            }
            else
            {
                fprintf(stderr, "Saindo sem salvar...");
                return 0;
            }
        case 1:
            agenda = adicionaContato(agenda, contadorContatos);
            contadorContatos++;
            fprintf(stderr, "contato inserido com sucesso!\n");
            break;
        case 2:
            fprintf(stderr, "Contatos impressos...\n");
            imprimeAgenda(agenda, contadorContatos);
            printf("\n");
            break;
        }
    }
    return 0;
}

contato *adicionaContato(contato *temp, int tamAgenda)
{
    contato *agenda = (contato *)realloc(temp, sizeof(contato) * tamAgenda + 1);
    if (!agenda)
    {
        fprintf(stderr, "Erro malloc !\n");
        exit(1);
    }
    char buff[100];
    agenda[tamAgenda].codigo = tamAgenda;
    getchar();
    scanf("%[^\n]", buff);
    getchar();
    agenda[tamAgenda].tamNome = strlen(buff);
    agenda[tamAgenda].nome = (char *)malloc(agenda[tamAgenda].tamNome + 1);
    strcpy(agenda[tamAgenda].nome, buff);

    return agenda;
}

void organizaAgenda(contato *agenda, int tamAgenda)
{
    int i, j;
    contato aux;
    for (i = 0; i < tamAgenda - 1; i++)
    {
        for (j = i + 1; j < tamAgenda; j++)
        {
            if (strcmp(agenda[i].nome, agenda[j].nome) > 0)
            {
                aux = agenda[i];
                agenda[i] = agenda[j];
                agenda[j] = aux;
            }
        }
    }
}

void imprimeAgenda(contato *agenda, int tamAgenda)
{
    int i;
    for (i = 0; i < tamAgenda; i++)
    {
        fprintf(stderr, "Codigo: %d\t", agenda[i].codigo);
        fprintf(stderr, "Nome: %s\t", agenda[i].nome);
        fprintf(stderr, "Chars: %d\n", agenda[i].tamNome);
    }
}

void salvaAgenda(contato *agenda, int tamAgenda, FILE *pContatos)
{
    int i;
    for (i = 0; i < tamAgenda; i++)
    {
        fwrite(&(agenda[i].codigo), sizeof(int), 1, pContatos);
        fwrite(&(agenda[i].tamNome), sizeof(int), 1, pContatos);
        fwrite(agenda[i].nome, agenda[i].tamNome, 1, pContatos);
    }
}

int leAgenda(contato *agenda, FILE *pContatos)
{
    int i = 0;
    int cod;
    char buff[100];
    while (!feof(pContatos))
    {
        if (!fread(&cod, sizeof(int), 1, pContatos))
        {
            return i;
        }
        else
        {
            //contato *temp = NULL;
            agenda = (contato *)realloc(agenda, sizeof(contato) * (i + 1));
            if (!agenda)
            {
                fprintf(stderr, "Erro malloc 1!\n");
            }
            agenda[i].codigo = cod;
            fread(&(agenda[i].tamNome), sizeof(int), 1, pContatos);
            fread(buff, agenda[i].tamNome, 1, pContatos);
            agenda[i].nome = (char *)malloc(agenda[i].tamNome + 1);
            if (!agenda[i].nome)
            {
                fprintf(stderr, "Erro malloc 2!\n");
            }
            strcpy(agenda[i].nome, buff);

            fprintf(stderr, "Codigo: %d\t", agenda[i].codigo);
            fprintf(stderr, "Nome: %s\t", agenda[i].nome);
            fprintf(stderr, "Chars: %d\n", agenda[i].tamNome);

            i++;
        }
    }
}