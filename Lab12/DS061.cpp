// main.cpp 약 20분 소요

#include <iostream>
#include "Queue.h"

using namespace std;

int main() {
    Queue q;
    int choice, flag = 1, value;

    while (flag == 1) {
        cout << "\n1.enqueue 2.dequeue 3.showfront 4.showrear 5.displayQueue 6.exit > ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a Value: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.showfront();
                break;
            case 4:
                q.showrear();
                break;
            case 5:
                q.displayQueue();
                break;
            case 6:
                flag = 0;
                cout << "bye!" << endl;
                break;
            default:
                cout << "Invalid choice, please enter a number between 1 and 6." << endl;
        }
    }

    return 0;
}
