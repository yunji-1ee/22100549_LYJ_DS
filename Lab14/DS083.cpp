#include <iostream>
using namespace std;

int size = 0;

void printArray(int* arr, int size)
{
    cout << "==> Heap : ";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}

void insertKey(int arr[], int N, int value)
{
    if (size == N)
    {
        cout << "\nOverflow: Could not insertKey\n";
        return;
    }

    // 새로운 값을 힙의 끝에 추가
    int i = size;
    arr[i] = value;
    size++;

    // 힙 속성을 만족하도록 상향 조정
    while (i != 0 && arr[(i - 1) / 2] < arr[i])
    {
        swap(arr[i], arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }

#ifdef _DEBUG
    printArray(arr, size);
#endif  
}

void maxHeapify(int arr[], int size, int rooti)
{
    int largest = rooti;
    int left = 2 * rooti + 1;
    int right = 2 * rooti + 2;

    if (left < size && arr[left] > arr[largest])
        largest = left;

    if (right < size && arr[right] > arr[largest])
        largest = right;

    if (largest != rooti)
    {
        swap(arr[rooti], arr[largest]);
        maxHeapify(arr, size, largest);
    }
}

void deleteKey(int arr[], int N)
{
    if (size <= 0)
    {
        cout << "\nCould not deleteKey\n";
        return;
    }

#ifdef _DEBUG
    cout << "=> Delete " << arr[0] << endl;
#endif    

    // 최대값(루트)을 마지막 요소로 교체하고 크기를 줄임
    arr[0] = arr[size - 1];
    size--;
    maxHeapify(arr, size, 0);

#ifdef _DEBUG
    printArray(arr, size);
#endif     
}

int main()
{
    int arr[20];
    int menu;
    while(1){        
        cout << "1. insert 2.delete 3.print 4.quit > " ;
        cin >> menu;
        if(menu == 1){
            int value;
            cout << "new value? ";
            cin >> value;
            insertKey(arr, 20, value);
        }
        else if(menu == 2){            
            deleteKey(arr, 20);
        }
        else if(menu == 3){
            printArray(arr, size);
        }
        else break;
    }
    cout << "Bye!" << endl;
    
    return 0;
}
