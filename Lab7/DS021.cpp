#include <iostream>
using namespace std;

//시작: 3:05
//끝 : 4:00
class Student {
private:
    string name;
    string sid;
    int score[3];  // 국어, 영어, 수학 점수 배열

    double getAvg() const {
        double sum = 0;
        for (int i = 0; i < 3; i++) {
            sum += score[i];
        }
        return sum / 3;
    }

public:
    // 학생 정보 입력받기
    void readInfo() {
        cin >> sid;
        for (int i = 0; i < 3; i++) {
            cin >> score[i];
        }
        cin.ignore();  // 점수 입력 후 개행 문자 제거
        getline(cin, name);  // 이름이 공백을 포함할 수 있으므로 getline 사용
    }

    // 결과 출력
    void print() const {
        cout << "[" << sid << "] " << name << endl;
        cout << "The Average score is " << getAvg() << endl;
    }
};

int main() {
    Student student;

    // 학생 정보 입력
    student.readInfo();

    // 결과 출력
    student.print();

    return 0;
}
