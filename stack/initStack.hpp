#include"stack.hpp"
#include"linkStack.hpp"

stack* initStack(const int arr[],const int size) {
    stack *s = new linkStack();

    for(int i = 0 ; i < size ; i++) {
       s->push(arr[i]);
    }
    
    return s;
}