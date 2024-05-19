#include <iostream>
using namespace std;

template <typename T>
class MyCircularQueue {
private:
    int maxsize;
    int front;
    int rear;
    T* list;
    int currentSize;

public:
    // 생성자
    MyCircularQueue(int size = 10) : maxsize(size), front(0), rear(0), currentSize(0) {
        list = new T[maxsize];
    }

    // 소멸자
    ~MyCircularQueue() {
        delete[] list;
    }

    // 큐 초기화
    void initialize() {
        front = 0;
        rear = 0;
        currentSize = 0;
    }

    // 큐가 비었는지 확인
    bool isEmpty() const {
        return currentSize == 0;
    }

    // 큐가 가득 찼는지 확인
    bool isFull() const {
        return currentSize == maxsize;
    }

    // 큐에 원소 추가
    void enqueue(const T& elem) {
        if (isFull()) {
            cout << "=> Queue is full!" << endl;
            return;
        }
        list[rear] = elem;
        rear = (rear + 1) % maxsize;
        currentSize++;
    }

    // 큐에서 원소 제거
    void dequeue() {
        if (isEmpty()) {
            cout << "=> Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % maxsize;
        currentSize--;
    }

    // 큐의 앞부분 원소 반환
    T Front() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return list[front];
    }

    // 큐의 뒷부분 원소 반환
    T Rear() const {
        if (isEmpty()) {
            throw runtime_error("Queue is empty");
        }
        return list[(rear - 1 + maxsize) % maxsize];
    }

    // 큐에 들어있는 원소 개수 반환
    int size() const {
        return currentSize;
    }

    // 큐의 상태를 상세히 출력
    void printDetail() const {
        cout << "Size : " << size() << endl;
        cout << "Queue : ";
        if (!isEmpty()) {
            for (int i = 0; i < size(); i++) {
                cout << "[" << list[(front + i) % maxsize] << "]";
            }
        }
        cout << endl;
        cout << "index : ";
        if (!isEmpty()) {
            for (int i = 0; i < size(); i++) {
                cout << (front + i) % maxsize + 1 << " ";
            }
        }
        cout << endl;
        cout << "front : " << front << ", rear : " << rear << endl;
    }
};

// 테스트 메인 함수
int main() {
    MyCircularQueue<int> queue(10);


    cout << "===== Dequeue x 1 =====" << endl;
    queue.dequeue();
    queue.printDetail();

    cout << "===== Enqueue x 7 (10~70) =====" << endl;
    for (int i = 10; i <= 70; i += 10) {
        queue.enqueue(i);
    }
    queue.printDetail();

    cout << "===== Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; i++) {
        queue.dequeue();
    }
    queue.printDetail();

    cout << "===== Enqueue x 6 (10~60) =====" << endl;
    for (int i = 10; i <= 60; i += 10) {
        queue.enqueue(i);
    }
    queue.printDetail();

    return 0;
}
