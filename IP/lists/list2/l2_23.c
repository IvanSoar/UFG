#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
	int A[] = {0,0,0,0,0};
	int B[] = {0,0,0,0,0};
	int i, flag = 0;
	double dist = 0.0;
	
	char texto[2002];
	scanf("%[^\n]", texto);
	
	for(i = 0; i < strlen(texto); i++){		
		if((texto[i] == ';' && flag == 1) || (i == (strlen(texto) - 1) && flag == 0)){
			flag = 2;
			printf("FORMATO INVALIDO!\n");
			break;
		} else {			
			switch(texto[i]){
				case ';': flag = 1; break;
				case 'a': flag == 0? A[0]++: B[0]++; break;
				case 'e': flag == 0? A[1]++: B[1]++; break;
				case 'i': flag == 0? A[2]++: B[2]++; break;
				case 'o': flag == 0? A[3]++: B[3]++; break;
				case 'u': flag == 0? A[4]++: B[4]++; break;
				case 'A': flag == 0? A[0]++: B[0]++; break;
				case 'E': flag == 0? A[1]++: B[1]++; break;
				case 'I': flag == 0? A[2]++: B[2]++; break;
				case 'O': flag == 0? A[3]++: B[3]++; break;
				case 'U': flag == 0? A[4]++: B[4]++; break;			
			}
		}
	}
	if(flag < 2){
		printf("(%d,%d,%d,%d,%d)\n", A[0], A[1], A[2], A[3], A[4]);
		printf("(%d,%d,%d,%d,%d)\n", B[0], B[1], B[2], B[3], B[4]);	
		
		for(i = 0; i < 5; i++){
			dist += pow(A[i] - B[i], 2);
		}
		
		printf("%.2f\n", sqrt(dist));
	}
}











