#include"stack.hpp"
#include"initStack.hpp"

int main() {
    int arr[] = {0,1,2,3,4,5,6,7,8,9};
    stack *s = initStack(arr,  10);
    s->dump();
    return 0;
}