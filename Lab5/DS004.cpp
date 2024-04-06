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
    
    score.result = (score.average >= 70) ? "Pass" : "Fail";
    return score;
}

int main() {
    st_score score = getScore();
    cout << "평균 점수: " << score.average << endl;
    cout << "결과: " << score.result << endl;

    return 0;
}
