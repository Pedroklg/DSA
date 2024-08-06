#include <stdlib.h>
#include <stdio.h>

int main () {
    int* ptr;
    printf("Endereco : %p \n", ptr);

    ptr = (int *)malloc(sizeof (int));
    printf("Endereco : %p \n Valor: %d \n", ptr, *ptr);

    return 0;
}