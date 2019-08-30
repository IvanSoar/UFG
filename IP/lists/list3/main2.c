#include<stdio.h>
#include<string.h>

int main(){
	char numero[1000];
	
	int i, j, ct, leds;
	scanf("%d", &ct);
	getchar();
	
	for(i = 0; i < ct; i++){
		scanf("%s", numero);
		getchar();
		leds = 0;
		
		for(j = 0; j < strlen(numero); j++){
			switch(numero[j]){
				case '0': leds += 6;
				break;
				case '1': leds += 2;
				break;
				case '2': leds += 5;
				break;
				case '3': leds += 5;
				break;
				case '4': leds += 4;
				break;
				case '5': leds += 5;
				break;
				case '6': leds += 6;
				break;
				case '7': leds += 4;
				break;
				case '8': leds += 7;
				break;
				case '9': leds += 6;
				break;
			}
		}
		printf("%d leds\n", leds);
	}
}