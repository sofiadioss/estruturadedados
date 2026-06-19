#ifndef PILHA_H
#define PILHA_H

#include <stdbool.h>

typedef struct pilha_t Pilha;

Pilha* pilha_criar(void);
void   pilha_empilhar(Pilha *pilha, int valor);
bool   pilha_desempilhar(Pilha *pilha, int *valor);
bool   pilha_topo(Pilha *pilha, int *valor);
bool   pilha_esta_vazia(Pilha *pilha);
void   pilha_exibir(Pilha *pilha);
void   pilha_destruir(Pilha *pilha);

#endif