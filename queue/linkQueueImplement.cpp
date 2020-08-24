#include"linkQueue.hpp"

bool linkQueue::hasNext() {
    return this->rear != nullptr ? true : false;
}

void linkQueue::enqueue(int data) {
    node* tmp = new node();
    tmp->data = data;
    tmp->next = nullptr;

    if(this->front == nullptr && this->rear == nullptr) {
        this->front = tmp;
        this->rear = tmp;
    } else {
        front->next = tmp;
        front = tmp;
    }
}

int linkQueue::dequeue() {
    int ret;
    if(this->hasNext()) {
        node* tmp;
        ret = this->rear->data;
        tmp = this->rear;

        //not last element
        if(this->rear != this->front) {
            this->rear = this->rear->next;
        } else {
            this->rear = nullptr;
            this->front = nullptr;
        }
        delete(tmp);
    } else {
       throw "queue is empty";   
    }

    return ret;
}


