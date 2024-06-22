#include "MinHeap.h"

int main() {
    MinHeap heap;
    int choice;

    while (true) {
        std::cout << "1. Array to minHeap 2. insert 3. delete 4. print 0. quit > ";
        std::cin >> choice;

        if (choice == 1) {
            int N;
            std::cout << "Enter number of elements: ";
            std::cin >> N;

            std::cout << "Enter elements: ";
            for (int i = 0; i < N; ++i) {
                int value;
                std::cin >> value;
                heap.insertKey(value);
            }
            std::cout << "minHeap => ";
            heap.printHeap();
        }
        else if (choice == 2) {
            int value;
            std::cout << "new value? ";
            std::cin >> value;
            heap.insertKey(value);
            std::cout << "minHeap => ";
            heap.printHeap();
        }
        else if (choice == 3) {
            int minVal = heap.deleteKey();
            if (minVal != -1)
                std::cout << "min value: " << minVal << std::endl;
            std::cout << "minHeap => ";
            heap.printHeap();
        }
        else if (choice == 4) {
            heap.printHeap();
        }
        else {
            std::cout << "Bye!" << std::endl;
            break;
        }
    }

    return 0;
}
