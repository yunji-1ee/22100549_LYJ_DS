#include <iostream>
#include <queue>

int findLastCard(int N) {
    std::queue<int> q;

    // 1부터 N까지의 카드를 큐에 삽입
    for (int i = 1; i <= N; ++i) {
        q.push(i);
    }

    // 카드를 버리고 아래로 넣는 작업 반복
    while (q.size() > 1) {
        q.pop(); // 맨 위의 카드를 버림
        int top = q.front(); // 그 다음 카드를 꺼내서
        q.pop();
        q.push(top); // 큐의 맨 아래로 넣음
    }

    return q.front(); // 마지막에 남은 카드 반환
}

int main() {
    int N;
    std::cin >> N;

    int lastCard = findLastCard(N);
    std::cout << lastCard << std::endl;

    return 0;
}
