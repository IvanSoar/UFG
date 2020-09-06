#include <iostream>
#include <vector>

using namespace std;

int main(){

    int pedras, sapos, i, j, posInicial, distPulo;

    cin >> pedras;
    cin >> sapos;

    vector<int> caminho (pedras);

    for(i = 0; i < sapos; i++){

        cin >> posInicial;
        cin >> distPulo;

        for(j = posInicial - 1; j < pedras; j += distPulo){
            caminho[j] = 1;
        }

        for(j = posInicial - 1; j >= 0; j -= distPulo){
            caminho[j] = 1;
        }
    }

    for(i = 0; i < pedras; i++){
        cout << caminho[i] << endl;
    }

    return 0;
}