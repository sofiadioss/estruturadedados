#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *pilha = pilha_criar();
    int valor;

    printf("A pilha esta vazia? %s\n", pilha_esta_vazia(pilha) ? "Sim" : "Nao");

    printf("\nEmpilhando 10, 20, 30, 40...\n");
    pilha_empilhar(pilha, 10);
    pilha_empilhar(pilha, 20);
    pilha_empilhar(pilha, 30);
    pilha_empilhar(pilha, 40);

    printf("Pilha atual: ");
    pilha_exibir(pilha);

    if (pilha_topo(pilha, &valor))
        printf("\nTopo: %d\n", valor);

    printf("\nDesempilhando...\n");
    while (!pilha_esta_vazia(pilha)) {
        pilha_desempilhar(pilha, &valor);
        printf("Retirado: %d | Pilha: ", valor);
        pilha_exibir(pilha);
    }

    printf("\nA pilha esta vazia? %s\n", pilha_esta_vazia(pilha) ? "Sim" : "Nao");

    pilha_destruir(pilha);
    printf("Pilha destruida. Memoria liberada!\n");

    return 0;
}