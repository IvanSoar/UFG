#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	char buff[200];
	int flag = 1;
	int i = 0;
	scanf("%[^\n]", buff);
	while(getchar() != EOF){
		while(i < strlen(buff) / 2){
			//printf("%c VS %c\n", buff[i], buff[strlen(buff) - 1 - i]);
			if(buff[i] != buff[strlen(buff) - 1 - i]){
				flag = 0;
				break;
			}
			i++;
		}
		if(flag == 1){
			printf("sim\n");
		} else {
			printf("nao\n");
		}
		scanf("%[^\n]", buff);
		flag = 1;
	}
}
