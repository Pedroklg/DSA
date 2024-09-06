#include <iostream>

using namespace std;

struct No {
    int valor;
    No* anterior;
    No* proximo;
};

No* cabeca = NULL;
No* cauda = NULL;

void insereLista(int valor, int posicao);
void removeValor(int valor);
void imprime();

int main() {
    insereLista(10, 0);
    insereLista(20, 1);
    insereLista(30, 1);
    imprime();

    removeValor(20);
    imprime();

    removeValor(40);
    imprime();

    insereLista(40, 1);
    insereLista(50, 1);
    imprime();

    removeValor(10);
    removeValor(50);
    removeValor(30);
    removeValor(40);
    imprime();

    return 0;
}

void insereLista(int valor, int posicao) {
    No* novoNo = new No();
    novoNo->valor = valor;
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;

    if (cabeca == NULL) {
        cabeca = cauda = novoNo;
        cout << "Valor inserido: " << valor << endl;
        return;
    }

    if (posicao == 0) {
        novoNo->proximo = cabeca;
        cabeca->anterior = novoNo;
        cabeca = novoNo;
        cout << "Valor inserido no início: " << valor << endl;
        return;
    }

    if (posicao == 1) {
        novoNo->anterior = cauda;
        cauda->proximo = novoNo;
        cauda = novoNo;
        cout << "Valor inserido no final: " << valor << endl;
        return;
    }

    cout << "Posicao invalida! Use 0 para inserir no início e 1 para o final." << endl;
    delete novoNo;
}

void removeValor(int valor) {
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

void imprime() {
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