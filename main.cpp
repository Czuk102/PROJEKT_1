


//
// Created by Czukulus on 20.05.2022.
/*
  This program was made in purpose to measure time complexity of specific sorting algorithms


*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int SIZE = 300000;


int *generateRandomArray(int size) {
    int *numbers = (int *) malloc(sizeof(*numbers) * size);
    for (int i = 0; i <= 300000; i++) {
        numbers[i] = rand();
    }
    return numbers;
}

int *generateSortedArray(int size) {
    int *numbers = (int *) malloc(sizeof(*numbers) * size);
    for (int i = 0; i < 300000; i++) {
        numbers[i] = i;
    }
    return numbers;
}

int *generateReverseSortedArray(int size) {
    int *numbers = (int *) malloc(sizeof(*numbers) * size);
    for (int i = 300000; i < 0; i--) {
        numbers[i] = i;
    }
    return numbers;
}


void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int n, int i) {

    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}


void heapSort(int arr[], int n) {

    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
    }
}


int partition(int array[], int low, int high) {


    int pivot = array[high];

    int i = (low - 1);

    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;

            swap(&array[i], &array[j]);
        }
    }


    swap(&array[i + 1], &array[high]);

    return (i + 1);
}

void quickSort(int array[], int low, int high) {
    if (low < high) {

        int pi = partition(array, low, high);

        quickSort(array, low, pi - 1);
        quickSort(array, pi + 1, high);
    }
}

void merge(int arr[], int p, int q, int r) {

    int n1 = q - p + 1;
    int n2 = r - q;

    int L[n1], M[n2];

    for (int i = 0; i < n1; i++)
        L[i] = arr[p + i];
    for (int j = 0; j < n2; j++)
        M[j] = arr[q + 1 + j];

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n1 && j < n2) {
        if (L[i] <= M[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = M[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = M[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {

        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

void bubbleSort(int arr[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++)

        // Last i elements are already
        // in place
        for (j = 0; j < n - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &arr[j + 1]);
}


int main() {

    printf("PROJEKT 1\n\n");
    printf("Program generuje statyczne tablice (losowe, posortowane rosnaco, posortowane malejaco) o wielkosci 300k,\n");
    printf("nastepnie sortuje je oraz mierzy czas operacji dla poszczegolnych algorytmow. \n\n");

    // numbers generated multiple times are the same in each array
    srand(1);
    int *randomArr1 = generateRandomArray(SIZE);

    clock_t start_heap = clock();
    heapSort(randomArr1, 300000);
    clock_t end_heap = clock();
    free(randomArr1);

    int *randomArr2 = generateRandomArray(SIZE);
    clock_t start_quick = clock();
    quickSort(randomArr2, 0, 300000 - 1);
    clock_t end_quick = clock();
    free(randomArr2);

    int *randomArr3 = generateRandomArray(SIZE);
    clock_t start_merge = clock();
    mergeSort(randomArr3, 0, 299999);
    clock_t end_merge = clock();
    free(randomArr3);

    int *randomArr4 = generateRandomArray(SIZE);
    clock_t start_bubble = clock();
    bubbleSort(randomArr4, 300000);
    clock_t end_bubble = clock();
    free(randomArr4);

    double elapsed_heap = double(end_heap - start_heap) / CLOCKS_PER_SEC;
    double elapsed_quick = double(end_quick - start_quick) / CLOCKS_PER_SEC;
    double elapsed_merge = double(end_merge - start_merge) / CLOCKS_PER_SEC;
    double elapsed_bubble = double(end_bubble - start_bubble) / CLOCKS_PER_SEC;


    printf("Wynik losowych liczb dla heapSort to %.5f sekund\n", elapsed_heap);
    printf("Wynik losowych liczb dla quickSort to %.5f sekund\n", elapsed_quick);
    printf("Wynik losowych liczb dla mergeSort to %.5f sekund\n", elapsed_merge);
    printf("Wynik losowych liczb dla bubbleSort to %.5f sekund\n\n", elapsed_bubble);

////////////////////////////////////////////////////////////////////////////////////////////

    int *sortedArr1;
    sortedArr1 = generateSortedArray(SIZE);
    start_heap = clock();
    heapSort(sortedArr1, 300000);
    end_heap = clock();
    free(sortedArr1);

    int *sortedArr2;
    sortedArr2 = generateSortedArray(SIZE);
    start_quick = clock();
    quickSort(sortedArr2, 0, 300000 - 1);
    end_quick = clock();
    free(sortedArr2);


    int *sortedArr3;
    sortedArr3 = generateSortedArray(SIZE);
    start_merge = clock();
    mergeSort(sortedArr3, 0, 300000 - 1);
    end_merge = clock();
    free(sortedArr3);


    int *sortedArr4;
    sortedArr4 = generateSortedArray(SIZE);
    start_bubble = clock();
    bubbleSort(sortedArr4, 300000);
    end_bubble = clock();
    free(sortedArr4);


    elapsed_heap = double(end_heap - start_heap) / CLOCKS_PER_SEC;
    elapsed_quick = double(end_quick - start_quick) / CLOCKS_PER_SEC;
    elapsed_merge = double(end_merge - start_merge) / CLOCKS_PER_SEC;
    elapsed_bubble = double(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    printf("Wynik posortowanych liczb dla heapSort to %.5f sekund\n", elapsed_heap);
    printf("Wynik posortowanych liczb dla quickSort to %.5f sekund\n", elapsed_quick);
    printf("Wynik posortowanych liczb dla mergeSort to %.5f sekund\n", elapsed_merge);
    printf("Wynik posortowanych liczb dla bubbleSort to %.5f sekund\n\n", elapsed_bubble);

//////////////////////////////////////////////////////////////////////////////////////////////

    int *reversedArr1;
    reversedArr1 = generateReverseSortedArray(SIZE);
    start_heap = clock();
    heapSort(reversedArr1, 300000);
    end_heap = clock();
    free(reversedArr1);

    int *reversedArr2;
    reversedArr2 = generateReverseSortedArray(SIZE);
    start_quick = clock();
    quickSort(reversedArr2, 0, 300000 - 1);
    end_quick = clock();
    free(reversedArr2);

    int *reversedArr3;
    reversedArr3 = generateReverseSortedArray(SIZE);
    start_merge = clock();
    mergeSort(reversedArr3, 0, 300000 - 1);
    end_merge = clock();
    free(reversedArr3);

    int *reversedArr4;
    reversedArr4 = generateReverseSortedArray(SIZE);
    start_bubble = clock();
    bubbleSort(reversedArr4, 300000);
    end_bubble = clock();
    free(reversedArr4);

    elapsed_heap = double(end_heap - start_heap) / CLOCKS_PER_SEC;
    elapsed_quick = double(end_quick - start_quick) / CLOCKS_PER_SEC;
    elapsed_merge = double(end_merge - start_merge) / CLOCKS_PER_SEC;
    elapsed_bubble = double(end_bubble - start_bubble) / CLOCKS_PER_SEC;

    printf("Wynik odwrotnie posortowanych liczb dla heapSort to %.5f sekund\n", elapsed_heap);
    printf("Wynik odwrotnie posortowanych liczb dla quickSort to %.5f sekund\n", elapsed_quick);
    printf("Wynik odwrotnie posortowanych liczb dla mergeSort to %.5f sekund\n", elapsed_merge);
    printf("Wynik odwrotnie posortowanych liczb dla bubbleSort to %.5f sekund\n\n", elapsed_bubble);
}

