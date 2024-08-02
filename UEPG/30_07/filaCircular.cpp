#include <iostream>

using namespace std;

#define TAM 3

int Fila[TAM], inicio = 0 , fim = 0, count = 0;

void insereFila(int valor);
void removeFila();
void inicioFila();
void imprime();

int main() {
    removeFila();
    insereFila(10);
    insereFila(8);

    cout << "----------------------" << endl;

    imprime();

    cout << "----------------------" << endl;

    insereFila(12);
    insereFila(14);

    imprime();

    cout << "----------------------" << endl;

    removeFila();
    imprime();

    cout << "----------------------" << endl;

    insereFila(14);
    imprime();

    cout << "----------------------" << endl;

    inicioFila();
    insereFila(16);

}

void insereFila(int valor) {
    if(count == TAM) {
        cout << "Fila cheia!" << endl;
        return;
    }
    count++;

    Fila[fim] = valor;

    if(fim == TAM-1) {
        fim = 0;
        return;
    }
    fim++;
}

void removeFila() {
    if(count == 0) {
        cout << "Fila vazia!" << endl;
    } else {
        count--;
        if(inicio == TAM-1) {
            inicio = 0;
        } else {
            inicio++;
        }
    }
}

void inicioFila() {
    if(count == 0) {
        cout << "Fila vazia!" << endl;
    } else {
        cout << "Inicio da fila: " << Fila[inicio] << endl;
    }
}

void imprime() {
    if(count == 0) {
        cout << "Fila vazia!" << endl;
        return;
    }
    int posAtual = inicio;
    bool reseted = false;
    for (int i = 0; i < count ; i++) {
        if (inicio + i == TAM && !reseted) {
            posAtual = 0;
        }
        cout << Fila[posAtual] << endl;
        posAtual++;
    }
    // int i = 0;
    // while(i < count) {
    //     cout << Fila[i] << endl;
    //     if(i == TAM-1) {
    //         i = 0;
    //     } else {
    //         i++;
    //     }
    // }
    // cout << Fila[i] << endl;
}