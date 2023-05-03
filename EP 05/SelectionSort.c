#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 20000

void selectionSort(int arr[], int n);

int main() {
    int arr[Max];
    int i;

    // preenche o array com números aleatórios
    for (i = 0; i < Max; i++) {
        arr[i] = rand() % 1000; // gera um número aleatório entre 0 e 999
    }

    // ordena o array e conta o tempo de execução
    clock_t start = clock();
    selectionSort(arr, Max);
    clock_t end = clock();

    // imprime o array ordenado
    for (i = 0; i < Max; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // imprime o tempo de execução
    printf("Tempo de execucao: %f segundos\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++) {
        min_idx = i;
        for (j = i+1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
