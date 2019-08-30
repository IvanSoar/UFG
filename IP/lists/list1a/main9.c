#include <stdio.h>
#include <math.h>

int main(){

    double m, a, t, v, s, w, mkg, akm, thr, v1;

    scanf("%lf", &m);
    scanf("%lf", &a);
    scanf("%lf", &t);

    mkg = m * 1000; //conversão de toneladas para kilos
    akm = a * 3.6;  //conversão de m/s para km/h
    thr = t * 60 * 60; //conversão de segundos em horas

    v = akm * t;
    v1 = a*t;
    s = (a * (t*t))/2;
    w = ((v1*v1)*mkg)/2;

    printf("VELOCIDADE = %.2f\n", truncf(v*100.0)/100.0);
    printf("ESPACO PERCORRIDO = %.2f\n", truncf(s*100.0)/100.0);
    printf("TRABALHO REALIZADO = %.2f\n", truncf(w*100.0)/100.0);

    return 0;
}
