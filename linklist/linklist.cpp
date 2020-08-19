#include "node.hpp"

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

std::vector<node*> initCommonTailList(int arr1[], int arr2[], int arr1Size, int arr2Size, int arr2pointToArr1Idx) {
    node* arr1Head = initViaArray(arr1, arr1Size);
    node* arr2Head = initViaArray(arr2, arr2Size);
    std::vector<node*> twoHeads;
    twoHeads.push_back(arr1Head);
    twoHeads.push_back(arr2Head);

    node* cur1 = arr1Head;
    node* cur2 = arr2Head;

    int idx = 0;
    while(cur1 != nullptr && idx < arr2pointToArr1Idx) {
        idx++;
        cur1 = cur1->next;
    }

    while(cur2->next != nullptr) {
        cur2 = cur2->next;
    }

    cur2->next = cur1;

    return twoHeads;

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

