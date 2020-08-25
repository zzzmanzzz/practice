#include"stack.hpp"
#include"initStack.hpp"
#include<iostream>
/*
反轉Stack
Reference Book 1, 2.3
*/

int getLastElement(stack *s) {
    int tmp;
    int ret;
    if(s->hasNext()) {
       tmp = s->pop();
       ret = getLastElement(s);
       s->push(tmp);
    } else {
        ret = s->pop();
    }
    return ret;
}

void reverseStack(stack* s) {
    if(!s->isEmpty()) {
        int data = getLastElement(s);
        reverseStack(s);
        s->push(data);
    }
}

int main() {
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    stack *s = initStack(arr,  10);
    reverseStack(s);
    s->dump();
    return 0;
}