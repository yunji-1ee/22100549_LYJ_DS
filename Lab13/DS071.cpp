#include <iostream>

using namespace std;

// 중간 과정을 출력
void printDebug(int *arr, int n)
{
    cout << "[";
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i];
        if (i != n - 1)
        {
            cout << "] [";
        }
    }
    cout << "]" << endl;
}

// 정!렬!
void selectionSort(int *arr, int n)
{
#ifdef DEBUG
    printDebug(arr, n);
#endif
    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);
#ifdef DEBUG
        printDebug(arr, n);
#endif
    }
}

int main()
{
    int n;
    cin >> n;              // 배열 크기 입력
    int *arr = new int[n]; // 동적 배열 할당

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i]; // 배열의 원소 입력
    }

    // 선택 정렬 수행
    selectionSort(arr, n);

    // 동적 배열 해제
    delete[] arr;

    return 0;
}
