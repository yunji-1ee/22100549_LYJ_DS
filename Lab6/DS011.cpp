#include <iostream>


void calculateSumAndMax(int* array, int size, int& totalSum, int& maxValue) {
    totalSum = 0;  
    maxValue = array[0]; 

    for (int i = 0; i < size; i++) {
        totalSum += array[i];  
        if (array[i] > maxValue) {  // 현재 요소가 최대값보다 크면 
            maxValue = array[i]; //최대값으로
        }
    }
}

int main() {
    int n;  // 입력받을 숫자의 개수
    std::cin >> n;  // 숫자 개수 입력

    int* numbers = new int[n];  // 동적 배열

    for (int i = 0; i < n; i++) {
        std::cin >> numbers[i];  // 숫자 입력
    }

    int totalSum = 0; 
    int maxValue = 0;  

  
    calculateSumAndMax(numbers, n, totalSum, maxValue);

    std::cout << totalSum << " "<< maxValue << std::endl;

    delete[] numbers;  // 동적 배열 메모리 해제
    return 0;
}
