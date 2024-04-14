#include <iostream>


//시작: 11:00
//끝:  12:00 ~

struct Product {
    char name[100];
    int price;
};

// 대소문자 구분 없이 문자열 비교
bool caseInsensitiveCompare(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        char c1 = (*str1 >= 'A' && *str1 <= 'Z') ? *str1 + 'a' - 'A' : *str1;
        char c2 = (*str2 >= 'A' && *str2 <= 'Z') ? *str2 + 'a' - 'A' : *str2;
        if (c1 != c2) return false;
        str1++; str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

// 제품 비교
bool areProductsEqual(const Product& p1, const Product& p2) {
    return caseInsensitiveCompare(p1.name, p2.name) && (p1.price == p2.price);
}

int main() {
    Product product1, product2;

    // 상품명과 가격 입력
    std::cin.getline(product1.name, 100);
    std::cin >> product1.price;
    std::cin.ignore();  // 개행 문자 지우기
    std::cin.getline(product2.name, 100);
    std::cin >> product2.price;
    std::cin.ignore();  // 개행 문자 지우기

    if (areProductsEqual(product1, product2)) {
        std::cout << product1.name << " is equal" << std::endl;
    } else {
        std::cout << product1.name << " and " << product2.name << " are not equal." << std::endl;
    }

    return 0;
}
