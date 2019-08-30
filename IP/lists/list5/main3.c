#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct NATAL {
    char * pais;
    char * texto;
} natal;

int main(){
    int i, j;
    char buffer[30];
    natal vetor[24] = { "brasil", "Feliz Natal!",
                        "alemanha", "Frohliche Weihnachten!",
                        "austria","Frohe Weihnacht!",
                        "coreia","Chuk Sung Tan!",
                        "espanha","Feliz Navidad!",
                        "grecia","Kala Christougena!",
                        "estados-unidos","Merry Christmas!",
                        "inglaterra","Merry Christmas!",
                        "australia","Merry Christmas!",
                        "portugal","Feliz Natal!",
                        "suecia","God Jul!",
                        "turquia","Mutlu Noeller",
                        "argentina","Feliz Navidad!",
                        "chile","Feliz Navidad!",
                        "mexico","Feliz Navidad!",
                        "antardida","Merry Christmas!",
                        "canada","Merry Christmas!",
                        "irlanda","Nollaig Shona Dhuit!",
                        "belgica","Zalig Kerstfeest!",
                        "italia","Buon Natale!",
                        "libia","Buon Natale!",
                        "siria","Milad Mubarak!",
                        "marrocos","Milad Mubarak!",
                        "japao","Merii Kurisumasu!"};
    int achou = 0;
    while(scanf("%[^\n]", buffer) != EOF){
        getchar();
        for(i = 0; i < 24; i++){
            achou = 0;
            for(j = 0; j < strlen(buffer); j++){
                if(buffer[j] != vetor[i].pais[j]){
                    break;
                } else {
                    achou++;
                }
            }
            if(achou == strlen(buffer)){
                printf("%s\n", vetor[i].texto);
                break;
            }
        }
        if(achou == 0){
            printf("-- NOT FOUND --\n");
        } else {
            achou = 0;
        }
    }

    return 0;
}