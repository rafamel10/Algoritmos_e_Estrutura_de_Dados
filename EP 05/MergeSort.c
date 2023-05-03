#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define Max 20000

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int arr[Max];
    int i;

    // preenche o array com números aleatórios
    for (i = 0; i < Max; i++) {
        arr[i] = rand() % 1000; // gera um número aleatório entre 0 e 999
    }

    // ordena o array e conta o tempo de execução
    clock_t start = clock();
    mergeSort(arr, 0, Max-1);
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

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // cria arrays temporários
    int L[n1], R[n2];

    // copia os dados para os arrays temporários L[] e R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // mescla os arrays temporários de volta em arr[l..r]
    i = 0;
    j = 0;
    k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // copia os elementos restantes de L[], se houver
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // copia os elementos restantes de R[], se houver
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
