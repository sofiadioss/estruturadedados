#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_t {
    int          valor;
    struct no_t *proximo;
} no_t;

struct fila_t {
    no_t *inicio;
    no_t *fim;
};

Fila* fila_criar(void) {
    Fila *fila = (Fila*) malloc(sizeof(Fila));
    if (fila == NULL) return NULL;
    fila->inicio = NULL;
    fila->fim    = NULL;
    return fila;
}

bool fila_esta_vazia(Fila *fila) {
    return fila->inicio == NULL;
}

void fila_enfileirar(Fila *fila, int valor) {
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return;
    novo->valor   = valor;
    novo->proximo = NULL;
    if (fila_esta_vazia(fila))
        fila->inicio = novo;
    else
        fila->fim->proximo = novo;
    fila->fim = novo;
}

bool fila_desenfileirar(Fila *fila, int *valor) {
    if (fila_esta_vazia(fila)) return false;
    no_t *removido = fila->inicio;
    *valor         = removido->valor;
    fila->inicio   = removido->proximo;
    if (fila->inicio == NULL)
        fila->fim = NULL;
    free(removido);
    return true;
}

bool fila_inicio(Fila *fila, int *valor) {
    if (fila_esta_vazia(fila)) return false;
    *valor = fila->inicio->valor;
    return true;
}

void fila_exibir(Fila *fila) {
    printf("Inicio -> [ ");
    no_t *atual = fila->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("] <- Fim\n");
}

void fila_destruir(Fila *fila) {
    no_t *atual = fila->inicio;
    while (atual != NULL) {
        no_t *proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
    free(fila);
}