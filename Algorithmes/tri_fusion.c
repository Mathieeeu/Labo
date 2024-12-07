// Algorithmes de tri fusion en C
// Complexité O(n log n) dans tous les cas

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ascending(int a, int b) {
    return a > b;
}

int descending(int a, int b) {
    return a < b;
}

// fonction pour fusionner deux tableaux triés
void merge(int arr[], int left[], int right[], int leftSize, int rightSize, int(*compare)(int, int)) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (compare(left[i], right[j])) {
            arr[k++] = right[j++];
        } else {
            arr[k++] = left[i++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }

    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}

// algorithme de tri fusion pour un tableau d'entiers
void mergeSort(int arr[], int size, int(*compare)(int, int)) {
    if (size < 2) {
        return;
    }

    int mid = size / 2;
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((size - mid) * sizeof(int));

    // Remplir les tableaux gauche et droit
    for (int i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    for (int i = mid; i < size; i++) {
        right[i - mid] = arr[i];
    }

    // Tri récursif
    mergeSort(left, mid, compare);
    mergeSort(right, size - mid, compare);

    // Fusionner les deux tableaux triés
    merge(arr, left, right, mid, size - mid, compare);

    // Libérer la mémoire
    free(left);
    free(right);
}

// Fonction pour afficher le tableau
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    clock_t start, end;
    int cpu_time_used;

    int data[] = {1, 5, 2, 3, 2, 9, 6, 7, 8, 4, 10, -1, 0, 11, 15, 13, 12, 14};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Tableau non trié (taille : %d): ", size);
    printArray(data, size);

    // trier le tableau par ordre croissant
    start = clock();
    mergeSort(data, size, &ascending);
    end = clock();
    cpu_time_used = (end - start) / (CLOCKS_PER_SEC/1000000);
    printf("Tableau trié par ordre croissant: ");
    printArray(data, size);
    printf("Temps d'exécution : %d µs\n", cpu_time_used);

    // trier le tableau par ordre décroissant
    start = clock();
    mergeSort(data, size, &descending);
    end = clock();
    cpu_time_used = (end - start) / (CLOCKS_PER_SEC/1000000);
    printf("Tableau trié par ordre décroissant: ");
    printArray(data, size);
    printf("Temps d'exécution : %d µs\n", cpu_time_used);

    return 0;
}
