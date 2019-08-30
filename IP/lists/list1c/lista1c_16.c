#include <stdio.h>
#include <math.h>
#define T 500
 
int main() {
 
    int mat[T], i = 0, cont = 1;
    float hor, val, sal[T];
    
    scanf("%d %f %f", &mat[i], &hor, &val);
    
    while(mat[i]*sal[i] != 0){
 
        sal[i] = hor*val;
		
		i++;
		cont++;
		
		scanf("%d %f %f", &mat[i], &hor, &val);
	}
	
	for(i = 0; i < cont-1; i++){
		printf("%d %.2f\n", mat[i], truncf(sal[i]*100.0)/100.0);
	}
	
    return 0;
}