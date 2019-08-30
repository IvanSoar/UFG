#include <stdio.h>
#include <math.h>

int main() {

    float renda, salario;
    int familia, escola, etnia, grupo;

    scanf("%f %d %d %d", &renda, &familia, &escola, &etnia);

    salario = 937.00;
    grupo = 0;

    if(escola == 2){
        if(renda/familia <= salario*1.5){
            if(etnia == 1 || etnia == 2 || etnia == 3){
                grupo = 2;
            } else {
                grupo = 1;
            }
        } else {
            if(etnia == 1 || etnia == 2 || etnia == 3){
                grupo = 4;
            } else {
                grupo = 3;
            }
        }
    }

    if(grupo == 0){
        printf("ALUNO NAO COTISTA");
    } else {
        printf("ALUNO COTISTA (L%d)\n", grupo);
    }

    return 0;
}
