#include "tabela_hash.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct no_t {
    int          valor;
    struct no_t *proximo;
} no_t;

struct hash_t {
    no_t **tabela;
    int    tamanho;
};

static int funcao_hash(TabelaHash *th, int valor) {
    return abs(valor) % th->tamanho;
}

TabelaHash* hash_criar(int tamanho) {
    TabelaHash *th = (TabelaHash*) malloc(sizeof(TabelaHash));
    if (th == NULL) return NULL;
    th->tamanho = tamanho;
    th->tabela  = (no_t**) calloc(tamanho, sizeof(no_t*));
    if (th->tabela == NULL) {
        free(th);
        return NULL;
    }
    return th;
}

bool hash_esta_vazia(TabelaHash *th) {
    for (int i = 0; i < th->tamanho; i++)
        if (th->tabela[i] != NULL) return false;
    return true;
}

void hash_inserir(TabelaHash *th, int valor) {
    int indice = funcao_hash(th, valor);
    no_t *novo = (no_t*) malloc(sizeof(no_t));
    if (novo == NULL) return;
    novo->valor   = valor;
    novo->proximo = th->tabela[indice];
    th->tabela[indice] = novo;
}

bool hash_buscar(TabelaHash *th, int valor) {
    int indice  = funcao_hash(th, valor);
    no_t *atual = th->tabela[indice];
    while (atual != NULL) {
        if (atual->valor == valor) return true;
        atual = atual->proximo;
    }
    return false;
}

bool hash_remover(TabelaHash *th, int valor) {
    int indice   = funcao_hash(th, valor);
    no_t *atual  = th->tabela[indice];
    no_t *anterior = NULL;
    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior == NULL)
                th->tabela[indice] = atual->proximo;
            else
                anterior->proximo = atual->proximo;
            free(atual);
            return true;
        }
        anterior = atual;
        atual    = atual->proximo;
    }
    return false;
}

void hash_exibir(TabelaHash *th) {
    printf("Tabela Hash:\n");
    for (int i = 0; i < th->tamanho; i++) {
        printf("  [%2d] -> ", i);
        no_t *atual = th->tabela[i];
        if (atual == NULL) {
            printf("vazio");
        } else {
            while (atual != NULL) {
                printf("%d ", atual->valor);
                atual = atual->proximo;
            }
        }
        printf("\n");
    }
}

void hash_destruir(TabelaHash *th) {
    for (int i = 0; i < th->tamanho; i++) {
        no_t *atual = th->tabela[i];
        while (atual != NULL) {
            no_t *proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
    }
    free(th->tabela);
    free(th);
}