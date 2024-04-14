#include <iostream>
#include <string>
using namespace std;

struct Menu {
    string name;
    int price;
};

struct Cafe {
    string name;
    int msize;
    Menu *list;
};

void addMenu(Menu &m) {
    string line;
    getline(cin, line);  //

    // 입력 받은 라인에서 메뉴 이름과 가격을 분리
    size_t pos = line.find_last_of(' ');  // 마지막 공백의 위치를 찾음
    m.name = line.substr(0, pos);  // 공백 전까지를 메뉴 이름으로
    m.price = stoi(line.substr(pos + 1));  // 공백 이후를 가격으로
}


void addCafe(Cafe &c) {
    getline(cin, c.name); 
    cin >> c.msize;
    cin.ignore(); // 숫자 입력 후 남은 개행 문자 제거
    c.list = new Menu[c.msize]; 
}


void displayMenus(Cafe &c) {
    cout << "==== " << c.name << " ====" << endl; 
    for (int i = 0; i < c.msize; i++) {
        cout << c.list[i].name << " " << c.list[i].price << endl; // 각 메뉴와 가격 출력
    }
    cout << "=============" << endl;
}

int main() {
    Cafe c;
    addCafe(c);
    for (int i = 0; i < c.msize; i++) {
        addMenu(c.list[i]);
    }

    displayMenus(c);

    delete[] c.list; // 동적 할당된 메모리 해제

    return 0;
}
