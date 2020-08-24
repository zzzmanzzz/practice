#ifndef DOUBLESTACKQUEUE_H
#define DOUBLESTACKQUEUE_H

#include"queue.hpp"
#include<stack>
/*
用兩個stack實作queue
Reference Book 1, 2.6
*/
class doubleStackQueue : public queue {
    private:
    std::stack<int> in;
    std::stack<int> out;

    public:
    doubleStackQueue(){};

    bool hasNext();
    int dequeue();
    void enqueue(int data);

    ~doubleStackQueue(){};
};

#endif