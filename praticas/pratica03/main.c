#include <stdio.h>
#include "conta.h"

int main() {
    Conta c = conta_criar(1001, 0.0);

    conta_depositar(c, 500.0);
    conta_depositar(c, 200.0);

    printf("Saldo: %.2f\n", conta_ver_saldo(c));

    conta_sacar(c, 100.0);
    printf("Saldo apos saque: %.2f\n", conta_ver_saldo(c));

    conta_sacar(c, 1000.0);

    conta_destruir(c);
return 0;
}