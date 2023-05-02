/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/1383 */

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int instancia = 1;

    while (n--) {
        int sudoku[9][9];
        int linhas[9][10] = {0}; // matriz para verificar se números das linhas já apareceram
        int colunas[9][10] = {0}; // matriz para verificar se números das colunas já apareceram
        int regioes[3][3][10] = {0}; // matriz para verificar se números das regiões já apareceram

        // leitura da matriz
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                scanf("%d", &sudoku[i][j]);
            }
        }

        // verificação das linhas e colunas
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int num = sudoku[i][j];
                if (linhas[i][num] || colunas[j][num]) {
                    printf("Instancia %d\nNAO\n\n", instancia);
                    goto proxima_instancia; // pula para a próxima instância
                } else {
                    linhas[i][num] = 1;
                    colunas[j][num] = 1;
                }
            }
        }

        // verificação das regiões
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        int num = sudoku[k][l];
                        if (regioes[i/3][j/3][num]) {
                            printf("Instancia %d\nNAO\n\n", instancia);
                            goto proxima_instancia; // pula para a próxima instância
                        } else {
                            regioes[i/3][j/3][num] = 1;
                        }
                    }
                }
            }
        }

        // se chegou até aqui, é uma solução válida
        printf("Instancia %d\nSIM\n\n", instancia);

        proxima_instancia:
        instancia++;
    }

    return 0;
}