#include <iostream>

using namespace std;


void printDebug(int* arr, int n) {
    cout << "[";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
        if (i != n - 1) {
            cout << "] [";
        }
    }
    cout << "]" << endl;
}

// Quick Sort의 분할 함수
int partition(int* arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (arr[j] < pivot) {
            ++i;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[right]);

    return i + 1;
}

// Quick Sort
void quickSort(int* arr, int left, int right, int n) {
    if (left < right) {
        int pi = partition(arr, left, right);

#ifdef DEBUG
        printDebug(arr, n);
#endif

        quickSort(arr, left, pi - 1, n);
        quickSort(arr, pi + 1, right, n);
    }
}

int main() {
    int n;
    cin >> n;
    int* arr = new int[n]; 

    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

#ifdef DEBUG
    printDebug(arr, n); 
#endif

    // Quick Sort 수행
    quickSort(arr, 0, n - 1, n);

#ifndef DEBUG
    cout << "Sorted array: ";
    printDebug(arr, n); 
#endif

    // 동적 배열 해제
    delete[] arr;

    return 0;
}
