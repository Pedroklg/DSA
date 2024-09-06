#include <iostream>

using namespace std;

struct No {
    int valor;
    No* anterior;
    No* proximo;
};

No* cabeca = NULL;
No* cauda = NULL;

void inserirNaLista(int valor, int posicao);
void removerValor(int valor);
void imprimir();

int main() {
    inserirNaLista(10, 0);
    inserirNaLista(20, 1);
    inserirNaLista(30, 1);
    imprimir();

    removerValor(20);
    imprimir();

    removerValor(40);
    imprimir();

    inserirNaLista(40, 1);
    inserirNaLista(50, 1);
    imprimir();

    removerValor(10);
    removerValor(50);
    removerValor(30);
    removerValor(40);
    imprimir();

    return 0;
}

void inserirNaLista(int valor, int posicao) {
    if (posicao < 0) {
        cout << "Posiaoo invalida!" << endl;
        return;
    }

    No* novoNo = new No();
    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if (posicao == 0) {
        if (cabeca == NULL) {
            cabeca = cauda = novoNo;
            cout << "Valor inserido: " << valor << endl;
            return;
        }
        novoNo->proximo = cabeca;
        cabeca->anterior = novoNo;
        cabeca = novoNo;
        cout << "Valor inserido: " << valor << endl;
        return;
    }

    No* temp = cabeca;
    int contador = 0;

    while (temp != NULL && contador < posicao - 1) {
        temp = temp->proximo;
        contador++;
    }

    if (temp == NULL) {
        cout << "Posicao fora dos limites!" << endl;
        delete novoNo;
        return;
    }

    novoNo->proximo = temp->proximo;
    novoNo->anterior = temp;

    if (temp->proximo != NULL) {
        temp->proximo->anterior = novoNo;
    } else {
        cauda = novoNo;
    }

    temp->proximo = novoNo;
    cout << "Valor inserido: " << valor << endl;
}

void removerValor(int valor) {
    if (cabeca == NULL) {
        cout << "Lista vazia, nada a remover." << endl;
        return;
    }

    No* temp = cabeca;

    while (temp != NULL) {
        if (temp->valor == valor) {
            if (temp == cabeca) {
                cabeca = temp->proximo;
                if (cabeca != NULL) cabeca->anterior = NULL;
                else cauda = NULL;
            } else if (temp == cauda) {
                cauda = temp->anterior;
                if (cauda != NULL) cauda->proximo = NULL;
            } else {
                temp->anterior->proximo = temp->proximo;
                temp->proximo->anterior = temp->anterior;
            }
            delete temp;
            cout << "Valor removido: " << valor << endl;
            return;
        }
        temp = temp->proximo;
    }

    cout << "Valor nao encontrado: " << valor << endl;
}

void imprimir() {
    if (cabeca == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }

    No* temp = cabeca;
    cout << "Conteudo da lista: ";
    while (temp != NULL) {
        cout << temp->valor << " ";
        temp = temp->proximo;
    }
    cout << endl;
}