#include <iostream>
#include <cmath> // sqrt와 pow 함수 불러오기
using namespace std;

int main() {
    double x1, y1, x2, y2, distance;
    cout << "첫 번째 점의 좌표를 입력하세요 (x,y): ";
    cin >> x1 >> y1;
    cout << "두 번째 점의 좌표를 입력하세요 (x,y): ";
    cin >> x2 >> y2;
    
    distance = sqrt(pow(x2-x1,2) + pow(y2-y1,2));
    cout << "두 점 사이의 거리: " << distance << endl;

    return 0;
}
