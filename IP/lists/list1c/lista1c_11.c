#include <stdio.h>
 
int main(){
	int n, i, cont = 0;
	
	scanf("%d\n", &n);
	
	float vetor[n];
	
	for (i = 0; i < n; i++){
		scanf("%d\n", &vetor[i]);
	}
	
	for(i = 0; i < n; i++){
		if(vetor[i+1] > vetor[i]){
			cont++;
		} else {
			cont = 1;
		}
	}
	
	printf("%d\n", cont);
}