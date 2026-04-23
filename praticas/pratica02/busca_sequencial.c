#include <stdio.h>

int main() {
    int vetor[100], valor, posicao = -1;

    for (int i = 0; i < 100; i++) {
        vetor[i] = i + 1;
    }

    printf("Vetor preenchido com valores de 1 a 100.\n");
    printf("Digite o valor a ser buscado: ");
    scanf("%d", &valor);

    for (int i = 0; i < 100; i++) {
        if (vetor[i] == valor) {
            posicao = i;
            break;
        }
    }

    if (posicao != -1) {
        printf("Valor encontrado na posicao %d\n", posicao);
    } else {
        printf("Valor nao encontrado\n");
    }

    printf("Melhor caso: O(1) - valor na primeira posicao\n");
    printf("Pior caso: O(n) - valor na ultima posicao ou nao encontrado\n");

    return 0;
}