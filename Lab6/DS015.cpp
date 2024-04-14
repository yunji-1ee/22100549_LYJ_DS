#include <iostream>
#include <string>


//시작: 5:15
//끝:  5: 30

// 문자열 앞의 공백과 탭 제거
std::string ltrim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t");
    if (start == std::string::npos) {
        return "";  // 문자열 전체가 공백 또는 탭인 경우
    }
    return str.substr(start);  // 첫 번째 공백이 아닌 문자부터 문자열 끝까지 반환
}

// 문자열 뒤의 공백과 탭 제거
std::string rtrim(const std::string& str) {
    size_t end = str.find_last_not_of(" \t");
    if (end == std::string::npos) {
        return "";  // 문자열 전체가 공백 또는 탭인 경우
    }
    return str.substr(0, end + 1);  // 시작부터 공백이 아닌 마지막 문자까지 반환
}

// 마지막 단어의 길이를 반환하는 함수
int lengthOfLastWord(const std::string& str) {
    std::string trimmed = ltrim(rtrim(str));

    //a마지막 공백찾기
    size_t lastSpace = trimmed.find_last_of(" \t");
    if (lastSpace == std::string::npos) {
        // 공백이 없으면 전체 문자열이 하나의 단어입니다.
        return trimmed.length();
    } else {
        // 마지막 공백 이후의 문자열 길이
        return trimmed.length() - lastSpace - 1;
    }
}

int main() {
    std::string input;
    std::getline(std::cin, input);

    int lastWordLength = lengthOfLastWord(input);
    std::cout << lastWordLength << std::endl;

    return 0;
}
