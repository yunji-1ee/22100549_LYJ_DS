#include <iostream>
#include <string>


//시작: 8:00
//끝:  8: 40


// 공통 prefix를 찾는 함수
std::string findCommonPrefix(std::string *words, int count) {
    if (count == 0) return "?";

    // 첫 번째 단어를 기준으로 하기
    std::string prefix = words[0];

    for (int i = 1; i < count; ++i) {
        std::string &currentWord = words[i];

        int maxLength = std::min(prefix.length(), currentWord.length());
        
        int j = 0;
        // 현재 단어와 prefix 비교
        while (j < maxLength && prefix[j] == currentWord[j]) {
            j++;
        }
        // 불일치하는 지점의 j에서 prefix 수정
        prefix = prefix.substr(0, j); //여기까지

        // 겹치는 문자가 없을 때 
        if (prefix.empty()) {
            return "?";
        }
    }
    return prefix.empty() ? "?" : prefix;
}

int main() {
    const int numWords = 3; // 입력받을 문자열 개수
    std::string words[numWords];

    for (int i = 0; i < numWords; ++i) {
        std::cin >> words[i];
    }

    std::string commonPrefix = findCommonPrefix(words, numWords);
    std::cout << commonPrefix << std::endl;

    return 0;
}
