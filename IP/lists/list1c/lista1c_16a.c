#include <stdio.h>
#include <math.h>

int main() {

    int mat, i;
	float hor, val, sal;

    scanf("%d %f %f", &mat, &hor, &val);
	getchar();
	
	while(mat*val*hor != 0){		
			
		sal = hor * val;
   
        printf("%d %.2f\n", mat, truncf(sal*100.0)/100.0);
		
		scanf("%d %f %f", &mat, &hor, &val);
		getchar();
    }

    return 0;
}
