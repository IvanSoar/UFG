#include<stdio.h>

int main(){
	int i, j, n;
	
	scanf("%d", &n);
	while(n != 0 && n <= 10000 && n > 1){
		int v[n - 1];
		int m = 0;
		
		for(i = 0; i < n; i++){
			scanf("%d", &v[i]);
			m = v[i] > m ? v[i]: m;
		}
		
		//passo 1
		int vCount[m + 1];
		int vOrd[n - 1];
		
		//passo 2
		for(i = 0; i < m + 1; i++){
			vCount[i] = 0;
		}
		
		//passo 3
		for(i = 0; i < n; i++){
			vCount[v[i]]++;
		}
		
		//passo 4
		for(i = 1; i < m + 1; i++){
			vCount[i] += vCount[i - 1];
		}
		
		//passo 5 - com erro
		for(i = 0; i < n; i++){
			vOrd[vCount[v[i]] - 1] = v[i];
			vCount[v[i]]--;
		}
		
		//passo 6
		for(i = 0; i < n; i++){
			i == 0 ? printf("%d", vOrd[i]) : printf(" %d", vOrd[i]);
		}
		
		printf("\n");
		scanf("%d", &n);		
	}
}