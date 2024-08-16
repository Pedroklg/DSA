#include <iostream>

using namespace std;

void push(int valor);
int vazia();
void pop();
void topoPilha();
void imprime();

struct Node
{
    int dado;
    Node *next;
};

Node *topPilha = nullptr;
Node *endPilha = nullptr;

int main()
{
    pop();

    push(15);
    push(10);
    push(5);

    imprime();

    cout << "------------" << endl;

    topoPilha();

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
        topPilha = aux;
        endPilha = aux;
        return;
    }

    endPilha->next = aux;
    endPilha = aux;
    return;
}

int vazia()
{
    if (topPilha == nullptr)
        return 1;

    return 0;
}

void pop()
{
    if (vazia())
    {
        cout << "Piha vazia" << endl;
        return;
    }

    Node *aux;
    aux = topPilha;

    if (topPilha == endPilha)
    {
        topPilha = nullptr;
        endPilha = nullptr;
        return;
    }
    topPilha = topPilha->next;

    delete (aux);
}

void topoPilha()
{
    cout << topPilha->dado << endl;
}

void imprime()
{
    if (vazia())
    {
        cout << "Pilha vazia!" << endl;
    }
    Node *aux;
    aux = topPilha;
    while (aux != nullptr)
    {
        cout << aux->dado << endl;
        aux = aux->next;
    }
}