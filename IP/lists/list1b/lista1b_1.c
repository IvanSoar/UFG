#include <stdio.h>
#include <math.h>

int main(){

    float nota1, nota2, nota3, media;

    scanf("%f %f %f", &nota1, &nota2, &nota3);

    media = (nota1 + nota2 + nota3)/3;

    if (media >= 6.0){
        printf("MEDIA = %.2f\n", media);
        printf("APROVADO\n");
    }
    else {
        printf("MEDIA = %.2f\n", media);
        printf("REPROVADO\n");
    }

    return 0;
}
