#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) : data(data), next(nullptr) {}
};

class MyLinkedStack {
private:
    Node* stacktop;
    int nodeCnt;

public:
    MyLinkedStack() : stacktop(nullptr), nodeCnt(0) {}

    ~MyLinkedStack() {
        initialize();
    }

    void initialize() {
        while (!isEmpty()) {
            pop();
        }
    }

    bool isEmpty() const {
        return stacktop == nullptr;
    }

    void push(const int& data) {
        Node* newNode = new Node(data);
        newNode->next = stacktop;
        stacktop = newNode;
        nodeCnt++;
    }

    void pop() {
        if (!isEmpty()) {
            Node* temp = stacktop;
            stacktop = stacktop->next;
            delete temp;
            nodeCnt--;
        }
    }

    int peek() const {
        if (!isEmpty()) {
            return stacktop->data;
        } else {
            cout << "Stack is empty" << endl;
            return -1; 
        }
    }

    int getNodeCnt() const {
        return nodeCnt;
    }

    void printAll() const {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            Node* current = stacktop;
            while (current != nullptr) {
                cout << current->data;
                if (current->next != nullptr) {
                    cout << " -> ";
                }
                current = current->next;
            }
            cout << " (" << nodeCnt << " nodes)" << endl;
        }
    }
};

int main() {
    MyLinkedStack stack;
    string command;
    int number;

    while (cin >> command) {
        if (command == "push") {
            cin >> number;
            stack.push(number);
        } else if (command == "pop") {
            stack.pop();
        } else if (command == "peek") {
            int topData = stack.peek();
            if (topData != -1) {
                cout << topData << endl;
            }
        } else if (command == "print") {
            stack.printAll();
        } else if (command == "clear") {
            stack.initialize();
        } else if (command == "q") {
            cout << "Bye!" << endl;
            break;
        } else {
            cout << "Invalid command!" << endl;
        }
    }

    return 0;
}
