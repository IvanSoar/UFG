#include <stdio.h>
#include <math.h>
 
int main() {
 
    int n;
    double soma, i;
 
    scanf("%d", &n);
	
	if(n <= 0){
		printf("Numero invalido!");
	} else {
		for(i = 1; i <= n; i++){
			soma += 1.0/(double)i;
		}
	printf("%.6f", trunc(soma*1000000.0)/1000000.0);
	}  
}