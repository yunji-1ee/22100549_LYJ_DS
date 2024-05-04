#include <iostream>
#include <string>
using namespace std;

struct Elem {
    int value;
};

class MyStack {
private:
    int maxsize;
    int top;
    Elem *list;

public:
    void init();
    bool isEmpty() const;
    bool isFull() const;
    void push(int v);
    Elem *pop();
    MyStack(int size = 10);
    ~MyStack() { delete[] list; };
    void print();
};

MyStack::MyStack(int size) {
    maxsize = size;
    list = new Elem[size];
    init();
}

void MyStack::init() {
    top = 0;
}

bool MyStack::isEmpty() const {
    return top == 0;
}

bool MyStack::isFull() const {
    return top == maxsize;
}

void MyStack::push(int v) {
    if (!isFull()) {
        list[top].value = v;
        top++;
    } 
}

void MyStack::print() {
    for (int i = 0; i < top; i++) {
        cout << list[i].value << endl;
    }
}

Elem *MyStack::pop() {
    if (!isEmpty()) {
        top--;
        return &list[top];
    } 
}

int main() {
    int stackSize;
    cin >> stackSize;
    MyStack stack(stackSize);

    string command;
    int number;

    while (true) {
        cin >> command;
        if (command == "push") {
            cin >> number;
            stack.push(number);
        } else if (command == "pop") {
            Elem* e = stack.pop();
    
        } else if (command == "print") {
            stack.print();
        } 
    }

    return 0;
}
