#include <iostream>

using namespace std;

int inverte(int);

int main(){

    int casos;
    cin >> casos;

    while(casos--){
        int num, rev;

        cin >> num;

        rev = inverte(num);

        if(num == rev){
            cout << "yes ";
        } else {
            cout << "no ";
        }
    }

    cout << endl;
}

int inverte(int x){
    int a = x / 1000;
    int b = x / 100 % 10;
    int c = x % 100 / 10;
    int d = x % 10;

    return d * 1000 + c * 100 + b * 10 + a;
}