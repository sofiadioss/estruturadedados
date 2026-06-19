#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_t {
    int          valor;
    struct no_t *proximo;
} no_t;

struct pilha_t {
    no_t *topo;
};

Pilha* pilha_criar(void) {
    Pilha *pilha = (Pilha*) malloc(sizeof(Pilha));
    if (pilha == NULL) return NULL;
    pilha->topo = NULL;
    return pilha;
}

bool pilha_esta_vazia(Pilha *pilha) {
    return pilha->topo == NULL;
}

void pilha_empilhar(Pilha *pilha, int valor) {
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return;
    novo->valor   = valor;
    novo->proximo = pilha->topo;
    pilha->topo   = novo;
}

bool pilha_desempilhar(Pilha *pilha, int *valor) {
    if (pilha_esta_vazia(pilha)) return false;
    no_t *removido = pilha->topo;
    *valor        = removido->valor;
    pilha->topo   = removido->proximo;
    free(removido);
    return true;
}

bool pilha_topo(Pilha *pilha, int *valor) {
    if (pilha_esta_vazia(pilha)) return false;
    *valor = pilha->topo->valor;
    return true;
}

void pilha_exibir(Pilha *pilha) {
    printf("Topo -> [ ");
    no_t *atual = pilha->topo;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void pilha_destruir(Pilha *pilha) {
    no_t *atual = pilha->topo;
    while (atual != NULL) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(pilha);
}