#include "node.hpp"
#include<iostream>
/*
找倒數第k個元素
Reference Book 1, 1.5
*/

node* findLastKthElement(node* head, int k) {
    if(k < 1 || head == nullptr) {
        return nullptr;
    }
    
    node* slowCur = head;
    node* fastCur = head;
    node* ret = nullptr;

    int idx = k;
    while(fastCur != nullptr) {
        fastCur = fastCur->next;
        if(idx == 0) {
            slowCur = slowCur->next;
        } else {
            idx--;
        }
    }

    if(idx == 0 && fastCur == nullptr) {
        ret = slowCur;
    } else {
        ret = nullptr;
    }
    return ret;
}


int main() {
    int k = 6;
    node* head = init();
    showList(head);
    node* kth = findLastKthElement(head, k);
    if(kth != nullptr) {
        std::cout << kth->data;
    } else {
        std::cout << "no last "<< k <<" data" << std::endl;
    }
}