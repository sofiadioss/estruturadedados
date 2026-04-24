#include <stdio.h>

long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1) return 1;
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int n;
    long long resultado = 1;

    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    printf("Fatorial com repeticao: %lld\n", resultado);
    printf("Complexidade: O(n)\n");

    printf("Fatorial com recursividade: %lld\n", fatorial_recursivo(n));
    printf("Complexidade: O(n)\n");

    return 0;
}
