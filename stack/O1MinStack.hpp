#ifndef O1MINSTACK_H
#define O1MINSTACK_H
#include"stack.hpp"
#include"linkStack.hpp"


/*
用O(1)取得stack中最小值
Reference Book 1, 2.5
*/
class O1MinStack : public stack {
     private:
     stack *s;
     stack *min;

    public:
    O1MinStack() {
        this->s = new linkStack();
        this->min = new linkStack();
    }
    bool hasNext() {return this->s->hasNext();};
    bool isEmpty() {return this->s->isEmpty();};
    void push(int data);
    int pop();
    void dump() {this->s->dump(); this->min->dump();};
    int getMin() { int ret = this->min->pop(); this->min->push(ret); return ret;};

    ~O1MinStack() {
        delete(s);
        delete(min);
    }
};


#endif