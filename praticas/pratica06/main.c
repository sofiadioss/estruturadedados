#include <stdio.h>
#include "lista_linear.h"

int main(void) {
    Lista *lista = lista_criar();

    printf("A lista esta vazia? %s\n", lista_esta_vazia(lista) ? "Sim" : "Nao");

    printf("\nInserindo 10, 20, 30, 40...\n");
    lista_inserir(lista, 10);
    lista_inserir(lista, 20);
    lista_inserir(lista, 30);
    lista_inserir(lista, 40);

    printf("Lista atual: ");
    lista_exibir(lista);

    printf("\nA lista esta vazia? %s\n", lista_esta_vazia(lista) ? "Sim" : "Nao");

    printf("\nBuscando 30: %s\n", lista_buscar(lista, 30) ? "Encontrado" : "Nao encontrado");
    printf("Buscando 99: %s\n", lista_buscar(lista, 99) ? "Encontrado" : "Nao encontrado");

    printf("\nRemovendo o do meio (20)...\n");
    lista_remover(lista, 20);
    printf("Lista: ");
    lista_exibir(lista);

    printf("\nRemovendo o primeiro (10)...\n");
    lista_remover(lista, 10);
    printf("Lista: ");
    lista_exibir(lista);

    printf("\nRemovendo o ultimo (40)...\n");
    lista_remover(lista, 40);
    printf("Lista: ");
    lista_exibir(lista);

    lista_destruir(lista);
    printf("\nLista destruida. Memoria liberada!\n");

    return 0;
}