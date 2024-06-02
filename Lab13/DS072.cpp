#include <iostream>

using namespace std;

// 중간 과정을 출력하기 위한 함수
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

// 삽입 정렬 함수
void insertionSort(int* arr, int n) {
#ifdef DEBUG
    printDebug(arr, n);
#endif
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        // key를 알맞은 위치에 삽입하기 위해 배열의 원소를 이동
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
#ifdef DEBUG
        printDebug(arr, n);
#endif
    }
}

int main() {
    int n;
    cin >> n; // 배열의 크기 입력
    int* arr = new int[n]; // 동적 배열 할당

    for (int i = 0; i < n; ++i) {
        cin >> arr[i]; // 배열의 원소 입력
    }

    // 삽입 정렬 
    insertionSort(arr, n);

    delete[] arr;

    return 0;
}
