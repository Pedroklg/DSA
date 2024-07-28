#include <iostream>

using namespace std;

int main() {
    int A[10], B[10];

    cout << "Digite 10 numeros inteiros para o array A:" << endl;
    for (int i = 0; i < 10; ++i) {\
        cout << "Digite o " << i + 1 << "o numero: ";
        cin >> A[i];
    }

    for (int i = 0; i < 10; ++i) {
        B[i] = A[9 - i];
    }

    cout << "Conteudo do array B (em ordem inversa de A):" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
