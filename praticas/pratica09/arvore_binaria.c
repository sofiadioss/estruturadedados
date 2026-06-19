#include "arvore_binaria.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_t {
    int          valor;
    struct no_t *esquerda;
    struct no_t *direita;
} no_t;

struct arvore_t {
    no_t *raiz;
};

Arvore* arvore_criar(void) {
    Arvore *arvore = (Arvore*) malloc(sizeof(Arvore));
    if (arvore == NULL) return NULL;
    arvore->raiz = NULL;
    return arvore;
}

bool arvore_esta_vazia(Arvore *arvore) {
    return arvore->raiz == NULL;
}

static no_t* inserir_recursivo(no_t *no, int valor) {
    if (no == NULL) {
        no_t *novo = (no_t*) malloc(sizeof(no_t));
        if (novo == NULL) return NULL;
        novo->valor     = valor;
        novo->esquerda  = NULL;
        novo->direita   = NULL;
        return novo;
    }
    if (valor < no->valor)
        no->esquerda = inserir_recursivo(no->esquerda, valor);
    else if (valor > no->valor)
        no->direita = inserir_recursivo(no->direita, valor);
    return no;
}

void arvore_inserir(Arvore *arvore, int valor) {
    arvore->raiz = inserir_recursivo(arvore->raiz, valor);
}

static void pre_ordem(no_t *no) {
    if (no == NULL) return;
    printf("%d ", no->valor);
    pre_ordem(no->esquerda);
    pre_ordem(no->direita);
}

static void em_ordem(no_t *no) {
    if (no == NULL) return;
    em_ordem(no->esquerda);
    printf("%d ", no->valor);
    em_ordem(no->direita);
}

static void pos_ordem(no_t *no) {
    if (no == NULL) return;
    pos_ordem(no->esquerda);
    pos_ordem(no->direita);
    printf("%d ", no->valor);
}

void arvore_exibir_pre_ordem(Arvore *arvore) {
    printf("Pre-ordem:  [ ");
    pre_ordem(arvore->raiz);
    printf("]\n");
}

void arvore_exibir_em_ordem(Arvore *arvore) {
    printf("Em-ordem:   [ ");
    em_ordem(arvore->raiz);
    printf("]\n");
}

void arvore_exibir_pos_ordem(Arvore *arvore) {
    printf("Pos-ordem:  [ ");
    pos_ordem(arvore->raiz);
    printf("]\n");
}

static void destruir_recursivo(no_t *no) {
    if (no == NULL) return;
    destruir_recursivo(no->esquerda);
    destruir_recursivo(no->direita);
    free(no);
}

void arvore_destruir(Arvore *arvore) {
    destruir_recursivo(arvore->raiz);
    free(arvore);
}