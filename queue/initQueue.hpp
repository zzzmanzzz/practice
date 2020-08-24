#include"queue.hpp"
#include"linkqueue.hpp"
#include"doubleStackQueue.hpp"

queue* initLinkQueue(const int arr[],const int size) {
    queue *q = new linkQueue();

    for(int i = 0 ; i < size ; i++) {
       q->enqueue(arr[i]);
    }
    
    return q;
}

queue* initDoubleStackQueue(const int arr[],const int size) {
    queue *q = new doubleStackQueue();

    for(int i = 0 ; i < size ; i++) {
       q->enqueue(arr[i]);
    }
    
    return q;
}