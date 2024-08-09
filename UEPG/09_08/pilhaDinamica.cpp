#include <iostream>

using namespace std;

void push(int value);
void pop();
int vazia();
void imprime();


struct Node {
    int dado;
    Node *next;
};

Node *pilha = nullptr;


int main () {
    push(5);
    push(10);
    push(15);
    push(20);

    imprime();

    cout << "----------" << endl;

    cout << vazia() <<  endl;

    cout << "----------" << endl;

    pop();
    pop();

    imprime();


    return 0;
}

int vazia () {
    if (pilha == nullptr) {
        return 1;
    }
    return 0;
}

void push(int value) {
    Node *aux;
    aux = new Node();
    aux -> dado = value;
    aux -> next = pilha;
    pilha = aux;
}

void pop() {
    if (vazia()) {
        cout << "Pilha vazia!" << endl;
        return;
    }
    Node *aux = pilha;
    pilha = pilha -> next;
    delete(aux);
}

void imprime () {
    if(vazia()) {
        cout << "Pilha vazia!" << endl;
        return;
    }

    Node *aux = pilha;
    while (aux != nullptr) {
        cout << aux -> dado << endl;
        aux = aux -> next;
    }

    delete (aux);
}