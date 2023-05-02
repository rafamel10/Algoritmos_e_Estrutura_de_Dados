/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/1238 */

#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j, k;
    char str1[51], str2[51], result[101];

    // Leitura do número de casos de teste
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        // Leitura das duas strings
        scanf("%s %s", str1, str2);

        // Combinando as strings
        j = 0;
        k = 0;
        while (str1[j] != '\0' || str2[k] != '\0') {
            if (str1[j] != '\0') {
                result[j+k] = str1[j];
                j++;
            }
            if (str2[k] != '\0') {
                result[j+k] = str2[k];
                k++;
            }
        }
        result[j+k] = '\0';

        // Impressão do resultado
        printf("%s\n", result);
    }

    return 0;
}