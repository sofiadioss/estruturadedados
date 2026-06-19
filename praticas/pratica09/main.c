#include <stdio.h>
#include "arvore_binaria.h"

int main(void) {
    Arvore *arvore = arvore_criar();

    printf("A arvore esta vazia? %s\n", arvore_esta_vazia(arvore) ? "Sim" : "Nao");

    printf("\nInserindo 50, 30, 70, 20, 40, 60, 80...\n");
    arvore_inserir(arvore, 50);
    arvore_inserir(arvore, 30);
    arvore_inserir(arvore, 70);
    arvore_inserir(arvore, 20);
    arvore_inserir(arvore, 40);
    arvore_inserir(arvore, 60);
    arvore_inserir(arvore, 80);

    printf("\nA arvore esta vazia? %s\n\n", arvore_esta_vazia(arvore) ? "Sim" : "Nao");

    arvore_exibir_pre_ordem(arvore);
    arvore_exibir_em_ordem(arvore);
    arvore_exibir_pos_ordem(arvore);

    arvore_destruir(arvore);
    printf("\nArvore destruida. Memoria liberada!\n");

    return 0;
}