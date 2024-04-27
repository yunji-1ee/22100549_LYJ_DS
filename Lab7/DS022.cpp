//시작: 10:00
//끝 : 11:30

#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int lcScore;
    int rcScore;

    int validateScore(const string& scoreType) {
        int score;
        cout << scoreType << "> ";
        cin >> score;
        while (score < 0 || score > 495) {
            cout << scoreType << "> ";  // 잘못된 점수 입력 
            cin >> score;
        }
        return score;
    }

public:
    // 생성자
    Student() : name(""), lcScore(0), rcScore(0) {}
    Student(string n) : name(n), lcScore(0), rcScore(0) {}
    Student(string n, int lc, int rc) : name(n), lcScore(lc), rcScore(rc) {}

    // 점수 입력 함수
    void inputScores() {
        lcScore = validateScore("LC");
        rcScore = validateScore("RC");
    }

    // 결과 출력 함수
    void printResult() {
        cout << "[" << name << "]" << endl;
        cout << "LC - " << lcScore << " " << (lcScore >= 350 ? "Pass" : "Fail") << endl;
        cout << "RC - " << rcScore << " " << (rcScore >= 350 ? "Pass" : "Fail") << endl;
        cout << "Total - " << (lcScore + rcScore) << endl;
    }
};

int main() {
    string studentName;
    getline(cin, studentName);

    Student student(studentName);
    student.inputScores();
    student.printResult();

    return 0;
}
