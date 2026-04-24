#include "ordenacao.h"

void bubble_sort(int *vetor, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

void selection_sort(int *vetor, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[min];
        vetor[min] = temp;
    }
}
int particionar(int *vetor, int inicio, int fim) {
    int pivot = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivot) {
            i++;
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
    }
    int temp = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = temp;
    return i + 1;
}


void quick_sort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int p = particionar(vetor, inicio, fim);
    
        quick_sort(vetor, inicio, p - 1);
        quick_sort(vetor, p + 1, fim);
    }
}