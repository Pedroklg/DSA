#include <iostream>

using namespace std;

void push(int valor);
int vazia();
void pop();
void firstFila();
void imprime();

struct Node
{
    int dado;
    Node *next;
};

Node *startFila = nullptr;
Node *endFila = nullptr;

int main()
{
    pop();

    push(15);
    push(10);
    push(5);

    imprime();

    cout << "------------" << endl;

    firstFila();

    cout << "------------" << endl;

    pop();
    pop();

    imprime();

    cout << "------------" << endl;

    cout << vazia() << endl;

    cout << "------------" << endl;

    pop();

    cout << vazia() << endl;

    return 0;
}

void push(int valor)
{
    Node *aux;
    aux = new Node();
    aux->dado = valor;
    aux->next = nullptr;

    if (vazia())
    {
        startFila = aux;
    }

    endFila -> next = endFila;
    endFila = aux;
    return;
}

int vazia()
{
    if (startFila == nullptr)
        return 1;

    return 0;
}

void pop()
{
    if (vazia())
    {
        cout << "Piha vazia!" << endl;
        return;
    }

    Node *aux;
    aux = startFila;

    if (startFila == endFila)
    {
        startFila = nullptr;
        endFila = nullptr;
        return;
    }
    startFila = startFila->next;

    delete (aux);
}

void firstFila()
{
    cout << startFila->dado << endl;
}

void imprime()
{
    if (vazia())
    {
        cout << "Fila vazia!" << endl;
    }
    Node *aux;
    aux = startFila;
    while (aux != nullptr)
    {
        cout << aux->dado << endl;
        aux = aux->next;
    }
}