#include <stdio.h>

int main() {

    int data, dia, mes, ano;

    scanf("%d", &data);

    ano = data % 10000;
    mes = (data % 1000000 - ano) / 10000;
    dia = (data % 100000000 - ano - mes) / 1000000;

    if(mes > 12 || dia > 31 || dia <= 0 || mes <= 0) {
        if(mes == 2 && dia > 28) {
            printf("Data invalida!\n");
        }
        printf("Data invalida!\n");
    } else {
        if(mes == 1) {
            printf("%d de janeiro de %d\n", dia, ano);
        }
        if(mes == 2) {
            printf("%d de fevereiro de %d\n", dia, ano);
        }
        if(mes == 3) {
            printf("%d de março de %d\n", dia, ano);
        }
        if(mes == 4) {
            printf("%d de abril de %d\n", dia, ano);
        }
        if(mes == 5) {
            printf("%d de maio de %d\n", dia, ano);
        }
        if(mes == 6) {
            printf("%d de junho de %d\n", dia, ano);
        }
        if(mes == 7) {
            printf("%d de julho de %d\n", dia, ano);
        }
        if(mes == 8) {
            printf("%d de agosto de %d\n", dia, ano);
        }
        if(mes == 9) {
            printf("%d de setembro de %d\n", dia, ano);
        }
        if(mes == 10) {
            printf("%d de outubro de %d\n", dia, ano);
        }
        if(mes == 11) {
            printf("%d de novembro de %d\n", dia, ano);
        }
        if(mes == 12) {
            printf("%d de dezembro de %d\n", dia, ano);
        }
        return 0;
    }
}
