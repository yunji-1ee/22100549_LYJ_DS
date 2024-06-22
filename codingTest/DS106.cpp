#include <iostream>
#include "MinHeap.h"

int main() {
    MinHeap heap;
    int command, value;

    std::cout << "1. Array to minHeap 2. insert 3. delete 4. print 0. quit > ";
    while (std::cin >> command && command != 0) {
        switch (command) {
            case 1: {
                int n;
                std::cin >> n;
                for (int i = 0; i < n; i++) {
                    std::cin >> value;
                    heap.insertKey(value);
                }
                std::cout << "minHeap => ";
                heap.printHeap();
                break;
            }
            case 2:
                std::cin >> value;
                heap.insertKey(value);
                std::cout << "minHeap => ";
                heap.printHeap();
                break;
            case 3:
                std::cout << "min value: " << heap.deleteKey() << std::endl;
                std::cout << "minHeap => ";
                heap.printHeap();
                break;
            case 4:
                std::cout << "minHeap => ";
                heap.printHeap();
                break;
            default:
                std::cout << "Invalid command" << std::endl;
        }
        std::cout << "1. Array to minHeap 2. insert 3. delete 4. print 0. quit > ";
    }
    std::cout << "bye!" << std::endl;
    return 0;
}
