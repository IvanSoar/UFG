#include <stdio.h>

int main(){
	
	int n, i, ant = 0, cont = 0, guarda = 0, seq = 0;
	
	scanf("%d\n", &n);
	
	for(i = 0; i < n; i++){
		
		scanf("%d", &seq);
	
		if(seq > ant){
			
			cont++;
			if (cont > guarda){
				guarda = cont;
			}
			
		} else {
			cont = 0;
		}
		
		ant = seq;
	}
	
	printf("O comprimento do segmento de numeros iguais e: %d\n", guarda);
}