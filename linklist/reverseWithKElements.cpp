#include "node.hpp"
#include<iostream>


node* reverseViaLoop(node* head) {
    if(head == nullptr || head->next == nullptr) {
        return head;
    }
    
    node* prev = head;    
    node* cur = head->next;
    head->next = nullptr;

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


/*
以每K個元素為一組反轉
Reference Book 1, 1.8
*/
node* reverseWithKElements(node* head, int k) {
    if(k < 2 || head == nullptr || head->next == nullptr) {
        return head;
    } 
    
    node* dummyHead = new node();
    dummyHead->next = head;
    
    node* prev = dummyHead;
    node* curHead = dummyHead->next;
    node *curTail;

    while(curHead != nullptr) {
        curTail = curHead;
        int counter = k;

        //find tail in k elements
        while (counter != 1) {
            counter--;
            if(curTail->next == nullptr) {
                break;
            }
            curTail = curTail->next;
        }

        //cut k elements
        prev->next = curTail->next;
        curTail->next = nullptr;

        node* tmp = reverseViaLoop(curHead);
        // now the head becomes tail
        curHead->next = prev->next;
        prev->next = tmp;

        prev = curHead;
        curHead = prev->next;
    }

    node* ret = dummyHead->next;
    delete(dummyHead);
    return ret;
}

int main() {
    node* head = init();
    showList(head);
    showList(reverseWithKElements(head, 6));
}