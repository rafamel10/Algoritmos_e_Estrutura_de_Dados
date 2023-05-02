/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/1036*/

#include <stdio.h>
#include <math.h>

int main() {
    double a, b, c, delta, x1, x2;

    // Leitura dos valores de A, B e C
    scanf("%lf %lf %lf", &a, &b, &c);

    // Cálculo do delta
    delta = pow(b, 2) - 4 * a * c;

    // Verificação da possibilidade de calcular as raízes
    if (a == 0 || delta < 0) {
        printf("Impossivel calcular\n");
    } else {
        // Cálculo das raízes
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        // Impressão do resultado com 5 dígitos após o ponto
        printf("R1 = %.5lf\n", x1);
        printf("R2 = %.5lf\n", x2);
    }

    return 0;
}