#include <iostream>

using namespace std;

int inverte(int);

int main(){
    int a, b, maior;
    cin >> a;
    cin >> b;

    a = inverte(a);
    b = inverte(b);
    maior = a > b ? a : b;

    cout << maior << endl;
}

int inverte(int a){
    return ((a % 10) * 100) + ((a % 100 / 10) * 10) + a / 100;
}