#include "node.hpp"
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

int main() {
    node* head = init();
    showList(head);
    showList(reverseViaRecursive(nullptr, head));
    return 0;
}