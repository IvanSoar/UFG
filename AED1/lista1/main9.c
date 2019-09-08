#include<stdio.h>

int verificaTamanho(int *);

int main(int argc, char const *argv[])
{
    int casos, num1[40], num2[40], i, tamNum1, tamNum2;

    scanf("%d", &casos);

    for(i = 0; i < casos; i++){
        scanf("%s", &num1);
        scanf("%s", &num2);
    }

    // tamNum1 = verificaTamanho(num1);
    // tamNum2 = verificaTamanho(num2);
    printf("%d\n", verificaTamanho(num1));
    printf("%d\n", verificaTamanho(num2));

    return 0;
}

int verificaTamanho(int * numero){
    int i;
    for(i = 0; 1; i++){
        printf("%d\n", (int)numero[i]);
        if(numero[i] == '\0' || numero[i] == '\n'){
            return i;
        }
    }
}
    