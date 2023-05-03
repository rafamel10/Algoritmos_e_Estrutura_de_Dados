#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define Max 20000

void insertionSort(int arr[], int n);

int main() {
    int arr[Max];
    int i;

    // preenche o array com números aleatórios
    for (i = 0; i < Max; i++) {
        arr[i] = rand() % 1000; // gera um número aleatório entre 0 e 999
    }

    // ordena o array e conta o tempo de execução
    clock_t start = clock();
    insertionSort(arr, Max);
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

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}