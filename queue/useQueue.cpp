#include"queue.hpp"
#include"initQueue.hpp"


int main() {
     int arr[] = {0,1,2,3,4,5,6,7,8,9};
     queue *q = initDoubleStackQueue(arr, 10);

     q->dump();

     return 0;
}