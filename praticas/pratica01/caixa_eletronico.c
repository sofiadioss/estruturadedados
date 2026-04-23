#include <stdio.h>

int main() {
    int valor, notas[7];
    int cedulas[] = {200, 100, 50, 20, 10, 5, 2};

    printf("Digite o valor do saque (maximo R$1000): ");
    scanf("%d", &valor);

    if (valor < 1 || valor > 1000) {
        printf("Valor invalido!\n");
        return 1;
    }

    printf("\nNotas utilizadas:\n");
    for (int i = 0; i < 7; i++) {
        notas[i] = valor / cedulas[i];
        valor %= cedulas[i];

        if (notas[i] > 0) {
            printf("R$%d: %d nota(s)\n", cedulas[i], notas[i]);
        }
    }

    return 0;
}