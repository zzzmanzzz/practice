#ifndef LINKSTACK_H
#define LINKSTACK_H
#include"stack.hpp"
/*
實作stack
Reference Book 1, 2.1
*/
struct node {
    int data;
    node* next;
};

class linkStack : public stack {
    private:
     node* cur;

    public:
    linkStack() {
        cur = nullptr;
    }
    bool hasNext();
    void push(int data);
    int pop();
    void dump();

    ~linkStack() {
        while(cur != nullptr) {
            node* tmp = cur;
            cur = cur->next;
            delete(tmp);
        }
    }
};

#endif