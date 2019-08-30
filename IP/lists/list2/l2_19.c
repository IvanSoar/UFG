#include<stdio.h>

int calculaDist(float * vet, int ind);

int main(){
	int n, i, p;
	float maiorDist;
	
	do {
	scanf("%d", &n);
	} while (n <= 2 && n >= 1000);
	
	float coords[3 * n];
	
	for (i = 0; i < n; i++){
		p = i * 3;
		scanf("%d %d %d", coords[p], coords[p + 1], coords[p + 1]);
		if(i > 0){
			maiorDist = calculaDist(coords, p);
		}
	}
}

int calculaDist(float * vet, int ind){
	int i;
	float dist, maior = 0;
	
	for(i = ind; i < ind + 3; i++){
		dist = vet[i] - vet[i - 3];
		maior = dist > maior ? dist : maior;
	}
	
	return maior;
}