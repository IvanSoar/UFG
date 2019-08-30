#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int *matricula, *hora;
    float *nf;

    int x, i, contador, aux;
    float p1, p2, p3, p4, p5, p6, p7, p8;
    float t1, t2, t3, t4, t5, mediat, mediap, ntf;

    matricula = malloc(sizeof(int));
    hora = malloc(sizeof(int));
    nf = malloc(sizeof(float));

    i = 0;
    contador = 0;
    while(matricula[i-1] != -1 && p1 != -1 && p2 != -1) {
        i++;
        matricula = realloc(matricula, sizeof(int)*i);
        hora = realloc(hora, sizeof(int)*i);
        nf = realloc(nf, sizeof(float)*i);

        scanf("%d %f %f %f %f %f %f %f %f %f %f %f %f %f %f %d", &matricula[i-1], &p1, &p2, &p3, &p4, &p5, &p6, &p7, &p8, &t1, &t2, &t3, &t4, &t5, &ntf, &hora[i-1]);

        mediap = (p1 + p2 + p3 + p4 + p5 + p6 + p7 + p8)/ 8.0;
        mediat = (t1 + t2 + t3 + t4 + t5)/ 5.0;
        nf[i-1] = (mediap*0.7) + (mediat*0.15)+(ntf*0.15);

        contador++;
    }

    for(x = 0; x < contador-1; x++) {
        if(hora[x] >= 96) {
            if(nf[x] >= 6.00) {
                printf("Matricula: %d, Nota Final: %.2f, Situacao Final: APROVADO\n", matricula[x], truncf(nf[x]*100.0)/100.0);
            } else {
                printf("Matricula: %d, Nota Final: %.2f, Situacao Final: REPROVADO POR NOTA\n", matricula[x], truncf(nf[x]*100.0)/100.0);
            }
        } else {
            if(nf[x] >= 6.00) {
                printf("Matricula: %d, Nota Final: %.2f, Situacao Final: REPROVADO POR FREQUENCIA\n", matricula[x], truncf(nf[x]*100.0)/100.0);
            } else {
                printf("Matricula: %d, Nota Final: %.2f, Situacao Final: REPROVADO POR NOTA E POR FREQUENCIA\n", matricula[x], truncf(nf[x]*100.0)/100.0);
            }
        }
    }

    free(matricula);
    free(hora);
    free(nf);
    matricula = NULL;
    nf = NULL;
    hora = NULL;
}
