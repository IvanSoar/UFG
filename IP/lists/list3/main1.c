#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define T 51

void impComb(char *strA, char *strB);

int main(){
	
	int ct = 0;
	scanf("%d", &ct);
	getchar();
	
	char nome1[T];
	char nome2[T];
	int i;
	
	while(ct > 0){
		scanf("%s", &nome1);
		getchar();
		scanf("%s", &nome2);
		getchar();
		
		impComb(nome1, nome2);
		ct--;
	}
}

void impComb(char *strA, char *strB){
	int i = 0;
	
	while(strA[i] != '\0' || strB[i] != '\0'){
		if(i < strlen(strA)){
			printf("%c", strA[i]);
		}
			
		if(i < strlen(strB)){
			printf("%c", strB[i]);
		}
		
		i++;
	}
	printf("\n");
}














