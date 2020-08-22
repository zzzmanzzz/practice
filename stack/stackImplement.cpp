#include"linkStack.hpp"
#include<iostream>

bool linkStack::hasNext() {
    return this->cur != nullptr ? true : false;
}

void linkStack::push(int data) {
        node* tmp = new node();
        tmp->data = data;

        if(!hasNext()) {
            this->cur = tmp;
            this->cur->next = nullptr;
        } else {
            tmp->next = cur;
            this->cur = tmp;
        }
}

int linkStack::pop() {
    int ret;
    if(!hasNext()) {
        throw "empty stack";
    } else {
        ret = this->cur->data;
        node* tmp = cur;
        cur = this->cur->next;
        delete(tmp);
    }
    return ret;
}

void linkStack::dump() {
    std::cout << "<top> ";
    while(hasNext()) {
        std::cout << pop() <<" ";
    }
    std::cout << "<bottom> ";
}

