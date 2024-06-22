#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList list;
    int N; // 수열의 개수
    std::cin >> N;

    for (int i = 0; i < N; ++i) {
        int score;
        std::string name;
        std::cin >> score;
        std::cin.ignore(); // 공백 문자 무시
        std::getline(std::cin, name);
        list.addLast(score, name);
    }

    // 버블 정렬을 사용하여 내림차순 정렬
    list.bubbleSort();

    // 정렬된 결과 출력
    list.print();

    return 0;
}
