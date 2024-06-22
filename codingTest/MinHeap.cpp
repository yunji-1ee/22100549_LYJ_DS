#include "MinHeap.h"
#include <iostream>
#include <stdexcept>

MinHeap::MinHeap() : length(0) {}

MinHeap::~MinHeap() {}

void MinHeap::insertKey(int value) {
    if (length >= 30) {
        throw std::overflow_error("Heap overflow");
    }
    arr[length] = value;
    minHeapifyUp(length);
    length++;
}

int MinHeap::deleteKey() {
    if (isEmpty()) {
        throw std::underflow_error("Heap underflow");
    }
    int rootValue = arr[0];
    arr[0] = arr[length - 1];
    length--;
    minHeapifyDown();
    return rootValue;
}

int MinHeap::peek() const {
    if (isEmpty()) {
        throw std::underflow_error("Heap underflow");
    }
    return arr[0];
}

int MinHeap::size() const {
    return length;
}

bool MinHeap::isEmpty() const {
    return length == 0;
}

void MinHeap::minHeapifyUp(int index) {
    while (index > 0 && arr[index] < arr[(index - 1) / 2]) {
        std::swap(arr[index], arr[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void MinHeap::minHeapifyDown(int root) {
    int smallest = root;
    int leftChild = 2 * root + 1;
    int rightChild = 2 * root + 2;

    if (leftChild < length && arr[leftChild] < arr[smallest]) {
        smallest = leftChild;
    }
    if (rightChild < length && arr[rightChild] < arr[smallest]) {
        smallest = rightChild;
    }
    if (smallest != root) {
        std::swap(arr[root], arr[smallest]);
        minHeapifyDown(smallest);
    }
}

void MinHeap::printHeap() const {
    for (int i = 0; i < length; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
