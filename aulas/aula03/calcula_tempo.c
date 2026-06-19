#include <stdio.h>
#include <time.h>
int main () {
   
    //ligou o cronometro
    clock_t tempo_inicial = clock();

    int soma = 10 +20; //O(1)
    //desligou o cronometro 
    clock_t tempo_final = clock();
    double duracao = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %5f segundos\n", duracao);


    tempo_inicial = clock();
    for (int i = 0; i < 100000; i++) {
        soma += i; //O(n)
    }
    tempo_final = clock();
    duracao = (double)(tempo_final - tempo_inicial) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %5f segundos\n", duracao);
    return 0;
}