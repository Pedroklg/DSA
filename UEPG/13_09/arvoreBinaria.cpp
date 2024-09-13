#include <iostream>

using namespace std;

struct no
{
    int dado;
    no *direita, *esquerda;
};

void inserir(int valor);
void removeValor(int valor);
void imprimeEmOrdem(no *no);

no *raiz = nullptr;

int main()
{
    inserir(8);
    inserir(5);
    inserir(2);
    inserir(4);
    inserir(3);

    imprimeEmOrdem(raiz);
}

void inserir(int valor)
{
    no *aux = nullptr, *aux2 = nullptr;
    aux = new no();
    aux2 = new no();

    aux->dado = valor;
    if (raiz == nullptr)
    {
        raiz = aux;
        return;
    }

    aux2 = raiz;

    while (true)
    {
        if (aux->dado == aux2->dado)
        {
            cout << "Valor repetido!" << endl;
            return;
        }

        if (aux->dado < aux2->dado)
        {
            if (aux2->esquerda == nullptr)
            {
                aux2->esquerda = aux;
                return;
            }
            aux2 = aux2->esquerda;
        }
        else
        {
            if (aux2->direita == nullptr)
            {
                aux2->direita = aux;
                return;
            }
            aux2 = aux2->direita;
        }
    }
}

void imprimeEmOrdem(no *no) {
    if(no != nullptr){
        imprimeEmOrdem(no->esquerda);
        cout << no -> dado << endl;
        imprimeEmOrdem(no -> direita);
    }
}
