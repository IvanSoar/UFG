#include <iostream>

using namespace std;

int calculaHarley(int);

int main(){

    int ano, prox;
    cin >> ano;

    prox = calculaHarley(ano);

    cout << prox << endl;

    return 0;
}

int calculaHarley(int ano){
    if(ano % 1986 <= 0){
        return 1986 + 76;
    } else {
        return (((ano - 1986) / 76 + 1) * 76) + 1986;
    }
}