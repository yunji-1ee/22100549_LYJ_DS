#include <iostream>
using namespace std;

int main() {
    double height, weight, bmi;
    cout << "신장(cm)과 체중(kg)을 입력하세요: ";
    cin >> height >> weight;
    
    bmi = weight / ((height / 100) * (height / 100));
    cout << "당신의 BMI는 " << bmi << " 입니다." << endl;
    
    if (bmi >= 25) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
