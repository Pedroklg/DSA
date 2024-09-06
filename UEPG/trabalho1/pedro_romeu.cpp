#include <iostream>

using namespace std;

struct Node {
    int valor;
    Node* prev;
    Node* next;
};

Node* Head = NULL;
Node* Tail = NULL;

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
    Node* novoNo = new Node();
    novoNo->valor = valor;
    novoNo->prev = NULL;
    novoNo->next = NULL;

    if (posicao == 0) {
        if (Head == NULL) {
            Head = novoNo;
            Tail = novoNo;
        } else {
            novoNo->next = Head;
            Head->prev = novoNo;
            Head = novoNo;
        }
    } else {
        if (Tail == NULL) {
            Head = novoNo;
            Tail = novoNo;
        } else {
            Tail->next = novoNo;
            novoNo->prev = Tail;
            Tail = novoNo;
        }
    }
    cout << "Valor inserido: " << valor << endl;
}

void removeValor(int valor) {
    Node* temp = Head;

    while (temp != NULL) {
        if (temp->valor == valor) {
            if (temp == Head) {
                Head = temp->next;
                if (Head != NULL) Head->prev = NULL;
                else Tail = NULL;
            } else if (temp == Tail) {
                Tail = temp->prev;
                if (Tail != NULL) Tail->next = NULL;
            } else {
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            delete temp;
            cout << "Valor removido: " << valor << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Valor nao encontrado: " << valor << endl;
}

void imprime() {
    if (Head == NULL) {
        cout << "Lista vazia" << endl;
        return;
    }
    Node* temp = Head;
    cout << "Conteudo da lista: ";
    while (temp != NULL) {
        cout << temp->valor << " ";
        temp = temp->next;
    }
    cout << endl;
}
