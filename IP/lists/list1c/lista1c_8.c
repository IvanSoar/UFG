#include <stdio.h>
void ordena(int *a, int *b);
 
int main() {
 
    unsigned int anos, a, b;
    float soma1, soma2;
 
    scanf("%d", &a);
    scanf("%d", &b);
	
	ordena(&a, &b);
 
    soma1 = (float)a;
    soma2 = (float)b;
 
    anos = 0;
    while(soma1 < soma2) {
        soma1 *= 1.03;
        soma2 *= 1.015;
        anos++;
    }
 
    printf("ANOS = %d\n", anos);
}

void ordena(int *a, int *b){
	int aux;
	
	printf("%d, %d\n", *a, *b);
	
	if(a > b){
		aux = *a;
		*a = *b;
		*b = aux;
	}
	
	printf("%d, %d\n", *a, *b);
}