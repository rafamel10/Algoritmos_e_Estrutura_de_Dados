/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/1871 */

#include <stdio.h>

int removeZeros(int n) {
    int res = 0, fator = 1;
    while (n > 0) {
        int digito = n % 10;
        if (digito != 0) {
            res += digito * fator;
            fator *= 10;
        }
        n /= 10;
    }
    return res;
}

int main() {
    int m, n;
    while (1) {
        scanf("%d %d", &m, &n);
        if (m == 0 && n == 0) break;
        int soma = removeZeros(m) + removeZeros(n);
        printf("%d\n", removeZeros(soma));
    }
    return 0;
}