#include <stdio.h>
 
int main(){
    float n, i, k, s;
    int cont;
    
    scanf("%f %f %f %f", &n, &i, &k, &s);
    
    printf("Tabuada de soma:\n");
    for (cont = 0; cont < k; cont++){
        printf("%.2f + %.2f = %.2f\n", n, i + s*cont, n + (i+s*cont));
    }
    
    printf("Tabuada de subtracao:\n");
    for (cont = 0; cont < k; cont++){
        printf("%.2f - %.2f = %.2f\n", n, i + s*cont, n - (i+s*cont));
    }
    
    printf("Tabuada de multiplicacao:\n");
    for (cont = 0; cont < k; cont++){
        printf("%.2f x %.2f = %.2f\n", n, i + s*cont, n * (i+s*cont));
    }
    
    printf("Tabuada de divisao:\n");
    for (cont = 0; cont < k; cont++){
        printf("%.2f / %.2f = %.2f\n", n, i + s*cont, n / (i+s*cont));
    }
}