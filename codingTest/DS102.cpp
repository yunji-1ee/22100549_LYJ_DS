#include <iostream>
#include "sort.h" // sort 라이브러리 포함

using namespace std;

int main() {
    int N, K; // N: 카드의 개수, K: 최대 교환 횟수
    cin >> N >> K;

    int* A = new int[N]; // A 덱
    int* B = new int[N]; // B 덱

    // A 덱 입력 받기
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }

    // B 덱 입력 받기
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }

    // A 덱 오름차순 정렬
    quickSort(A, 0, N - 1);
    // B 덱 내림차순 정렬
    quickSortDesc(B, 0, N - 1);

    // 최대 K번 교환
    for (int i = 0; i < K && i < N; ++i) {
        if (A[i] < B[i]) {
            swap(A[i], B[i]);
        } else {
            break;
        }
    }

    // A 덱의 합 계산
    int sumA = 0;
    for (int i = 0; i < N; ++i) {
        sumA += A[i];
    }

    // 결과 출력
    cout << K << " " << sumA << endl;

    delete[] A; // 동적 배열 메모리 해제
    delete[] B; // 동적 배열 메모리 해제

    return 0;
}
