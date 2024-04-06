#include <iostream>
#include <string>

using namespace std;

int main() {
    string input;
    cout << "문자열을 입력하세요: ";
    getline(cin, input); // 공백을 포함하여 전체 줄 읽기

    // 알파벳의 빈도수를 저장
    int freq[26] = {0}; // 알파벳 a-z까지 빈도수 저장배열
    int blanks = 0;     // 공백 

    for (char ch : input) {
        if (ch >= 'A' && ch <= 'Z') {     // 대문자일 경우
            freq[ch - 'A']++;             
        } else if (ch >= 'a' && ch <= 'z') { // 소문자일 경우
            freq[ch - 'a']++;             
        } else if (ch == ' ') {           // 공백일 경우
            blanks++;
        }
    }

    // 결과 출력
    cout << "blanks : " << blanks << endl;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            cout << char('a' + i) << " : " << freq[i] << endl;
        }
    }

    return 0;
}
