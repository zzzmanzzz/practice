#ifndef STACK_H
#define STACK_H

class stack {
    public:
    virtual void push(int data) = 0;
    virtual int pop() = 0;
    virtual ~stack(){};
};

#endif
