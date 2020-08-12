#include "node.hpp"

/*
反轉鄰接linklist元素
Reference Book 1, 1.7
*/

node* reverseNeighbor(node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }

    node* dummyHead = new node();
    dummyHead->next = head;

    node* prev = dummyHead;
    node* cur = head;
    node* forInsert;

    while(cur != nullptr && cur->next != nullptr) {
        forInsert = cur->next;

        cur->next = forInsert->next;
        forInsert->next = cur;
        prev->next = forInsert;
        prev = cur;
        cur = cur->next;
    }

    node* ret = dummyHead->next;
    delete(dummyHead);
    return ret; 

}

int main() {
    int arr[] = {0, 1, 2, 3 , 4, 5, 6, 7, 8, 9};
    node* head = initViaArray(arr, 10);
    
    showList(head);
    showList(reverseNeighbor(head));

    head = initViaArray(arr, 3);
    
    showList(head);
    showList(reverseNeighbor(head));

}