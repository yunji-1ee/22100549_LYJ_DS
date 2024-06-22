#ifndef MINHEAP_H
#define MINHEAP_H

#include <iostream>

class MinHeap {
private:
    int arr[30];   // 힙을 저장할 배열
    int length;    // 현재 노드의 수

public:
    MinHeap() : length(0) {}

    ~MinHeap() {}

    void insertKey(int value) {
        if (length == 30) {
            std::cout << "\nOverflow: Could not insertKey\n";
            return;
        }
        int i = length;
        arr[i] = value;
        length++;

        while (i != 0 && arr[(i - 1) / 2] > arr[i]) {
            std::swap(arr[i], arr[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    int deleteKey() {
        if (length <= 0) {
            std::cout << "\nCould not deleteKey\n";
            return -1;
        }
        int root = arr[0];
        arr[0] = arr[length - 1];
        length--;
        minHeapifyDown(0);
        return root;
    }

    int peek() const {
        if (length <= 0) {
            std::cout << "\nHeap is empty\n";
            return -1;
        }
        return arr[0];
    }

    int size() const {
        return length;
    }

    bool isEmpty() const {
        return length == 0;
    }

    void minHeapifyUp(int index) {
        while (index != 0 && arr[(index - 1) / 2] > arr[index]) {
            std::swap(arr[index], arr[(index - 1) / 2]);
            index = (index - 1) / 2;
        }
    }

    void minHeapifyDown(int root = 0) {
        int smallest = root;
        int left = 2 * root + 1;
        int right = 2 * root + 2;

        if (left < length && arr[left] < arr[smallest])
            smallest = left;
        if (right < length && arr[right] < arr[smallest])
            smallest = right;
        if (smallest != root) {
            std::swap(arr[root], arr[smallest]);
            minHeapifyDown(smallest);
        }
    }

    void printHeap() const {
        for (int i = 0; i < length; ++i)
            std::cout << arr[i] << " ";
        std::cout << std::endl;
    }
};

#endif
