#include<stdio.h>
 
int reverso(int, int);
 
int main(){
    int numero;
    scanf("%d", &numero);
    reverso(numero, 0);
}
 
int reverso(int numero, int flag)
{
    int resto = numero % 10;
 
    if(numero > 0){
        flag = resto != 0 ? 1 : flag;
 
        if(flag)
            printf("%d", resto);
 
        return reverso(numero / 10, flag);
    } else {
        printf("\n");
    }
}