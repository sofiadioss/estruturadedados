#include <stdio.h>
#include "tabela_hash.h"

int main(void) {
    TabelaHash *th = hash_criar(10);

    printf("A tabela esta vazia? %s\n", hash_esta_vazia(th) ? "Sim" : "Nao");

    printf("\nInserindo 10, 25, 35, 42, 72, 93, 5...\n");
    hash_inserir(th, 10);
    hash_inserir(th, 25);
    hash_inserir(th, 35);
    hash_inserir(th, 42);
    hash_inserir(th, 72);
    hash_inserir(th, 93);
    hash_inserir(th,  5);

    printf("\n");
    hash_exibir(th);

    printf("\nA tabela esta vazia? %s\n", hash_esta_vazia(th) ? "Sim" : "Nao");

    printf("\nBuscando 42: %s\n", hash_buscar(th, 42) ? "Encontrado" : "Nao encontrado");
    printf("Buscando 99: %s\n", hash_buscar(th, 99) ? "Encontrado" : "Nao encontrado");

    printf("\nRemovendo 35...\n");
    hash_remover(th, 35);
    hash_exibir(th);

    hash_destruir(th);
    printf("\nTabela destruida. Memoria liberada!\n");

    return 0;
}