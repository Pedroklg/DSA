#include <iostream>

using namespace std;

int main() {
    int numeros[10];
    int num, ocorrencias = 0;
    int maior, menor;
    double soma = 0.0;

    cout << "Digite 10 numeros inteiros:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << "Digite o " << i + 1 << "o numero: ";
        cin >> numeros[i];
    }

    cout << "Ordem direta:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    cout << "Ordem inversa:" << endl;
    for (int i = 9; i >= 0; --i) {
        cout << numeros[i] << " ";
    }
    cout << endl;

    maior = menor = numeros[0];
    for (int i = 1; i < 10; ++i) {
        if (numeros[i] > maior) maior = numeros[i];
        if (numeros[i] < menor) menor = numeros[i];
    }
    cout << "Maior elemento: " << maior << endl;
    cout << "Menor elemento: " << menor << endl;

    cout << "Digite um numero para buscar suas ocorrencias: ";
    cin >> num;
    cout << "Numero " << num << " encontrado nas posicoes: ";
    for (int i = 0; i < 10; ++i) {
        if (numeros[i] == num) {
            cout << i << " ";
            ++ocorrencias;
        }
    }
    if (ocorrencias == 0) {
        cout << "Nenhuma ocorrencia encontrada.";
    }
    cout << endl;

    for (int i = 0; i < 10; ++i) {
        soma += numeros[i];
    }
    cout << "Media dos valores: " << soma / 10 << endl;

    return 0;
}
