#ifndef MINHEAP_H
#define MINHEAP_H

class MinHeap {
private:
    int arr[30];
    int length;

    void minHeapifyUp(int index);
    void minHeapifyDown(int root = 0);

public:
    MinHeap();
    ~MinHeap();

    void insertKey(int value);
    int deleteKey();
    int peek() const;
    int size() const;
    bool isEmpty() const;
    void printHeap() const;
};

#endif
