// LinkedList.cpp
#include "LinkedList.h"
#include <iostream>

// 소멸자
LinkedList::~LinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
}

// 리스트에 요소 추가
void LinkedList::addLast(int score, const std::string& name) {
    Node* newNode = new Node(score, name);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// 버블 정렬을 사용한 내림차순 정렬
void LinkedList::bubbleSort() {
    if (head == nullptr) return;

    bool swapped;
    Node* ptr1;
    Node* lptr = nullptr;

    do {
        swapped = false;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->score < ptr1->next->score) {
                std::swap(ptr1->score, ptr1->next->score);
                std::swap(ptr1->name, ptr1->next->name);
                swapped = true;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// 리스트 출력
void LinkedList::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->score << " " << current->name << std::endl;
        current = current->next;
    }
}
