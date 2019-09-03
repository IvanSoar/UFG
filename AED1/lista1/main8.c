#include<stdio.h>

int primo(int num);

int main(){
    
    int casos, i, num;

    scanf("%d", &casos);

    for (i = 0; i < casos; i++){
        scanf("%d", &num);
        if(primo(num)){
            printf("primo\n");
        } else {
            printf("composto\n");
        }
    }

    return 0;
}

int primo(int num){
    int j;
    if(num == 2){
        return 1;
    }
    if(num % 2 == 0){
        return 0;
    }
    for (j = 3; j < num; j+=2){
        if(num % j == 0){
            return 0;
        }
    }
    return 1;  
}