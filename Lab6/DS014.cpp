#include <iostream>
#include <string>


//시작: 3:5
//끝:  3:25
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

int main() {
    std::string input;
    std::getline(std::cin, input);

    std::string trimmed = ltrim(rtrim(input));
    std::cout << trimmed << std::endl;
    return 0;
}
