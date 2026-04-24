#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

void copiar_vetor(int *origem, int *destino, int n) {
    for (int i = 0; i < n; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int n = 100;
    int original[100], v1[100], v2[100], v3[100];
    clock_t inicio, fim;
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        original[i] = rand() % 1000;
    }

    copiar_vetor(original, v1, n);
    copiar_vetor(original, v2, n);
    copiar_vetor(original, v3, n);

    inicio = clock();
    bubble_sort(v1, n);
    fim = clock();
    printf("Bubble Sort:    %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    selection_sort(v2, n);
    fim = clock();
    printf("Selection Sort: %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    inicio = clock();
    quick_sort(v3, 0, n - 1);
    fim = clock();
    printf("Quick Sort:     %.6f segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    return 0;
}