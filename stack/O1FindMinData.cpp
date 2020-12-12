#include"stack.hpp"
#include"O1MinStack.hpp"
#include<iostream>


/*
用O(1)取得stack中最小值
Reference Book 1, 2.5
*/
int main() {

    int arr[] = {-69, -84, 99, 26, -25, 16, -26, 7, -19, -98};
    O1MinStack m;

    for(int i : arr) {
        m.push(i);
    }
    std::cout << m.getMin() << std::endl;
    m.pop();
    std::cout << m.getMin() << std::endl;
    m.dump();      
    return 0;
}