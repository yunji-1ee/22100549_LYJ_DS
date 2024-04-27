#include <iostream>
#include <string>
using namespace std;

class Product {
private:
    string name;
    double price;
    int discountRate;
    string size;
    string manufacturer;

public:
    // 생성자
    Product() : name(""), price(0.0), discountRate(0), size(""), manufacturer("") {}

    // 상품 입력 함수
    void inputProduct() {
        getline(cin, name);
        cin >> price >> discountRate >> size >> manufacturer;
        cin.ignore();  // 입력 스트림 버퍼 비우기
    }

    // 상품 정보 출력 함수
    void printProduct() const {
        double finalPrice = price * (100 - discountRate) / 100;
        cout << finalPrice << " (-" << discountRate << "%) " << name << " " << size << " " << manufacturer << endl;
    }
};

int main() {
    Product products[100]; // 상품을 최대 100개 저장할 수 있는 배열
    int productCount = 0;
    int option;

    while (true) {
        cout << "1. Add 2.List 3.Quit > ";
        cin >> option;
        cin.ignore(); // 입력 스트림 버퍼 비우기 (개행 문자 제거)

        if (option == 1) {
            if (productCount < 100) {
                products[productCount].inputProduct();
                productCount++;
            } 
        } else if (option == 2) {
            for (int i = 0; i < productCount; i++) {
                products[i].printProduct();
            }
        } else if (option == 3) {
            break;
    }

    return 0;
}}
