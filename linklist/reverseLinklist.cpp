#include "node.hpp"
#include<iostream>
/*
  Link list逆序問題
  Reference Book 1, 1.1   
*/

node* reverseViaLoop(node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    
    node* prev = head;    
    node* cur = head->next;
    prev->next = nullptr;

    node* ret;

    node* next;
    for(; cur != nullptr; cur = next) {
         if(cur->next == nullptr) {
            ret = cur;
        }
        next = cur->next;
        cur->next = prev;
        prev = cur;
       
    }
    return ret;
}

node* reverseViaRecursive(node* prev, node* cur) {
     if(cur == nullptr || cur->next == nullptr) {
        return cur;
    }

    node* ret;
    if(cur->next == nullptr) {
        ret = cur;
        cur->next = prev;
        return ret;
    } 
    node* next = cur->next;
    cur->next = prev;
    return reverseViaRecursive(cur, next);
}

node* reverseViaInsert(node* head) {
     if(head == nullptr || head->next == nullptr) {
        return head;
    }

    node* dummyHead = new node();
    dummyHead->next = head;
    node* cur = head->next;
    head->next = nullptr;

    while(cur != nullptr) {
        node* dNext = dummyHead->next;
        node* cNext = cur->next;
        dummyHead->next = cur;
        cur->next = dNext;
        cur = cNext;
    }

    node* ret = dummyHead->next;
    delete(dummyHead);

    return ret;
}

int main() {
    node* head = init();
    showList(head);
    showList(reverseViaInsert(head));
    return 0;
}