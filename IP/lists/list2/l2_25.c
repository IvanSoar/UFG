#include<stdio.h>
#define T 6

void troca(int *a, int *b);
void ordena(int *vet);
int comparaAposta(int *vetSort, int *vetApos);

int main(){
	int i, k, n, sorteio[T], aposta[T], match, sena, quina, quadra;
	
	for(i = 0; i < T; i++){
		scanf("%d", &sorteio[i]);
	}
	
	ordena(sorteio);
	
	k = match = sena = quina = quadra = 0;
	
	scanf("%d", &n);
	while(k < n && n >= 1 && n <= 50000){
		for(i = 0; i < T; i++){
			scanf("%d", &aposta[i]);
		}		
		ordena(aposta);
		
		match = comparaAposta(sorteio, aposta);
		
		sena += match == 6 ? 1 : 0;
		quina += match == 5 ? 1 : 0;
		quadra += match == 4 ? 1 : 0;
		
		k++;
	}	
	sena > 0 ? printf("Houve %d acertador(es) da sena\n", sena) : printf("Nao houve acertador(es) da sena\n");
	quina > 0 ? printf("Houve %d acertador(es) da quina\n", quina) : printf("Nao houve acertador(es) da quina\n");
	quadra > 0 ? printf("Houve %d acertador(es) da quadra\n", quadra) : printf("Nao houve acertador(es) da quadra\n");
}

void troca(int *a, int *b){
	int c;
	c = *a;
	*a = *b;
	*b = c;
}

void ordena(int *vet){
	int i, j;
	for(i = 0; i < T - 1; i++){
		for(j = i + 1; j < T; j++){
			vet[i] > vet[j] ? troca(&vet[i], &vet[j]) : 1;
		}
	}
}

int comparaAposta(int *vetSort, int *vetApos){
	int i, j, cont, ind;
	ind = cont = 0;
	for(i = 0; i < T; i++){
		for(j = ind; j < T; j++){
			if(vetSort[i] == vetApos[j]){
				ind = j;
				cont++;
				break;
			} else if(vetApos[j] > vetSort[i]){
				break;
			}
		}
	}
	return cont;
}