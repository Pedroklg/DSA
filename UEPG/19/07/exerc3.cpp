#include <iostream>

using namespace std;

int main() {
    int A[10], B[10];
    int valor, count = 0;

    cout << "Digite 10 numeros inteiros para o array A:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o " << i + 1 << "o numero: ";
        cin >> A[i];
    }

    cout << "Digite um valor de referencia: ";
    cin >> valor;

    for (int i = 0; i < 10; ++i) {
        if (A[i] > valor) {
            B[count++] = A[i];
        }
    }

    cout << "Conteudo do array B (numeros maiores que " << valor << "):" << endl;
    for (int i = 0; i < count; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;

    return 0;
}
