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
    MyCircularQueue(int size = 10) : maxsize(size), front(0), rear(0), currentSize(0) {
        list = new T[maxsize];
    }

    ~MyCircularQueue() {
        delete[] list;
    }

    void initialize() {
        front = 0;
        rear = 0;
        currentSize = 0;
    }

    bool isEmpty() const {
        return currentSize == 0;
    }

    bool isFull() const {
        return currentSize == maxsize;
    }

    void enqueue(const T& elem) {
        if (isFull()) {
            cout << "=> Queue is full!" << endl;
            return;
        }
        list[rear] = elem;
        rear = (rear + 1) % maxsize;
        currentSize++;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "=> Queue is empty!" << endl;
            return;
        }
        front = (front + 1) % maxsize;
        currentSize--;
    }

    T Front() const {
        if (isEmpty()) {
            return -1;
        }
        return list[front];
    }

    T Rear() const {
        if (isEmpty()) {
            return -1;
        }
        return list[(rear - 1 + maxsize) % maxsize];
    }

    int size() const {
        return currentSize;
    }

    void printDetail() const {
        if (isEmpty()) {
            return;
        }
        for (int i = 0; i < size(); i++) {
            cout << list[(front + i) % maxsize];
            if (i < size() - 1) cout << " => ";
        }
        cout << endl;
    }
};

void processCommands(MyCircularQueue<int>& queue) {
    string command;
    while (true) {
        cin >> command;
        if (command == "en") {
            int value;
            cin >> value;
            queue.enqueue(value);
        } else if (command == "de") {
            queue.dequeue();
        } else if (command == "front") {
            cout << "=> " << queue.Front() << endl;
        } else if (command == "rear") {
            cout << "=> " << queue.Rear() << endl;
        } else if (command == "size") {
            cout << "=> " << queue.size() << endl;
        } else if (command == "empty") {
            cout << "=> " << queue.isEmpty() << endl;
        } else if (command == "print") {
            queue.printDetail();
        } else if (command == "q") {
            break;
        } else {
            cout << "Invalid command" << endl;
        }
    }
}

int main() {
    int queueSize;
    cin >> queueSize;
    MyCircularQueue<int> queue(queueSize);

    processCommands(queue);

    return 0;
}
