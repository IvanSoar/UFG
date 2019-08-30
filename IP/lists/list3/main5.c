#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]){
    int m, n, i;
    char buff[20];
    scanf("%d %d", &m, &n);
    while(m * n != 0){
        sprintf(buff, "%d", m + n);
        for(i = 0; i < strlen(buff); i++){
            if(buff[i] != '0'){
                printf("%c", buff[i]);
            }
        }
		printf("\n");
        scanf("%d %d", &m, &n);
    }
    return 0;
}
