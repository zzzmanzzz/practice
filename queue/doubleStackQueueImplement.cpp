#include"doubleStackQueue.hpp"

bool doubleStackQueue::hasNext() {
    return !in.empty() || !out.empty();
}

int doubleStackQueue::dequeue() {
    if(out.empty()) {
        while(!in.empty()) {
            out.push(in.top());
            in.pop();
        }
    }
    int ret = out.top();
    out.pop();
    return ret;
}

void doubleStackQueue::enqueue(int data) {
    in.push(data);
}