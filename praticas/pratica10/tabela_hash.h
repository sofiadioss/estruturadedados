#ifndef TABELA_HASH_H
#define TABELA_HASH_H

#include <stdbool.h>

typedef struct hash_t TabelaHash;

TabelaHash* hash_criar(int tamanho);
void        hash_inserir(TabelaHash *th, int valor);
bool        hash_buscar(TabelaHash *th, int valor);
bool        hash_remover(TabelaHash *th, int valor);
void        hash_exibir(TabelaHash *th);
bool        hash_esta_vazia(TabelaHash *th);
void        hash_destruir(TabelaHash *th);

#endif