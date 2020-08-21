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

void linkStack::push(int data) {
        node* tmp = new node();
        tmp->data = data;

        if(cur == nullptr) {
            cur = tmp;
            cur->next = nullptr;
        } else {
            tmp->next = cur;
            cur = tmp;
        }
}

int linkStack::pop() {
    int ret;
    if(cur == nullptr) {
        throw "empty stack";
    } else {
        ret = cur->data;
        node* tmp = cur;
        cur = cur->next;
        delete(tmp);
    }
    return ret;
}

