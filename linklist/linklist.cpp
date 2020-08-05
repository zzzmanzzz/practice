#include "node.hpp"
#include <iostream>

const int _LENGTH = 10;
node* init() {
    node *head = new node();
    node *cur = head;

    for(int i = 0 ; i < _LENGTH ; i++) {
        cur->data = i;
        if(i == _LENGTH - 1) {
           cur->next = nullptr;
        } else {
           cur->next = new node();
        }
        cur = cur->next;
    }
    return head;
}

node* initWithDuplicate() {
    node *head = new node();
    node *cur = head;

    for(int i = 0 ; i < _LENGTH ; i++) {
        cur->data = i % (_LENGTH - 3);
        if(i == _LENGTH - 1) {
           cur->next = nullptr;
        } else {
           cur->next = new node();
        }
        cur = cur->next;
    }
    return head;
}

void showList(node* head) {
    node* cur = head;
    for(; cur != nullptr ;cur = cur->next) {
        std::cout << cur->data;
        if(cur->next == nullptr) {
            std::cout << std::endl;
        } else {
            std::cout<<", ";
        }
    }
}

