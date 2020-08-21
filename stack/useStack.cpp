#include"stack.hpp"
#include"linkStack.hpp"
#include<iostream>

int main() {
    stack *s = new linkStack();
    s->push(1);
    s->push(2);
    s->push(3);

     try{
    std::cout<< s->pop();
    std::cout<< s->pop();
    std::cout<< s->pop();
    std::cout<< s->pop();
     } catch(char const* e){
         std::cout << e;
     }

    return 0;
}