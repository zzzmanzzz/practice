#include"node.hpp"
#include<iostream>

/*
刪除link list中 非末端節點 只能走一次linkkist
Reference Book 1, 1.10
*/


node* deleteInternalNode(node* head, int idx) {
    if(head== nullptr || idx < 0) {
        return nullptr;
    }

    node* cur = head;
    int curIdx = 0;
    while(idx > curIdx && cur != nullptr) {
        cur = cur->next;
        curIdx++;
    }

    if(cur == nullptr || cur->next == nullptr) {
        std::cout << "current index "<< curIdx << " is >= last index " << idx; 
        return nullptr;
    }

    node* next = cur->next;
    cur->data = next->data;
    cur->next = next->next;
    delete(next);
    
    return head;
}

int main() {
    node* head = init();
    showList(head);

    showList(deleteInternalNode(head, 8));

    return 0;
}