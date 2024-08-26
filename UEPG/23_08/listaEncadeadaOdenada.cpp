#include <iostream>

using namespace std;

struct No {
    int dado;
    No *prox;
};

No *topoLista = nullptr;

void insereLista(int valor);
void recuperaLista();
void removeLista(int posicao);
void removeValor(int valor);
void imprime();

int main() {
    insereLista(5);
    insereLista(10);
    insereLista(15);
    insereLista(2);

    recuperaLista();

    imprime();

    removeLista(2);

    imprime();

    removeValor(5);

    recuperaLista();

    imprime();

    return 0;
}

void insereLista(int valor) {
    No *anterior = nullptr, *atual = topoLista;
    No *aux = new No();
    aux->dado = valor;

    while(atual != nullptr && atual->dado < valor){
        anterior = atual;
        atual = atual->prox;
    }
    if(anterior == nullptr){
        aux->prox = topoLista;
        topoLista = aux;
    } else {
        aux->prox = anterior->prox;
        anterior->prox = aux;
    }
    cout << "Numero inserido: " << valor << endl;
}

void recuperaLista() {
    if (topoLista == nullptr) {
        cout << "Lista vazia!" << endl;
    } else {
        cout << "Topo da lista: " << topoLista->dado << endl;
    }
}

void removeLista(int posicao) {
    if (topoLista == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    No *aux = topoLista;
    No *anterior = nullptr;
    int cont = 0;

    while (cont < posicao && aux != nullptr) {
        anterior = aux;
        aux = aux->prox;
        cont++;
    }

    if (aux == nullptr) {
        cout << "Posicao invalida!" << endl;
        return;
    }

    if (anterior == nullptr) {
        topoLista = aux->prox;
    } else {
        anterior->prox = aux->prox;
    }

    delete aux;
    cout << "Numero na posicao " << posicao << " removido!" << endl;
}

void removeValor(int valor) {
    if (topoLista == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    No *anterior = nullptr;
    No *atual = topoLista;

    while (atual != nullptr && atual->dado != valor) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == nullptr) {
        cout << "Valor " << valor << " nao encontrado na lista!" << endl;
        return;
    }

    if (anterior == nullptr) {
        topoLista = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    delete atual;
    cout << "Valor " << valor << " removido da lista!" << endl;
}

void imprime() {
    if (topoLista == nullptr) {
        cout << "Lista vazia!" << endl;
        return;
    }

    No *aux = topoLista;

    while (aux != nullptr) {
        cout << aux->dado << endl;
        aux = aux->prox;
    }
}