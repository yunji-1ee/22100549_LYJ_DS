#include <iostream>
#include <string>

using namespace std;

int romanCharToValue(char c) {
    switch(c) {
        case 'I': return 1;
        case 'V': return 5;
        case 'X': return 10;
        case 'L': return 50;
        case 'C': return 100;
        case 'D': return 500;
        case 'M': return 1000;
        default: return 0;
    }
}

int main() {
    string roman;
    cout << "로마 숫자를 입력하세요: ";
    cin >> roman;

    int arabic = 0;

    for (char c : roman) {
        arabic += romanCharToValue(c);
    }

    cout << "아라비아 숫자: " << arabic << endl;

    return 0;
}