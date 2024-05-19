#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class Student {
public:
    float gpa;
    string name;

    Student() : gpa(0.0), name("") {}
    Student(float g, const string& n) : gpa(g), name(n) {}
};

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
            return T();
        }
        return list[front];
    }

    int size() const {
        return currentSize;
    }
};

void analyzeGPA(const string& filename) {
    ifstream infile(filename);
    if (!infile) {
        cerr << "Unable to open file " << filename << endl;
        return;
    }

    string line;
    MyCircularQueue<Student> queue(20); // 20명 정도를 수용할 크기의 큐 생성

    while (getline(infile, line)) {
        istringstream iss(line);
        float gpa;
        string name;
        iss >> gpa >> ws;
        getline(iss, name);
        queue.enqueue(Student(gpa, name));
    }

    float highestGPA = -1.0;
    string topStudents[20]; // 최대 20명의 학생을 수용할 수 있는 배열
    int topCount = 0;
    int n = queue.size();

    for (int i = 0; i < n; i++) {
        Student current = queue.Front();
        queue.dequeue();
        if (current.gpa > highestGPA) {
            highestGPA = current.gpa;
            topCount = 0;
            topStudents[topCount++] = current.name;
        } else if (current.gpa == highestGPA) {
            topStudents[topCount++] = current.name;
        }
    }

    cout << "Highest GPA = " << highestGPA << endl;
    for (int i = 0; i < topCount; i++) {
        cout << topStudents[i] << " " << highestGPA << endl;
    }
}

int main() {
    analyzeGPA("data1.txt");
    return 0;
}
