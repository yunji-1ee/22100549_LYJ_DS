#include <iostream>
using namespace std;

class MyCircularQueue
{

private:
    int maxsize;
    int front;
    int rear;
    MyCircularQueue *list;

public:
    MyCircularQueue(int n = 10) : maxsize(n), front(0), rear(0), list(n, 0)
    {
    } // MyCircularQueue

    void initialize()
    {
        front = 0;
        rear = 0;
        int *list = new int[length];
    } // initialize

    bool isFull() const
    { // 큐가 꽉 차있는가
        return (rear + 1) % maxsize == front;
    }

    bool isEmpty() const
    { // 큐가 비어있는가
        return front == rear;
    }

    void enqueue(const int elem &)
    {
        if (!isFull())
        { // 큐가 꽉 차있지 않다면
            list[rear] = elem;
            rear = (rear + 1) % maxsize;
        }
    }
    void dequeue()
    {
        if (!isEmpty())
        { // 큐가 비어있다면
            front = (front + 1) % maxsize;
        }
    }

    int front() const
    {
    }

    int rear() const
    {
        if (!isEmpty)
            [return rear = //
            ]
    }



    int main()
    {
        MyCircularQueue[10];

        
        cout << "====Dequeue x 1 ====" << endl;
        cout << ""
    }
}; // class