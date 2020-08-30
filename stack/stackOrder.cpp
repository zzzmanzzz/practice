#include"stack.hpp"
#include"linkStack.hpp"
#include<iostream>

bool isPossiblePopOrder(const int arr1[], const int arr2[], const int arrSize) {
    if(arrSize < 1 || arr1 == nullptr || arr2 == nullptr) {
        return false;
    }
    stack *s = new linkStack(); 
  

   int idx1 = 0;
   int idx2 = 0;
    while(idx2 < arrSize){
       if(idx1 < arrSize) {
         s->push(arr1[idx1]);
         idx1++;
       } else {
           break;
       }

       int tmp = s->pop();
       if(tmp != arr2[idx2]) {
          s->push(tmp);
          continue;
       } else {
            idx2++;
            while(!s->isEmpty()) {
              tmp = s->pop();
              if(arr2[idx2] != tmp) {
                  s->push(tmp);
                  break;
              }
              idx2++;
           }
       }

    }
    return idx1 == idx2;
}


int main() {
    int arr1[] = {0, 1, 2, 3, 4};
    int arr2[] = {4 ,3,2,1}; //true
    //int arr2[] = {0, 3, 2, 1, 4}; //true
    //int arr2[] = {0, 3, 4, 2, 1}; //true
    //int arr2[] = {0, 3, 1, 2, 4}; //false
    int size = 5;

    for(int i = 0;  i < 5;  i++ ) {
        std::cout << arr1[i] <<", ";
    }
    std::cout << std::endl; 
    for(int i = 0;  i < 5;  i++ ) {
        std::cout << arr2[i] <<", ";
    }

    std::cout << std::endl; 
    bool ans = isPossiblePopOrder(arr1, arr2, size);
    std::cout << ans;
    return 0;


}