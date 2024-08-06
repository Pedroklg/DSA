#include <iostream>

using namespace std;

int main () {
    int count = 1;
    int *ptr;
    int valor;
    ptr = &count;
    valor = *ptr;
    valor = valor + 1;
    *ptr = count + 1;

    cout << "Valor inteiro da variavel count: " << count << endl;
    cout << "Endereco da variavel contador: " << &count << endl;
    cout << "Valor do endereco de contador por ptr: " << ptr << endl;
    cout << "Valor inteiro da variavel valor : " << valor << endl;
    cout << "Valor inteiro da variavel count: " << count << endl;
    cout << "Valor inteiro da variavel *ptr " << count << endl;


    return 0;
}