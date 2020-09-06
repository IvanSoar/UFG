#include <iostream>

using namespace std;

void imprimeCovertido(int);
void seleciona(int);

int main(){
    int casos;
    cin >> casos;

    while(casos--){
        int num;

        cin >> num;

        imprimeCovertido(num);
        cout << endl;
    }
}

void imprimeCovertido(int num){
    if (num >= 4){
        imprimeCovertido(num / 4);
        seleciona(num % 4);
    } else {
        seleciona(num % 4);
    }
}

void seleciona(int a){
    switch(a){
    case 0 : cout << "A"; break;
    case 1 : cout << "C"; break;
    case 2 : cout << "G"; break;
    case 3 : cout << "T"; break;
    }
}