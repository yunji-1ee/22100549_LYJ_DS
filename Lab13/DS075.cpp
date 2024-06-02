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

// 병합 함수
void merge(int* arr, int left, int mid, int right, int n) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // 임시 배열
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; ++i)
        R[i] = arr[mid + 1 + i];

    // 병합 
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

    // 남은 데이터 복사
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

#ifdef DEBUG
    printDebug(arr, n);
#endif
}

// Merge Sort 함수
void mergeSort(int* arr, int left, int right, int n) {
    if (left >= right) return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid, n);
    mergeSort(arr, mid + 1, right, n);
    merge(arr, left, mid, right, n);
}

int main() {
    int n;
    cin >> n; 
    int* arr = new int[n]; // 동적 배열 할당

    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; 
    }

#ifdef DEBUG
    printDebug(arr, n); 
#endif
    mergeSort(arr, 0, n - 1, n);

#ifndef DEBUG
    printDebug(arr, n); // 정렬 결과 출력
#endif
    // 동적 배열 해제
    delete[] arr;

    return 0;
}
