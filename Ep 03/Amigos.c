/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/3160*/

#include <stdio.h>
#include <string.h>

#define MAX_AMIGOS 100

int main(int argc, char *argv[]) {
    char lista_atual[MAX_AMIGOS][50], nova_lista[MAX_AMIGOS][50];
    char amigo_indicacao[50], nome_amigo[50];
    int i, j, n_atual, n_nova, pos_indicacao;

    // leitura da lista atual de amigos
    fgets(lista_atual[0], 50, stdin);
    n_atual = 0;
    while (lista_atual[n_atual][strlen(lista_atual[n_atual])-1] != '\n') {
        n_atual++;
        fgets(lista_atual[n_atual], 50, stdin);
    }
    lista_atual[n_atual][strlen(lista_atual[n_atual])-1] = '\0';
    n_atual++;

    // leitura da nova lista de amigos
    fgets(nova_lista[0], 50, stdin);
    n_nova = 0;
    while (nova_lista[n_nova][strlen(nova_lista[n_nova])-1] != '\n') {
        n_nova++;
        fgets(nova_lista[n_nova], 50, stdin);
    }
    nova_lista[n_nova][strlen(nova_lista[n_nova])-1] = '\0';
    n_nova++;

    // leitura do amigo de indicação
    fgets(amigo_indicacao, 50, stdin);
    amigo_indicacao[strlen(amigo_indicacao)-1] = '\0';

    // encontrar posição de indicação (se houver)
    pos_indicacao = n_atual;
    if (strcmp(amigo_indicacao, "nao") != 0) {
        for (i = 0; i < n_atual; i++) {
            if (strcmp(lista_atual[i], amigo_indicacao) == 0) {
                pos_indicacao = i;
                break;
            }
        }
    }

    // inserir nova lista antes do amigo de indicação (se houver)
    j = pos_indicacao;
    for (i = 0; i < n_nova; i++) {
        strcpy(nome_amigo, nova_lista[i]);
        if (strcmp(nome_amigo, lista_atual[pos_indicacao]) != 0) {
            // evitar inserir amigo de indicação duas vezes
            if (j == pos_indicacao) {
                j++;
            }
            strcpy(lista_atual[j], nome_amigo);
            j++;
        }
    }

    // exibir nova lista de amigos atualizada
    for (i = 0; i < n_atual + n_nova - 1; i++) {
        printf("%s\n", lista_atual[i]);
    }

    return 0;
}