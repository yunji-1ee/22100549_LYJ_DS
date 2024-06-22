#include <iostream>

void merge(int* array, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = array[left + i];
    for (int j = 0; j < n2; ++j)
        R[j] = array[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        array[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

void mergeSort(int* array, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        merge(array, left, mid, right);
    }
}

int main() {
    int sizeA, sizeB;
    std::cin >> sizeA >> sizeB;

    int totalSize = sizeA + sizeB;
    int* scores = new int[totalSize];

    // A반 점수 입력
    for (int i = 0; i < sizeA; ++i) {
        std::cin >> scores[i];
    }

    // B반 점수 입력
    for (int i = 0; i < sizeB; ++i) {
        std::cin >> scores[sizeA + i];
    }

    // 점수 내림차순 정렬
    mergeSort(scores, 0, totalSize - 1);

    // 정렬된 점수 출력
    for (int i = 0; i < totalSize; ++i) {
        std::cout << scores[i] << " ";
    }
    std::cout << std::endl;

    delete[] scores;

    return 0;
}
