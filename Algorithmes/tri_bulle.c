// Algorithmes de tri à bulle en C
// Complexité O(n^2) en moyenne et dans le pire des cas, O(n) dans le meilleur des cas

#include <stdio.h>
#include <time.h>

int ascending(int a, int b) {
    return a > b;
}

int descending(int a, int b) {
    return a < b;
}

// algorithme de tri à bulle pour un tableau d'entiers
void bubbleSort(int arr[], int size, int(*compare)(int,int)) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                // échanger les éléments s'ils sont dans le mauvais ordre
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// fonction pour afficher un tableau d'entiers
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
    int size = sizeof(data) / sizeof(data[0]); // Size = nombre d'éléments dans le tableau, ici 5 sauf que sizeof(data) renvoie la taille totale du tableau en octets et sizeof(data[0]) renvoie la taille d'un élément du tableau en octets. La division des deux donne le nombre d'éléments dans le tableau.

    printf("Tableau non trié: ");
    printArray(data, size);

    // trier le tableau par ordre croissant
    start = clock();
    bubbleSort(data, size, &ascending);
    end = clock();
    cpu_time_used = (end - start) / (CLOCKS_PER_SEC/1000000);
    printf("Tableau trié par ordre croissant: ");
    printArray(data, size);
    printf("Temps d'exécution : %d µs\n", cpu_time_used);


    // trier le tableau par ordre décroissant
    start = clock();
    bubbleSort(data, size, &descending);
    end = clock();
    cpu_time_used = (end - start) / (CLOCKS_PER_SEC/1000000);
    printf("Tableau trié par ordre décroissant: ");
    printArray(data, size);
    printf("Temps d'exécution : %d µs\n", cpu_time_used);

    return 0;
}