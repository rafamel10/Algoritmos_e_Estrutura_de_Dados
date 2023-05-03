#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 20000

void heapSort(int arr[], int n);

int main() {
    int arr[Max];
    int i;

    // preenche o array com números aleatórios
    for (i = 0; i < Max; i++) {
        arr[i] = rand() % 1000; // gera um número aleatório entre 0 e 999
    }

    // ordena o array e conta o tempo de execução
    clock_t start = clock();
    heapSort(arr, Max);
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

void heapify(int arr[], int n, int i) {
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
    }

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i >= 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}
