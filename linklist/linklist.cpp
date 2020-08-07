#include "node.hpp"
#include <iostream>



node* initViaArray(int arr[], int size) {
    node *head = new node();
    node *cur = head;

    for(int i = 0 ; i < size ; i++) {
        cur->data = arr[i];
        if(i == size - 1) {
           cur->next = nullptr;
        } else {
           cur->next = new node();
        }
        cur = cur->next;
    }
    return head;
}

node* init() {
    int arr[] = {0, 1, 2, 3 , 4, 5, 6, 7, 8, 9};
    return initViaArray(arr, 10);
}

node* initWithDuplicate() {
    int arr[] = {0, 1, 4, 3 , 4, 2, 2, 2, 1, 4};
    return initViaArray(arr, 10);
}

void showList(node* head) {
    node* cur = head;
    for(; cur != nullptr ;cur = cur->next) {
        std::cout << cur->data;
        if(cur->next == nullptr) {
            std::cout << std::endl;
        } else {
            std::cout<<", ";
        }
    }
}

