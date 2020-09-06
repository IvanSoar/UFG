#include <iostream>

using namespace std;

int primo(int);

int main(){
    
    int casos, i, num;

    cin >> casos;

    for (i = 0; i < casos; i++){

        cin >> num;

        if(primo(num)){
            cout << "primo" << endl;
        } else {
            cout << "composto" << endl;
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