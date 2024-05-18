#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    int maxsize;
    int front;
    int rear;
    vector<int> list;

public:
    MyCircularQueue(int n = 10) : maxsize(n), front(0), rear(0), list(n, 0) {}

    void initialize() {
        front = 0;
        rear = 0;
        list = vector<int>(maxsize, 0);
    }

    bool isEmpty() const {
        return front == rear;
    }

    bool isFull() const {
        return (rear + 1) % maxsize == front;
    }

    void enqueue(int elem) {
        if (!isFull()) {
            list[rear] = elem;
            rear = (rear + 1) % maxsize;
        } else {
            cout << "Queue is full!" << endl;
        }
    }

    void dequeue() {
        if (!isEmpty()) {
            front = (front + 1) % maxsize;
        } else {
            cout << "Queue is empty!" << endl;
        }
    }

    int Front() const {
        if (!isEmpty()) {
            return list[front];
        } else {
            throw runtime_error("Queue is empty!");
        }
    }

    int Rear() const {
        if (!isEmpty()) {
            return list[(rear - 1 + maxsize) % maxsize];
        } else {
            throw runtime_error("Queue is empty!");
        }
    }

    int size() const {
        return (rear - front + maxsize) % maxsize;
    }

    void printDetail() const {
        cout << "Size : " << size() << endl;
        cout << "Queue : ";
        if (isEmpty()) {
            cout << "[]" << endl;
        } else {
            for (int i = front; i != rear; i = (i + 1) % maxsize) {
                cout << "[" << list[i] << "]";
            }
            cout << endl;
        }
        cout << "index : ";
        for (int i = front; i != rear; i = (i + 1) % maxsize) {
            cout << i << " ";
        }
        cout << endl;
        cout << "front : " << front << ", rear : " << rear << endl;
    }

    void print() const {
        cout << "Queue : ";
        if (isEmpty()) {
            cout << "[]" << endl;
        } else {
            for (int i = front; i != rear; i = (i + 1) % maxsize) {
                cout << list[i] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    MyCircularQueue q(10);

    cout << "===== Dequeue x 1 =====" << endl;
    q.dequeue();
    q.printDetail();

    cout << "===== Enqueue x 7 (10 ~ 70) =====" << endl;
    for (int i = 10; i <= 70; i += 10) {
        q.enqueue(i);
    }
    q.printDetail();

    cout << "===== Dequeue x 3 =====" << endl;
    for (int i = 0; i < 3; ++i) {
        q.dequeue();
    }
    q.printDetail();

    cout << "===== Enqueue x 6 (10 ~ 60) =====" << endl;
    for (int i = 10; i <= 60; i += 10) {
        q.enqueue(i);
    }
    q.printDetail();

    return 0;
}
