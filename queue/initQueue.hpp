#include"queue.hpp"
#include"linkqueue.hpp"

queue* initQueue(const int arr[],const int size) {
    queue *q = new linkQueue();

    for(int i = 0 ; i < size ; i++) {
       q->enqueue(arr[i]);
    }
    
    return q;
}