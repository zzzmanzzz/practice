#include "node.hpp"

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


int main() {
    node* head = init();
    showList(head);
    showList(reverseViaLoop(head));
    return 0;
}