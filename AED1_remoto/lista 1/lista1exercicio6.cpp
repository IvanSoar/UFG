#include<iostream>
#include <vector>

using namespace std;

int main(){

    int rotulos, tipos, i, temp;

    cin >> rotulos;
    cin >> tipos;

    int menor = rotulos + 1;
    vector<int> embalagens  (tipos);

    for(i = 0; i < rotulos; i++){

        cin >> temp;

        embalagens[temp - 1] += temp < tipos + 1 ? 1 : 0;
    }

    for(i = 0; i < tipos; i++){
        menor = menor > embalagens[i] ? embalagens[i] : menor;
    }

    cout << menor << endl;

    return 0;
}