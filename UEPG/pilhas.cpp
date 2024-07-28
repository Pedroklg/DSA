#include <iostream>
#include <string>

using namespace std;

#define TAM 10

int Pilha[TAM], topo = -1;

void push(int valor);
bool vazia();
void pop();
int topoPilha();
void imprime();
void limparPilha();
bool verificaExpressao(string expressao);

int main() {
    push(10);
    push(20);
    cout << "A pilha esta vazia? " << (vazia() ? "Sim" : "Nao") << endl;
    cout << "Topo da pilha: " << topoPilha() << endl;
    imprime();
    pop();
    imprime();

    limparPilha();

    string expressao1 = "{[()]}";
    cout << "Expressao: " << expressao1 << endl;
    cout << "Verificacao: " << (verificaExpressao(expressao1) ? "Correta" : "Incorreta") << endl;

    limparPilha();

    string expressao2 = "{[(])}";
    cout << "Expressao: " << expressao2 << endl;
    cout << "Verificacao: " << (verificaExpressao(expressao2) ? "Correta" : "Incorreta") << endl;

    return 0;
}

void push(int valor) {
    if (topo == TAM - 1) {
        cout << "Pilha cheia!" << endl;
        return;
    }
    topo++;
    Pilha[topo] = valor;
    cout << valor << " inserido na pilha" << endl;
}

bool vazia() {
    return topo == -1;
}

void pop() {
    if (vazia()) {
        cout << "Pilha vazia" << endl;
        return;
    }
    topo--;
    cout << "Elemento removido" << endl;
}

int topoPilha() {
    if (vazia()) {
        cout << "Pilha vazia" << endl;
        return -1;
    }
    return Pilha[topo];
}

void imprime() {
    if (vazia()) {
        cout << "Pilha vazia" << endl;
        return;
    }
    cout << "Conteudo da pilha:" << endl;
    for (int i = topo; i >= 0; i--) {
        cout << Pilha[i] << endl;
    }
}

void limparPilha() {
    topo = -1;
    cout << "Pilha limpa" << endl;
}

bool verificaExpressao(string expressao) {
    for (char c : expressao) {
        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (vazia()) return false;
            char topoChar = topoPilha();
            if ((c == ')' && topoChar != '(') || 
                (c == ']' && topoChar != '[') || 
                (c == '}' && topoChar != '{')) {
                return false;
            }
            pop();
        }
    }
    return vazia();
}
