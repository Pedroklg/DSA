#include <iostream>

using namespace std;

struct Node {
    int valor;
    Node* prox;
};

Node* head;

Node* criarNo(int valor) {
    Node* novoNo = new Node();
    novoNo->valor = valor;
    novoNo->prox = nullptr;
    return novoNo;
}

void insereLista(int valor) {
    Node* novoNo = criarNo(valor);
    if (!head || valor < head->valor) {
        novoNo->prox = head;
        head = novoNo;
    } else {
        Node* atual = head;
        while (atual->prox && atual->prox->valor < valor) {
            atual = atual->prox;
        }
        novoNo->prox = atual->prox;
        atual->prox = novoNo;
    }
}

void recuperaLista(int valor) {
    int pos = 0;
    Node* atual = head;
    while (atual) {
        if (atual->valor == valor) {
            cout << "Valor " << valor << " encontrado na posicao: " << pos << endl;
            return;
        }
        if (atual->valor > valor) {
            break;
        }
        atual = atual->prox;
        pos++;
    }
    cout << "Valor " << valor << " nao encontrado na lista." << endl;
}

void removeLista(int pos) {
    if (!head) {
        cout << "Lista vazia" << endl;
        return;
    }
    Node* atual = head;
    if (pos == 0) {
        head = head->prox;
        delete atual;
        return;
    }
    for (int i = 0; atual != nullptr && i < pos - 1; i++) {
        atual = atual->prox;
    }
    if (!atual || !atual->prox) {
        cout << "Posicao invalida" << endl;
        return;
    }
    Node* temp = atual->prox;
    atual->prox = temp->prox;
    delete temp;
}

void removeValor(int valor) {
    if (!head) {
        cout << "Lista vazia" << endl;
        return;
    }
    if (head->valor == valor) {
        Node* temp = head;
        head = head->prox;
        delete temp;
        return;
    }
    Node* atual = head;
    while (atual->prox && atual->prox->valor != valor) {
        if (atual->prox->valor > valor) {
            cout << "Valor " << valor << " nao encontrado" << endl;
            return;
        }
        atual = atual->prox;
    }
    if (!atual->prox) {
        cout << "Valor " << valor << " nao encontrado" << endl;
        return;
    }
    Node* temp = atual->prox;
    atual->prox = temp->prox;
    delete temp;
}

void imprime() {
    if (!head) {
        cout << "Lista vazia" << endl;
        return;
    }
    Node* atual = head;
    while (atual) {
        cout << atual->valor << " ";
        atual = atual->prox;
    }
    cout << endl;
}

int main() {
    Node* lista = nullptr;

    insereLista(10);
    insereLista(5);
    insereLista(15);
    insereLista(7);

    cout << "Lista apos insercoes: ";
    imprime();

    recuperaLista(7);
    recuperaLista(20);

    cout << "Removendo valor 7: " << endl;
    removeValor(7);
    imprime();

    cout << "Removendo na posicao 1: " << endl;
    removeLista(1);
    imprime();

    cout << "Tentando remover valor inexistente 30: " << endl;
    removeValor(30);
    imprime();

    return 0;
}
