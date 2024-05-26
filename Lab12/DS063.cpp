#include <iostream>
#include "Queue.h"

using namespace std;

// 라운드 결과를 출력하는 함수
void printRoundResult(int round, const string& result) {
    cout << "Round " << round << " - " << result << "\n";
}

int main() {
    int n;
    cin >> n;

    Queue player1, player2;  // 두 플레이어의 큐 생성
    int card;

    for (int i = 0; i < n; ++i) {
        cin >> card;
        player1.enqueue(card);  // 첫 번째 플레이어의 카드 순서 입력받고 큐에 추가
    }


    for (int i = 0; i < n; ++i) {
        cin >> card;
        player2.enqueue(card);  // 두 번째 플레이어의 카드 순서 입력받아고 큐에 추가
    }

    int score1 = 0, score2 = 0;  // 두 플레이어의 점수 초기화
    int p1_previous_diff = 0, p2_previous_diff = 0;  // 이전 라운드의 점수 차이 저장할 변수 초기화

    for (int round = 1; round <= n; ++round) {

        int p1_current = player1.getFront();  // 첫 번째 플레이어의 현재 카드 가져오기
        player1.dequeue();  // 첫 번째 플레이어의 현재 카드 큐에서 제거

        int p2_current = player2.getFront();  // 두 번째 플레이어의 현재 카드 가져오기
        player2.dequeue();  // 두 번째 플레이어의 현재 카드 큐에서 제거

        // 첫 라운드일 경우 대결 숫자는 현재 카드 값, 이후 라운드일 경우 대결 숫자 계산
        if (round > 1) {
            p1_current += p1_previous_diff;
            p2_current += p2_previous_diff;
        }

       // cout << p1_current << " : " << p2_current;  // 현재 카드 값 출력

        // 대결 결과에 따라 점수와 결과 출력
        if (p1_current > p2_current) {
            score1++;
            p1_previous_diff = (p1_current - p2_current) - 1;
            p2_previous_diff = 0;
            printRoundResult(round, "P1 win!");

        } else if (p1_current < p2_current) {
            score2++;
            p2_previous_diff = (p2_current - p1_current) - 1;
            p1_previous_diff = 0;
            printRoundResult(round, "P2 win!");

        } else {
            p1_previous_diff = 0;
            p2_previous_diff = 0;
            printRoundResult(round, "Draw!");
        }
    }

    // 최종 승자 결정 및 출력
    if (score1 > score2) {
        cout << "Final - P1 win!\n";

    } else if (score1 < score2) {
        cout << "Final - P2 win!\n";

    } else {
        cout << "Final - Draw!\n";
    }

    return 0;
}
