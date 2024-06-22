#include <iostream>
#include "sort.h" // sort 라이브러리 포함

using namespace std;

int main() {
    int N; // 수열의 개수
    cin >> N; // 첫 번째 줄에서 N 입력 받음

    int* numbers = new int[N]; // 수열을 저장할 동적 배열 생성

    // 수열 입력 받기
    for (int i = 0; i < N; ++i) {
        cin >> numbers[i];
    }

    // 내림차순 정렬
    quickSort(numbers, 0, N - 1);

    // 정렬된 수열 출력
    for (int i = 0; i < N; ++i) {
        cout << numbers[i];
        if (i < N - 1) {
            cout << " ";
        }
    }

    delete[] numbers; // 동적 배열 메모리 해제

    return 0;
}
