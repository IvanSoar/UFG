#include <stdio.h>
#include <math.h>
 
int main() {
 
    int pessoas, numero, i;
    float popular, geral, arqui, cadeiras, renda;
    
    scanf("%d", &numero);
    
    for (i = 0; i < numero; i++){
        scanf("%d %f %f %f %f", &pessoas, &popular, &geral, &arqui, &cadeiras);
 
        renda = ((pessoas*(popular/100))+(pessoas*(geral/100)*5)+(pessoas*(arqui/100)*10)+(pessoas*(cadeiras/100)*20));
        renda = ((pessoas*(popular/100))+(pessoas*(geral*0.05))+(pessoas*(arqui*0.1))+(pessoas*(cadeiras*0.2)));
 
        printf("A RENDA DO JOGO N. %d E = %.2f\n", i+1, truncf(renda*100.0)/100.0);
    }
    return 0;
}