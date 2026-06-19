#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

typedef struct fila_t Fila;

Fila* fila_criar(void);
void  fila_enfileirar(Fila *fila, int valor);
bool  fila_desenfileirar(Fila *fila, int *valor);
bool  fila_inicio(Fila *fila, int *valor);
void  fila_exibir(Fila *fila);
bool  fila_esta_vazia(Fila *fila);
void  fila_destruir(Fila *fila);

#endif