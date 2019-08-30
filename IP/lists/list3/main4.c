#include<stdio.h>
#include<string.h>

int main(){
	int i, j, n;
	int cont1, cont2, cont3;
	char num[6];
	
	scanf("%d", &n);
	getchar();
	
	for(i = 0; i < n; i++){
		scanf("%s", num);
		getchar();
		cont1 = cont2 = cont3 = 0;
		for(j = 0; j < strlen(num); j++){
			cont1 += (j == 0 && num[j] == 'o') || (j == 1 && num[j] == 'n') || (j == 2 && num[j] == 'e') ? 1 : 0;
			cont2 += (j == 0 && num[j] == 't') || (j == 1 && num[j] == 'w') || (j == 2 && num[j] == 'o') ? 1 : 0;
			cont3 += (j == 0 && num[j] == 't') || (j == 1 && num[j] == 'h') || (j == 2 && num[j] == 'r') || (j == 3 && num[j] == 'e') || (j == 4 && num[j] == 'e')? 1 : 0;
		}		
		cont1 > cont2 && cont1 > cont3 ? printf("1\n") : 1;
		cont2 > cont1 && cont2 > cont3 ? printf("2\n") : 1;
		cont3 > cont1 && cont3 > cont2 ? printf("3\n") : 1;
	}
}