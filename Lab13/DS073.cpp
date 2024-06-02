#include <iostream>
using namespace std;

//버블 정렬 함수



//중간 과정 출력
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

// 오름차순
void bubbleSortAscending(int* arr, int n) {
#ifdef DEBUG
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        printDebug(arr, n);
    }
#else
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
#endif
}

// 내림차순
void bubbleSortDescending(int* arr, int n) {
#ifdef DEBUG
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
        printDebug(arr, n);
    }
#else
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
#endif
}

int main() {
    int n;
    cin >> n; 
    int* arr = new int[n]; 
    int* arrCopy = new int[n]; // 원본 배열 저장

    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
        arrCopy[i] = arr[i]; 
    }

    cout << "=== ascending order ===" << endl;
#ifdef DEBUG
    printDebug(arr, n); 
#endif
    // 오름차순 정렬 및 출력
    bubbleSortAscending(arr, n);

    cout << "=== descending order ===" << endl;
#ifdef DEBUG
    printDebug(arrCopy, n); // 초기 배열 상태 출력
#endif
    // 내림차순 정렬 및 출력
    bubbleSortDescending(arrCopy, n);

    // 동적 배열 해제
    delete[] arr;
    delete[] arrCopy;

    return 0;
}
