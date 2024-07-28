#include <iostream>

using namespace std;

#define TAM 10
int fila[TAM], inicio = 0, fim = 0, count = 0;

void insert(int valor);


int main () {

    insert(10);
    insert(20);

    for(int i = 0; i <= TAM ; i++ ){
        
        if(fila[i] != 0)cout << fila[i] << endl;
    }

    return 0;
}

void insert(int valor) {
    if( count == TAM ) {
        cout << "FIla cheia" << endl;
        return;
    }
    fila[fim] = valor;
    count ++;

    if( fim == TAM -1 ) {
        fim = 0;
    } else {
        fim--;
    }
    cout << "Valo inserido " << valor << endl;

}