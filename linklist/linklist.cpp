#include "node.hpp"
#include <iostream>

node* initViaArray(int arr[], int size) {
    if(size < 1 || arr == nullptr) {
        return nullptr;
    }

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

node* initWithLoop(int arr[], int size, int startIndex) {
    if(startIndex >= size || startIndex < 0) {
        return nullptr;
    }
    node* head = initViaArray(arr, size);
    node* cur = head;
    node* loopStart = nullptr;
    int idx = 0;
    while(cur != nullptr) {
       if(idx == startIndex) {
           loopStart = cur;
           break;
       } else {
           idx++;
           cur = cur->next;
       }
    }
    cur = loopStart;
    while(true) { 
        if(cur->next == nullptr) {
            cur->next = loopStart;
            break;
        }
        cur = cur->next;
    }
    return head;
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

