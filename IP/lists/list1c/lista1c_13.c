#include <stdio.h>
#include <math.h>

int main(){
	int n, cont1 = 0, cont2 = 0;
	float mediaPar = 0, mediaImpar = 0;
		
	while(1){
		
		scanf("%d", &n);
		
		if(n == 0){
			break;
		} else {
			if(n % 2 == 0){			
				mediaPar += (float)n;
				cont1++;
			} else {			
				mediaImpar += (float)n;
				cont2++;
			}
		}
	}
	
	if(cont1 && cont2 != 0){
		mediaPar /= (float)cont1;
		mediaImpar /= (float)cont2;
	}
	
	printf("MEDIA PAR: %.2f\n", truncf(mediaPar*100.0)/100.0);
	printf("MEDIA IMPAR: %.2f\n", truncf(mediaImpar*100.0)/100.0);
}