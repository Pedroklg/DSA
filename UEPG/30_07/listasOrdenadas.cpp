#include <iostream>

using namespace std;

#define TAM 3

int Fila[TAM], inicio = 0 , fim = 0;

void insereFila(int valor);
void removeFila();
void inicioFila();
void imprime();

int main() {

}

void insereFila(int valor) {
    if(inicio == 0 && fim == TAM-1 || fim == inicio-1) {
        cout << "Fila cheia!" << endl;
    } else {
        if(fim == TAM-1) {
            fim = 0;
        } else {
            fim++;
        }
        Fila[fim] = valor;
    }
}

void removeFila() {
    if(inicio == fim) {
        cout << "Fila vazia!" << endl;
    } else {
        if(inicio == TAM-1) {
            inicio = 0;
        } else {
            inicio++;
        }
    }
}

void inicioFila() {
    if(inicio == fim) {
        cout << "Fila vazia!" << endl;
    } else {
        cout << "Inicio da fila: " << Fila[inicio] << endl;
    }
}

void imprime() {
    if(inicio == fim) {
        cout << "Fila vazia!" << endl;
    } else {
        int i = inicio;
        while(i != fim) {
            cout << Fila[i] << " ";
            if(i == TAM-1) {
                i = 0;
            } else {
                i++;
            }
        }
        cout << Fila[i] << endl;
    }
}