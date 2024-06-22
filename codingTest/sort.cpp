#include "sort.h"

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void quickSort(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && arr[i] < pivot) ++i;
        while (j > left && arr[j] > pivot) --j;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);

    quickSort(arr, left, j - 1);
    quickSort(arr, j + 1, right);
}

void quickSortDesc(int arr[], int left, int right) {
    if (left >= right) return;

    int pivot = arr[left];
    int i = left + 1;
    int j = right;

    while (i <= j) {
        while (i <= right && arr[i] > pivot) ++i;
        while (j > left && arr[j] < pivot) --j;

        if (i < j) {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[left], arr[j]);

    quickSortDesc(arr, left, j - 1);
    quickSortDesc(arr, j + 1, right);
}
