#include <stdio.h>
 
int main(){
    int n, i, fatorial;
    
    scanf("%d", &n);
    
    fatorial = n;
    
    for (i = n-1; i > 0; i--){
        fatorial *= i;
    }
    
    if(n == 0){
        fatorial = 1;
    }
    
    printf("%d! = %d\n", n, fatorial);
}