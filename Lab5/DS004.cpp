#include <iostream>
#include <string>
using namespace std;

struct st_score {
    int kor, eng, math;
    int total;
    double average;
    string result;
};

st_score getScore() {
    st_score score;
    cout << "국어, 영어, 수학 점수를 입력하세요: ";
    cin >> score.kor >> score.eng >> score.math;
    
    score.total = score.kor + score.eng + score.math;
    score.average = score.total / 3.0;
    

    return score;
}

int main() {
    st_score score = getScore();
   cout << score.total << " " << score.average << endl;
    cout << "Korean - " << (score.kor >= 70 ? "Pass" : "Fail") << endl;
    cout << "English - " << (score.eng >= 70 ? "Pass" : "Fail") << endl;
    cout << "Math - " << (score.math >= 70 ? "Pass" : "Fail") << endl;

    return 0;
}
