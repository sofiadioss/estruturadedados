#include <stdio.h> 
int main() {
    int n; /*guarda quantos números o usuário quer calcular a média*/
    float soma = 0.0, numero; /*soma guarda a soma dos números, numero guarda o número digitado pelo usuário*/
    
    printf("Quantos números você deseja calcular a média? ");
    scanf("%d", &n);

    if(n < 1 || n > 100) {
        printf("Número inválido. Por favor, digite um número entre 1 e 100.\n");
        return 1; /* Encerra o programa com código de erro */
    }
    for (int i = 1; i <= n; i++) {
        printf("Digite o número %d: ", i);
        scanf("%f", &numero);
        soma += numero; /*soma recebe a soma dos números digitados pelo usuário*/
    }
    printf("A média aritmética é: %.2f\n", soma / n); /*imprime a média aritmética dos números digitados pelo usuário*/
    
    return 0;
}