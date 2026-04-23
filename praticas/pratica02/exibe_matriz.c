#include <stdio.h>
#include <time.h>

int main() {
    int matriz[10][10];
    clock_t inicio, fim;
    double tempo1, tempo2;

    for (int i = 0; i < 10; i++)
        for (int j = 0; j < 10; j++)
            matriz[i][j] = i * 10 + j;

    printf("Forma 1 - dois lacos aninhados:\n");
    inicio = clock();
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
    fim = clock();
    tempo1 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nForma 2 - um unico laco:\n");
    inicio = clock();
    for (int k = 0; k < 100; k++) {
        printf("%d ", matriz[k/10][k%10]);
        if ((k + 1) % 10 == 0) printf("\n");
    }
    fim = clock();
    tempo2 = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("\nTempo com dois lacos: %f segundos\n", tempo1);
    printf("Tempo com um laco: %f segundos\n", tempo2);
    printf("Complexidade dos dois: O(n^2)\n");
    printf("Ambos percorrem os mesmos 100 elementos\n");

    return 0;
}