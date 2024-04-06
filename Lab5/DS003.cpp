#include <iostream>
using namespace std;

int main() {
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int month, day, dayCount = 0;
    
    cout << "월, 일을 입력하세요: ";
    cin >> month >> day;

    for (int i = 0; i < month - 1; ++i) {
        dayCount += daysInMonth[i];
    }

    dayCount += day;

    cout  << dayCount << endl;

    return 0;
}
