// LinkedList.h
#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <string>

struct Node {
    int score;
    std::string name;
    Node* next;

    Node(int s, const std::string& n) : score(s), name(n), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() : head(nullptr) {}
    ~LinkedList();

    void addLast(int score, const std::string& name);
    void bubbleSort();
    void print() const;
};

#endif
