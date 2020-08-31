#include"linkStack.hpp"
#include"O1MinStack.hpp"
#include<iostream>

bool linkStack::hasNext() {
    return this->cur->next != nullptr ? true : false;
}

bool linkStack::isEmpty() {
    return this->cur == nullptr ? true : false;
}

void linkStack::push(int data) {
        node* tmp = new node();
        tmp->data = data;

        if(isEmpty()) {
            this->cur = tmp;
            this->cur->next = nullptr;
        } else {
            tmp->next = cur;
            this->cur = tmp;
        }
}

int linkStack::pop() {
    int ret;
    if(isEmpty()) {
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
    while(!isEmpty()) {
        std::cout << pop() <<" ";
    }
    std::cout << "<bottom>" << std::endl;
}


/*------------------------------------
用O(1)取得stack中最小值
Reference Book 1, 2.5
--------------------------------------*/

void O1MinStack::push(int data) {
    int tmp;

    if(!this->min->isEmpty()) {
       tmp = this->min->pop();
       this->min->push(tmp);
    } else {
       tmp = data;
    }

    if(data <= tmp) {
        this->min->push(data);
    }
    this->s->push(data);
}

int O1MinStack::pop() {
    int ret;
    if(isEmpty()) {
        throw "empty stack";
    } else {
        ret = this->s->pop();
        int tmp = this->min->pop();

        if(tmp != ret) {
            this->min->push(tmp);
        }
    }
    return ret;
}
