#include <iostream>
#include <stack>
#include <string>

std::string removeAdjacentDuplicates(const std::string& s) {
    std::stack<char> stack;

    for (char ch : s) {
        if (!stack.empty() && stack.top() == ch) {
            stack.pop(); // 중복 문자 제거
        } else {
            stack.push(ch); // 스택에 문자 추가
        }
    }

    // 스택에서 결과 문자열 생성
    std::string result;
    while (!stack.empty()) {
        result = stack.top() + result;
        stack.pop();
    }

    return result;
}

std::string removeAllAdjacentDuplicates(const std::string& s) {
    std::string current = s;
    std::string previous;

    // 더 이상 중복이 없을 때까지 반복
    do {
        previous = current;
        current = removeAdjacentDuplicates(previous);
    } while (current != previous);

    return current;
}

int main() {
    std::string input;
    std::cin >> input;

    std::string result = removeAllAdjacentDuplicates(input);

    std::cout << result << std::endl;

    return 0;
}
