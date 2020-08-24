#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>

class queue {
    public:
    virtual int dequeue() = 0;
    virtual void enqueue(int data) = 0;
    virtual bool hasNext() = 0;
    virtual void dump();
    virtual ~queue(){};
};



#endif