#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

Node *dequeStart = nullptr;
Node *dequeEnd = nullptr;

void insereDeque(int valor, int lado);
void removeDeque(int lado);
void inicioDeque();
void finalDeque();
void imprimeDeque();

int main() {
    insereDeque(5, 1);
    insereDeque(10, 1);
    insereDeque(15, 0);
    insereDeque(2, 1);

    inicioDeque();
    finalDeque();

    imprimeDeque();

    removeDeque(0);

    imprimeDeque();

    removeDeque(1);

    inicioDeque();
    finalDeque();

    imprimeDeque();

    return 0;
}

void insereDeque(int valor, int lado) {
    Node *aux = new Node();
    aux->data = valor;
    aux->next = nullptr;
    aux->prev = nullptr;

    if (dequeStart == nullptr) {
        dequeStart = aux;
        dequeEnd = aux;
    } else if (lado == 0) {
        aux->next = dequeStart;
        dequeStart->prev = aux;
        dequeStart = aux;
    } else {
        aux->prev = dequeEnd;
        dequeEnd->next = aux;
        dequeEnd = aux;
    }

    cout << "Numero inserido: " << valor << (lado == 0 ? " no início" : " no fim") << endl;
}

void removeDeque(int lado) {
    if (dequeStart == nullptr) {
        cout << "Deque vazio!" << endl;
        return;
    }

    if (lado == 0) {
        Node *aux = dequeStart;
        dequeStart = dequeStart->next;
        if (dequeStart != nullptr) {
            dequeStart->prev = nullptr;
        } else {
            dequeEnd = nullptr;
        }
        delete aux;
        cout << "Numero removido do início!" << endl;
    } else {
        Node *aux = dequeEnd;
        dequeEnd = dequeEnd->prev;
        if (dequeEnd != nullptr) {
            dequeEnd->next = nullptr;
        } else {
            dequeStart = nullptr;
        }
        delete aux;
        cout << "Numero removido do fim!" << endl;
    }
}

void inicioDeque() {
    if (dequeStart == nullptr) {
        cout << "Deque vazio!" << endl;
    } else {
        cout << "Inicio do deque: " << dequeStart->data << endl;
    }
}

void finalDeque() {
    if (dequeEnd == nullptr) {
        cout << "Deque vazio!" << endl;
    } else {
        cout << "Fim do deque: " << dequeEnd->data << endl;
    }
}

void imprimeDeque() {
    if (dequeStart == nullptr) {
        cout << "Deque vazio!" << endl;
        return;
    }

    Node *aux = dequeStart;

    cout << "Elementos do deque:" << endl;
    while (aux != nullptr) {
        cout << aux->data << endl;
        aux = aux->next;
    }
}
