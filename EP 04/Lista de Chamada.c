/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/2381 */

#include <stdio.h>
#include <string.h>

#define MAX 100

struct aluno {
    char nome[21];
    int posicao;
};

int main() {
    struct aluno alunos[MAX];
    int n, k, i, j;

    // leitura dos dados
    scanf("%d %d", &n, &k);
    for (i = 0; i < n; i++) {
        scanf("%s", alunos[i].nome);
        alunos[i].posicao = i + 1;
    }

    // ordenação dos alunos por nome
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
                struct aluno temp = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = temp;
            }
        }
    }

    // impressão do nome do aluno sorteado
    printf("%s\n", alunos[k - 1].nome);

    return 0;
}
