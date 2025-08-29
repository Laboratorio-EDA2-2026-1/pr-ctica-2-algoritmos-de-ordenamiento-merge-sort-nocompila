#include <stdio.h>
#include <stdlib.h>

/*
    Ejercicio: Implementación de Merge Sort

    Descripción:
    Se reciben n arreglos lineales, cada uno de tamaño n.
    El programa debe combinarlos en un solo arreglo de tamaño n*n
    y ordenarlo en orden creciente usando Merge Sort.

    Entrada:
    - Un número entero n
    - n arreglos de tamaño n (n*n enteros en total)

    Salida:
    - Un solo arreglo de tamaño n*n con los elementos ordenados en orden creciente

    Ejemplo:

    Input:
    3
    3 1 5
    2 9 4
    8 7 6

    Output:
    1 2 3 4 5 6 7 8 9
*/

// ---- Prototipos ----
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);

int main() {
    int n;
    printf("Ingrese el tamaño de n: ");
    scanf("%d", &n);  // Leer el número de arreglos

    int total = n * n;  
    int *arr = (int *)malloc(total * sizeof(int));

    // Leer n arreglos de tamaño n
    for (int i = 0; i < n; i++) {
        printf("Ingrese los elementos del arreglo %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i * n + j]);
        }
    }

    // Ordenar usando merge sort
    mergeSort(arr, 0, total - 1);

    int duplicado = 0;
    for (int i = 0; i < total; i++) {
        if (i == 0 || arr[i] != arr[i - 1]) {
            arr[duplicado++] = arr[i];
        }
    }

    // Imprimir el arreglo ordenado
    printf("Arreglo ordenado: ");
    for (int i = 0; i < duplicado; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

// ---- Implementa mergeSort ----
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mitad = left + (right - left) / 2;
        mergeSort(arr, left, mitad);
        mergeSort(arr, mitad + 1, right);
        merge(arr, left, mitad, right);
    }
}

// ---- Implementa merge ----
void merge(int arr[], int left, int mitad, int right) {
    int n1 = mitad - left + 1;
    int n2 = right - mitad;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mitad + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }

    free(L);
    free(R);
}
