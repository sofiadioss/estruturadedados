#include "lista_linear.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_t {
    struct no_t *anterior;
    int          valor;
    struct no_t *proximo;
} no_t;

struct lista_t {
    no_t *primeiro;
    no_t *ultimo;
};

Lista* lista_criar(void) {
    Lista *lista = (Lista*) malloc(sizeof(Lista));
    if (lista == NULL) return NULL;
    lista->primeiro = NULL;
    lista->ultimo   = NULL;
    return lista;
}

bool lista_esta_vazia(Lista *lista) {
    return lista->primeiro == NULL;
}

void lista_inserir(Lista *lista, int valor) {
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return;
    novo->valor    = valor;
    novo->proximo  = NULL;
    novo->anterior = lista->ultimo;
    if (lista_esta_vazia(lista))
        lista->primeiro = novo;
    else
        lista->ultimo->proximo = novo;
    lista->ultimo = novo;
}

bool lista_buscar(Lista *lista, int valor) {
    no_t *atual = lista->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) return true;
        atual = atual->proximo;
    }
    return false;
}

bool lista_remover(Lista *lista, int valor) {
    no_t *atual = lista->primeiro;
    while (atual != NULL && atual->valor != valor)
        atual = atual->proximo;
    if (atual == NULL) return false;
    if (atual->anterior != NULL)
        atual->anterior->proximo = atual->proximo;
    else
        lista->primeiro = atual->proximo;
    if (atual->proximo != NULL)
        atual->proximo->anterior = atual->anterior;
    else
        lista->ultimo = atual->anterior;
    free(atual);
    return true;
}

void lista_exibir(Lista *lista) {
    printf("[ ");
    no_t *atual = lista->primeiro;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void lista_destruir(Lista *lista) {
    no_t *atual = lista->primeiro;
    while (atual != NULL) {
        no_t *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
    free(lista);
}