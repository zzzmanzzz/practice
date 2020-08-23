#ifndef LINKQUEUE_H
#define LINKQUEUE_H

#include"queue.hpp"
/*
實作queue
Reference Book 1, 2.2
*/
struct node {
    int data;
    node* next;
};

class linkQueue : public queue {
    private:
    node* front;
    node* rear;

    public:
    linkQueue() {
        this->front = nullptr;
        this->rear = nullptr;
    }

    bool hasNext();
    int dequeue();
    void enqueue(int data);

    void dump();

    ~linkQueue() {
        while(rear != nullptr) {
            node* tmp = rear;
            rear = rear->next;
            delete(tmp);
        }
    }
};


#endif