/*Enunciado: https://www.beecrowd.com.br/judge/pt/problems/view/1002 */

#include <stdio.h>
#define Pi 3.14159


void calculaPi(double raio){
    double area;
    area=Pi*raio*raio;
    printf("A=%.4lf\n",area);
}
int main() {
    double x;
    scanf("%lf",&x);
    calculaPi(x);
    return 0;
}