#include <stdio.h>

int main() {
    float peso, altura, imc;

    printf("Digite o peso (kg): ");
    scanf("%f", &peso);

    printf("Digite a altura (m): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("IMC: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Situacao: abaixo do peso\n");
    } else if (imc <= 24.9) {
        printf("Situacao: peso normal\n");
    } else if (imc <= 29.9) {
        printf("Situacao: sobrepeso\n");
    } else {
        printf("Situacao: obesidade\n");
    }

    return 0;
}
