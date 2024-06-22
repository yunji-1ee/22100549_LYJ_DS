#include <iostream>
#include "sort.h" 
using namespace std;

int main() {
    int N, K; // N: 응시자 수, K: 수상자 수
    cin >> N >> K;

    int* scores = new int[N]; 
    // 점수 입력 받기
    for (int i = 0; i < N; ++i) {
        cin >> scores[i];
    }

    // 내림차순 정렬
    quickSortDesc(scores, 0, N - 1);

    // K번째 점수 출력 (상위 K명 중 최소 점수)
    cout << scores[K - 1] << endl;

    delete[] scores; // 동적 배열 메모리 해제

    return 0;
}
