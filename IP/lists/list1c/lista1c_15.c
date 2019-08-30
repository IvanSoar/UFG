#include <stdio.h>

void primo(int a);

int main(){
	
	int n;
	
	scanf("%d", &n);
	
	primo(n);
	
	return 0;
}

void primo(int a){
	int i, primo = 0;
			
	if(a >= 0){
		if(a == 0){
			printf("NAO PRIMO");
		} else {
			if(a == 1){
				printf("NAO PRIMO");
			} else {		
				if(a == 2){
					printf("PRIMO");
				} else {
					for(i = 2; i < a; i++){
						if(a % i == 0){
							primo = 1;
						}
					}					
					switch(primo){
						case 0: printf("PRIMO"); break;
						case 1: printf("NAO PRIMO"); break;
					}					
				}		
			}
		}
	} else {
		printf("Numero invalido!");
	}
}