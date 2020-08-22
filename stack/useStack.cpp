#include"stack.hpp"
#include"linkStack.hpp"

int main() {
    stack *s = new linkStack();
    s->push(1);
    s->push(2);
    s->push(3);
    
    s->dump();

    return 0;
}