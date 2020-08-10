#include "node.hpp"
#include<iostream>
/*
檢查linklist是否存在環
1->2->3->4---|
      ^      |
      |------|
Reference Book 1, 1.6
*/

int main() {
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int loopIdx = 9; 
    node* head = initWithLoop(arr, 10,  loopIdx);

    showList(head);
    return 0;
}