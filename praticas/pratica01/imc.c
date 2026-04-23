#include <stdio.h>
int main() {
    float peso, altura, imc;

    printf("Digite seu peso (em kg): ");
    scanf("%f", &peso);

    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);

    imc = peso / (altura * altura);

    printf("Seu IMC é: %.2f\n", imc);

    if (imc < 18.5) {
        printf("Classificação: Abaixo do peso\n");
    } else if (imc < 25.0) {
        printf("Classificação: Peso normal\n");
    } else if (imc  < 30.0) {
        printf("Classificação: Sobrepeso\n");
    } else if (imc < 35.0) {
        printf("Classificação: Obesidade grau I\n");   
    }  else if (imc < 40.0) {
        printf("Classificação: Obesidade grau II\n");
    } else {
        printf("Classificação: Obesidade grau III\n");
    }

    return 0;
}