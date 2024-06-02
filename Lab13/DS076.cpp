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

// Selection Sort
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
        printDebug(arr, n);
    }
}

// Insertion Sort
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
        printDebug(arr, n);
    }
}

// Bubble Sort
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        printDebug(arr, n);
    }
}

// Quick Sort
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

void quickSort(int* arr, int left, int right, int n) {
    if (left < right) {
        int pi = partition(arr, left, right);
        printDebug(arr, n);
        quickSort(arr, left, pi - 1, n);
        quickSort(arr, pi + 1, right, n);
    }
}

// Merge Sort
void merge(int* arr, int left, int mid, int right, int n) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
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

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
    printDebug(arr, n);
}

void mergeSort(int* arr, int left, int right, int n) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid, n);
        mergeSort(arr, mid + 1, right, n);
        merge(arr, left, mid, right, n);
    }
}

int main() {
    int choice;
    while (true) {
        cout << "1.selection 2.insertion 3.bubble 4.quick 5.merge 6.exit > ";
        cin >> choice;
        if (choice == 6) {
            cout << "bye!" << endl;
            break;
        }

        int n;
        cout << "Enter count: ";
        cin >> n;
        int* arr = new int[n];
        cout << "Enter numbers: ";
        for (int i = 0; i < n; ++i) {
            cin >> arr[i];
        }

        switch (choice) {
            case 1:
                cout << "==== selection sort ====" << endl;
                printDebug(arr, n);
                selectionSort(arr, n);
                break;
            case 2:
                cout << "==== insertion sort ====" << endl;
                printDebug(arr, n);
                insertionSort(arr, n);
                break;
            case 3:
                cout << "==== bubble sort ====" << endl;
                printDebug(arr, n);
                bubbleSort(arr, n);
                break;
            case 4:
                cout << "==== quick sort ====" << endl;
                printDebug(arr, n);
                quickSort(arr, 0, n - 1, n);
                break;
            case 5:
                cout << "==== merge sort ====" << endl;
                printDebug(arr, n);
                mergeSort(arr, 0, n - 1, n);
                break;
            default:
                break;
        }

        delete[] arr;
    }

    return 0;
}
