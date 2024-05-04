#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class MyStack {
private:
    string* list;
    int maxsize;
    int top;

public:
    MyStack(int size = 100) {  
        maxsize = size;
        list = new string[maxsize];
        top = 0;
    }

    ~MyStack() {
        delete[] list;
    }

    void clear() {
        top = 0;  
    }

    void push(const string& name) {
        if (top < maxsize) {
            list[top++] = name;
        }
    }

    void print() {
        for (int i = 0; i < top; i++) {
            cout << list[i]  << "\n";
        }
        cout << "\n";  
    }
};

int main() {
    MyStack stack;
    ifstream inFile("data.txt"); 
    string line;
    float maxGPA = 0.0;
    float gpa;
    string name;

    while (getline(inFile, line)) {
        istringstream iss(line);
        iss >> gpa >> ws;
        getline(iss, name);
        
        if (gpa > maxGPA) {
            maxGPA = gpa;
            stack.clear();
            stack.push(name);
        } else if (gpa == maxGPA) {
            stack.push(name);
        }
    }

    inFile.close();

    cout << "Top GPA: " << maxGPA << "\n"; 
    stack.print();

    return 0;
}
