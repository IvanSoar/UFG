#include <iostream>

using namespace std;

int main(){
    int a, b, max;
    char opr;
    int res;

    cin >> max;
    cin >> a;
    cin >> opr;
    cin >> b;

    if (opr == '+'){
        res = a + b;
    } else if (opr == 'x'){
        res = a * b;
    }

    if(res > max){
        cout << "overflow" << endl;
    } else {
        cout << "no overflow" << endl;
    }
}