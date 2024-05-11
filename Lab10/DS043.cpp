#include <iostream>
#include <string>
#include <stack>
using namespace std;

class MyLinkedStack {
private:
    struct Node {
        char data;
        Node* next;
        Node(char data) : data(data), next(nullptr) {}
    };
    Node* stacktop;
    int nodeCnt;

public:
    MyLinkedStack() : stacktop(nullptr), nodeCnt(0) {}
    ~MyLinkedStack() {
        while (!isEmpty()) pop();
    }

    bool isEmpty() const { return stacktop == nullptr; }
    void push(char data) {
        Node* newNode = new Node(data);
        newNode->next = stacktop;
        stacktop = newNode;
        nodeCnt++;
    }
    char pop() {
        if (isEmpty()) throw runtime_error("Stack underflow");
        char data = stacktop->data;
        Node* temp = stacktop;
        stacktop = stacktop->next;
        delete temp;
        nodeCnt--;
        return data;
    }
};

void processInput(const string& input) {
    MyLinkedStack leftStack, rightStack;
    
    for (size_t i = 0; i < input.length(); ++i) {
        char ch = input[i];
        if (ch == '<') {
            if (!leftStack.isEmpty()) {
                char moved = leftStack.pop();
                rightStack.push(moved);
            }
        } else if (ch == '>') {
            if (!rightStack.isEmpty()) {
                char moved = rightStack.pop();
                leftStack.push(moved);
            }
        } else {
            leftStack.push(ch);
        }
    }

    // 오른쪽 스택에서 왼쪽스텍으로 reverse
    while (!leftStack.isEmpty()) {
        rightStack.push(leftStack.pop());
    }


    string result;
    while (!rightStack.isEmpty()) {
        result += rightStack.pop();
    }

    cout << "=> " << result << endl;
}

int main() {
    string input;

    while (getline(cin, input)) {
        if (input == "q") break;
        processInput(input);
    }

 
    return 0;
}
