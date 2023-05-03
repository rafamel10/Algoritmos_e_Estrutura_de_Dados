#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 20000

void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);

int main() {
    int arr[Max];
    int i;

    // preenche o array com números aleatórios
    for (i = 0; i < Max; i++) {
        arr[i] = rand() % 1000; // gera um número aleatório entre 0 e 999
    }

    // ordena o array e conta o tempo de execução
    clock_t start = clock();
    quickSort(arr, 0, Max-1);
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

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = partition(arr, left, right);
        quickSort(arr, left, pivot - 1);
        quickSort(arr, pivot + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for (int j = left; j <= right - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[right];
    arr[right] = temp;
    return i + 1;
}
