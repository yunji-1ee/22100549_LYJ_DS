#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <cctype>
using namespace std;

class MyLinkedStack {
private:
    struct Node {
        int data;
        Node* next;
        Node(int data) : data(data), next(nullptr) {}
    };
    Node* stacktop;
    int nodeCnt;

public:
    MyLinkedStack() : stacktop(nullptr), nodeCnt(0) {}
    ~MyLinkedStack() {
        while (!isEmpty()) pop();
    }

    bool isEmpty() const { return stacktop == NULL; }
    void push(int data) {
        Node* newNode = new Node(data);
        newNode->next = stacktop;
        stacktop = newNode;
        nodeCnt++;
    }
    int pop() {
        int data = stacktop->data;
        Node* temp = stacktop;
        stacktop = stacktop->next;
        delete temp;
        nodeCnt--;
        return data;
    }

    int getNodeCnt() const { return nodeCnt; }
};

int evaluateExpression(const string& expression) {
    MyLinkedStack stack;
    stringstream ss(expression);
    string token;
    int result = 0;

    while (ss >> token) {
        if (token == "=") {
            if (stack.getNodeCnt() == 1) {
                result = stack.pop();
                return result;  
            } else {
                cout << " => Too many operands !!!" << endl;
                return -1;
            }


        } else if (token[0] == '#' && isdigit(token[1])) {
            stack.push(stoi(token.substr(1)));

        } else if (token == "+" || token == "-" || token == "*" || token == "/")
         {//연산식
            if (stack.getNodeCnt() < 2) {
                return -1;
            }
            int right = stack.pop();
            int left = stack.pop();
            switch (token[0]) {
                case '+': stack.push(left + right); break;
                case '-': stack.push(left - right); break;
                case '*': stack.push(left * right); break;
                case '/':
                    if (right == 0) {
                        cout << " => Division by 0 !!!" << endl;
                        return -1;
                    }
                    stack.push(left / right);
                    break;
                default:
                    cout << " => Expression error !!!" << endl;
                    return -1;
            }
        }
    }

    cout << "=> Expression error !!!" << endl;
    return -1;
}

int main() {
    string expression;
    getline(cin, expression);
    int result = evaluateExpression(expression);
    if (result != -1) {
        cout << expression << " " << result << endl;
    }
    return 0;
}
