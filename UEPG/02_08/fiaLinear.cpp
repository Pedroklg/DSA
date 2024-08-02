#include <iostream>

using namespace std;
#define TAM 10

int count = 0, Lista[TAM];

void insereLista(int valor);
void recuperaLista(int posicao);
void removeLista(int posicao);
void removeValor(int valor);
void imprime();

int main () {
    insereLista(1);
    insereLista(2);
    insereLista(3);
    insereLista(4);
    insereLista(5);
    insereLista(6);
    insereLista(7);
    insereLista(15);
    insereLista(9);
    insereLista(10);
    insereLista(4);
    insereLista(4);
    insereLista(4);

    imprime();

    removeLista(2);

    imprime();

    removeValor(2);

    imprime();

    recuperaLista(1);
}

void insereLista(int valor) {
    if(count == TAM-1) {
        cout << "Lista cheia!" << endl;
        return;
    }
    int novoNumPos = 0;
    for (int i = 0; i < count; i++) {
        if(valor > Lista[i]) {
            novoNumPos = i+1;
        } else {
            break;
        }
    }
    
    for (int i = novoNumPos; i < count ; i++){
        int temp = Lista[i+1];
        Lista[i+1] = Lista[i];
        Lista[i] = temp;
    }

    Lista[novoNumPos] = valor;
    count++;
}

void recuperaLista(int posicao) {
    if ( posicao < 0 || posicao > count) {
        cout << "Posição inválida!" << endl;
        return;
    }
    cout << "Valor na posição " << posicao << ": " << Lista[posicao] << endl;
}

void removeLista(int posicao) {
    if (posicao < 0 || posicao > count) {
        cout << "Posicao invalida" << endl;
        return;
    }
    for (int i = posicao; i < count; i++) {
        Lista[i] = Lista[i+1];
    }
    count--;
}

void removeValor(int valor) {
    int posicao = 0;
    for (int i = 0; i < count; i++) {
        if (Lista[i] == valor) {
            posicao = i;
            break;
        }
        if (Lista[i] > valor) {
            cout << "Valor" << valor << "nao encontrado na lista" << endl;
            return;
        }
    }

    for (int i = posicao; i < count; i++) {
        Lista[i] = Lista[i+1];
    }
    count--;
}

void imprime() {
    if (count < 0) {
        cout << "Lista vazia" << endl;
    }

    cout << "Lista Ordenada:" << endl;
    for (int i = 0; i < count; i++) {
        cout << Lista[i] << endl;
    }
}