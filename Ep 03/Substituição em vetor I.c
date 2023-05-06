/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/1172 */

#include <stdio.h>

int main() {
    int x[10];

    // lendo os valores do vetor
    for (int i = 0; i < 10; i++) {
        scanf("%d", &x[i]);
    }

    // substituindo os valores nulos e negativos por 1
    for (int i = 0; i < 10; i++) {
        if (x[i] <= 0) {
            x[i] = 1;
        }
    }

    // mostrando o vetor resultante
    for (int i = 0; i < 10; i++) {
        printf("X[%d] = %d\n", i, x[i]);
    }

    return 0;
}
