#include <stdio.h>
#include "fila.h"

int main(void) {
    Fila *fila = fila_criar();
    int valor;

    printf("A fila esta vazia? %s\n", fila_esta_vazia(fila) ? "Sim" : "Nao");

    printf("\nEnfileirando 10, 20, 30, 40...\n");
    fila_enfileirar(fila, 10);
    fila_enfileirar(fila, 20);
    fila_enfileirar(fila, 30);
    fila_enfileirar(fila, 40);

    printf("Fila atual: ");
    fila_exibir(fila);

    if (fila_inicio(fila, &valor))
        printf("\nPrimeiro da fila: %d\n", valor);

    printf("\nDesenfileirando...\n");
    while (!fila_esta_vazia(fila)) {
        fila_desenfileirar(fila, &valor);
        printf("Atendido: %d | Fila: ", valor);
        fila_exibir(fila);
    }

    printf("\nA fila esta vazia? %s\n", fila_esta_vazia(fila) ? "Sim" : "Nao");

    fila_destruir(fila);
    printf("Fila destruida. Memoria liberada!\n");

    return 0;
}