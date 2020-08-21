#ifndef LINKSTACK_H
#define LINKSTACK_H
#include"stack.hpp"

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
    void push(int data);
    int pop();
    ~linkStack() {
        while(cur != nullptr) {
            node* tmp = cur;
            cur = cur->next;
            delete(tmp);
        }
    }
};

#endif