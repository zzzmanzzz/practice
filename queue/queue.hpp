#ifndef QUEUE_H
#define QUEUE_H

class queue {
    public:
    virtual int dequeue() = 0;
    virtual void enqueue(int data) = 0;
    virtual bool hasNext() = 0;
    virtual void dump() = 0;
    virtual ~queue(){};
};

#endif