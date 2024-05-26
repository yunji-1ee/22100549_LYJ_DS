// Queue.cpp

#include "Queue.h"
#include <iostream>
using namespace std;

Queue::Queue() {
    front = nullptr;
    rear = nullptr;
}

Queue::~Queue() {
    while (!isempty()) {
        dequeue();
    }
}

bool Queue::isempty() {
    return front == nullptr && rear == nullptr;
}

void Queue::enqueue(int value) {
    Node* ptr = new Node();
    ptr->data = value;
    ptr->link = nullptr;

    if (front == nullptr) {
        front = ptr;
        rear = ptr;
    } else {
        rear->link = ptr;
        rear = ptr;
    }
}

void Queue::dequeue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else if (front == rear) {
        delete front;
        front = rear = nullptr;
    } else {
        Node* ptr = front;
        front = front->link;
        delete ptr;
    }
}

void Queue::showfront() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "element at front: " << front->data << "\n";
    }
}

void Queue::showrear() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        cout << "element at rear: " << rear->data << "\n";
    }
}

int Queue::getFront() {
    if (!isempty()) {
        return front->data;
    } else{
        return -1; //예외처리 대신 (큐가 비어있음을 가리킴)
    }
}

int Queue::getRear() {
    if (!isempty()) {
        return rear->data;
    } else {
        return -1;
    }
}

void Queue::displayQueue() {
    if (isempty()) {
        cout << "Queue is empty\n";
    } else {
        Node* ptr = front;
        while (ptr != nullptr) {
            cout << ptr->data;
            ptr = ptr->link;

            if (ptr != nullptr) {
                cout << " → ";
            }
        }
        cout << endl;
    }
}
