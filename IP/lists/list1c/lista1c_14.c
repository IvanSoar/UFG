#include <stdio.h>

//declaração do protótipo
void processa(int t);

int main(){
	int n;
	
	scanf("%d", &n);
	
	if(n < 2){
		printf("Campeonato invalido!");
	} else {
		processa(n);
	}
}

void processa(int t){
	int i, j, cont = 1;
	
	for(i = 1; i <= t; i++){
		for (j = i + 1; j != i && j <= t; j++){
			printf("Final %d: Time%d X Time%d\n", cont, i, j);
			cont++;
		}
	}
}

