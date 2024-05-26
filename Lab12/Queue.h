// Queue.h

#ifndef QUEUE_H
#define QUEUE_H

class Queue {
private:
    struct Node {
        int data;
        Node* link;
    };

    Node* front;
    Node* rear;

public:
    Queue();            // 생성자
    ~Queue();           // 소멸자
    bool isempty();     // 큐가 비어 있는지 확인하는 함수
    void enqueue(int value);  // 큐에 요소를 추가하는 함수
    void dequeue();     // 큐에서 요소를 제거하는 함수
    void showfront();   // 큐의 앞에 있는 요소를 보여주는 함수
    void showrear();    // 큐의 뒤에 있는 요소를 보여주는 함수
    int getFront();     // 큐의 앞에 있는 요소를 반환하는 
    int getRear();      // 큐의 뒤에 있는 요소를 반환하는 함수
    void displayQueue(); // 큐의 모든 요소를 보여주는 함수
};

#endif // QUEUE_H
