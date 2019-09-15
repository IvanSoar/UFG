#include <stdio.h>
 
int ackerman(int, int);
 
int main(){
    int m, n;
 
    scanf("%d %d", &m, &n);
 
    printf("%d\n", ackerman(m, n));
}
 
int ackerman(int m, int n){
    if(m == 0){
        return n + 1;
    }
 
    if (n == 0 && m > 0){
        return ackerman(m - 1, 1);
    }
 
    if(n > 0 && m > 0){
        return ackerman(m - 1, ackerman(m, n - 1));
    }
}