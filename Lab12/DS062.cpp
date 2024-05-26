#include <iostream>
#include "Queue.h"

//약 20분 소요
using namespace std;

int fibonacci(int n) {
    if (n <= 0) return 0; // 유효하지 않은 입력에 대한 처리
    if (n == 1 || n == 2) return 1;

    Queue q;
    q.enqueue(1);
    q.enqueue(1);

    for (int i = 3; i <= n; ++i) {
        int first = q.getFront();
        q.dequeue();
        int second = q.getFront();
        int next = first + second;
        q.enqueue(next);
    }

    return q.getRear();
}

void printOrdinal(int n) {
    switch (n) {
        case 1: cout << "1st: "; break;
        case 2: cout << "2nd: "; break;
        case 3: cout << "3rd: "; break;
        default: cout << n << "th: "; break;
    }
}

int main() {
    int n;
    cout << "";
    cin >> n;

    if (n < 1 || n > 20) {
        return 1;
    }

    Queue q;
    q.enqueue(1);
    q.enqueue(1);


    if (n >= 1) {
        printOrdinal(1);
        cout << "1\n";
    }
    if (n >= 2) {
        printOrdinal(2);
        cout << "1\n";
    }

    for (int i = 3; i <= n; ++i) {
        int first = q.getFront();
        q.dequeue();
        int second = q.getFront();
        int next = first + second;
        q.enqueue(next);

        printOrdinal(i);
        cout << next << "\n";
    }

    cout << "=> fibonacci(" << n << ") : " << q.getRear() << "\n";

    return 0;
}
