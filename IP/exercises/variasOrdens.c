//
//  variasOrdens.c

#include <stdio.h>
#include <math.h>

void troca (float *i, float *j){
	float aux;
	aux =*i;
	*i = *j;
	*j = aux;
}

void ordenaCrescente(float *x, float *y, float *z ){
	//ordena os valores apontados por x, y e z, de tal modo que eles
	//fiquem em ordem crescente: *x <= *y <= *z
	if(*x > *y){
			troca (x,y); //O menor entre *x e *y esta em *x
	}
	if(*x > *z){
		troca (x,z); //O menor entre *x, *y e *z esta em *x
	}
	if(*y > *z){
		troca (y,z); //agora, *x <= *y <= *z
	}
}

void imprime (int x, float y, float w, float z){
				switch (x) {
					case 1: // imprime em ordem crescente
						printf ("%.2f %.2f %.2f\n", truncf(y*100.0)/100.0,truncf(w*100.0)/100.0, truncf(z*100.0)/100.0);
						break;
					case 2:// imprime em ordem decrescente
						printf ("%.2f %.2f %.2f\n", truncf(z*100.0)/100.0,truncf(w*100.0)/100.0, truncf(y*100.0)/100.0);
						break;
					case 3: //imprime o segundo maior, o maior e o menor
						printf ("%.2f %.2f %.2f\n", truncf(w*100.0)/100.0,truncf(z*100.0)/100.0, truncf(y*100.0)/100.0);
						break;
					default:// Nao ha nada a fazer
						break;
				}
	}

int main(){
	int i;
	float a,b,c;
	scanf("%d", &i);
	scanf("%f", &a);
	scanf("%f", &b);
	scanf("%f", &c);
	ordenaCrescente(&a, &b, &c);
	imprime (i, a, b, c);

}