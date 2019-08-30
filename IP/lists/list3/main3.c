#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int letraVogal(int letra);

int main(){
	int n, i, j, let, vog, con;
	char frase[10000];
	
	let = vog = con = n = 0;
	
	do {
		scanf("%d", &n);
		getchar();
	} while(n == 0);
	
	for(j = 0; j < n; j++){
		scanf("%[^\n]", frase);
		getchar();
		let = vog = con = 0;
		for(i = 0; i < strlen(frase); i++){
			if(((int)frase[i] > 64 && (int)frase[i] < 91) || ((int)frase[i] > 96 && (int)frase[i] < 123)){
				let++;
				vog += letraVogal(frase[i]) ? 1 : 0;
				con += !letraVogal(frase[i]) ? 1 : 0;
			}
		}
		printf("Letras = %d\n", let);
		printf("Vogais = %d\n", vog);
		printf("Consoantes = %d\n", con);
	}
}

int letraVogal(int flag){
	switch(flag){
		case 65: flag = 1; break;
		case 69: flag = 1; break;
		case 73: flag = 1; break;
		case 79: flag = 1; break;
		case 85: flag = 1; break;
		case 97: flag = 1; break;
		case 101: flag = 1; break;
		case 105: flag = 1; break;
		case 111: flag = 1; break;
		case 117: flag = 1; break;
		default: flag = 0; break;
	}
	return flag;
}