#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 정렬 기준을 정의하는 함수
bool compare(const string &a, const string &b)
{
    if (a.length() == b.length())
        return a < b; // 길이가 같으면 사전 순으로
    else
        return a.length() < b.length(); // 길이 순으로
}

int main()
{
    int n;
    cin >> n; // 단어의 갯수

    vector<string> words(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> words[i];
    }

    vector<string> unique_words;
    for (const string &word : words)
    {
        // 중복을 제거하기 위해 vector와 find 함수를 사용
        if (find(unique_words.begin(), unique_words.end(), word) == unique_words.end())
        {
            unique_words.push_back(word);
        }
    }

    // 정렬!
    sort(unique_words.begin(), unique_words.end(), compare);

    // 결과 출력
    cout << "\n"
             << endl;
    for (const string &word : unique_words)
    {
        cout << word << endl;
    }

    return 0;
}
